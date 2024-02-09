#include <complex>
#include <numeric>
#include <iostream>
#include <vector>
#include <chrono>
#include <math.h>
#include <thread>
#include <algorithm>
#include <future>

using namespace std;

int MAX_DEPTH = 4;

typedef complex<double> cx;
// radix-2 in-place FFT, n must be 2^k (e.g. 2,4,6,...)
void fft(int n, cx x[]) {
	const cx J(0, 1);
	const double PI = 3.14159265358979324;
	// check the trivial case
	if (n == 1)
		return;

	// perform two sub-transforms
	int n2 = n/2; // size of sub-transform
	cx *xe = new cx[n2];
	cx *xo = new cx[n2];
	for (int i = 0; i < n2; i++) { // perform n/2 DIF 'butterflies'
		xe[i] = x[i] + x[i+n2];						 // even subset
		xo[i] = (x[i] - x[i+n2])*exp(-J*(2*PI*i/n)); // odd subset
	}
	fft(n2, xe);
	fft(n2, xo);

	// construct the result vector
	for (int k = 0; k < n2; k++) {
		x[2*k]   = xe[k]; // even k
		x[2*k+1] = xo[k]; // odd k
	}

	delete[] xe;
	delete[] xo;
}

// Attempt 1, making htreads for every split
void fftInefficientThreads(int n, cx x[]) {
	const cx J(0, 1);
	const double PI = 3.14159265358979324;
	// check the trivial case
	if (n == 1)
		return;

	// perform two sub-transforms
	int n2 = n/2; // size of sub-transform
	cx *xe = new cx[n2];
	cx *xo = new cx[n2];
	for (int i = 0; i < n2; i++) { // perform n/2 DIF 'butterflies'
		xe[i] = x[i] + x[i+n2];						 // even subset
		xo[i] = (x[i] - x[i+n2])*exp(-J*(2*PI*i/n)); // odd subset
	}

	thread thread_even(fftInefficientThreads,n2, xe);
	thread  thread_odd(fftInefficientThreads,n2, xo);

	thread_even.join();
	 thread_odd.join();

	// construct the result vector
	for (int k = 0; k < n2; k++) {
		x[2*k]   = xe[k]; // even k
		x[2*k+1] = xo[k]; // odd k
	}

	delete[] xe;
	delete[] xo;
}

// Attempt 2 - limiting depth
void fftEfficient1( int n,  cx x[], int depth = 0) {

	const cx J(0, 1);
	const double PI = 3.14159265358979324;
	// check the trivial case
	if (n == 1)
		return;

	// perform two sub-transforms
	int n2 = n/2; // size of sub-transform
	cx *xe = new cx[n2];
	cx *xo = new cx[n2];
	for (int i = 0; i < n2; i++) { // perform n/2 DIF 'butterflies'
		xe[i] = x[i] + x[i+n2];						 // even subset
		xo[i] = (x[i] - x[i+n2])*exp(-J*(2*PI*i/n)); // odd subset
	}
	if (depth < MAX_DEPTH){
		thread thread_even( fftEfficient1,n2, xe, depth + 1);
		thread  thread_odd( fftEfficient1,n2, xo, depth + 1);

		thread_even.join();
		 thread_odd.join();
	} else {
		 fftEfficient1(n2, xe, depth + 1);
		 fftEfficient1(n2, xo, depth + 1);
	}

	// construct the result vector
	for (int k = 0; k < n2; k++) {
		x[2*k]   = xe[k]; // even k
		x[2*k+1] = xo[k]; // odd k
	}

	delete[] xe;
	delete[] xo;

}


// Measure class responsible for measuring execution times

//class FFTTestBed {
//public:
//
//public:
//
//
//}

class Measure {
public:
	vector <double> avvec;

	Measure(int n, cx* x) : N(n), input(new cx[N]) {
		for (int i = 0; i < N; ++i) {
			input[i] = x[i]; 
		}
	}
		
//	void measure(TestFunction& func, double &mean, double &stdev, int iterations = 30) {
	void measurefft(double &mean, double &stdev, int iterations = 30) {

		for (int a = 0; a < 30; a++){ 
			auto start = chrono::high_resolution_clock::now();

			fftInefficientThreads(N, input);

			auto stop = chrono::high_resolution_clock::now();
			auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
			double duration_double = static_cast<double>(duration.count());
			avvec.push_back(duration_double);
		}
		sort(avvec.begin(), avvec.end(), greater<double>());
		avvec.erase(avvec.begin(), avvec.begin() + 10);

		double total = accumulate(avvec.rbegin(), avvec.rend(), 0.0, [](double accum, double val){ return accum + val; });
		mean = total/avvec.size();

		double total2 = accumulate(avvec.rbegin(), avvec.rend(), 0.0, [mean](double accum, double val){

			return accum + (val - mean)*(val - mean);


		 });

		stdev =  sqrt(total2/(avvec.size()));

	}

private:
	int N;
	cx* input;

};




int main() {

	int N = 8;
	for (int n = 0; n < 15; n++){ // segfault over 15, but why?
		N *=2;
		complex<double> input[N];

		// create the test input signal sequence
		for (int i = 0; i < N; i++)
			input[i] = complex<double>(i, -i);  // linear ramp for real part, negative ramp for imaginary part



		vector <double> avvec;
		double ave;

		double stddiv;

		Measure m(N, input);
		m.measurefft(ave, stddiv, 10000);
		cout << "Time taken by fft at N=" << N << " Average microseconds: "
			  << (int) ave << "±" <<  (int) stddiv << "micros" << endl;



	}

	int num_threads = thread::hardware_concurrency(); // Get number of cores
cout << num_threads<< endl;
	return EXIT_SUCCESS;
}

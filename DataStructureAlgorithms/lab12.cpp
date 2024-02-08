#include <complex>
#include <numeric>
#include <iostream>
#include <vector>
#include <chrono>
#include <math.h>

using namespace std;

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

// Measure class responsible for measuring execution times
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

			fft(N, input);

			auto stop = chrono::high_resolution_clock::now();
			auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
			double duration_double = static_cast<double>(duration.count());
			avvec.push_back(duration_double);
		}

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
	m.measurefft(ave, stddiv);
	cout << "Time taken by fft at N=" << N << " Average microseconds: "
		  << (int) ave << "±" <<  (int) stddiv << "ms" << endl;


	// display the results
//	for (const auto& c: input)
//		cout << c << endl;

	}
	return EXIT_SUCCESS;
}

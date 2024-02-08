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
	const double PI = 3.14159265359;
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

double get_average(vector<double> my_vec){
	double accum = 0;
	double count = 0;
	for(auto v: my_vec){
		accum += v;
		count += 1;
	}

	return  accum / count;
}


int main() {

	vector<double> average_me;

	int N = 8;
	for (int n = 0; n < 15; n++){ // segfault over 15, but why?
	N *=2;
	complex<double> input[N];

	// create the test input signal sequence
	for (int i = 0; i < N; i++)
		input[i] = complex<double>(i, -i);  // linear ramp for real part, negative ramp for imaginary part

	vector <double> avvec;
	for (int a = 0; a < 5; a++){ // measuring 100 times for statistics.
		auto start = chrono::high_resolution_clock::now();

		fft(N, input);

		auto stop = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
		double duration_double = static_cast<double>(duration.count());
		avvec.push_back(duration_double);
	}

	double total = accumulate(avvec.rbegin(), avvec.rend(), 0.0, [](double accum, double val){ return accum + val; });
	double ave = total/avvec.size();

	double total2 = accumulate(avvec.rbegin(), avvec.rend(), 0.0, [ave](double accum, double val){

		return accum + (val - ave)*(val - ave);


	 });

	cout << "Time taken by fft at N=" << N << " Average microseconds: "
		  << (int) ave << "±" <<  (int) sqrt(total2/(avvec.size())) * 3 << "ms" << endl;


	// display the results
//	for (const auto& c: input)
//		cout << c << endl;

	}
	return EXIT_SUCCESS;
}

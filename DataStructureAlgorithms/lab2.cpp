#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class Measurements {
	private:
	double* data;

	public:
	int data_length;
	
	int read(const char *fname){

		string filename = fname;
		ifstream file(filename);

		if (!file.is_open()) {
			cerr << "Can't open file - '" << filename << "'" << endl;
			return 0;
		}

		string line;
		getline(file, line);

		data_length = stoi(line);
//cout << data_length << endl;
		data = new double[data_length];

		getline(file, line); 
		string temp_string = line;
		istringstream iss(temp_string);

	for(int i = 0; i < data_length; ++i) {
		if(!(iss >> data[i])) {
			cerr << "Error reading number at position " << i << endl;
			delete data;
		}
	}

		file.close();


	return 1;
	
	}
	
	void print(){
		for (int i = 0; i < data_length; ++i) {
			cout << data[i] << " ";
		}
		cout << endl;
	}
	
	double mean(){
		return sum()/data_length;
	}

	double sum(){
		double accum = 0;
		for (int i = 0; i < data_length; ++i) {
			accum += data[i];
		}
		return accum;
	}

	void inc(double a){
		for (int i = 0; i < data_length; ++i) {
			data[i] += a;
		}
	}


	Measurements& operator=(const Measurements& other){


		if (this == &other) {
			return *this;
		}

		data_length = 100;

//  Why doesn't this work? it just crashes.
// 		if (data != nullptr) {
//			delete data;
//		}

		data = new double[data_length];
		for (int i = 0; i < data_length; ++i) {
			data[i] = other.data[i];
		}

		return *this;
	}

    ~Measurements() { 
        delete data; 
    }
};


int main(int argc, char *argv[]) {
	Measurements m1, m2;
	if (m1.read("mea.dat")) {
		m1.print();
		m2 = m1;
		m2.inc(0.1);
		cout << "Mean m1 is " << m1.mean() << endl;
		cout << "Mean m2 is " << m2.mean() << endl;
	}
	return 0;
}

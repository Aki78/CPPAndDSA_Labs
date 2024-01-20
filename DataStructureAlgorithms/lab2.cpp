
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class Measurements {
	private:
	int data_length;
	double* data;

	public:
	
	int read(const char *fname){

		string filename = fname;
		ifstream file(filename);

		if (!file.is_open()) {
			cerr << "Could not open the file - '" << filename << "'" << endl;
			return 0;
		}

		string line;
		getline(file, line);

		data_length = stoi(line);
		data = new double[data_length];

		getline(file, line); 
		string temp_string = line;
		istringstream iss(temp_string);

	for(int i = 0; i < data_length; ++i) {
		if(!(iss >> data[i])) {
			cerr << "Error reading number at position " << i << endl;
			delete[] data;
		}
	}

		file.close();
	cout << "closing file";


	return 1;
	
	}
	
	void print(){
	cout << "starting printing";
		for (int i = 0; i < data_length; ++i) {
			cout << data[i] << " ";
		}
		cout << endl;
	}
//	
//	double mean(){
//	}
//
//	Measurement& operator=(Masurement & other){
//
//	}
};

//ostream& operator<<(ostream& os, const Time& my_time) {
//	os << ":";
//	return os;
//}

//istream& operator>>(istream& is, Time& time2) {
//	string temp_string;
//	size_t colonPos;
//
//	is >> temp_string;
//	colonPos = temp_string.find(':');
//	string hour_string = temp_string.substr(0, colonPos);
//	string minute_string = temp_string.substr(colonPos + 1);
//	time2.set_hour(stoi(hour_string));
//	time2.set_minute(stoi(minute_string));
//
//	return is;
//}

//class RaceTime : public Time {
//	
//}

//istream& operator>>(istream& is, RaceTime& time2) {
//	string temp_string;
//	size_t colonPos;
//
//	is >> temp_string;
//	colonPos = temp_string.find(' ');
//	string hour_string = temp_string.substr(0, colonPos);
//	string minute_string = temp_string.substr(colonPos + 1);
//	time2.set_hour(stoi(hour_string));
//	time2.set_minute(stoi(minute_string));
//
//	return is;
//}

int main(int argc, char *argv[]) {
	Measurements m1, m2;
	if (m1.read("mea.dat")) {
cout << "printing now: " << endl;
		m1.print();
//		m2 = m1;
//		m2.inc(0.1);
//		cout << "Mean m1 is " << m1.meanMeasurements() << endl;
//		cout << "Mean m2 is " << m2.meanMeasurements() << endl;
	}
//	else
//		cout << "Can't open the file '" << filename << "'" << endl;
	return 0;
}

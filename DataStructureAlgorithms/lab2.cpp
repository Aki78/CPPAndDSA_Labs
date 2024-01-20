
#include <iostream>
#include <string>

using namespace std;

class Measurement {
    private:
    public:
        
    void read(const char *filename){
        
    }
    
    void print(){
    }
    
    double mean(){
    }

    Measurement& operator=(Masurement & other){

    }
};

ostream& operator<<(std::ostream& os, const Time& my_time) {
    os << ":";
    return os;
}

istream& operator>>(istream& is, Time& time2) {
    string temp_string;
    size_t colonPos;

    is >> temp_string;
    colonPos = temp_string.find(':');
    string hour_string = temp_string.substr(0, colonPos);
    string minute_string = temp_string.substr(colonPos + 1);
    time2.set_hour(stoi(hour_string));
    time2.set_minute(stoi(minute_string));

    return is;
}

class RaceTime : public Time {
    
}

istream& operator>>(istream& is, RaceTime& time2) {
    string temp_string;
    size_t colonPos;

    is >> temp_string;
    colonPos = temp_string.find(' ');
    string hour_string = temp_string.substr(0, colonPos);
    string minute_string = temp_string.substr(colonPos + 1);
    time2.set_hour(stoi(hour_string));
    time2.set_minute(stoi(minute_string));

    return is;
}

int main(int argc, char *argv[]) {
	Measurements m1, m2;
	if (m1.read(filename)) {
		m1.print();
		m2 = m1;
		m2.inc(0.1);
		cout << "Mean m1 is " << m1.meanMeasurements() << endl;
		cout << "Mean m2 is " << m2.meanMeasurements() << endl;
	}
	else
		cout << "Can't open the file '" << filename << "'" << endl;
	return 0;
}

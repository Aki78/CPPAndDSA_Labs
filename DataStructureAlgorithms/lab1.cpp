
#include <iostream>
#include <string>

using namespace std;

#define MAX_RACE_TIMES 10

class Time {
	private:
		int hour;
		int minute;
	public:
		string temp_string;
		
	void read(string print_me){
		cout << print_me << ": ";
		cin >> temp_string;
		size_t colonPos = temp_string.find(':');
		string hour_string = temp_string.substr(0, colonPos);
		string minute_string = temp_string.substr(colonPos + 1);
		
		hour = stoi(hour_string);
		minute = stoi(minute_string);
		
	}
	
	void set_hour(int new_hour){
		hour = new_hour;
	}
	
	void set_minute(int new_minute){
		minute = new_minute;
	}
	int get_hour() const {
		return hour;
	}
	
	int get_minute() const {
		return minute;
	}
	
	Time subtract( Time& time2) {
		Time temp;
		int hour_didff = hour - time2.get_hour();
		int min_didff = minute - time2.get_minute();
		temp.set_hour(hour_didff);
		temp.set_minute(min_didff);

		return temp;
	}
	Time add( Time& time2) {
		Time temp;
		int hour_didff = hour + time2.get_hour();
		int min_didff = minute + time2.get_minute();
		temp.set_hour(hour_didff);
		temp.set_minute(min_didff);

		return temp;
	}
	
	void display(){
		if (hour < 10) cout << "0" << abs(hour);
		else cout << abs(hour);
		cout << ":";
		if (minute < 10 ) cout << "0" << abs(minute);
		else cout << abs(minute);
		cout << endl;
	}
	
	bool lessThan(const Time& time2) const {
		if (time2.hour != hour) return time2.hour < hour;
		else return time2.minute < minute;
	}
	
	Time operator-( Time& time2) {
		return subtract(time2);
	}

	Time operator+( Time& time2) {
		return add(time2);
	}
	
	bool operator<(Time& time2){
		return lessThan(time2);
	}
	
	friend ostream& operator<<(ostream& os, const Time& my_time);
	friend istream& operator>>(istream& is, const Time& my_time);
};

ostream& operator<<(std::ostream& os, const Time& my_time) {
	if (my_time.get_hour() < 10) os << "0" << abs(my_time.get_hour());
	else os << abs(my_time.get_hour());
	os << ":";
	if (my_time.get_minute() < 10 ) os << "0" << abs(my_time.get_minute());
	else os << abs(my_time.get_minute());
//	os << endl;
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
	
	

	friend ostream& operator<<(ostream& os, const RaceTime& my_time);
	friend istream& operator>>(istream& is, const RaceTime& my_time);
};


ostream& operator<<(std::ostream& os, const RaceTime& my_time) {
	if (my_time.get_hour() < 10) os << "0" << abs(my_time.get_hour());
	else os << abs(my_time.get_hour());
	os << ":";
	if (my_time.get_minute() < 10 ) os << "0" << abs(my_time.get_minute());
	else os << abs(my_time.get_minute());
	return os;
}

istream& operator>>(istream& is, RaceTime& time2) {
	string temp_string;
	size_t colonPos;
	int hour, minute;

	cout << "Give the time 1 (hh mm)?  ";
//	is >> temp_string;
	is >> hour >> minute;
//	temp_string.erase(0, temp_string.find_first_not_of(" \n\r\t\f\v"));
//	temp_string.erase(temp_string.find_last_not_of(" \n\r\t\f\v") + 1);
//	colonPos = temp_string.find('\f');

//	string hour_string = temp_string.substr(0, colonPos);
//	string minute_string = temp_string.substr(colonPos + 1);

//	time2.set_hour(stoi(hour_string));
//	time2.set_minute(stoi(minute_string));


	time2.set_hour(hour);
	time2.set_minute(minute);

	return is;
}


int startRace(RaceTime* my_times){
	string size_string;
	int size;

	cout << "How many times you have? ";
	cin >> size_string;
	size = stoi(size_string);
	cout << size << endl;

	for(int i = 0; i < size; i++){
		cin >> my_times[i];
	}
	return size;
}

void printRaces(RaceTime* my_times, int size){
	cout << "Result list:" << endl;

	cout << " " << 1 << ": " << my_times[0] << " 00:00" << endl;

	for(int i = 1; i < size; i++){
		cout << " " << i+1 << ": " << my_times[i] <<  " " << my_times[i] - my_times[i-1] << endl;
	}
}

int main(){
	// Exercie 1A 
//	Time time1, time2, duration;
//	time1.read("Enter time 1");
//	time2.read("Enter time 2");
	

	
//	if (time1.lessThan(time2)) {
//		
//		duration = time2.subtract(time1);
//		cout << "Starting time was ";
//		time1.display();
//		
//	} else {
//		
//		duration = time1.subtract(time2);
//		cout << "Starting time was ";
//		time2.display();
//		
//	}
//	
//	cout << "Duration was ";
//	duration.display();
//	
	// Exercize 1B 
	
//	Time start, end, duration;
//	cout << "Enter starting time "; cin >> start;
//	cout << "Enter ending time "; cin >> end;
//	duration = start < end ? end - start : start - end;
//	cout << "Duration " << duration << endl;
//	cout << "Starting time was " << end - duration << endl;
//	cout << "Ending time was " << start + duration << endl;

	// Exercize 1C
	RaceTime raceTimeList[MAX_RACE_TIMES];
	int size = startRace(raceTimeList);
	printRaces(raceTimeList, size);


	return 0;
}

#include <iostream>
#include <string>
#include <stdexcept>

//Interface for ADT stack
#define MAXN 10

template <class T>
class Stack {
private:
	T   array[MAXN];
	int top;
public:

// Implementations of operation functions
	Stack() {
		top = -1;
	}

	bool push(T item) {
		if (top >= MAXN - 1)
		return(false);
		else {
		array[++top] = item;
		return (true);
		}
	}

	bool pop(T &item) {
		if (top == - 1)
		return(false);
		else {
		item = array[top--];
		return (true);
		}
	}

	void print() {
		int i;

		cout << "\nStack is : ";
		for (i = top; i >= 0 ; i-- )
			cout << endl << array[i];

		cout << endl;
	}


};



using namespace std;

class RPN {
	private:
	public:
	RPN(int h, int m){
		hour = h;
		minute = m;

	} 
	RPN(): hour(0), minute(0){

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
	
	RPN subtract( RPN& time2) {
		RPN temp;
		int hour_didff = hour - time2.get_hour();
		int min_didff = minute - time2.get_minute();
		temp.set_hour(hour_didff);
		temp.set_minute(min_didff);
		return temp;
	}
	RPN add( RPN& time2) {
		RPN temp;
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
	
	bool lessThan(const RPN& time2) const {
		if (time2.hour != hour) return time2.get_hour() < hour;
		else return  time2.get_minute() < minute;
	}
	
	RPN operator-( RPN& time2) {
		return subtract(time2);
	}

	RPN operator+( RPN& time2) {
		return add(time2);
	}
	
	bool operator<(RPN& time2){
		return lessThan(time2);
	}
	bool operator==(const RPN& time2) const {
		return (hour == time2.hour) && (minute == time2.minute);
	}
	
	friend ostream& operator<<(ostream& os, const RPN& my_time);
	friend istream& operator>>(istream& is, const RPN& my_time);
};

ostream& operator<<(std::ostream& os, const RPN& my_time) {
	if (my_time.get_hour() < 10) os << "0" << abs(my_time.get_hour());
	else os << abs(my_time.get_hour());
	os << ":";
	if (my_time.get_minute() < 10 ) os << "0" << abs(my_time.get_minute());
	else os << abs(my_time.get_minute());
	os << endl;
	return os;
}

istream& operator>>(istream& is, RPN& time2) {
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



//Application
int main () {
	 RPN item;
	 return 0;
}

#include <iostream>
#include <string>
#include <stdexcept>


#define  MAX 10

using namespace std;

template <class T>
class List {

private:
	int count;
	T   array[MAX];
	void compress(T *array, int empty_slot, int n) {

		for (int i = empty_slot + 1; i < n; i++)
			array[i - 1] = array[i];
	}

public:

	List() {
		count = 0;
	}

	bool empty() {
		return count == 0;
	}

	int size() {
		return count;
	}

	const T &operator[](int i) const {
		if (count > 0 && i <= count)
			return array[i - 1];
		else
			throw range_error("Index error");
	}

	bool insert_to_end(T item) {
		if (count < MAX) {
			array[count++] = item;
			return true;
		}
		else
			return false;
	}

	bool insert(T item) {
		if (count < MAX) {
			for (int i = 0; i < count+1; i++){
				if (array[i] < item) {
cout << " HIT " << endl;
						array[i] = item;
						return true;
					}
				}

				array[count++] = item;
				return true;
			}
		else
			return false;
		}

	bool find_pos(T item, int *pos) {
		int i;

		for (i = 0; i < count; i++) {
			if (array[i] == item) {
				*pos = i;
				return true;
			}
		}

		return false;
	}

	bool del(int orderNo) {
		if (orderNo >= 0 && orderNo < count) {
			//take item out means nothing
			compress(array, orderNo, count);
			--count; 	// or should this be inside compress
			return true;
		}
		else
			return false;
	}


};


class Time {
	private:
		int hour;
		int minute;
	public:
		string temp_string;

	Time(int h, int m){
		hour = h;
		minute = m;

	} 
	Time(): hour(0), minute(0){

	} 
		
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
		if (time2.hour != hour) return time2.get_hour() < hour;
		else return  time2.get_minute() < minute;
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
	bool operator==(const Time& time2) const {
		return (hour == time2.hour) && (minute == time2.minute);
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
	os << endl;
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




//Application
int main () {
	 List<Time> list;
	 Time item;
	int i;

	 cout << "Enter items?\n";
	 cin >> item;
	 while (!(item == Time(0, 0))) {
		 //list.insert_to_end(item);
//		 list.insert_to_end(item);
		 list.insert(item);
		 cin >> item;
	 }
	 //Print the contents of the list
	 for (i = 1; i <= list.size(); i++)
		 cout << "\n " << i << "th item was \n" << list[i];
	 cout << "\nDelete list items ?";
	 cin >> item;
	 while (!(item == Time(0, 0))) {
		if(list.find_pos(item, &i)) {
			cout << "\nThe position of the item in list is \n" << i;
			list.del(i);
		 } else
			cout << "\nItem not found";
			cin >> item;
		 }
	 //Print the contents of the list
	 for (i = 1; i <= list.size(); i++)
		cout << "\n " << i << "th item was " << list[i];
	cout << endl;

	 return 0;
}

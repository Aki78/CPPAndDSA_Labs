#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <unistd.h>
#include <termios.h>
#include <list>
#include <algorithm> 


#define  MAX 10

using namespace std;


//==========Part A====================================================
class Time {
	private:
		int hour, minute;
	public:
		string temp_string;

	Time(int h, int m){hour = h; minute = m;} 
	Time(char h, char m){hour = h - '0'; minute = m - '0';}
	Time(): hour(0), minute(0){} 
		
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

	bool greaterThan(const Time& time2) const {
		if (time2.hour != hour) return time2.get_hour() > hour;
		else return  time2.get_minute() > minute;
	}
	
	Time operator-( Time& time2) {
		return subtract(time2);
	}

	Time operator+( Time& time2) {
		return add(time2);
	}
	
	bool operator<( const Time& time2) const{
		return lessThan(time2);
	}

	bool operator>( const Time& time2) const{
		return greaterThan(time2);
	}
	bool operator==(const Time& time2) const {
		return (hour == time2.hour) && (minute == time2.minute);
	}
	
	friend ostream& operator<<(ostream& os, const Time& my_time);
	friend istream& operator>>(istream& is, const Time& my_time);
};

ostream& operator<<(ostream& os, const Time& my_time) {
	if (my_time.get_hour() < 10) os << "0" << abs(my_time.get_hour());
	else os << abs(my_time.get_hour());
	os << ":";
	if (my_time.get_minute() < 10 ) os << "0" << abs(my_time.get_minute());
	else os << abs(my_time.get_minute());
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


void printTimes(std::list<Time> my_times){
		cout << "Result list:" << endl;
	auto it = my_times.begin();
		cout << *it << endl ;
	++it;
	for (; it != my_times.end(); ++it) {
		cout << *it << endl;
	}

}

void printDiff(std::list<Time> my_times){
		cout << "Result list:" << endl;

	auto it = my_times.begin();
		cout << " " << *it << " 00:00" << endl ;

	for (; it != my_times.end(); ++it) {
				cout << " " << *it <<  " " << *it - *it++ << endl ;
		std::advance(it,-1);
		}
}

//==========Part B====================================================

// Interface of double linked list
// starting point
template <class T>
class Tdbl {
private:
	// definition of the list node class
	class Node {
	public:
		T _value;	
		Node *_pNext;	
		Node *_pPrev;	
		Node() : _pNext(NULL), _pPrev(NULL){}
		Node(T val) : _value(val), _pNext(NULL), _pPrev(NULL){}
		Node(T val, Node* next) : _value(val), _pNext(next), _pPrev(NULL){}
	};

	Node *first;
	Node *last;

public:

	Tdbl() {
		first = NULL;
		last = NULL;
	}

	~Tdbl() {
		Node *aux1, *aux2;

		aux1 = first;
		while (aux1 != NULL) {
			aux2 = aux1->_pNext;
			delete aux1;
			printf("Deleted\n"); //for testing purposes
			aux1 = aux2;
		}
	}

	Tdbl<T>& insert_to_back(T data) {
		Node *aux1, *aux2;

		aux1 = first;
		Node *newnode = new Node(data);

		if (first == NULL) first = newnode; //first node
		else { last -> _pNext = newnode; newnode -> _pPrev = last;} //not first node

		last = newnode;
			
		return *this;
	}

	Tdbl<T>& insert_to_front(T data) {
		Node *aux1, *aux2;

		aux1 = first;
		Node *newnode = new Node(data);

		if (first == NULL) first = newnode;
		else{
			first = newnode;
			aux1 -> _pPrev = first;
			newnode->_pNext = aux1;
		} 

			
		return *this;
	}

	void print(ostream &out) const {
		Node *what;

		out << "\nList:";
		what = first;
		while (what != NULL) {
			out << " " << what->_value << " ";
			what = what->_pNext;
		}
		out << endl;
	}

	void print() const {
		Node *what;

		cout << "\nList:";
		what = first;
		while (what != NULL) {
			cout << " " << what->_value << " ";
			what = what->_pNext;
		}
		cout << endl;
	}

	void print_reverse() const {
		Node *what;

		cout << "\nList:";
		what = last;
		while (what != NULL) {
			cout << " " << what->_value << " ";
			what = what->_pPrev;
		}
		cout << endl;
	}


};


template <class T>
ostream &operator<<(ostream &out,  Tdbl<T> const &data) {
	data.print(out);
	return out;
}



//==========Part C====================================================


template <class T>
class Matrix {
private:
	// definition of the list node class
	class Node {
	public:
		T _value;	
		Node *_pNext;	
		Node() : _pNext(NULL){}
		Node(T val) : _value(val), _pNext(NULL){}
		Node(T val, Node* next) : _value(val), _pNext(next){}
	};


	class RowNode {
	public:
		int rowInd;
		Node* colHead;
		RowNode(int r) : rowInd(r), colHead(NULL){}
	};

	RowNode* firstR;
	RowNode* lastR;

	Matrix(): firstR(NULL), lastR(NULL) {}
	~Matrix(){}


};
//Application
int main () {

// Part A

	struct termios oldt, newt;
	tcgetattr(STDIN_FILENO, &oldt); // Save old terminal settings
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO); // Turn off canonical mode and echoing
	tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Apply new settings



	std::list<Time> list;
	vector<int> inputVec;
	Time item;
	int i = 0;
	int num;

	vector<int>::iterator it;
	std::list<Time>::iterator list_it;


// getting the inputs
	char c;
	cout << "Enter times (terminate with 0 0): ";
	i = 0;
	while (true) {
		char c1 = 'a';
		char c2 = 'b';
		c1 = c;
		cin >> c;
		c2 = c;
		cout <<  c << " " ;
		if (c1 == '0' && c2 == '0') break;
		if (i > 0 && ( i%2 != 0)) list.push_back(Time(c1,c2));
		++i;
	}


	for (it = inputVec.begin(); it != inputVec.end(); ++it) {
		cout << *it << " ";
	}

	cout << endl;
	cout << "Unsorted list:" << endl;
	printTimes(list);
	list.sort(std::greater<Time>());
//	list.sort(std::less<Time>());
	cout << "Sorted list:" << endl;
	printTimes(list);
	cout << "Time difference" << endl;
	printDiff(list);



	tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restore old terminal settings

// Part B
	Tdbl<int> dbl;

	dbl.print();
	dbl.print_reverse();
	dbl.insert_to_back(10);
	dbl.print();
	dbl.print_reverse();
	dbl.insert_to_front(20);
	dbl.print();
	dbl.print_reverse();
	dbl.insert_to_back(30);
	dbl.print();
	dbl.print_reverse();
	dbl.insert_to_front(40);
	dbl.print();
	dbl.print_reverse();
	dbl.insert_to_back(50);
	dbl.print();
	dbl.print_reverse();


	 return 0;
}


// Implementation of list



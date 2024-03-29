#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

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
	RPN(): hour(0), minute(0){} 
	
	
	RPN subtract( RPN& other) {return *this}
	RPN add( RPN& other) {return *this}
	
	void display(){}
	
	bool lessThan(const RPN& other) const {return true}
	
	RPN operator-( RPN& other) {
		return subtract(other);
	}

	RPN operator+( RPN& other) {
		return add(other);
	}
	
	bool operator<(RPN& other){
		return lessThan(other);
	}
	bool operator==(const RPN& other) const {return true;}
	
	friend ostream& operator<<(ostream& os, const RPN& my_time);
	friend istream& operator>>(istream& is, const RPN& my_time);
};

ostream& operator<<(std::ostream& os, const RPN& my_time) {

	os << "HEllo World" << endl;
	return os;
}

istream& operator>>(istream& is, RPN& other) {
	string temp_string;
	is >> temp_string;
	return is;
}



//Application
int main () {
	 RPN item;
	 return 0;
}

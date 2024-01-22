#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <cctype>
#define MAXN 100

enum {NUM,OPE,BAD};
using namespace std;


//Interface for ADT stack

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
		if (top >= MAXN - 1) return(false);
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




//class RPN {
//
//	private:
//	public:
//	RPN() {} 
//	
//	
//	RPN subtract( RPN& other) {return *this;}
//	RPN add( RPN& other) {return *this;}
//	
//	void display(){}
//	
//	bool lessThan(const RPN& other) const {return true;}
//	
//	RPN operator-( RPN& other) {
//		return subtract(other);
//	}
//
//	RPN operator+( RPN& other) {
//		return add(other);
//	}
//	
//	bool operator<(RPN& other){
//		return lessThan(other);
//	}
//	bool operator==(const RPN& other) const {return true;}
//	
//	friend ostream& operator<<(ostream& os, const RPN& my_time);
//	friend istream& operator>>(istream& is, const RPN& my_time);
//};
//
//ostream& operator<<(ostream& os, const RPN& my_time) {
//
//	os << "HEllo World" << endl;
//	return os;
//}
//
//istream& operator>>(istream& is, RPN& other) {
//	string temp_string;
//	is >> temp_string;
//	return is;
//}


bool getInputType(const string& input) {

	stringstream ss(input);
	double num;
	if (ss >> num && ss.eof()) {
		return NUM;
	}

	if (input == "+" || input == "-" || input == "=") {
		return OPE;
	}

	return BAD;
}

bool add(Stack<string>& stack){

	string temp0, temp1;
	if(!stack.pop(temp0)){
		stack.push(temp0);
		return false;
	}
	if(!stack.pop(temp1)){
		stack.push(temp0);
		return false;
	}
	stack.push(to_string(stod(temp0) + stod(temp1)));

	return true;

}


bool subtract(Stack<string>& stack){

	string temp0, temp1;
	if(!stack.pop(temp0)){
		stack.push(temp0);
		return false;
	}
	if(!stack.pop(temp1)){
		stack.push(temp0);
		return false;
	}
	stack.push(to_string(stod(temp0) - stod(temp1)));

	return true;

}


void printTop(Stack<string>& stack){

	string temp;
	stack.pop(temp) ;
	cout << "Top Value is: " << temp << endl;

	stack.push(temp);

}



void operateOnStack(Stack<string>& stack){

	string op;
	stack.pop(op);	
	
	switch (op[0]) {
		case '-':
			while(subtract(stack)){};
			break;
		case '=':
			printTop(stack);
			break;
		case '+':
			while(add(stack)){};
			break;
		default:
			cout << "Invalid operator" << endl;
			break;
	}

}


int main() {

	// Exercise 4A
	string input;
	Stack<string> calc_stack;

	cout << "Enter a number or an operator (+, -, =)" << endl;
	while (true) {

		getline(cin, input);

		if (getInputType(input) == NUM) {
			calc_stack.push(input);

		} else if (getInputType(input) == OPE) {
			
			calc_stack.push(input);
			operateOnStack(calc_stack);

		} else {

			cout << "Incorrect" << endl;
		}
	}

	return 0;
}
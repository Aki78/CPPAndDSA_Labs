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
	cout << "OPE IS HAPPENIONG" <<  input << endl;
		return OPE;
	}

	return BAD;
}

bool add(Stack<string>& stack){
	cout << "adding" << endl;

	string temp0, temp1;
	if(stack.pop(temp0)) return true;
	if(stack.pop(temp1)) return true;

	return stack.push(to_string(stod(temp0) + stod(temp1)));

}


bool subtract(Stack<string>& stack){

	string temp0, temp1;

	if(stack.pop(temp0)) return true;
	if(stack.pop(temp1)) return true;

	return stack.push(to_string(stod(temp0) - stod(temp1)));

}


bool printTop(Stack<string>& stack){

	string temp;
	if(stack.pop(temp)) return true;

	cout << "The top is: " << temp;
	return stack.push(temp);

}



void operateOnStack(Stack<string>& stack){

	string op;
	stack.pop(op);	
	cout << "Operating" << endl;
	

	switch (op[0]) {
		case '+':
			while(add(stack)){};
			break;
		case '-':
			while(subtract(stack)){};
			break;
		case '=':
			printTop(stack);
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
	cout << "entering ope" << endl;
			
			calc_stack.push(input);
			operateOnStack(calc_stack);

		} else {

			cout << "Incorrect" << endl;
		}
	}

	return 0;
}

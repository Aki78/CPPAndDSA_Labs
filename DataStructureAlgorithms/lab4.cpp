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
		if (top == - 1) return(false);
		else {
			item = array[top--];
			return (true);
		}
	}

	void print() {
		int i;

		cout << "\nStack is : ";
		for (i = top; i >= 0 ; i-- ) cout << endl << array[i];

		cout << endl;
	}


};


class Calculator {
	private:
		string input;
		Stack<string> stack;
		string temp0, temp1;
		

	bool add(){

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


	bool subtract(){

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

	void printTop(){

		stack.pop(temp0) ;
		cout << "Top Value is: " << temp0 << endl;

		stack.push(temp0);

	}

	void operateOnStack(){

		string op;
		stack.pop(op);	
		
		switch (op[0]) {
			case '+':
				while(add()){};
				break;
			case '-':
				while(subtract()){};
				break;
			case '=':
				printTop();
				break;
			default:
				cout << "Invalid operator" << endl;
				break;
		}

	}

	public:
	Calculator() {} 
	void run() {

		cout << "Enter a number or an operator (+, -, =)" << endl;
		while (true) {

			getline(cin, input);

			if (getInputType(input) == NUM) {
				stack.push(input);

			} else if (getInputType(input) == OPE) {
				
				stack.push(input);
				operateOnStack();

			} else {

				cout << "Incorrect" << endl;
			}
		}

	}


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

	
	
	friend ostream& operator<<(ostream& os, const Calculator& my_time);
	friend istream& operator>>(istream& is, const Calculator& my_time);
};

ostream& operator<<(ostream& os, const Calculator& my_time) {

	return os;
}

istream& operator>>(istream& is, Calculator& other) {
	string temp_string;
	is >> temp_string;
	return is;
}

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


	Calculator calc;
	calc.run();

	return 0;
}

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <cctype>
#include <vector>
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




class CalculatorB1 {

	private:
		Stack<string> stack;
		string temp0;
		string input;
		Stack<string> tempStack;

	void printTop(){

		stack.pop(temp0) ;
		cout << "Top Value is: " << temp0 << endl;
		stack.push(temp0);

	}

	public:

	CalculatorB1() {} 
	int run() {
		cout << "Give an infix equation at one line" << endl;
		getline(cin, input);
		stack.print();

		infixToPostfix(input);
		
		printTop();

		return 0;
	}


	vector<string> stringToCharVector(const string& str) {
		vector<string> charVec;


		for (char c : str) {
			if (c != ' ') {  
				charVec.push_back(string(1, c));  
			}
		}

		return charVec;
	}

//	bool getInputType(const string& input) {
//
//		stringstream ss(input);
//		double num;
//		if (ss >> num && ss.eof()) {
//			return NUM;
//		}
//
//		if (input == "+" || input == "-" || input == "*" || input == "/" ||  input == "=" || input == "Q") {
//			return OPE;
//		}
//
//		return BAD;
//	}

	void infixToPostfix(string& infix){
		for(char c : infix) {

			string cString = string(1, c);
			if(isdigit(c)) {
				stack.push(cString);
			} else if(c == '+' || c == '*') {
				while(tempStack.pop(temp0) > -1 ) {
					if (precedence(c) <= precedence(temp0[0]))
						stack.push(temp0);
				}
					tempStack.push(cString);
			}
		}

		while(tempStack.pop(temp0) > -1) {
			stack.push(temp0);
		}

	}


	int precedence(char op) {
		if(op == '*') return 2;
		else if(op == '+') return 1;
		return 0;
	}

};


int main() {

// Part A

//	CalculatorA calc;
//	calc.run();

// Part B1

	CalculatorB1 calc;
	calc.run();


	return 0;
}

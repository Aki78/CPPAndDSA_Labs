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


//class CalculatorA {
//
//	private:
//		string input, temp0, temp1;
//		Stack<string> stack;
//		
//
//	bool add(){
//
//		if(!stack.pop(temp0)){
//			stack.push(temp0);
//			return false;
//		}
//		if(!stack.pop(temp1)){
//			stack.push(temp0);
//			return false;
//		}
//		stack.push(to_string(stod(temp0) + stod(temp1)));
//
//		return true;
//
//	}
//
//
//	bool subtract(){
//
//		if(!stack.pop(temp0)){
//			stack.push(temp0);
//			return false;
//		}
//		if(!stack.pop(temp1)){
//			stack.push(temp0);
//			return false;
//		}
//		stack.push(to_string(stod(temp1) - stod(temp0)));
//
//		return true;
//
//	}
//
//	void printTop(){
//
//		stack.pop(temp0) ;
//		cout << "Top Value is: " << temp0 << endl;
//		stack.push(temp0);
//
//	}
//
//	void operateOnStack(){
//
//		string op;
//		stack.pop(op);	
//		
//		switch (op[0]) {
//			case '+':
//				add();
//				break;
//			case '-':
//				subtract();
//				break;
//			case '=':
//				printTop();
//				break;
//			case 'Q':
//				stack.print();
//				break;
//			default:
//				cout << "Invalid operator" << endl;
//				break;
//		}
//	}
//
//	public:
//
//	CalculatorA() {} 
//	void run() {
//		cout << "Enter a number or an operator (+, -, =)" << endl;
//		while (true) {
//
//			getline(cin, input);
//			
//
//			if (getInputType(input) == NUM) {
//				stack.push(input);
//
//			} else if (getInputType(input) == OPE) {
//				
//				stack.push(input);
//				operateOnStack();
//
//			} else {
//
//				cout << "Incorrect" << endl;
//			}
//		}
//
//	}
//	bool getInputType(const string& input) {
//
//		stringstream ss(input);
//		double num;
//		if (ss >> num && ss.eof()) {
//			return NUM;
//		}
//
//		if (input == "+" || input == "-" || input == "=" || input == "Q") {
//			return OPE;
//		}
//
//		return BAD;
//	}
//};


class CalculatorB1 {

	private:
		Stack<string> stack;
		string temp0;
		string input;
		


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

		vector<string> stackList = stringToCharVector(input);
		Stack<string> opeStack;
		string temp_char;

		for(string c: stackList ) {

			if (getInputType(c) == NUM) stack.push(c);
			else if (getInputType(c) == OPE) opeStack.push(c);
			else return -1;
			
		}
		
		while(opeStack.pop(temp_char)) { stack.push(temp_char);}
		stack.print();
		printTop();

		return 0;
	}



	vector<string> stringToCharVector(const string& str) {
		vector<string> charVec;


	    for (char c : str) {
		if (c != ' ') {  
		    charVec.push_back(std::string(1, c));  
		}
	    }

		return charVec;
	}

	bool getInputType(const string& input) {

		stringstream ss(input);
		double num;
		if (ss >> num && ss.eof()) {
			return NUM;
		}

		if (input == "+" || input == "-" || input == "*" || input == "/" ||  input == "=" || input == "Q") {
			return OPE;
		}

		return BAD;
	}
	void infixTopostfix(char *infix, char *postfix){
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

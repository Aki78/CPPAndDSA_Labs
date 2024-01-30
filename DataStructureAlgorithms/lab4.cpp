#include <iostream>
#include <string>
# include <sstream>
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
		Stack<string> postfix;
		string infix;
		string temp0;
		string input;
		Stack<string> tempStack;
		bool ErrorStatus = false;

	void printTop(){

		postfix.pop(temp0) ;
		cout << "Top Value is: " << temp0 << endl;
		postfix.push(temp0);

	}

	public:

	CalculatorB1() {} 
	int run() {
		cout << "Give an infix equation at one line" << endl;

		infixToPostfix();
		if(ErrorStatus==true)
			for(int i = 0; i < 100; i++) 
				postfix.pop(temp0);

		postfix.print();

		
		printTop();

		return 0;
	}

	
	string removeSpaces(string input) {
		string output;
		for (char c : input) {
			if (c != ' ') {
				output += c;
			}
		}
		return output;
	}

	void readLine() {
		getline(cin, infix);
		infix = removeSpaces(infix);
		
	}


	bool getInputType(const char& input) {
		string input_string (1,input);

		stringstream ss(input_string);
		double num;
//			cout << "prepping number"<< endl;
		if (ss >> num && ss.eof()) {
//			cout << "GEtting number"<< endl;
			return NUM;
		}

		if (input == '+' ||  input == '*' ||  input == '=' || input == 'Q') {
			cout << "GEtting operator: "<< input << endl;
			return OPE;
		}

		cout << "GEtting BAD"<< endl;
		return BAD;
	}

	void infixToPostfix(){
		readLine();
		for(int i=0; i < infix.size(); i++){
			string char_string (1,infix[i]);
			int input_type = getInputType(infix[i]);
			cout << "input Tyep: " << input_type << endl;
			if(input_type == NUM) postfix.push(char_string);
			else if (input_type == OPE){dealWithOperators();}
			else dealWithBadInput();
		}
		infix = "";
	}


	void dealWithOperators(){

		cout << "Dealing" << endl;

	}


	void dealWithBadInput(){

		cout << "Bad iput" << endl;
		ErrorStatus = true;
		infix = "";
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

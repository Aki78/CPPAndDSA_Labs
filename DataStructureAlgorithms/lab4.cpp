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
		Stack<string> opestack;
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
		while(!ErrorStatus){
			cout << "Give an infix equation at one line" << endl;

			infixToPostfix();
			if(ErrorStatus==true)
				for(int i = 0; i < 100; i++) 
					postfix.pop(temp0);

			postfix.print();

			
			printTop();
		}

		cout << "Bad input, program terminado" << endl;

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


	int getInputType(const char& input) {
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

		cout << "GEtting BAD"<< input << endl;
		return BAD;
	}

	void infixToPostfix(){
		readLine();
		for(int i=0; i < infix.size(); i++){
			string char_string (1,infix[i]);
			int input_type = getInputType(infix[i]);
		//	cout << "input Tyep: " << input_type << endl;
			if(input_type == NUM) postfix.push(char_string);
			else if (input_type == OPE){dealWithOperators(precedence(infix[i]), char_string);}
			else dealWithBadInput();
		}
		while(opestack.pop(temp0)){ cout << "AAA: " << temp0 << endl; postfix.push(temp0);}
		infix = "";
		postfix.print();
	}


	int dealWithOperators(int new_prec, string new_ope_string){

		if(!opestack.pop(temp0)){
			postfix.push(new_ope_string);
//			postfix.print();
			return 0;
		}
		int old_prec =  precedence(temp0);

		if(old_prec == new_prec){
			opestack.push(new_ope_string);
			postfix.push(temp0);
			postfix.print();
			return 0;
		}
		else if(old_prec < new_prec ){
			opestack.push(temp0);
			opestack.push(new_ope_string);
			cout << "Ope stack:" << endl;
			opestack.print();
			postfix.print();
			return 0;
		}
		else if(old_prec > new_prec ){
			postfix.push(temp0);
			opestack.push(new_ope_string);
			postfix.print();
			return 0;
		}

		while (new_prec <= old_prec):
                // Pop operators with higher or equal precedence and append them to the postfix expression
                postfixExpression.append(operatorStack.pop())
            // Push the current operator onto the stack
            operatorStack.push(token)

		return 1;
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

	int precedence(string op) {
		if(op == "*") return 2;
		else if(op == "+") return 1;
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

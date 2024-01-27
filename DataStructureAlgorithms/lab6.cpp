/* dynlist.cpp -- Dynamic linked linear list */

#include <iostream>

using namespace std;


// Interface of list
template <class T>
class LinkedList {
private:
	// definition of the list node class
	class Node {
	public:
		T _value;	// data
		Node *_pNext;	// pointer to the next node
		Node() : _pNext(NULL) {}
		Node(T val) : _value(val), _pNext(NULL) {}
		Node(T val, Node* next) : _value(val), _pNext(next) {}
	};

	Node *first;
//	Node *last;

public:

	LinkedList() {
		first = NULL;
	//	last = NULL;
	}

	~LinkedList() {
		Node *aux1, *aux2;

		aux1 = first;
		while (aux1 != NULL) {
			aux2 = aux1->_pNext;
			delete aux1;
			printf("Deleted\n"); //for testing purposes
			aux1 = aux2;
		}
	}

	LinkedList<T>& insert_to_end(T data) {
		Node *aux1, *aux2;

		aux1 = first;
		Node *newnode = new Node(data);
		if (first == NULL){
			first = newnode;		//first node
		}
		else{
			while (aux1 -> _pNext != NULL) {
				printf("\n data is %c\n", aux1->_value); //for testing purposes
				aux1 = aux1->_pNext;
cout << "test "<< endl;
			}
			aux1-> _pNext = newnode;

		}			
			
//			last->_pNext = newnode;	//not first node
//		last = newnode;

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
};

// Implementation of list

template <class T>
ostream &operator<<(ostream &out,  LinkedList<T> const &data) {
	data.print(out);
	return out;
}



// Application
int main (void)  {
	LinkedList<char> list;

	list.insert_to_end('a').insert_to_end('b').insert_to_end('c').insert_to_end('d');

	cout << list;
	cout << list;
}

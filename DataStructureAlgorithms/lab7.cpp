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

public:

	LinkedList() {
		first = NULL;
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
				aux1 = aux1->_pNext;
cout << "test "<< endl;
			}
			aux1-> _pNext = newnode;

		}			
			
		return *this;
	}

	void print(ostream &out) const {
		Node *what;

		if (first != NULL){
			out << "\nList:";
			what = first;
			while (what != NULL) { 
				out << " " << what->_value << " ";
				what = what->_pNext;
			}
			out << endl;
		}
	}

	void print() const {
		Node *what;

		if (first != NULL){
			cout << "\nList:";
			what = first;
			while (what != NULL) {
				cout << " " << what->_value << " ";
				what = what->_pNext;
			}
			cout << endl;
		}
	}


	void delete_first(){
		if (first != NULL){
			Node *aux1, *aux2;
			aux1 = first;
			first = first->_pNext;
			cout << "Deleting inner...: " << first->_value << endl;
			delete[] aux1;
		}

	}

	void delete_last(){

		 if (first != NULL) {
			  if (first->_pNext == NULL) {
				  delete first;
				  first = NULL;
			  } else {
				  Node *aux1 = first;
				  Node *aux2 = NULL;

				  while (aux1->_pNext != NULL) {
					   aux2 = aux1;
					   aux1 = aux1->_pNext;
				  }

				  aux2->_pNext = NULL;
				  delete aux1;
		     }
		}
			
	}

	bool find_pos(T item, int &pos){
		pos = 0;
		if (first != NULL){
			Node *aux1; 
			Node  aux2;
			
			aux1 = first;

			while (aux1 -> _pNext != NULL) {
				pos++;
				aux1 = aux1->_pNext;
				if(aux1->_value == item) return true;
			}
		}
			
		return false;
	}



};


template <class T>
ostream &operator<<(ostream &out,  LinkedList<T> const &data) {
	data.print(out);
	return out;
}




// Application
int main ()  {


	LinkedList<char> list;
	int order_no;
	char to_be_searched;
	list.delete_last();
	list.insert_to_end('?');
	list.delete_last();
	list.insert_to_end('x');
	list.insert_to_end('a');
	list.insert_to_end('b');
	list.insert_to_end('c');
	list.insert_to_end('d');
	list.insert_to_end('y');
	list.print();
	list.print();
	cout << "Enter first character to be searced\n";
	cin >> to_be_searched;
	if (list.find_pos(to_be_searched, order_no))
		cout << "The order no is " << order_no << endl;

	else
		cout << "Not found\n";
	cout << "Enter second character to be searced\n";
	cin >> to_be_searched;
	if (list.find_pos(to_be_searched, order_no))
		cout << "The order no is " << order_no << endl;
	else
		cout << "Not found\n";
	list.delete_first();
	cout << "Deleting First\n";
	cout << list;
	cout << "Deleted First\n";
	list.delete_last();
cout << "final list" << endl;
	cout << list;

	return (EXIT_SUCCESS);


}

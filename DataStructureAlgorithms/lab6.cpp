/* dynlist.cpp -- Dynamic linked linear list */

#include <iostream>

using namespace std;


// Interface of list

//====PartA=======================================================

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


//====PartB=======================================================


class NodeData {

	friend ostream& operator<< (ostream& stream, const NodeData *p);

	public:
	virtual ostream& print(ostream &stream) const = 0;
	virtual bool operator<(NodeData *) = 0;

};


ostream& operator<< (ostream& stream, const NodeData *p) {
	return p->print(stream);
}


class Complex: public NodeData{
private:

	double x;
	double y;


public:

	Complex(double x0=0, double y0=0):x(x0),y(y0){}

	virtual ostream& print(ostream &stream) const override {
		stream << x << " + " << y << "i";
		return stream;
	}



	virtual bool operator<(NodeData *node) override {
		Complex *complexNode = dynamic_cast<Complex*>(node);
//		Complex *complexNode = node; // Did not work...
		if (!complexNode) {
			return false; 
		}
		
		return (x * x + y * y) < (complexNode->x * complexNode->x + complexNode->y * complexNode->y);
	}


	friend ostream& operator<< (ostream& stream, const Complex &c) {
		return c.print(stream);
	}


};


class String : public NodeData {
private:
	std::string value;

public:
	String(const std::string &val) : value(val) {}

	virtual ostream& print(ostream &stream) const override {
		stream << value;
		return stream;
	}

	virtual bool operator<(NodeData *other) override {
		String *stringOther = dynamic_cast<String*>(other);
		if (!stringOther) {
			return false; // or handle differently
		}
		return value < stringOther->value;
	}
};





//================================================================
// Application
int main ()  {

// Bart A
//	LinkedList<char> list;
//
//	list.insert_to_end('a').insert_to_end('b').insert_to_end('c').insert_to_end('d');
//
//	cout << list;



// Bart B


LinkedList<NodeData *> list;
//list.insert_to_end(new Complex(1, 3));
//list.insert_to_end(new Complex(5, 9));
list.insert_to_end(new String("First complex number")).insert_to_end(new Complex(1, 3));
list.insert_to_end(new String("Second complex number")).insert_to_end(new Complex(5, 9));
list.print(cout);



}

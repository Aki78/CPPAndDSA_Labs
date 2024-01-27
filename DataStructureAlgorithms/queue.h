/* standard array queue implementation */
#include <iostream>

using namespace std;

// The interface of queue
#define MAXN 5
template <class T>
class Queue {
private:
    T   array[MAXN];
    int number_of_items;

public:
	Queue();
	bool enqueue(T item);
	bool dequeue(T &item);
	void print();
};


// The implementation of queue
template <class T>
Queue<T>::Queue() {
	number_of_items = 0;
}

template <class T>
bool Queue<T>::enqueue(T item) {
    if (number_of_items >= MAXN)
        return(false);
    else {
        array[number_of_items++] = item;
        return (true);
    }
}

template <class T>
bool Queue<T>::dequeue(T &item) {
    int i;

    if (number_of_items == 0)
        return(false);
    else {
        item = array[0];
        for (i = 0; i < number_of_items-1; i++)
            array[i] = array[i+1];
        number_of_items--;
        return (true);
   }
}

template <class T>
void Queue<T>::print() {
    int i;

    cout << "\nQueue now: \n\n";
    for (i = 0; i < number_of_items; i++ ) {
        cout << " " << array[i] << "";
    }
    cout << "\n\n";
}
/* simple test program to test the queue implementation */
#include <iostream>
#include <conio.h>
#include "queue.h"

using namespace std;


// Application
int main() {
    Queue<char> queue;
    bool        succeed;
    char        chr;

    cout << "\nEnter a letter to be queued ";
    cout << "\nor digit 1 to dequeue a letter";
    cout << "\nor Return to quit a program\n";

    chr = _getche();
    while (chr != '\n' && chr != '\r') {
        if (isalpha(chr)) {
            succeed=queue.enqueue(chr);
            queue.print();
            if (!succeed)
                printf("\n Enqueue operation failed\n");
        }
        if (chr == '1') {
            succeed = queue.dequeue(chr);
            if  (succeed) {
                cout << "\na letter dequeued " << chr << " ";
				queue.print();
            } else
                cout << "\nDequeue operation failed\n ";
        }
            chr = _getche();
    }
	
	return 0;
}

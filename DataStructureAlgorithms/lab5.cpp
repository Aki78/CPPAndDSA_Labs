/* simple test program to test the queue implementation */
#include <iostream>

#include <termios.h>
#include <unistd.h>

#define N 100000


using namespace std;

// The interface of queue
#define MAXN 5
template <class T>
class Queue {
private:
	T   *array;
	int number_of_items;

public:


// The implementation of queue
	Queue() {
		number_of_items = 0;
		array = new T[MAXN];
	}

	bool enqueue(T item) {
		checkSizeAndResize();
	//	if (number_of_items >= MAXN)
//			return(false);
//		else {
			array[number_of_items++] = item;
			return (true);
//		}
	}

	bool dequeue(T &item) {
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

	void checkSizeAndResize(){
		if(number_of_items%5 == 0){
			T* new_array = new T[number_of_items + 5];
			for (int i = 0; i < number_of_items; ++i) {
				new_array[i] = array[i];
			}
			T* arrayPtr = array;
			delete array;
			array = new_array;
		}
		
	}


	void print() {
		int i;

		cout << "\nQueue now: \n\n";
		for (i = 0; i < number_of_items; i++ ) {
			cout << " " << array[i] << "";
		}
		cout << "\n\n";
	}


};




char getChar() {
// Replacement of the windows specific function _getche()
	char ch;
	struct termios oldt, newt;

	tcgetattr(STDIN_FILENO, &oldt); // Get the current terminal settings
	newt = oldt; // Copy the settings to the new variable
	newt.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echo
	tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Apply the new settings

	ch = getchar(); // Read a single character

	tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restore the original settings
	return ch;
}


// Application
int main() {
//	  Part A

//	Queue<char> queue;
//	bool		succeed;
//	char		chr;
//
//	cout << "\nEnter a letter to be queued ";
//	cout << "\nor digit 1 to dequeue a letter";
//	cout << "\nor Return to quit a program\n";
//
////	chr = _getche();
//	chr = getChar(); //I had to use this because _getche is windows specific and doesn't exist in linux
//	while (chr != '\n' && chr != '\r') {
//		if (isalpha(chr)) {
//			succeed=queue.enqueue(chr);
//			queue.print();
//			if (!succeed)
//				printf("\n Enqueue operation failed\n");
//		}
//		if (chr == '1') {
//			succeed = queue.dequeue(chr);
//			if  (succeed) {
//				cout << "\na letter dequeued " << chr << " ";
//				queue.print();
//			} else
//				cout << "\nDequeue operation failed\n ";
//		}
////			chr = _getche();
//			std::cin.get();
//	}




//	  Part B


	Queue<int> queue;
	int item;
	clock_t tic, tac;
	double duration;
	int i;


	cout << "Fill the queue with " << N << " items\n";
	item = 0;
	for (i = 0; i < N; i++) {
		if (!queue.enqueue(item++)) {
			cerr << "Enqueue failed\n";
			exit(1);
		}
	}
	cout << "Remove half of them\n";
	for (i = 0; i < N/2; i++) {
		if (!queue.dequeue(item)) {
			cerr << "Dequeue failed\n";
			exit(1);
		}
	}
	cout << "Add then new " << N/2 << " items to the queue\n";
	item++;
	for (i = 0; i < N/2; i++) {
		if (!queue.enqueue(item++)) {
			cerr << "Enqueue failed\n";
			exit(1);
		}
	}
	// then we deque elements and measure the execution time
	cout << "Then dequeue them\n";
	tic = clock();
	for (i = 0; i < N; i++) queue.dequeue(item);
	tac = clock();
	cout << "Last item value " << item << " (should be " << N-1 << ")\n";
	cout << "(tic " << tic << ", tac " << tac << ")\n";
	duration = (double)(tac - tic) / CLOCKS_PER_SEC;
	cout << "\ndequeue took " << duration / (double)N*1e6 << " us to run\n";
	
	return 0;
}

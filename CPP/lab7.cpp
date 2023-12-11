/* Implementation of Counter Class (use this if .obj does not work) */

#include "counter.h"
#include <iostream>
#include <climits>

using namespace std;

class LimitedCounter {
private:
    Counter counter;
    int maxCount;

public:
    LimitedCounter(int initCount, int initMax):counter(initCount),maxCount(initMax){}

    LimitedCounter& operator++() {
        if (counter.getCount() < maxCount) ++counter;
        return *this;
    }

    LimitedCounter operator++(int) {
        LimitedCounter temp = *this;
        if (counter.getCount() < maxCount) counter++;
        return temp;
    }

    void reset() {
        counter.reset();
    }

    int getCount() const {
        return counter.getCount();
    }

    friend ostream& operator<<(ostream& out, const LimitedCounter& lc) {
        out << lc.counter;
        return out;
    }

    bool operator<(int value) const {
        return counter < value;
    }
};

class DerivedLimitedCounter : public Counter{
	private:
		int maxCount;
	public:
	DerivedLimitedCounter(): maxCount(INT_MAX){}
	DerivedLimitedCounter(int initCount, int initMax): Counter(initCount), maxCount(initMax){}

	DerivedLimitedCounter& operator++() {
		if(getCount() < maxCount) Counter::operator++();
	   return *this;
	}

	DerivedLimitedCounter operator++(int) {
	   DerivedLimitedCounter old = *this;;
	    if(getCount() < maxCount) Counter::operator++();
	   return old;
	}
};

class AssociatedLimitedCounter {
private:
    Counter* counter;
    int maxCount;

public:
    AssociatedLimitedCounter(Counter* c, int initMax = INT_MAX):counter(c),maxCount(initMax){}

    AssociatedLimitedCounter& operator++() {
        if (counter && counter->getCount() < maxCount)  ++(*counter);
        return *this;
    }

    AssociatedLimitedCounter operator++(int) {
        AssociatedLimitedCounter temp = *this;
        if (counter && counter->getCount() < maxCount) (*counter)++;
        return temp;
    }

    void reset() {
        if (counter) counter->reset();
    }

    int getCount() const {
        return counter ? counter->getCount() : 0;
    }

    friend ostream& operator<<(ostream& out, const AssociatedLimitedCounter& lc) {
        if (lc.counter)  out << *(lc.counter);
        return out;
    }

    bool operator<(int value) const {
        return counter && (*counter) < value;  // Delegate to Counter's operator<
    }
};




int main() {
	// Part A
 LimitedCounter lc(0, 5); //initial value 0, upper limit 5
 cout << lc++ << endl; //output should be 0
 cout << ++lc << endl; //output should be 2
 lc.reset();
 for (int i = 0; i < 9; i++) {
lc++;
 cout << lc << endl; //output is 1 2 3 4 5 5 5 5 5
 }
 cout << lc.getCount() << endl; //output is 5
 cout << (lc < 7);//Testing the comparison operator //output is 1
 cout << (lc < 1);//Testing the comparison operator //output is 0

	// Part B
 DerivedLimitedCounter lcd(3, 5); //initial value 3, upper limit 5
 cout << lcd++ << endl; //output should be 3
 cout << ++lcd << endl; //output should be 5
 lcd.reset();
 for (int i = 0; i < 9; i++) {
lcd++;
 cout << lcd << endl; //output is 1 2 3 4 5 5 5 5 5
 }
 cout << lcd.getCount() << endl; //output is 5
 cout << (lcd < 7);//Testing the comparison operator //output is 1
 cout << (lcd < 1);//Testing the comparison operator //output is 0


	 // Part E for Extra
	 //
 Counter myCount(0);
 AssociatedLimitedCounter lca(&myCount, 5); // initial value 0, upper limit 5
 cout << lca++ << endl; // output should be 0
 cout << ++lca << endl; // output should be 2
 lca.reset();
 for (int i = 0; i < 9; i++) {
 lca++;
 cout << lca << endl; // output is 1 2 3 4 5 5 5 5 5
 }
 cout << lca.getCount() << endl; // output is 5
 cout << (lca < 7) << endl; // Testing the comparison, output is 1
 cout << (lca < 1) << endl; // Testing the comparison, output is 0




 return 0;
 }

#include <climits>
#include <iostream>


using namespace std;

class Counter {
    friend ostream &operator<<(ostream &out, const Counter &c);
    public:
	virtual Counter& increment() = 0;
	Counter(int n0 = 0) {
	     count = n0;
	}
	Counter& operator++() {
	   count++;
	   return *this;
	}

	void reset(){
	   count = 0;
	}
	int getCount() const{
	   return count;
	}

	bool operator<(const Counter &c2) const {
		return count < c2.count;
	}

	    private:
		int count;
	};


ostream &operator<<(ostream & out, const Counter &c) {
     out << "\nCounter value is now " << c.count ;
     return out;
}

class LimitedCounter : public Counter{
	private:
		int maxCount;
	public:
	LimitedCounter(): maxCount(INT_MAX){}
	LimitedCounter(int initCount, int initMax): Counter(initCount), maxCount(initMax){}


    Counter& increment() override {
        if (getCount() < maxCount) {
            Counter::operator++();
        }
        return *this;
    }
};

class RoundupCounter : public Counter {
private:
	int maxCount;

public:
	RoundupCounter(int initCount, int initMax) : Counter(initCount), maxCount(initMax) {}

	Counter& increment() override {
		if (getCount() >= maxCount)  reset();
		else  Counter::operator++();
		return *this;
	}
};

void UseCounter(Counter* counter, int increments) {
    for (int i = 0; i < increments; ++i) counter->increment();
}

int main() {
 LimitedCounter counterA(0, 5);
 RoundupCounter counterB(0, 5);
 UseCounter(&counterA, 8); UseCounter(&counterB, 8);
 cout << "Counter A: " << counterA << endl; // output should be 5
 cout << "Counter B: " << counterB << endl; // output should be 2
 return 0;
}

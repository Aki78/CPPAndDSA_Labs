/* Header file of Counter Class*/

#include <iostream>
using namespace std;
//Class definition
class Counter {
    friend ostream &operator<<(ostream &out, const Counter &c);
    public:
	virtual Counter& increment() = 0;
        Counter(int n0 = 0);
        Counter &operator++();
        bool operator<(const Counter &c2) const;
        void reset();
	int getCount() const;

    private:
        int count;
};


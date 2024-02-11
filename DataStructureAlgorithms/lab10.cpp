#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>


using namespace std;

class RandGen {
public:
	RandGen(): the_numbers() {srand(time(NULL));}
	int operator()() {
		int number;
		do {
			number = rand() % 37 + 1;
		} while(find(the_numbers.begin(), the_numbers.end(), number) != the_numbers.end());
			the_numbers.push_back(number);
		return number;
	}

private:
	vector<int> the_numbers; // its used for mirroring the actual vector



};

int main(void) {
	vector<int> my_numbers(7);
	vector<int> my_numbers2(7);
	ostream_iterator<int> out_it(cout, " ");
	ostream_iterator<int> out_it2(cout, "\n");
	vector<int> identicalElements;

	RandGen randGen;
	cout << "First lotto row: ";
	generate(my_numbers.begin(), my_numbers.end(), randGen);
	copy(my_numbers.begin(), my_numbers.end(), out_it);
	cout << endl;


	cout << "Second lotto row: ";
	generate(my_numbers2.begin(), my_numbers2.end(), randGen);
	copy(my_numbers2.begin(), my_numbers2.end(), out_it);
	cout << endl << "Same numbers: " << endl;

	int i = 1;
	for_each(my_numbers.begin(), my_numbers.end(), [&](int item1) {
		if (std::find(my_numbers2.begin(),my_numbers2.end(), item1) != my_numbers2.end()) {
			identicalElements.push_back(item1);
			cout << "#" << i << ": " << item1 << endl;
			i++;
		}
	});


}

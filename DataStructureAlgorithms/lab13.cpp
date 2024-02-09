#include <fstream>  
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;
struct Data {
	int index;
	int value;
	int weight;
};

#include <iostream>
#include <vector>

class BitArray {

public:
	vector<int> bitArray;
	BitArray(int N) {
		bitArray = vector<int>(N,0);
	}

	BitArray& operator++() {
		for (int i = bitArray.size() - 1; i >= 0; --i) {
			if (bitArray[i] == 0) { 
				bitArray[i] = 1;
				return *this;
			}
			bitArray[i] = 0;
		}
		return *this;
	}

	void print() const {
		for (const auto& array : bitArray) {
			cout << array;
		}
		cout << endl;
	}
};

void getOptimalBits(BitArray bitArray,vector<int>& val_vec, vector<int>& weight_vec, BitArray& bestBits, int &currentMaxVal, int& currentCapacity, int capacity){

	int totalValue = inner_product(val_vec.begin(), val_vec.end(), bitArray.bitArray.begin(), 0);
	int totalWeight = inner_product(weight_vec.begin(), weight_vec.end(), bitArray.bitArray.begin(), 0);

	bool is_over_capacity = totalWeight > capacity;
	bool is_more_valuable = currentMaxVal < totalValue;

	//cout << totalValue << " " << totalWeight << endl;

	if(!is_over_capacity && is_more_valuable){
		currentMaxVal = totalValue; // updaing new weight
		bestBits = bitArray; // updating best combination so far
		currentCapacity= totalWeight; // updating best combination so far
	}

}


int main() {
	string filename = "easy20.txt";
	ifstream file(filename);
	int capacity = 0;

	if (!file.is_open()) {
		cout << "Error opening file: " << filename << endl;
		return 1; 
	}

	int size; 
	file >> size; 

	vector<Data> matrix; 
	vector<int> val_vec; 
	vector<int> weight_vec; 

	int index, value, weight; 

	for (int i = 0; i < size; ++i) {
		file >> index >> value >> weight;
		matrix.push_back({index, value, weight});
		val_vec.push_back(value);
		weight_vec.push_back(weight);
	}
	file >> capacity;

	file.close();

	for (int i = 0; i < size; ++i) {
		cout << "Index: " << matrix[i].index << " Value: " << matrix[i].value << " Weight: " << matrix[i].weight << " Capacyt: " << capacity<< endl;
	}

	int N = val_vec.size();
	BitArray bitArray(N);
 	int currentMaxVal = 0;
 	int currentCapacity = 0;
	BitArray bestBits(N);

	for(int i=0; i < pow(2, size); i++){
		++bitArray;
		getOptimalBits(bitArray, val_vec,  weight_vec, bestBits, currentMaxVal, currentCapacity, capacity);
	}


	cout << currentMaxVal << " " << currentCapacity << endl;
	bestBits.print();

//cout << "Initial state:" << endl;
//bitArray.print();
//++bitArray;
//cout << "After increment:" << endl;
//bitArray.print();
//++bitArray;
//cout << "After another increment:" << endl;
//bitArray.print();

	return 0;
}


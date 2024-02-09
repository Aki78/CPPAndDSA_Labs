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

void getOptimalBits(BitArray bitArray,vector<int>& val_vec, vector<int>& weight_vec, BitArray& bestBits, int &currentMaxVal, int& currentWeight, int capacity){

	int totalValue = inner_product(val_vec.begin(), val_vec.end(), bitArray.bitArray.begin(), 0);
	int totalWeight = inner_product(weight_vec.begin(), weight_vec.end(), bitArray.bitArray.begin(), 0);

	bool is_over_capacity = totalWeight > capacity;
	bool is_more_valuable = currentMaxVal < totalValue;

	//cout << totalValue << " " << totalWeight << endl;

	if(!is_over_capacity && is_more_valuable){
		currentMaxVal = totalValue; // updaing new weight
		bestBits = bitArray; // updating best combination so far
		currentWeight= totalWeight; // updating best combination so far
	}

}


void greedy( vector<int>& final_val_vec,vector<int>& final_weight_vec,vector<int>& final_ind_vec,  vector<int> ind_vec, vector<int> weight_vec, vector<int> val_vec, int capacity){
	int currentWeight = 0;

	int i = 0;


	while(capacity > currentWeight){
		final_val_vec.push_back(val_vec[i]);
		final_weight_vec.push_back(weight_vec[i]);
		final_ind_vec.push_back(ind_vec[i]);
		++i;
		currentWeight = accumulate(final_weight_vec.begin(), final_weight_vec.end(), 0); 
		//cout << currentWeight << endl;
	}
	final_ind_vec.pop_back(); // Removing the last value, cuz it is over the limit
	final_val_vec.pop_back(); // Removing the last value, cuz it is over the limit
	final_weight_vec.pop_back(); // Removing the last value, cuz it is over the limit


}


vector<int> rearrange(vector<int> vec, vector<int> ind_vec){
	vector<int> arranged_vec(vec.size());
	int j = 0;
	for(int i: ind_vec){
		arranged_vec[j] = vec[i-1];
		j++;
	}

	return arranged_vec;
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

//=== PART A ================
	vector<Data> matrix; 
	vector<int> val_vec; 
	vector<int> weight_vec; 
	vector<int> ind_vec; 



	int index, value, weight; 

	for (int i = 0; i < size; ++i) {
		file >> index >> value >> weight;
		matrix.push_back({index, value, weight});
		val_vec.push_back(value);
		ind_vec.push_back(index);
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
 	int currentWeight = 0;
	BitArray bestBits(N);

	for(int i=0; i < pow(2, size); i++){
		++bitArray;
		getOptimalBits(bitArray, val_vec,  weight_vec, bestBits, currentMaxVal, currentWeight, capacity);
	}


	cout << currentMaxVal << " " << currentWeight << endl;
	bestBits.print();


//=== PART B ================
	sort(ind_vec.begin(), ind_vec.end(), [&val_vec](int a, int b) { return val_vec[a] > val_vec[b]; });

//	auto rearrange = [](const auto& src, vector<int> arr_vec) {
//		vector<int> temp(src.size());
//		for (size_t i = 0; i < arr_vec.size(); ++i) 
//			temp[i] = src[arr_vec[i]];
//		return temp;
//	};


	vector<int> val_vec_arranged = rearrange(val_vec, ind_vec);
	vector<int> weight_vec_arranged = rearrange(weight_vec, ind_vec);

	cout << val_vec_arranged[0] << endl;


	for (int i = 0; i < ind_vec.size(); ++i) {
		cout << ind_vec[i] << " " << val_vec_arranged[i] << " " << weight_vec_arranged[i] << endl;
	}

	vector<int> final_val_vec;
	vector<int> final_weight_vec;
	vector<int> final_ind_vec;


	greedy(final_val_vec, final_weight_vec, final_ind_vec, ind_vec, weight_vec_arranged, val_vec_arranged, capacity);

	cout << "size of the final vector: " << final_ind_vec.size() << endl;


//	sort(final_ind_vec.begin(), final_ind_vec.end() );


//	final_val_vec = rearrange(final_val_vec, final_ind_vec);
//	final_weight_vec = rearrange(final_weight_vec, final_ind_vec);

	for (int i = 0; i < final_ind_vec.size(); ++i) {
		cout << final_ind_vec[i] << " " << final_val_vec[i] << " " << final_weight_vec[i] << endl;
	}


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


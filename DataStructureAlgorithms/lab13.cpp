#include <fstream>  // For file operations
#include <iostream>
#include <vector>

using namespace std;
struct Data {
	int index;
	int value;
	int weight;
};

int main() {
	string filename = "easy20.txt";
	ifstream file(filename);

	if (!file.is_open()) {
		cout << "Error opening file: " << filename << endl;
		return 1; 
	}

	int size; 
	file >> size; 

	vector<Data> matrix; 

	int index, value, weight; 

	for (int i = 0; i < size; ++i) {
		file >> index >> value >> weight;
		matrix.push_back({index, value, weight});
	}

	file.close();

	for (int i = 0; i < size; ++i) {
		cout << "Index: " << matrix[i].index << " Value: " << matrix[i].value << " Weight: " << matrix[i].weight << endl;
	}

	return 0;
}


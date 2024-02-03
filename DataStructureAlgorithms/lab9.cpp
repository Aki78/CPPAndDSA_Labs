#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>


using namespace std;



vector<string> split_num(const string& line) {
	vector<string> words;
	istringstream iss(line);
	string word;
	while (iss >> word) {
		words.push_back(word);
	}
	return words;
}

vector<string> getConcatenatedAndLastElement(const vector<string>& A) {
	vector<string> B;
	
	string concatenated;
	for (size_t i = 0; i < A.size() - 1; ++i) {
		concatenated += A[i];
		concatenated += " ";
		
	}
	B.push_back(concatenated);
	B.push_back(A.back());
	
	return B;
}


int main() {
	// Create a map using a binary search tree
	map<int, int> bst;
	string a = "Hello Wrodl 20";
	vector<string> b = getConcatenatedAndLastElement(split_num(a));
	cout << "b0: " << b[0] << endl;
	cout << "b1: " << b[1] << endl;
	

	// Insert elements into the binary search tree
	bst.insert({50, 0});
	bst.insert({30, 0});
	bst.insert({20, 0});
	bst.insert({40, 0});
	bst.insert({70, 0});
	bst.insert({60, 0});
	bst.insert({80, 0});

	cout << "Searching for elements in the binary search tree:\n";
	cout << "Is 30 present? " << (bst.find(30) != bst.end() ? "Yes" : "No") << endl;
	cout << "Is 45 present? " << (bst.find(45) != bst.end() ? "Yes" : "No") << endl;

	cout << "Elements of the binary search tree in ascending order:\n";
	for (const auto& pair : bst) {
		cout << pair.first << " ";
	}
	cout << endl;

	return 0;
}


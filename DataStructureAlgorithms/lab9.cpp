#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>


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

string trimEnd(const string& str) {

	auto endPos = find_if(str.rbegin(), str.rend(), [](char ch) { // Lambda function!!! Yay :D
		return !isspace(ch);
	}).base();

	return string(str.begin(), endPos);
}


int main() {
	
	map<string, int> bst;
	string a = "Hello Wrodl 20";
	vector<string> b = getConcatenatedAndLastElement(split_num(a));
	cout << "b0: " << b[0] << endl;
	cout << "b1: " << b[1] << endl;
	

	bst.insert({trimEnd(b[0]), stoi(b[1])});

	cout << "Searching for elements in the binary search tree:\n";
	cout << "Is 30 present? " << (bst.find("Hello Wrodl") != bst.end() ? "Yes" : "No") << endl;
	cout << "Is 45 present? " << (bst.find("a") != bst.end() ? "Yes" : "No") << endl;

	cout << "Elements of the binary search tree in ascending order:\n";
	for (const auto& pair : bst) {
		cout << pair.first << " ";
	}
	cout << endl;

	return 0;
}


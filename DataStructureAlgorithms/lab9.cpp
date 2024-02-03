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
	B.push_back(A[0]);
	if (A.size() == 2){
		B.push_back(A[1]);
		return B;
	}
	for (size_t i = 1; i < A.size() - 1; ++i) {
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

void print(map<string,int> bst){
	cout << "Content of the phonebook:" << endl;
	for (const auto& pair : bst) {
		cout << pair.first << ":  " << pair.second << endl;
	}
	cout << endl;

}

void handleDelete(map<string,int>& bst, const string s){
	auto it = bst.find(s);
	cout << "deleting " << s << endl; 
	if (it != bst.end()) bst.erase(s);
	else cout << "Name "  << s <<  " does not exist" << endl;
}


int main() {
	string input;	
	map<string, int> bst;
	string a = "Hello Wrodl 20";
	vector<string> b = getConcatenatedAndLastElement(split_num(a));
	cout << "b0: " << b[1] << endl;
	cout << "b1: " << b[2] << endl;
	

	bst.insert({trimEnd(b[1]), stoi(b[2])});

	while(true){
		getline(cin, input);
		b =  getConcatenatedAndLastElement(split_num(input));
		if(b[0] == "add") bst.insert({trimEnd(b[1]), stoi(b[2])});
		else if(b[0] == "list") print(bst); 
		else if(b[0] == "delete") handleDelete(bst, b[1]); 
		else cout <<  "Unrecognized command " << b[0] << endl; 


	if (input == "exit") {
		std::cout << "Exiting the program..." << std::endl;
		break; // Exit the loop
	}

	}



	return 0;
}


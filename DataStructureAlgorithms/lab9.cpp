#include <iostream>
#include <map>


using namespace std;
int main() {
	// Create a map using a binary search tree
	map<int, int> bst;

	// Insert elements into the binary search tree
	bst.insert({50, 0});
	bst.insert({30, 0});
	bst.insert({20, 0});
	bst.insert({40, 0});
	bst.insert({70, 0});
	bst.insert({60, 0});
	bst.insert({80, 0});

	// Search for elements in the binary search tree
	std::cout << "Searching for elements in the binary search tree:\n";
	std::cout << "Is 30 present? " << (bst.find(30) != bst.end() ? "Yes" : "No") << std::endl;
	std::cout << "Is 45 present? " << (bst.find(45) != bst.end() ? "Yes" : "No") << std::endl;

	// Print the elements of the binary search tree in ascending order
	std::cout << "Elements of the binary search tree in ascending order:\n";
	for (const auto& pair : bst) {
		std::cout << pair.first << " ";
	}
	std::cout << std::endl;

	return 0;
}


#include <stdio.h>
#include<iostream>
#include<string.h>
#include <fstream>
#include <string>
#define _CRT_RAND_S
#include <stdlib.h>

using namespace std;

class MyString{
public:
    char *c_string;
    MyString() : c_string(nullptr){
    }
    
    MyString(const char* str) {
        c_string = new char[strlen(str) + 1];
        strcpy(c_string, str);
        c_string[strlen(str)] = '\0';
    }
    
    MyString(const MyString &s) {
        c_string = new char[strlen(s.c_string) + 1];
        strcpy(c_string, s.c_string);
        c_string[strlen(s.c_string) ] = '\0';
    }
    
    ~MyString() {
        delete[] c_string;
    }

    MyString operator+(const MyString& other) const {
        char* buff = new char[strlen(c_string) + strlen(other.c_string) + 1];
        buff[0] = '\0';
        strcat(buff,c_string);
        strcat(buff,other.c_string);
        MyString plussed(buff);
        delete[] buff;
        
            return plussed;
        }
    friend ostream& operator<<(ostream& ost, const MyString& obj);
        
        
    MyString& operator=(const MyString& other) {
        if (this != &other) {
            delete[] c_string;
            c_string = new char[strlen(other.c_string) + 1];
            strcpy(c_string, other.c_string);
        }
        return *this;
    }

    MyString& operator++() {
        int len = strlen(c_string);
        char* buff = new char[len + 2];

        strcpy(buff, c_string);
        buff[len] = 'X';
        buff[len + 1] = '\0';

        delete[] c_string;
        c_string = buff;

        return *this;
    }
    
    MyString operator++(int) {
        MyString buff = *this;
        ++*this;
        return buff;
    }

    char& operator[](int index) {
        if (index >= 0 && index < strlen(c_string)) {
            return c_string[index];
        } else {
            cout << "DANGER!!!" << endl;
        }
    }
    
    operator const char*() const {
        return c_string;
    }

};

ostream& operator<<(ostream& ost, const MyString& obj) {
    ost << obj.c_string;
return ost;
}

//--PartB--------------------------------
//Helper functtions
//---------------------------------------

string find_field(const string& myXML, const string& myTag) {
    string startTag = "<" + myTag+ ">";
    string endTag = "</" + myTag+ ">";
    size_t location0 = myXML.find(startTag) + startTag.length();
    size_t location1 = myXML.find(endTag);

    if (location0 == string::npos || location1 == string::npos) return "No Tag!!!";

    return myXML.substr(location0, location1 - location0);
}


//--Part Extra--------------------------------
//Helper Functions
//---------------------------------------
size_t countNewLines(const string& str) {
    size_t count = 0;
    for (char ch : str) {
        if (ch == '\n') {
            ++count;
        }
    }
    return count;
}

string getNthLine(const string& str, size_t n) {
    size_t lineNum = 0;
    size_t startPos = 0;

//    cout << "N is: " << n << endl;

    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] == '\n') {
            lineNum++;
            if (lineNum == n) {
                size_t endPos = i - startPos;
                return str.substr(startPos, endPos);
            }
            startPos = i + 1;
        }
    }

    // Checking if the line is the last line without a newline at the end
    if (lineNum == n - 1) {
        return str.substr(startPos);
    }

    // If nth line does not exist, return an empty string
    return "";
}

//--Part Extra--------------------------------
//Class Def
//---------------------------------------

class WordPool {
private:
    string words;
    string category;
    string rand_word;

public:
    WordPool(){}
//    string rand_word;
    string summed_words;

    void fill(const string& A_cat, ifstream& inputFile){
	    string page,line;


        while(getline (inputFile, line)) {
		page += line + '\n';
		line.erase();
         }
	    inputFile.clear();
	    inputFile.seekg(0, ios::beg); 

	    words = page;
	    category = A_cat;



	// magic number 5 is to erase [X]\n.
	    words.erase(0,words.find("[" + category + "]") + 5);
	    size_t new_length = words.size();
	//2 is to erase \n.
        size_t erase_from = words.find("[");
	if (erase_from != string::npos) words.erase(erase_from, new_length - erase_from);
	//cout << words << endl;
                
    }

    void setRandomWord(){
//	cout << "word list is: " << word_list << endl; 
        size_t size =  countNewLines(words);
        int n = rand();
//	cout << "WORDS ARE" << words << endl;
//	cout << "size is: " << size << endl; 
        size_t index = n % size;
        rand_word = getNthLine(words, index);
//	cout << "words are: " << words << endl;
//	cout << "rand word is: " << rand_word << endl;
    }

    WordPool& operator=(const WordPool& other) {
       if (this != &other) {
        }
        return *this;
    }


     WordPool operator+(WordPool& other) {

	    other.setRandomWord();

	    //summed_words = other.rand_word + other.summed_words;
	    cout << "RAND WORD IS: " << other.rand_word << endl;


	    setRandomWord();

	    WordPool newObject = *this;
	    newObject.summed_words = rand_word +  other.rand_word + other.summed_words;;
//	    newObject.words = words;
//	    cout <<  newObject.summed_words <<endl ;
	    cout << "summed words are: " << endl;
	    cout << "summed words are: " << newObject.summed_words <<endl ;
	    cout << endl;
	    

            return newObject;
        }


    operator const string() const {
        return summed_words;
    }
};

//-----------------------------------------
string giveStatement(string filename) {
WordPool g, a, s, v;
ifstream inputFile(filename);
g.fill("G", inputFile); a.fill("A", inputFile); s.fill("S", inputFile); v.fill("V", inputFile);
return g + a + s + v + g + a + s;
}
//------------------------------------

int main(){
	srand(time(nullptr));
// Task A
    
    MyString s;
    
    char name[30];
    s = "Matti"; //Conversion c-string -> String
    cout << s;
    strcpy(name, s); //Conversion String -> c-string
    cout << name << endl;


// Task B

    string page, line, location, temperature;
    ifstream inputFile("weather.xml");

    while (getline (inputFile, line)) {
        page.append(line);
        line.erase();
    }

    location = find_field(page,"location");
    temperature = find_field(page,"temp_c");

    cout << "Location: " << location << endl;
    cout << "Temperature: " << temperature << endl;

// Task Extra
	cout << "statement is: " << endl;
	cout << giveStatement("oracle.dat") << endl;
	cout << "end of statment. " << endl;

	cout << "program terminated..." << endl;

    return 0;
}




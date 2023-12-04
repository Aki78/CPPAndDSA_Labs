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
        cout << "Destroyed!\n";
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
//Class Def
//---------------------------------------

class WordPool {
private:
    string* words;
    string category;
    size_t size;

public:
    WordPool():size(0){}

    void fill(const string& A_cat, ifstream& inputFile){
        string line;
	category = A_cat;
        bool categoryFound = false;
        while (getline(inputFile, line)){
            if (line == "[" + category + "]"){
                categoryFound = true;
                continue;
            }
            if (categoryFound){
                if (line.empty() || line[0] == '[') break;
                words[size++] = line;
            }
        }
    }

    string getRandomWord() const{
	srand(time(nullptr));
        int n = rand();
        size_t index = n % size;
        return words[index];
    }

     WordPool operator+(const WordPool& other) const {
            return getRandomWord() + " " + other.getRandomWord();
        }
};

//-----------------------------------------
string giveStatement(string filename) {
WordPool g, a, s, v;
ifstream inputFile(filename);
//g.fill("G", inputFile); a.fill("A", inputFile); s.fill("S", inputFile); v.fill("V", inputFile);
return g + a + s + v + g + a + s;
}
//------------------------------------

int main(){
    
    MyString s;
    
    char name[30];
    s = "Matti"; //Conversion c-string -> String
    cout << s;
    strcpy(name, s); //Conversion String -> c-string
    cout << name;

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



    return 0;
}




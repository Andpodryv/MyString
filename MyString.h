#pragma once
#include <iostream>
#include <cstdlib>



using namespace std;

class MyString {
private:
	char* str;
	unsigned int _size_;
	unsigned int _capacity_;
	void add(MyString* str, const char* string, int new_size);
	void new_memory(unsigned int new_size);
public:
	//Constructors
	MyString();
	MyString(const char* string);
	MyString(const std::initializer_list<char>& list);
	MyString(const std::string& string);
	MyString(const char* string, unsigned int count);
	MyString(unsigned int count, char symb);
	MyString(const MyString& copy);
	MyString(int value);
	//Destructor
	~MyString();

	//Operators
	MyString operator +(MyString& copy);
	MyString operator +(const char* string);
	MyString operator +(const std::string& string);
	MyString& operator +=(MyString& additing);
	MyString& operator +=(std::string& additing);
	MyString& operator +=(const char* additing);


	MyString& operator =(const char* string);
	MyString& operator =(const std::string& string);
	MyString& operator =(const char symb);
	MyString& operator =(const MyString& copy);

	char& operator[](unsigned int index);

	bool operator>(MyString& str);
	bool operator<(MyString& str);
	bool operator>=(MyString& str);
	bool operator<=(MyString& str);
	bool operator==(MyString& str);
	bool operator!=(MyString& str);

	char* c_str();
	char* data();
	unsigned int length();
	unsigned int size();
	bool empty();
	unsigned int capacity();
	void clear();
	void shrink_to_fit();

	// Adding
	void insert(int index, int count, char symb);
	void insert(int index, const char* string);
	void insert(int index, const char* string, int count);
	void insert(int index, std::string& string);
	void insert(int index, std::string& string, int count);

	// Erase
	void erase(int index, int count);
	// Adding 2
	void append(int count, char symb);
	void append(const char* string);
	void append(const char* string, int index, int count);
	void append(std::string& string);
	void append(std::string& string, int index, int count);
	// Replace
	void replace(int index, int count, const char* string);
	void replace(int index, int count, std::string& string);
	// Substr
	MyString substr(int index);
	MyString substr(int index, int count);

	// Find
	int find(const char* string);
	int find(const char* string, unsigned int index);
	int find(const std::string& string);
	int find(const std::string& string, unsigned int index);

};

std::ostream& operator<<(std::ostream& os, MyString& string);
std::istream & operator>>(std::istream & is, MyString & string); 

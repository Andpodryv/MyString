#include "MyString.h"
using namespace std;

MyString::MyString() {
	this->str = nullptr;
	this->_size_ = 0;
	this->_capacity_ = 0;
}
MyString::MyString(const char* string) {
	this->_size_ = strlen(string);
	this->_capacity_ = this->_size_ + 1;
	this->str = new char[this->_size_ + 1];
	for (int i = 0; i != this->_size_; i++) {
		this->str[i] = string[i];
	}
	this->str[this->_size_] = '\0';
}
MyString::MyString(const std::initializer_list<char>& list) {
	this->str = new char[list.size() + 1];
	int size = 0;
	for (char i : list) {
		*(this->str + size) = i;
		size++;
	}
	*(this->str + size) = '\0';
	this->_size_ = size;
	this->_capacity_ = size + 1;
}
MyString::MyString(const std::string& string) {
	unsigned int size = string.size();
	this->_size_ = size;
	this->_capacity_ = size + 1;
	this->str = new char[size + 1];
	strncpy(this->str, string.c_str(), size);
	this->str[size] = '\0';
}
MyString::MyString(const char* string, unsigned int count) {
	unsigned int len = strlen(string);
	if (count > len) count = len;
	this->str = new char[count + 1];
	this->_size_ = count;
	this->_capacity_ = count + 1;
	for (unsigned int i = 0; i != count; i++) {
		this->str[i] = string[i];
	}
	this->str[count] = '\0';
}
MyString::MyString(unsigned int count, char symb) {
	this->str = new char[count + 1];
	this->_size_ = count;
	this->_capacity_ = count + 1;
	for (unsigned int i = 0; i != count; i++) {
		this->str[i] = symb;
	}
	this->str[count] = '\0';
}
MyString::MyString(const MyString& copy) {
	if (copy.str != nullptr) {
		unsigned int size = strlen(copy.str);
		unsigned int capacity = size + 1;
		this->str = new char[capacity];
		this->_size_ = size;
		this->_capacity_ = capacity;
		for (unsigned int i = 0; i != size; i++) {
			this->str[i] = copy.str[i];
		}
		this->str[size] = '\0';
	}
	else {
		this->str = nullptr;
		this->_size_ = 0;
		this->_capacity_ = 0;
	}

}
MyString::MyString(int value) {
	int size = 1, number_duplicate = value;
	if (!(value >= 0 && value <= 9))
	{
		for (int st = 10;; size++, st = pow(10, size))
		{
			if (number_duplicate / st == 0)
				break;
		}
	}

	this->_size_ = size;
	this->_capacity_ = this->_size_ + 1;
	this->str = new char[this->_capacity_];
	this->str[size] = '\0';
	if (value != 0)
		for (; size > 0; size--)
		{
			this->str[size - 1] = value % 10 + '0';
			value /= 10;
		}
	else
	{
		this->str[size - 1] = '0';
	}
}
MyString::~MyString() {
	delete[] this->str;
	this->str = nullptr;
	this->_size_ = 0;
	this->_capacity_ = 0;
}
/////////////////////////////////
MyString MyString::operator +(MyString& copy) {
	unsigned int new_size = this->size() + copy.size();
	unsigned int size_first = this->size();
	MyString new_str;
	new_str.str = new char[new_size + 1];
	new_str._size_ = new_size;
	new_str._capacity_ = new_size + 1;
	unsigned int i = 0;
	for (unsigned int j = 0; j != size_first; j++, i++) {
		new_str.str[j] = this->str[j];
	}
	for (unsigned int j = 0; i != new_size; j++, i++) {
		new_str.str[i] = copy.str[j];
	}
	new_str.str[new_size] = '\0';
	return new_str;
}
MyString MyString::operator +(const char* string) {
	unsigned int new_size = this->size() + strlen(string);
	unsigned int size_first = this->size();
	MyString new_str;
	new_str.str = new char[new_size + 1];
	new_str._size_ = new_size;
	new_str._capacity_ = new_size + 1;
	unsigned int i = 0;
	for (unsigned int j = 0; j != size_first; j++, i++) {
		new_str.str[j] = this->str[j];
	}
	for (unsigned int j = 0; i != new_size; j++, i++) {
		new_str.str[i] = string[j];
	}
	new_str.str[new_size] = '\0';
	return new_str;
}
MyString MyString::operator +(const std::string& string) {
	unsigned int new_size = this->size() + strlen(string.c_str());
	unsigned int size_first = this->size();
	MyString new_str;
	new_str.str = new char[new_size + 1];
	new_str._size_ = new_size;
	new_str._capacity_ = new_size + 1;
	unsigned int i = 0;
	for (unsigned int j = 0; j != size_first; j++, i++) {
		new_str.str[j] = this->str[j];
	}
	for (unsigned int j = 0; i != new_size; j++, i++) {
		new_str.str[i] = string[j];
	}
	new_str.str[new_size] = '\0';
	return new_str;
}

MyString& MyString::operator +=(MyString& additing) {
	unsigned int new_size = this->size() + additing.size();
	unsigned int size_first = this->size();
	MyString new_str;
	new_str.str = new char[new_size + 1];
	new_str._size_ = new_size;
	new_str._capacity_ = new_size + 1;
	unsigned int i = 0;
	for (unsigned int j = 0; j != size_first; j++, i++) {
		new_str.str[j] = this->str[j];
	}
	for (unsigned int j = 0; i != new_size; j++, i++) {
		new_str.str[i] = additing.str[j];
	}
	new_str.str[new_size] = '\0';
	delete[] this->str;
	this->str = nullptr;
	this->_size_ = 0;
	this->_capacity_ = 0;
	*(this) = new_str;
	return *this;
}

MyString& MyString::operator +=(std::string& additing) {
	unsigned int new_size = this->size() + strlen(additing.c_str());
	unsigned int size_first = this->size();
	MyString new_str;
	new_str.str = new char[new_size + 1];
	new_str._size_ = new_size;
	new_str._capacity_ = new_size + 1;
	unsigned int i = 0;
	for (unsigned int j = 0; j != size_first; j++, i++) {
		new_str.str[j] = this->str[j];
	}
	for (unsigned int j = 0; i != new_size; j++, i++) {
		new_str.str[i] = additing[j];
	}
	new_str.str[new_size] = '\0';
	*(this) = new_str;
	return *this;
}
MyString& MyString::operator +=(const char* additing) {
	MyString temp(additing);
	return this->operator += (temp);
}

MyString& MyString::operator =(const char* string) {
	delete[] this->str;
	this->str = nullptr;
	int size = strlen(string);
	this->str = new char[size + 1];
	strncpy(this->str, string, size);
	this->str[size] = '\0';
	this->_size_ = size;
	this->_capacity_ = size + 1;
	return *this;
}
MyString& MyString::operator =(const std::string& string) {
	delete[] this->str;
	this->str = nullptr;
	int size = string.size();
	this->str = new char[size + 1];
	strncpy(this->str, string.c_str(), size);
	this->str[size] = '\0';
	this->_size_ = size;
	this->_capacity_ = size + 1;
	return *this;
}
MyString& MyString::operator =(const char symb) {
	delete[] this->str;
	this->str = nullptr;
	this->str = new char[2];
	this->str[0] = symb;
	this->str[1] = '\0';
	this->_size_ = 1;
	this->_capacity_ = 2;
	return *this;
}
MyString& MyString::operator =(const MyString& copy) {//
	if (this->str != nullptr) {
		delete[] this->str;
		this->str = nullptr;
	}
	this->str = new char[strlen(copy.str) + 1];
	this->_size_ = strlen(copy.str);
	this->_capacity_ = strlen(copy.str) + 1;
	strncpy(this->str, copy.str, strlen(copy.str));
	this->str[strlen(copy.str)] = '\0';
	return *this;
}
/////////////////////////////////
char& MyString::operator[](unsigned int index) {
	return this->str[index];
}

bool MyString::operator>(MyString& str) {
	return strcmp(this->str, str.c_str()) > 0;
}
bool MyString::operator<(MyString& str) {
	return strcmp(this->str, str.c_str()) < 0;
}
bool MyString::operator>=(MyString& str) {
	if (this->operator==(str))
		return true;
	else
		return this->operator>(str);
}
bool MyString::operator<=(MyString& str) {
	if (this->operator==(str))
		return true;
	else
		return this->operator<(str);
}
bool MyString::operator==(MyString& str) {
	return (str.size() == this->size()) && (strcmp(this->str, str.str) == 0);
}
bool MyString::operator!=(MyString& str) {
	return !(this->operator==(str));
}

/////////////////////////////////
char* MyString::c_str() {
	return this->str;
}
char* MyString::data() {
	return this->str;
}
unsigned int MyString::length() {
	return this->_size_;
}
unsigned int MyString::size() {
	return this->_size_;
}
bool MyString::empty() {
	return(this->_size_ == 0);
}
unsigned int MyString::capacity() {
	return this->_capacity_;
}
void MyString::clear() {
	this->_size_ = 0;
	if (this->str != nullptr) {
		*this->str = '\0';
	}
}
void MyString::shrink_to_fit() {
	if ((this->size() != 0 && this->capacity() != 0) && (this->size() < this->capacity() - 1)) {
		char* string = new char[this->size() + 1];
		strncpy(string, this->str, this->size() + 1);
		new_memory(this->size());
		strncpy(this->str, string, this->size() + 1);
	}
}
std::ostream& operator<<(std::ostream& os, MyString& str) {
	for (int i = 0; i != str.size(); i++) {
		os << str[i];
	}
	return os;
}
std::istream& operator>>(std::istream& is, MyString& string) {
	string.clear();
	string.shrink_to_fit();
	char in = 0;
	is.get(in);
	while (in != '\n' && in != '\r' && !is.eof()) {
		string.append(1, in);
		is.get(in);
	}
	return is;
}
/////////////////////////////////
void MyString::add(MyString* str, const char* string, int new_size) {
	delete[] str->str;
	str->str = nullptr;
	str->str = new char[new_size + 1];
	strncpy(str->str, string, new_size);
	str->str[new_size] = '\0';
	str->_size_ = strlen(string);
	str->_capacity_ = strlen(string) + 1;
	delete[] string;
}
void MyString::insert(int index, int count, char symb) {
	unsigned int new_size = this->size() + count;
	int border = index + count, j = 0;
	char* str = new char[new_size + 1];
	for (int i = 0; i != new_size; i++) {
		if (i >= index && i < border) {
			str[i] = symb;
		}
		else {
			str[i] = this->str[j];
			j++;
		}
	}
	str[new_size] = '\0';
	add(this, str, new_size);
}
void MyString::insert(int index, const char* string) {
	this->insert(index, string, strlen(string));
}
void MyString::insert(int index, const char* string, int count) {
	unsigned int new_size = this->size() + count;
	int border = index + count, j = 0, z = 0;
	char* str = new char[new_size + 1];
	for (int i = 0; i != new_size; i++) {
		if (i >= index && i < border) {
			for (; count != 0; count--) {
				str[i] = string[z];
				z++;
				i++;
			}
			i--;
		}
		else {
			str[i] = this->str[j];
			j++;
		}
	}
	str[new_size] = '\0';
	add(this, str, new_size);
}
void MyString::insert(int index, std::string& string) {
	this->insert(index, string, string.size());
}
void MyString::insert(int index, std::string& string, int count) {
	int new_size = this->size() + count;
	int border = index + count, j = 0;
	char* str = new char[new_size + 1];
	for (int i = 0; i != new_size; i++) {
		if (i >= index && i < border) {
			strncpy(str + i, string.c_str(), count);
			i += count - 1;
		}
		else {
			str[i] = this->str[j];
			j++;
		}
	}
	str[new_size] = '\0';
	add(this, str, new_size);
}
/////////////////////////////////
void MyString::erase(int index, int count) {
	if (index + count > this->_size_) {
		return;
	}
	else {
		int new_size = this->size() - count;
		int size = this->size();
		int j = 0;
		char* str = new char[new_size + 1];
		for (int i = 0; i != size; i++) {
			if (i == index) {
				i += count - 1;
			}
			else {
				str[j] = this->str[i];
				j++;
			}
		}
		str[new_size] = '\0';
		strncpy(this->str, str, new_size + 1);
		this->_size_ = new_size;
	}
}
/////////////////////////////////
void MyString::append(int count, char symb) {
	if (count > 0) {
		char* string = new char[count + 1];
		for (int i = 0; i != count; i++) {
			*(string + i) = symb;
		}
		*(string + count) = '\0';
		append(string);
	}
}
void MyString::append(const char* string) {
	append(string, 0, strlen(string));
}
void MyString::append(const char* string, int index, int count) {
	int new_size = this->size() + count;
	char* str = new char[new_size + 1];
	strncpy(str, this->str, this->size());
	strncpy(str + this->size(), string + index, count);
	*(str + new_size) = '\0';
	add(this, str, new_size);
}
void MyString::append(std::string& string) {
	append(string, 0, string.size());
}
void MyString::append(std::string& string, int index, int count) {
	int new_size = this->size() + count;
	char* str = new char[new_size + 1];
	strncpy(str, this->str, this->size());
	strncpy(str + this->size(), string.c_str() + index, count);
	*(str + new_size) = '\0';
	add(this, str, new_size);
}
/////////////////////////////////
void MyString::replace(int index, int count, const char* string) {
	int new_size = this->size() - count + strlen(string);
	char* str = new char[new_size + 1];
	strncpy(str, this->str, index);
	strncpy(str + index, string, strlen(string));
	strncpy(str + index + strlen(string), this->str + index + count, this->size() - index - count);
	*(str + new_size) = '\0';
	add(this, str, new_size);
}
void MyString::replace(int index, int count, std::string& string) {
	char* str = new char[string.size() + 1];
	strncpy(str, string.c_str(), string.size());
	*(str + string.size()) = '\0';
	replace(index, count, str);
	delete[] str;
}
/////////////////////////////////
MyString MyString::substr(int index) {
	char* str = new char[this->_capacity_ - index];
	strncpy(str, this->str + index, this->_size_ - index);
	*(str + this->_capacity_ - index - 1) = '\0';
	return MyString(str);
}
MyString MyString::substr(int index, int count) {
	if (this->_size_ < index || this->_size_ < index + count) {
		return MyString();
	}
	char* str = new char[count + 1];
	strncpy(str, this->str + index, count);
	*(str + count) = '\0';
	return MyString(str);
}
/////////////////////////////////
int MyString::find(const char* string) {
	return this->find(string, 0);
}
int MyString::find(const char* string, unsigned int index) {
	if (strstr(this->str + index, string) != NULL) {
		char* result;
		result = strstr(this->str + index, string);
		return result - this->str;
	}
	else return -1;
}
int MyString::find(const std::string& string) {
	return this->find(string, 0);
}
int MyString::find(const std::string& string, unsigned int index) {
	if ((strstr(this->str + index, string.c_str())) != nullptr) {
		char* result;
		result = strstr(this->str + index, string.c_str());
		return result - this->str;
	}
	else return -1;
}

void MyString::new_memory(unsigned int new_size) {
	delete[] this->str;
	this->str = nullptr;
	this->str = new char[new_size + 1];
	this->_size_ = new_size;
	this->_capacity_ = new_size + 1;
}
/////////////////////////////////
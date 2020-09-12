#include<iostream>
#include"MyString .h"
#include<conio.h>
#include<fstream>

using namespace std;

MyString::MyString() { // default constructor
	strArr = NULL;
	length = 0;
}
MyString::MyString(char* p) { // parametarize constructor
	int size = 0;
	for (int i = 0; p[i] != '\0'; i++) { // find size
		size++;
	}
	length = size;
	strArr = new char[length + 1];
	for (int i = 0; p[i] != '\0'; i++) { // copy data from one array to another
		strArr[i] = p[i];
	}
	strArr[length] = '\0';
}
MyString::MyString(const MyString& p) { // cope constructor
	length = p.length;
	if (p.strArr != NULL) { // if string not null
		strArr = new char[length + 1];
		for (int i = 0; p.strArr[i] != '\0'; i++) { // copy data
			strArr[i] = p.strArr[i];
		}
		strArr[length] = '\0';
	}
}
MyString& MyString::stringSize(const char* p) { //use to find string size
	int size = 0;
	for (int i = 0; p[i] != '\0'; i++) { // find size
		size++;
	}
	MyString temp;
	temp.length = size;
	temp.strArr = new char[temp.length + 1];
	return *this;
}

MyString MyString:: operator +(const MyString p) { // add two string
	MyString temp;
	temp.length = p.length + length; // length of two string
	temp.strArr = new char[temp.length + 1];
	int i = 0;
	if (strArr == NULL && p.strArr!=NULL) { // if first NUll but second not NULL
		for (int j = 0; p.strArr[j] != '\0'; j++) { // copy of first string
			temp.strArr[j] = p.strArr[j];
		}
		temp.strArr[temp.length] = '\0';
	}
	else if (strArr != NULL && p.strArr != NULL) {  // if first not NUll and second also not NULL
		for (; strArr[i] != '\0'; i++) { // copy data
			temp.strArr[i] = strArr[i];
		}
		for (int j = 0; j<p.length; j++) {  // copy data 
			temp.strArr[i] = p.strArr[j];
			i++;
		}
		temp.strArr[temp.length] = '\0';
	}
	else if (strArr != NULL && p.strArr == NULL) { // if first not NULL and second NULL
		for (int j = 0; strArr[j] != '\0'; j++) { // copy data
			temp.strArr[j] = strArr[j];
		}
		temp.strArr[temp.length] = '\0';
	}
	return temp;
}

MyString MyString:: operator +(char* p) { // if first class object and second normal string
	MyString temp = stringSize(p); // transfer normal string into MyString
	return (*this + temp);
}
MyString MyString :: operator -(char* p) { // if first class object and second normal string
	MyString temp = stringSize(p); // transfer normal string into MyString
	for (int i = 0; i<temp.length; i++) {
		temp.strArr[i] = p[i];
	}
	temp.strArr[temp.length] = '\0';
	return (*this - temp);
}

MyString MyString :: operator -(MyString& p) { // if both are class objects
	MyString temp = *this;
	bool present = false;
	int start = 0;
	int end = 0;
	int leftArrIndex = 0;
	if (p.strArr == NULL && strArr != NULL) { // if first is NULL and second is not NULL
		temp = *this;
	} 
	
	// chaeck left array is present
	else if (p.strArr != NULL && strArr != NULL){ // if first is not NULL and second also
		for (int i = 0; i < temp.length; i++) { // check string start from which index
			start = i;
			if (p.strArr[0] == temp.strArr[i]) { // check string end at which index
				for (int j = i; leftArrIndex < p.length; j++) {
					if (p.strArr[leftArrIndex] == temp.strArr[j]) {
						present = true;
						leftArrIndex++;
					}
					else {
						present = false;
						leftArrIndex = (p.length);
						start = 0;
						end = 0;
					}
					end = j;
				}
				leftArrIndex = 0;
				if (present) { // left array is present
					end++;
					temp.length -= (end - start);
					while (temp.strArr[end - 1] != '\0') { // removing existing array
						temp.strArr[start] = temp.strArr[end];
						end++;
						start++;
					}
					leftArrIndex = 0;
					present = false;
					i = 0;
				}
			}
		}
	}
	else if (p.strArr == NULL && strArr != NULL) { // if first is NULL and second is not NULL
		return temp;
	}
	return temp;
}

void MyString:: operator =(const char* p) { // if first is a class object and second is a normal string
	MyString temp = stringSize(p);// transfer normal string into MyString
	for (int i = 0; i < temp.length; i++) { // copy string
		temp.strArr[i] = p[i];
	}
	temp.strArr[temp.length] = '\0';
	operator =(temp);
}
void MyString:: operator =(const MyString p) { // if both are class object 

	if (strArr != NULL && p.strArr == NULL) { // if first is not NULL and Second is Not NUll
		length = 0;
		char* temp = strArr;
		strArr = NULL;
		delete[]temp;
		temp = NULL;
	}
	else if (strArr == NULL && p.strArr != NULL) { // if First NUll and second is not NULL
		length = p.length;
		strArr = new char[length + 1];
		for (int i = 0; p.strArr[i] != '\0'; i++) { // copy string
			strArr[i] = p.strArr[i];
		}
		strArr[length] = '\0';
	}
	else if (strArr != NULL && p.strArr != NULL) { // if first not NUll and second Not NUll
		length = p.length;
		char* temp = strArr;
		strArr = NULL;
		delete[]temp;
		temp = NULL;

		length = p.length;
		strArr = new char[length + 1];
		for (int i = 0; p.strArr[i] != '\0'; i++) { //copy data
			strArr[i] = p.strArr[i];
		}
		strArr[length] = '\0';
	}
}

bool MyString:: operator ==(const char* p) {
	MyString temp = stringSize(p);// transfer normal string into MyString
	return (*this == temp);
}

bool MyString:: operator ==(const MyString p) {
	bool isEquall = false;
	if (length == p.length) { // if both length are same
		for (int i = 0; i < length; i++) {
			if (strArr[i] == p.strArr[i]) { // if both array element are same
				isEquall = true;
			}
			else {
				isEquall = false;
				i = length;
			}
		}
	}
	return isEquall;
}

bool MyString:: operator !=(const char* p) {
	MyString temp = stringSize(p);// transfer normal string into MyString
	return (*this == temp);
}

bool MyString:: operator !=(const MyString p) {
	return !(*this == p);
}

bool MyString:: operator <(const MyString p) { // if both are class object
	bool isless = false;
	if (length == p.length) { // if 
		for (int i = 0; i < length; i++) {
			if (strArr[i] < p.strArr[i]) {
				isless = true;
			}
			else {
				isless = false;
				i = length;
			}
		}
	}
	else if (length < p.length) {
		isless = true;
	}
	return isless;
}

bool MyString:: operator <(const char* p) {
	MyString temp = stringSize(p);// transfer normal string into MyString
	return (*this < temp);
}

bool MyString:: operator >(const char* p) {
	MyString temp = stringSize(p);// transfer normal string into MyString
	return (*this > temp);
}

bool MyString:: operator >(const MyString p) { // if both are class object
	if (length == p.length) { // length same of both strings
		return 0;
	}
	return !(*this < p);
}

char MyString:: operator [](int p) {
	if (strArr != NULL) { // if left stinr is not NULL
		if (p >= 0 && p < length) { //given number is in the range of index of string
			return strArr[p];
		}
	}
	else {
		cout <<"Invalid Index";
	}
}

ostream& operator<<(ostream& out, const MyString& p) { //  // for class object
	if (p.length == 0) { // if string empty
		cout << "Empty";
		return out;
	}
	else {
		for (int i = 0; p.strArr[i] != '\0'; i++) { // show output
			out << p.strArr[i];
		}
	}
	return out;
}

ostream& operator<<(ostream& out, char *p) { //  // for non class object
	for (int i = 0; p[i] != '\0'; i++) { // show out put
		out << p[i];
	}
	return out;
}

istream& operator >> (istream& in, MyString& p) { // for class object
	if (p.length == 0) { // if string empty or NULl
		cout << "Enter size of string :";
		in >> p.length;
	}
	else {
		delete[]p.strArr;
		p.length = -1;
		while(p.length <= 0) { // take size of string
			cout << "Enter size of string :";
			in >> p.length;
		}
	}
	p.strArr = new char[p.length + 1];
	char c;
	cout << "Enter String :";
	for (int i = 0; i< p.length; i++) { // enter data from user
		c = getche();
		if ((int)c != 13) {
			p.strArr[i] = c;
		}
	}
	p.strArr[p.length] = '\0';
	cout << "\n";
	return in;
}

ofstream& operator<<(ofstream& fout, const MyString& p) { //for class object
	if (p.length == 0) { // string empty
		fout << '0';
		fout << endl << NULL;
		return fout;
	}
	else {
		fout <<endl<< p.length<<"\n";
		for (int i = 0; p.strArr[i] != '\0'; i++) { // handle for show output
			fout << p.strArr[i];
		}
	}
	return fout;
}
ifstream& operator>>(ifstream& fin, MyString& p) {  // for class object and read data from file
	if (!fin.eof()) { //file not ended
		fin >> p.length; // take file length
		char c;
		fin >> c;
		if (p.strArr == NULL && c != NULL) { // first null but second not
			p.strArr = new char[p.length + 1];// allocat memory
			p.strArr[0] = c;
			for (int i = 1; i < p.length + 1; i++) { // get data from file
				fin.get(p.strArr[i]);
			}
			p.strArr[p.length] = '\0';
		}
		else if (p.strArr != NULL && c != NULL) { //first not NULL and second also
			delete[] p.strArr;
			p.strArr = new char[p.length + 1]; // allocate memort
			p.strArr[0] = c;
			for (int i = 1; i < p.length + 1; i++) { //gat data from file
				fin.get(p.strArr[i]);
			}
			p.strArr[p.length] = '\0';
		}
		else if (p.strArr != NULL && c == NULL) { //first not NUll but Second isNUll
			delete[]p.strArr;
		}
	}
	return fin;
}

~MyString(){
	delete[]strArr;
	strArr = NULL;
}



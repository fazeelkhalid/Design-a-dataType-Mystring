#ifndef  MyString _H
#define  MyString_H
#include<iostream>
#include<fstream>

using namespace std;

class  MyString {
private:
	char* strArr;
	int length; // store lengh of strArr including NULL
	MyString& stringSize(const char* p); // getstring and convert it in Mystring
public:
	MyString(); //default constrctor
	MyString(char* p); //parameterized constrctor
	MyString(const MyString& p); // copy constrctor

	MyString operator +(const MyString p); 
	MyString operator +(char *p);
	MyString operator -(MyString& p);
	MyString operator -(char *p);
	
	void operator =(const MyString p);
	void operator =(const char* p);
	
	bool operator ==(const MyString p);
	bool operator ==(const char* p);
	bool operator !=(const MyString p);
	bool operator !=(const char* p);
	bool operator <(const MyString p);
	bool operator <(const char* p);
	bool operator >(const MyString p);
	bool operator >(const char* p);
	
	char operator [](int p);

	friend ostream& operator<<(ostream& out, char *p);//output on console
	friend ostream& operator<<(ostream& out,const MyString& p); //output on console
	friend istream& operator>>(istream& in,  MyString& p); // input from console
	friend ofstream& operator<<(ofstream& fout,const MyString& p); //output in file
	friend ifstream& operator>>(ifstream& fin, MyString& p);//input from file
};



#endif // ! MyString _H

#include<iostream>
#include<fstream>
#include"MyString .h"
#include<conio.h>

using namespace std;

int menu() {
	cout << endl;
	for (int i = 0; i < 40; i++) { // print upper line
		cout << char(223);
	}
	int operation = -1;
	cout << "\n 0 : Exist ";
	cout << "\n 1 : Input from counsole ";
	cout << "\n 2 : Input from file ";
	cout << "\n 3 : Output on counsole ";
	cout << "\n 4 : Output in file ";
	cout << "\n 5 : Sum two objects ";
	cout << "\n 6 : Sum object and string ";
	cout << "\n 7 : Subtract two objests ";
	cout << "\n 8 : Subtract object and string ";
	cout << "\n 9 : Check two objests are \"=\" ";
	cout << "\n 10 : Check objects and string are \"=\"";
	cout << "\n 11 : Check two objests are \"!=\"";
	cout << "\n 12 : Check objects and string are \"!=\"";
	cout << "\n 13 : Check which is \"<\" from two objects";
	cout << "\n 14 : Check which is \"<\" from object and string ";
	cout << "\n 15 : Check which is \">\" from two objects";
	cout << "\n 16 : Check which is \">\" from object and string ";
	cout << "\n 17 : clearScrean\n\t";
	while(operation < 0 || operation > 17) { //in case of wrong input
		cin >> operation;
		if (operation < 0 || operation > 17) {
			cout << "\nWroung Input :";
		}
	}
	return operation;
}


int main() {
	int operation = -1;
	bool isExit = false;
	char c[100];
	MyString p1("feeleedsadsal khalid"); // first object
	MyString p2; // second object
	MyString p; // store final fting
	while (!isExit) {
		operation = menu(); // use to handle or select operation
		switch (operation) {
			case 0: { // exist from program
				isExit = true;
				break;
			}
			case 1: { //input from console
				cin >> p1>> p2;
				break;
			}
			case 2: {//input from file
				ifstream fin;
				fin.open("Input.txt");
				fin >> p1, p2;
				fin.close();
				break;
			}
			case 3: {//output on console
				cout << "\n p : " << p;
				cout << "\n p1 : " << p1;
				cout << "\n p2 : " << p2;
				break;
			}
			case 4: {//output in file
				ofstream fout;
				fout.open("Input.txt");
				fout << p1 << p2;
				fout.close();
				break;
			}
			case 5: {// add two class obj
				p = p1 + p2;
				break;
			}
			case 6: { // add one class obj and one simple string
				cout << "Enter string :";
				for (int i = 0; (int)c[i - 1] != 13; i++) {
					c[i] = getche();
				}
				p = p1 + c;
				break;
			}
			case 7: { //subtract two class obj
				p = p1 - p2;
				break;
			}
			case 8: { //sub class obj and sting
				cout << "Enter string :";
				for (int i = 0; (int)c[i - 1] != 13; i++) {
					c[i] = getche();
				}
				p = p1 - c;
				break;
			}
			case 9: {//chech two obj are equal
				if (p1 == p2) {
					cout << "\np1 and p2 are equall";
				}
				if (p == p1) {
					cout << "\np and p1 are equall";
				}
				if (p == p2) {
					cout << "\np and p2 are equall";
				}
				break;
			}
			case 10: { // chech obj and string are equal
				cout << "Enter string :";
				for (int i = 0; (int)c[i - 1] != 13; i++) {
					c[i] = getche();
				}
				if (p == c) {
					cout << "\np and c are equall";
				}
				if (p1 == c) {
					cout << "\np1 and c are equall";
				}
				if (p2 == c) {
					cout << "\np2 and c are equall";
				}
				break;
			}
			case 11: {//check two obj are not equal
				if (p1 != p2) {
					cout << "\np1 and p2 are not equall";
				}
				if (p != p1) {
					cout << "\np and p1 are not equall";
				}
				if (p != p2) {
					cout << "\np and p2 are not equall";
				}
				break;
			}
			case 12: { //check obj and string are not equal
				cout << "Enter string in c :";
				for (int i = 0; (int)c[i - 1] != 13; i++) {
					c[i] = getche();
				}
				if (p != c) {
					cout << "\np and c are not equall";
				}
				if (p1 != c) {
					cout << "\np1 and c are not equall";
				}
				if (p2 != c) {
					cout << "\np2 and c are not equall";
				}
				break;
			}
			case 13: { // check which obj is less
				if (p1 < p2) {
					cout << "\np1 is less than p2";
				}
				if (p < p1) {
					cout << "\np is less than p1";
				}
				if (p < p2) {
					cout << "\np is less than p2";
				}
				break;
			}
			case 14: {check which obj is less than string
				cout << "Enter string in c :";
				for (int i = 0; (int)c[i - 1] != 13; i++) {
					c[i] = getche();
				}
				if (p < c) {
					cout << "\np is less than c";
				}
				if (p1 < c) {
					cout << "\np1 is less than c";
				}
				if (p2 < c) {
					cout << "\np2 is less than c";
				}
				break;
			}
			case 15: { //check which obj is greater 
				if (p1 > p2) {
					cout << "\np1 is greater than p2";
				}
				if (p > p1) {
					cout << "\np is greater than p1";
				}
				if (p > p2) {
					cout << "\np is greater than p2";
				}
				break;
			}
			case 16: { //check which obj is greater than string
				cout << "Enter string in c :";
				for (int i = 0; (int)c[i - 1] != 13; i++) {
					c[i] = getche();
				}
				if (p > c) {
					cout << "\np is greater than c";
				}
				if (p1 > c) {
					cout << "\np1 is greater than c";
				}
				if (p2 > c) {
					cout << "\np2 is greater than c";
				}
				break;
			}
			case 17: { // clear screen
				system("CLS");
				break;
			}
		}
	}
	system("PAUSE");
	return 0;
}

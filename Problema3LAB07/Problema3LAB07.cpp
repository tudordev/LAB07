// Problema3LAB07.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

class Student {
	string nume;
	string prenume;
	float media;

public:
	Student( string num, string pre , float med = 0.0) 
	{
		media = med;
		nume = num;
		prenume = pre;
	}
	Student() {};
	void setName(string name) { nume = name; }
	void setPrename(string prename) { prenume = prename; }
	void setMedia(float med) { media = med; }

	float getMedia() { return media; }
	string getName() { return nume; }
	string getPrename() { return prenume; }

	friend istream& operator>>(istream &in, Student &stud);
	friend ostream& operator<<(ostream &out, Student &stud);

};


istream& operator>>(istream &in, Student &stud)
{
	cout << "Introduceti datele studentului " << endl;
	cout << "Numele: ";
	getline(in, stud.nume);
	cout << "Prenume: ";
	getline(in, stud.prenume);
	cout << "Media: ";
	in >> stud.media;
	
	return in;
}

ostream& operator<<(ostream &out, Student &stud)
{
	cout << "Datele studentului sunt: " << endl;
	out << "Numele: " << stud.nume << endl;
	out << "Prenumele: " << stud.prenume << endl;
	out << "Media: " << stud.media << endl;

	return out;
}

int main()
{
	Student ob1;
	cin >> ob1;
	cout << ob1;
	//comentariu




    return 0;
}


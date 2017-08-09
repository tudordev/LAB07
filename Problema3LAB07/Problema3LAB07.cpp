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
	//Student(const Student &ob2);// copy constructor
	void setName(string name) { nume = name; }
	void setPrename(string prename) { prenume = prename; }
	void setMedia(float med) { media = med; }

	float getMedia() { return media; }
	string getName() { return nume; }
	string getPrename() { return prenume; }

	friend istream& operator>>(istream &in, Student &stud);
	friend ostream& operator<<(ostream &out, Student &stud);
	friend bool operator< (const Student &c1, const Student &c2);


	void operator=( Student &rhs) {
		media = rhs.media;
		nume = rhs.nume;
		prenume = rhs.prenume;
	}


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
	cin.ignore();
	
	return in;
}

ostream& operator<<(ostream &out, Student &stud)
{
	//cout << "Datele studentului sunt: " << endl;
	out << "Numele: " << stud.nume << endl;
	out << "Prenumele: " << stud.prenume << endl;
	out << "Media: " << stud.media << endl;

	return out;
}

bool operator<(const Student &c1, const Student &c2)
{
	return c1.media < c2.media;
}


void Sortare(Student tablou[]);
void Respins(Student tablou[]);

int main()
{
	Student ob1;
	Student tablou[4];
	int i = 0;

	for (i = 0; i < 4; ++i)
	{
		cin >> ob1;
		tablou[i] = ob1;
	}
	cout << "Studentii respinsi sunt: " << endl;
	
	Respins(tablou);
	cout << "Stundetii sortati in ordinea descrescatorea a mediilor: " << endl;
	Sortare(tablou);
	

	for (i = 0; i < 4; i++)
	{
		cout << tablou[i];
	}

	
    return 0;
}

void Sortare(Student tablou[])
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 3 - i; j++)
		{
			if (tablou[j] < tablou[j+1])
			{
			    Student aux = tablou[j];
				tablou[j] = tablou[j+1];
				tablou[j+1] = aux;
			}
		}
	}


}

void Respins(Student tablou[])
{
	for (int i = 0; i < 4; ++i)
	{
		if (tablou[i].getMedia() < 5)
			cout << "Studentul " << tablou[i] << "este respins!" << endl;
	}

}
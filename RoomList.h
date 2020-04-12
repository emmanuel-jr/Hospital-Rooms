#pragma once
#include <fstream>
#include <queue>
#include "People.h"
#include "UnsortedType.h"

const int MAX_ITEMS = 100;
ofstream out;

struct Rooms
{
	int number;
	Doctor* doc;
	queue<Patient> q;

	int getNum()
	{
		return number;
	}
};




class roomList
{
	Rooms array[MAX_ITEMS];

public:
	roomList()
	{
		for (int i = 0; i < MAX_ITEMS; i++)
		{
			array[i].doc = nullptr;
			array[i].number = i + 1;
		}
	}
	

	void inDoc(UnsortedType unsort)
	{
		string name, code;
		int room;

		cout << "\nEnter your name : ";
		cin >> name;

		cout << "Enter your speciality code : ";
		cin >> code;

		cout << "Enter your preferred room number : ";
		cin >> room;

		out << "\nEnter your name : " << name << endl;
		out << "Enter your speciality code : " << code << endl;
		out << "Enter your preferred room number : " << room << endl;

		while (array[room - 1].doc != nullptr)
		{
			cout << "\nSorry the room is not available right now" << endl << endl;
			cout << "Enter your another room number : ";
			cin >> room;

			out << "\nSorry the room is not available right now" << endl << endl;
			out << "Enter your another room number : " << room << endl;
		}

		array[room - 1].doc = new Doctor;
		array[room - 1].doc->name = name;
		array[room - 1].doc->specialitycode = code;

		unsort.InsertItem(array[room - 1]);

		cout << "\nWelcome Dr." << name << endl << endl;

		out << "\nWelcome Dr." << name << endl << endl;
	}

};


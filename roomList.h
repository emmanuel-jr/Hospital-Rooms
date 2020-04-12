#pragma once
#include <fstream>
#include <queue>
#include "People.h"

const int MAX_ITEMS = 100;
ofstream out;

struct Rooms
{
	int number;
	Doctor* doc;
	queue<Patient> q;

	int getNum(Rooms& room)
	{
		return room.number;
	}
};




class roomList
{
	Rooms array[MAX_ITEMS];

public:
	roomList();
	
	void assignPatient(string special, int& min);
	void positive(Patient p, int& min);
	void outPatient();
	void inPatient();
	void outDoc();
	void inDoc();

};

roomList::roomList()
{
	for (int i = 0; i < MAX_ITEMS; i++)
	{
		array[i].doc = nullptr;
		array[i].number = i + 1;
	}
}


void roomList::assignPatient(string special, int& min)
{

	for (int i = 0; i < MAX_ITEMS; ++i)
	{
		if (array[i].doc != nullptr && array[i].doc->specialitycode == special)
		{              //assigning to the pediatrician having minimum waiting list
			if (min == -1)
				min = i;                                      //assigning first peditrician

			else if (array[min].q.size() > array[i].q.size())
				min = i;    //current is the minimum waiting list
		}
	}
}

void roomList::positive(Patient p, int& min)
{
	cout << "Go to Room number " << min + 1 << endl;

	out << "Go to Room number " << min + 1 << endl;

	array[min].q.push(p);
}

void roomList::outPatient()
{
	string name;
	int room;

	cout << "\nEnter your name : ";
	cin >> name;

	cout << "Enter your room number : ";
	cin >> room;

	cout << "Good bye, " << name << "!\nHave a nice day." << endl; //good bye message

	out << "\nEnter your name : " << name << endl;
	out << "Enter your room number : " << room << endl;

	out << "Good bye, " << name << "!\nHave a nice day." << endl; //good bye message

	array[room - 1].q.pop();
}

void roomList::inPatient()
{
	Patient p;
	string name, code;
	int age;

	cout << "\nEnter your name : ";
	cin >> name;

	cout << "Enter your age : ";
	cin >> age;

	out << "\nEnter your name : " << name << endl;
	out << "Enter your age : " << age << endl;
	
	p.name = name;
	p.age = age;

	int min = -1;

	if (age < 16)
	{                                   //checking the age
		assignPatient("PED", min);

		if (min == -1)
		{
			cout << "\nSorry no pediatricians are available" << endl;           //min is assigned to none
			out << "\nSorry no pediatricians are available" << endl;
		}
		else
			positive(p, min);                                           //assigned to the min peditrician
	}

	else
	{     
		cout << "\nEnter your requested speciality code : ";
		cin >> code;

		out << "\nEnter your requested speciality code : " << code << endl;

		assignPatient(code, min);

		if (min != -1)
			positive(p, min);                              //assigned to the preferred code

		else
		{            
			//preferred code is not available
			cout << "\nSorry, your preferred doctor is not available" << endl;
			cout << "We will assign you to a General Practitioner" << endl;

			out << "\nSorry, your preferred doctor is not available" << endl;
			out << "We will assign you to a General Practitioner" << endl;

			assignPatient("GEN", min);

			if (min != -1)
				positive(p, min);                             //found min waiting list for gen

			else
			{                                                                   //gen is not available
				for (int i = 0; i < MAX_ITEMS; ++i)
				{
					if (array[i].doc != nullptr)
					{                             //searching for any other doc
						if (min == -1)
							min = i;

						else if (array[min].q.size() > array[i].q.size())
							min = i;   //same as before
					}

				}

				if (min != -1)
					positive(p, min);                    //found any other doc with min waiting list

				else
				{
					cout << "\nSorry no doctors are available" << endl;    //not found
					out << "\nSorry no doctors are available" << endl;
				}
			}

		}

	}
}

void roomList::outDoc()
{
	string name;
	cout << "\nEnter your name : ";
	cin >> name;

	out << "\nEnter your name : " << name;





	for (int i = 0; i < MAX_ITEMS; ++i)
	{
		if (array[i].doc != nullptr && array[i].doc->name == name)
		{
			//finding the doc’s room

			if (array[i].q.empty())
				array[i].doc = nullptr;           //doc’s queue is empty

			else
			{
				//finding other availabe doctors for patients

				for (int j = 0; j < MAX_ITEMS; j++)
				{
					if (array[j].doc != nullptr && i != j)
					{
						while (!array[i].q.empty())
						{
							//reassign patients on waiting list to another doctor

							Patient temp = array[i].q.front();
							array[j].q.push(temp);
							array[i].q.pop();
						}

						array[i].doc = nullptr;                      //removing the doctor

						break;

					}

				}

			}

		}

	}

	cout << "\nGood bye Dr." << name << "!\nHave a nice day." << endl;

	out << "\nGood bye Dr." << name << "!\nHave a nice day." << endl;
}

void roomList::inDoc()
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

	cout << "\nWelcome Dr." << name << endl << endl;

	out << "\nWelcome Dr." << name << endl << endl;
}
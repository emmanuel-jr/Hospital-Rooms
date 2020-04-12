#include "UnsortedType.h"


UnsortedType::UnsortedType()
	:length(0), currPos(0)
{}


UnsortedType::~UnsortedType()
{}


bool UnsortedType::IsFull() const
{
	return(length == MAX_ITEMS - 1);
}


int  UnsortedType::LengthIs() const
{
	return length;
}


void  UnsortedType::InsertItem(Rooms& item)
{
	if (IsFull())
		cerr << "Array is full";

	examRoom[length] = item;
	length++;
}


void  UnsortedType::DeleteItem(Rooms item)
{
	item.doc = nullptr;                      //removing the doctor
	item = examRoom[length - 1];
	length--;
}


void UnsortedType::assignPatient(string special, int& min)
{
	for (int i = 0; i < length; i++)
	{
		if (examRoom[i].doc != nullptr && examRoom[i].doc->specialitycode == special)
		{              //assigning to the pediatrician having minimum waiting list
			if (min == -1)
				min = i;                                      //assigning first peditrician

			else if (examRoom[min].q.size() > examRoom[i].q.size())
				min = i;    //current is the minimum waiting list
		}
	}
}


void UnsortedType::positive(Patient p, int& min)
{
	cout << "Go to Room number " << min + 1 << endl;

	out << "Go to Room number " << min + 1 << endl;

	examRoom[min].q.push(p);
}


void UnsortedType::outPatient()
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

	examRoom[room - 1].q.pop();
}


void UnsortedType::inPatient()
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
				for (int i = 0; i < length; i++)
				{
					if (examRoom[i].doc != nullptr)
					{                             //searching for any other doc
						if (min == -1)
							min = i;

						else if (examRoom[min].q.size() > examRoom[i].q.size())
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


void UnsortedType::outDoc()
{
	string name;
	cout << "\nEnter your name : ";
	cin >> name;

	out << "\nEnter your name : " << name;

	for (int i = 0; i < length; ++i)
	{
		if (examRoom[i].doc != nullptr && examRoom[i].doc->name == name)
		{
			//finding the doc’s room

			if (examRoom[i].q.empty())
				examRoom[i].doc = nullptr;           //doc’s queue is empty

			else
			{
				//finding other availabe doctors for patients

				for (int j = 0; j < length; j++)
				{
					if (examRoom[j].doc != nullptr && i != j)
					{
						while (!examRoom[i].q.empty())
						{
							//reassign patients on waiting list to another doctor

							Patient temp = examRoom[i].q.front();
							examRoom[j].q.push(temp);
							examRoom[i].q.pop();
						}

						DeleteItem(examRoom[i]);
						

						break;

					}

				}

			}

		}

	}

	cout << "\nGood bye Dr." << name << "!\nHave a nice day." << endl;

	out << "\nGood bye Dr." << name << "!\nHave a nice day." << endl;
}



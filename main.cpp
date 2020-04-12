/*
   Name: Emmanuel Idun
   Student #: 200418000
   Program: CS 210-001
   Assignment # 5

   Problem: A doctor checks in by telling the scheduler his or her name, an examination room number,
			and a medical specialty code. Each doctor has a favorite room. The scheduler checks to
			see whether the room is free. If so, it assigns this doctor to the room; if not, it rejects the
			request with a message, and the doctor can try again to check in. When a doctor checks
			out, the examination room is freed.
			A patient checking in gives a name, age, specialist code, and emergency indication. The
			scheduler tries to match up the patient with a doctor according to a set of rules that are
			described here. If there is a match, the patient is seen by the assigned doctor. If this
			doctor is currently seeing a patient, the new patient is queued to see the doctor. If it is the
			emergency case, the patient should be moved to the front of the waiting list.

	Assumptions: There are l00 examination rooms at the clinic, each with a waiting room attached.
				 Specialty codes are as follows:
				 Pediatrics PED
				 General practice GEN
				 Internal medicine INT
				 Cardiology CAR
				 Surgeon SUR
				 Obstetrics OBS
				 Psychiatry PSY
				 Neurology NEU
				 Orthopedics ORT
				 Dermatology DET
				 Ophthalmology OPT
				 Ear, Nose, and Throat ENT


*/




#include "roomList.h"

int main()
{
	roomList List;
	UnsortedType rooms;
	char check;
	char position;

	out.open("output.txt");

	if (!out)
	{
		cout << "Sorry, your output file could not open" << endl;
		return -1;
	}


	cout << "Welcome to Akai House Clinic" << endl;
	cout << "Where you feel satisfied after coming.\n" << endl;

	out << "Welcome to Akai House Clinic" << endl;
	out << "Where you feel satisfied after coming.\n" << endl;

	while (true)
	{
		cout << "Kindly identify yourself based on options below" << endl;
		cout << "D: Doctor" << endl;
		cout << "P: Patient" << endl;

		cin >> position;

		out << "Kindly identify yourself based on options below" << endl;
		out << "D: Doctor" << endl;
		out << "P: Patient" << endl;
		out << position;


		cout << "Type I for check - in or O for checkout: ";
		cin >> check;

		out << "Type I for check - in or O for checkout: " << check;

		if (position == 'D')
		{
			if (check == 'I')                                        //doctor checking in
				List.inDoc(rooms);

			else if (check == 'O')                 //doctor checking out
				rooms.outDoc();
		}

		else if (position == 'P')
		{
			if (check == 'I')
				rooms.inPatient();                                //patient checking in

			else if (check == 'O')
				rooms.outPatient();             //patient checking out                              
		}

	}

	return 0;
}
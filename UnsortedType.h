#pragma once

#include "roomList.h"



class UnsortedType
{
	Rooms examRoom[MAX_ITEMS];
	int length;
	int currPos;

public:
	UnsortedType();

	~UnsortedType();

	

	bool IsFull() const;
	// Function: Determines whether list is full.
	// Pre: List has been initialized.
	// Post: Function value = (list is full)

	int LengthIs() const;
	// Function: Determines the number of elements in list.
	// Pre: List has been initialized.
	// Post: Function value = number of elements in list

	//void RetrieveItem(ItemType& item, bool& found);
	// Function: Retrieves list element whose key matches item's
	// key (if present).
	// Pre: List has been initialized.
	// Key member of item is initialized.
	// Post: If there is an element someItem whose key matches
	// item's key, then found = true and item is a copy of
	// someItem; otherwise found = false and item is unchanged.
	// List is unchanged.

	void InsertItem(Rooms& item);
	// Function: Adds item to list.
	// Pre: List has been initialized.
	// List is not full.
	// item is not in list.
	// Post: item is in list.

	void DeleteItem(Rooms item);
	// Function: Deletes the element whose key matches item's key.
	// Pre: List has been initialized.
	// Key member of item is initialized.
	// One and only one element in list has a key matching
	// item's key.
	// Post: No element in list has a key matching item's key.

	void assignPatient(string special, int& min);
	void positive(Patient p, int& min);
	void outPatient();
	void inPatient();
	void outDoc();

};



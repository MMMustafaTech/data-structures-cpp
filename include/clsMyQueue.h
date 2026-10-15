#pragma once
#include <iostream>
#include "clsDblLinkedList.h"


template <class T>
class clsMyQueue
{ 


protected:

	clsDblLinkedList<T> _MyList;



public:

	
	void push(T Item) {

		_MyList.InsertAtEnd(Item);
	}

	void Print() {
		_MyList.PrintList();
	}

	unsigned short Size() {
		return _MyList.Size();
	}

	bool IsEmpty() {
		return _MyList.IsEmpty();
	}

	T front() {
		return _MyList.GetItem(0);
	}

	T back() {
		return _MyList.GetItem(Size() - 1);
	}

	void pop() {
		_MyList.DeleteFirstNode();
	}

	T GetItem(unsigned short Index) {
		return _MyList.GetItem(Index);
	}

	void Reverse() {
		_MyList.Reverse();
	}

	void UpdateItem(unsigned short Index, T Item) {
		_MyList.UpdateItem(Index, Item);
	}

	void InsertAfter(unsigned short Index, T Item) {
		_MyList.InsertAfter(Index, Item);
	}

	void InsertAtFront(T Item) {
		_MyList.InsertAtBeginning(Item);
	}

	void InsertAtBack(T Item) {
		_MyList.InsertAtEnd(Item);
	}

	void Clear() {
		_MyList.Clear();
	}

};


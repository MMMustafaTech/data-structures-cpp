#pragma once
#include <iostream>
#include "clsDynamicArray.h"

template <class T>
class clsMyQueueArr
{

protected:

	clsDynamicArray<T> _MyArray;


public:

	void push(T Item) {
		_MyArray.InsertAtEnd(Item);
	}

	void Print() {
		_MyArray.PrintList();
	}

	int Size() {
		return _MyArray.Size();
	}

	bool IsEmpty() {
		return Size() == 0;
	}

	T front() {
		return _MyArray.GetItem(0);
	}

	T back() {
		return _MyArray.GetItem(Size() - 1);
	}

	void pop() {
		_MyArray.DeleteFirstItem();
	}

	void Reverse() {
		_MyArray.Reverse();
	}

	T GetItem(int Index) {
		return _MyArray.GetItem(Index);
	}

	void UpdateItem(int Index, T Item) {
		_MyArray.SetItem(Index, Item);
	}

	void InsertAfter(int Index, T Item) {
		_MyArray.InsertAfter(Index, Item);
	}

	void InsertAtFront(T Item) {
		_MyArray.InsertAtBeginning(Item);
	}

	void InsertAtBack(T Item) {
		_MyArray.InsertAtEnd(Item);
	}

	void Clear() {
		_MyArray.Clear();
	}























};


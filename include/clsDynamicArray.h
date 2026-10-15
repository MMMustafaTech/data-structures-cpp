#pragma once
#include <iostream>

using namespace std;

template <class T>
class clsDynamicArray
{

private:
	T* _OriginalArray;
	unsigned int _Size;

public:

	clsDynamicArray(int Size = 0) {

		if (Size < 0) Size = 0;

		_Size = Size;
		_OriginalArray = new T[_Size];
	}

	~clsDynamicArray() {

		delete[] _OriginalArray;
		_OriginalArray = nullptr;
	}


	void SetItem(unsigned int Index, T Item) {

		if (Index > _Size || _Size < 0) return;

		_OriginalArray[Index] = Item;
	}

	bool IsEmpty() {
		return _Size == 0;
	}

	unsigned int Size() {
		return _Size;
	}

	void PrintList() {

		if (_OriginalArray == nullptr) return;

		for (unsigned int i = 0; i < _Size; i++) cout << _OriginalArray[i] << "  ";
	}

	void Resize(int NewSize)
	{
		if (NewSize < 0)
			NewSize = 0;

		T* TempArray = new T[NewSize];

		int CopySize = (NewSize < _Size) ? NewSize : _Size;

		for (int i = 0; i < CopySize; i++)
		{
			TempArray[i] = _OriginalArray[i];
		}

		delete[] _OriginalArray;

		_OriginalArray = TempArray;
		_Size = NewSize;
	}

	T GetItem(int Index) {

		if (Index < 0) Index = 0;

		if (Index > _Size) Index = _Size;

		return _OriginalArray[Index];


	}

	void Reverse() {

		int Counter = 0;
		T* TempArray = new T[_Size];

		for (int i = _Size - 1; i >= 0; i--) {

			TempArray[Counter] = _OriginalArray[i];
			Counter++;

		}

		delete[] _OriginalArray;
		_OriginalArray = TempArray;
	}

	void Clear() {
		_Size = 0;
		delete _OriginalArray;
		_OriginalArray = nullptr;

	}

	void DeleteItemAt(int Index) {

		if (Index >= _Size || Index < 0) return;

		_Size--;

		T* TempArray = new T[_Size];
		

		for (int i = 0; i < Index; i++) {

			TempArray[i] = _OriginalArray[i];
		}

		for (int i = Index + 1; i < _Size + 1; i++) {
			TempArray[i - 1] = _OriginalArray[i];
		}

		//delete _OriginalArray;
		_OriginalArray = TempArray;
		
	}


	void DeleteFirstItem() {
		DeleteItemAt(0);
	}


	void DeleteLastItem() {
		DeleteItemAt(_Size - 1);
	}

	int Find(T Item) {


		for (int i = 0; i < _Size; i++) {

			if (_OriginalArray[i] == Item) return i;

		}

		return -1;
	}

	void DeleteItem(T Item) {
		int Index = Find(Item);
		if (Index == -1) return;

		DeleteItemAt(Index);
	}

	void InsertAt(int Index, T Item) {


		if (Index > _Size || Index < 0) return;

		_Size++;

		T* TempArray = new T[_Size];


		for (int i = 0; i < Index; i++) {

			TempArray[i] = _OriginalArray[i];
		}

		TempArray[Index] = Item;

		for (int i = Index; i < _Size - 1; i++) {
			TempArray[i + 1] = _OriginalArray[i];
		}

		//delete _OriginalArray;
		_OriginalArray = TempArray;

	}

	void InsertAtBeginning(T Item) {
		InsertAt(0, Item);
	}

	void InsertAtEnd(T Item) {
		InsertAt(_Size, Item);
	}

	void InsertBefore(int Index, T Item) {
		return (Index < 1) ? InsertAtBeginning(Item) : InsertAt(Index - 1, Item);
	}

	void InsertAfter(int Index, T Item) {
		return (Index >= _Size) ? InsertAt(_Size - 1, Item) : InsertAt(Index + 1, Item);
	}




};


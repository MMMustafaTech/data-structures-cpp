#pragma once
#include <iostream>

using namespace std;

template <class T>
class clsDblLinkedList
{

public:

	class Node {
	public:
		T Value;
		Node* Next;
		Node* Prev;

		Node(T Value)
		{
			this->Value = Value;
			Next = nullptr;
			Prev = nullptr;
		}
	};

private: 
	Node* Head = nullptr;
	unsigned short _Size = 0;

public:


	void InsertAtBeginning(T Value) {



		Node* NewNode = new Node(Value);

		NewNode->Next = Head;

		if (Head != nullptr) Head->Prev = NewNode;

		Head = NewNode;

		_Size++;
	}



	Node* Find(T Value)
	{

		Node* Current = Head;

		while (Current != nullptr) {

			if (Current->Value == Value)
				return Current;


			Current = Current->Next;
		}

		return nullptr;


	}



	void InsertAfter(Node* Current, T Value) {

		if (Current == nullptr) return;

		Node* newNode = new Node(Value);
		newNode->Next = Current->Next;
		newNode->Prev = Current;

		if (Current->Next != nullptr) {
			Current->Next->Prev = newNode;
		}
		Current->Next = newNode;
		_Size++;
	}

	void InsertAfter(unsigned short Index, T Value) {

		Node* Current = GetNode(Index);
		InsertAfter(Current, Value);
	}



	void InsertAtEnd(T Value) {

		Node* NewNode = new Node(Value);

		if (Head == nullptr) {
			Head = NewNode;
			return;
		}


		Node* Current = Head;

		while (Current->Next != nullptr) Current = Current->Next;

		NewNode->Prev = Current;

		Current->Next = NewNode;
		_Size++;
	}



	void DeleteNode(Node*& NodeToDelete) {

		if (Head == nullptr || NodeToDelete == nullptr) {
			return;
		}
		if (Head == NodeToDelete) {
			Head = NodeToDelete->Next;
		}
		if (NodeToDelete->Next != nullptr) {
			NodeToDelete->Next->Prev = NodeToDelete->Prev;
		}
		if (NodeToDelete->Prev != nullptr) {
			NodeToDelete->Prev->Next = NodeToDelete->Next;
		}
		delete NodeToDelete;
		_Size--;
	}


	void DeleteFirstNode() {

		if (Head == nullptr) return;

		Node* Current = Head;

		Head = Current->Next;

		if (Head != nullptr) Head->Prev = nullptr;

		delete Current;
		_Size--;
	}


	void DeleteLastNode() {

		if (Head == nullptr) return;

		Node* Current = Head;
		Node* Prev = Head;

		if (Head->Next == nullptr) {
			Head = nullptr;
			delete Current;
			_Size--;
			return;
		}

		while (Current->Next != nullptr) {
			Prev = Current;
			Current = Current->Next;
		}

		Prev->Next = nullptr;

		delete Current;
		_Size--;
	}


	void PrintList() {

		Node* Current = Head;

		while (Current != nullptr) {
			cout << Current->Value << "  ";

			Current = Current->Next;
		}
		cout << endl;
	}

	unsigned short Size() {
		return _Size;
	}

	bool IsEmpty() {

		return _Size == 0;

	}

	void Clear() {
		while (_Size > 0) {

			DeleteFirstNode();

		}
	}

	void Reverse() {

		if (_Size == 0) return;

		Node* Current = Head;
		Node* temp = nullptr;

		while (Current!= nullptr) {
			temp = Current->Prev;
			Current->Prev = Current->Next;
			Current->Next = temp;
			Current = Current->Prev;
		}

		if (temp != nullptr) Head = temp->Prev;
	}


	Node* GetNode(unsigned short Index) {

		if (Index >= _Size) return nullptr;

		Node* Current = Head;

		for (unsigned short i = 0; i < Index; i++) Current = Current->Next;

		return Current;
		
	}

	T GetItem(unsigned short Index) {

		Node* Current = GetNode(Index);

		if (Current == nullptr) return NULL;

		return Current->Value;
	}


	void UpdateItem(unsigned short Index, T Value) {

		Node* Current = GetNode(Index);

		if (Current == nullptr) return;


		Current->Value = Value;
	}

};


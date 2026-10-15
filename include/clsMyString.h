#pragma once
#include <iostream>
#include "clsMyStackArr.h"

using namespace std;

class clsMyString
{

private:

	clsMyStackArr <string> _Undo;
	clsMyStackArr <string> _Redo;


public:

	clsMyString() {
		_Undo.push("");
	}

	string GetValue() {
		return _Undo.Top();
	}

	void SetValue(string Value) {

		_Undo.push(Value);
	}

	__declspec(property(get = GetValue, put = SetValue)) string Value;

	void Undo() {

		if (_Undo.IsEmpty()) return;

		_Redo.push(_Undo.Top());
		_Undo.pop();
	}

	void Redo() {

		if (_Redo.IsEmpty()) return;

		_Undo.push(_Redo.Top());
		_Redo.pop();
	}



};


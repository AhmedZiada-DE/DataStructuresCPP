#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Output
{
private: 
	string path;
	bool result;
	T value;
public:
	Output(bool result, string path, T value): result(result), path(path), value(value){}
	void displayOutput() {
		cout << "Value is: " << value << endl;
		cout << "Result: " << result << endl;
		cout << "Path: " << path << endl << endl;
	}
};


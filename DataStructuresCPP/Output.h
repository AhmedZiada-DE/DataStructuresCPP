#pragma once
#include <iostream>
using namespace std;
class Output
{
private: 
	string path;
	bool result;
public:
	Output(bool result, string path): result(result), path(path){}
	void displayOutput() {
		cout << "Result: " << result << endl;
		cout << "Path: " << path << endl;
	}
};


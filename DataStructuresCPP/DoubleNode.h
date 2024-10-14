#pragma once
#include <iostream>
using namespace std;

template <typename T>
class DoubleNode
{
public:
	DoubleNode<T>* previous, *next;
	T value;
	DoubleNode(DoubleNode* previous, T value, DoubleNode* next):
		previous(previous), value(value), next(next){}

};


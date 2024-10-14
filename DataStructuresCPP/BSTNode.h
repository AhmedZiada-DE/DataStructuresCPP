#pragma once
#include <iostream>
using namespace std;

template <typename T>
class BSTNode
{
public:
	BSTNode<T>* left, * right;
	T value;
	BSTNode(T value): left(nullptr), value(value), right(nullptr){}
};


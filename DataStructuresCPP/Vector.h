#pragma once

#include <iostream>
using namespace std;

template <typename T>
class Vector
{
private:
	int size, capacity;
	T* arr;
	void expand() {
		capacity *= 2;
		T* temp = new T[capacity];
		for (int i = 0; i < size; i++) {
			temp[i] = arr[i];
		}
		delete[] arr;
		arr = temp;
	}
public:
	Vector() : size(0), capacity(2) {
		arr = new T[capacity];
	}
	bool isEmpty() {
		return size == 0;
	}
	bool isFull() {
		return size == capacity;
	}
	int getSize() {
		return size;
	}
	int getCapacity() {
		return capacity;
	}
	void push_back(T value) {
		arr[size] = value;
		size++;
		if (isFull()) {
			expand();
		}
	}
	void pop_back() {
		if(isEmpty()){
			return;
		}
		size--;
	}
	void push_front(T value) {
		if (isEmpty()) {
			push_back(value);
			return;
		}
		for (int i = size; i > 0; i--) {
			arr[i] = arr[i - 1];
		}
		arr[0] = value;
		size++;
		if (isFull()) {
			expand();
		}
	}
	void pop_front() {
		if (isEmpty()) {
			return;
		}
		for (int i = 0; i < size - 1; i++) {
			arr[i] = arr[i + 1];
		}
		size--;
	}
	T operator[](int index) {
		return arr[index];
	}
	//Copy constructor
	Vector(const Vector<T>& copy) {
		size = copy.size;
		capacity = copy.capacity;
		arr = new T[capacity]; 
		for (int i = 0; i < size; i++) {
			arr[i] = copy.arr[i];
		}
	}
	// we can delete the arr in the copy constructor
	//instead of using the operator=
	//since the equal operator uses the copy constructor
	void operator=(Vector copy) {
		delete[] arr;

		size = copy.size;
		capacity = copy.capacity;
		arr = new T[capacity];
		for (int i = 0; i < size; i++) {
			arr[i] = copy.arr[i];
		}
	}
	~Vector() {
		delete[] arr;
	}
};


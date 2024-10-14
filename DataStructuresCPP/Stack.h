#pragma once
#include <iostream>
using namespace std;
#include "Node.h"

template <typename T>
class Stack
{
private:
	Node<T>* head;
	void push_back(T value) {
		if (isEmpty()) {
			push(value);
			return;
		}
		auto ptr = head;
		while (ptr->next != nullptr) {
			ptr = ptr->next;
		}
		ptr->next = new Node<T>(value, nullptr);
	}
public:
	Stack(): head(nullptr){}
	bool isEmpty() {
		return head == nullptr;
	}
	void push(T value) {
		head = new Node<T>(value, head);
	}
	void pop() {
		if (isEmpty()) {
			return;
		}
		auto temp = head;
		head = head->next;
		delete temp;
	}
	Stack(const Stack& copy) {
		head = nullptr;
		auto ptr = copy.head;
		while (ptr != nullptr) {
			push_back(ptr->value);
			ptr = ptr->next;
		}
	}
	void operator=(Stack copy) {
		while (!isEmpty()) {
			pop();
		}
		head = nullptr;
		auto ptr = copy.head;
		while (ptr != nullptr) {
			push_back(ptr->value);
			ptr = ptr->next;
		}
	}
	T top() {
		return head->value;
	}
	void reverse() {
		Stack<T> rev;
		while (!isEmpty()) {
			rev.push(top());
			pop();
		}
		*this = rev;
	}
	~Stack() {
		while (!isEmpty()) {
			pop();
		}
	}
};


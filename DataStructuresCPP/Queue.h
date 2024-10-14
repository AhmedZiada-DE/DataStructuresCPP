#pragma once
#include <iostream>
using namespace std;
#include "DoubleNode.h"
#include <stack>

template <typename T>
class Queue
{
private:
	DoubleNode<T>* head, * tail;
public:
	Queue() : head(nullptr), tail(nullptr) {};
	bool isEmpty() {
		return head == nullptr;
	}
	void push(T value) {
		if (isEmpty()) {
			head = tail = new DoubleNode<T> (nullptr, value, nullptr);
			return;
		}
		tail = tail->next = new DoubleNode<T> (tail, value, nullptr);
	}
	void pop() {
		if (isEmpty()) {
			return;
		}
		if (head == tail) {
			delete head;
			head = tail = nullptr;
			return;
		}
		head = head->next;
		delete head->previous;
		head->previous = nullptr;
	}
	T front() {
		return head->value;
	}
	T back() {
		return tail->value;
	}
	Queue(const Queue<T>& copy) {
		head = tail = nullptr;
		auto ptr = copy.head;
		while (ptr != nullptr) {
			push(ptr->value);
			ptr = ptr->next;
		}
	}
	void operator=(Queue queue) {
		while (!isEmpty()) {
			pop();
		}
		head = tail = nullptr;
		auto ptr = queue.head;
		while (ptr != nullptr) {
			push(ptr->value);
			ptr = ptr->next;
		}
	}
	//Reverse queue using a stack
	void reverse() {
		stack<T> st;
		while (!isEmpty()) {
			st.push(front());
			pop();
		}
		while (!st.empty()) {
			push(st.top());
			st.pop();
		}
	}
	~Queue() {
		while (!isEmpty()) {
			pop();
		}
	}

};


#pragma once
#include "DoubleNode.h"

template <typename T>
class DoubleLinkedList
{
private:
	DoubleNode<T>* head, * tail;
public:
	DoubleLinkedList(): head(nullptr), tail(nullptr){}
	//isEmpty, push_front, pop_front, push_back, pop_back, Copy Constructor
	//Iterator, Operators overriding, Destructor
	bool isEmpty() {
		return head == nullptr;
	}
	void push_front(T value) {
		if (isEmpty()) {
			head = tail = new DoubleNode<T>(nullptr, value, nullptr);
			return;
		}
		head = head->previous = new DoubleNode<T>(nullptr, value, head);
	}
	void pop_front() {
		if (isEmpty()) {
			return;
		}
		if (head == tail) {
			delete tail;
			head = tail = nullptr;
			return;
		}
		head = head->next;
		delete head->previous;
		head->previous = nullptr;
	}
	void push_back(T value) {
		if (isEmpty()) {
			push_front(value);
			return;
		}
		tail = tail->next = new DoubleNode<T>(tail, value, nullptr);
	}
	void pop_back() {
		if (isEmpty()) {
			return;
		}
		if (head == tail) {
			delete tail;
			head = tail = nullptr;
			return;
		}
		tail = tail->previous;
		delete tail->next;
		tail->next = nullptr;
	}
	DoubleLinkedList(const DoubleLinkedList& copy) {
		head = tail = nullptr;
		auto ptr = copy.head;
		while (ptr != nullptr) {
			push_back(ptr->value);
			ptr = ptr->next;
		}
	}
	void operator=(const DoubleLinkedList& copy) {
		while (!isEmpty()) {
			pop_front();
		}
		auto ptr = copy.head;
		while (ptr != nullptr) {
			push_back(ptr->value);
			ptr = ptr->next;
		}
	}
	class Iterator {
	private:
		DoubleNode<T>* ptr;
	public:
		Iterator() : ptr(nullptr) {}
		Iterator(DoubleNode<T>* ptr) : ptr(ptr) {}
		void operator=(const Iterator& it) {
			ptr = it.ptr;
		}
		bool operator!=(Iterator it) {
			return ptr != it.ptr;
		}
		T operator*() {
			return ptr->value;
		}
		void operator++() {
			ptr = ptr->next;
		}
		void operator++(int) {
			ptr = ptr->next;
		}
		void operator--() {
			ptr = ptr->next;
		}
		void operator--(int) {
			ptr = ptr->previous;
		}
	};
	Iterator begin() {
		return Iterator(head);
	}
	Iterator before_end() {
		return Iterator(tail);
	}
	Iterator end() {
		return Iterator(nullptr);
	}
	~DoubleLinkedList() {
		while (!isEmpty()) {
			pop_front();
		}
	}
};


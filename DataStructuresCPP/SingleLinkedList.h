#pragma once
#include "Node.h"

template <typename T>
class SingleLinkedList
{
private:
	Node<T>* head;
public:
	SingleLinkedList(): head(nullptr){}

	bool isEmpty() {
		return head == nullptr;
	}
	void push_back(T value) {
		if (isEmpty()) {
			push_front(value);
			return;
		}
		auto ptr = head;
		while (ptr->next != nullptr) {
			ptr = ptr->next;
		}
		ptr->next = new Node<T> (value, nullptr);
	}
	void pop_back() {
		if (isEmpty()) {
			return;
		}
		auto ptr = head;
		while (ptr->next->next != nullptr) {
			ptr = ptr->next;
		}
		delete ptr->next;
		ptr->next = nullptr;
	}
	void push_front(T value) {
		head = new Node<T> (value, head);
	}
	void pop_front() {
		if (isEmpty()) {
			return;
		}
		auto temp = head;
		head = head->next;
		delete temp;
	}
	T operator[](int index) {
		auto ptr = head;
		for (int i = 0; i < index && ptr->next != nullptr; i++) {
			ptr = ptr->next;
		}
		return ptr->value;
	}
	SingleLinkedList(const SingleLinkedList& copyList) {
		head = nullptr;
		auto ptr = copyList.head;
		while (ptr != nullptr) {
			push_back(ptr->value);
			ptr = ptr->next;
		}
	}
	void operator=(SingleLinkedList copyList) {
		while (!isEmpty()) {
			pop_back();
		}
		auto ptr = copyList.head;
		while (ptr != nullptr) {
			push_back(ptr->value);
			ptr = ptr->next;
		}
	}
	class Iterator {
		private:
			Node<T>* ptr;
		public:
			Iterator(): ptr(ptr){}
			Iterator(Node<T>* ptr): ptr(ptr){}
			void operator=(const Iterator& it) {
				ptr = it.ptr;
			}
			bool operator!=(const Iterator& it) {
				return ptr != it.ptr;
			}
			void operator++() {
				ptr = ptr->next;
			}
			void operator++(int) {
				ptr = ptr->next;
			}
			T operator*() {
				return ptr->value;
			}
	};
	Iterator begin() {
		return Iterator(head);
	}
	Iterator end() {
		return Iterator(nullptr);
	}
	~SingleLinkedList() {
		while (!isEmpty()) {
			pop_front();
		}
	}

};

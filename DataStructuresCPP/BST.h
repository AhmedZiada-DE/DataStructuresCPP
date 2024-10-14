#pragma once
#include "BSTNode.h"
//Output class to trace the BST 
#include "Output.h"

template <typename T>
class BST
{
private:
	BSTNode<T>* root;
public:
	BST() : root(nullptr) {};
	bool isEmpty() {
		return root == nullptr;
	}
	//insert 
	Output insert(T value) {
		string path;
		path = "Root";
		if (isEmpty()) {
			root = new BSTNode<T>(value);
			return Output(true, path);
		}
		auto ptr = root;
		while (ptr->value != value) {
			if (value > ptr->value) {
				if (ptr->right == nullptr) {
					ptr->right = new BSTNode<T>(value);
					path += "->Right";
					return Output(true, path);
				}
				else {
					ptr = ptr->right;
					path += "->Right";
				}
			}
			else {
				if (value < ptr->value) {
					if (ptr->left == nullptr) {
						ptr->left = new BSTNode<T>(value);
						path += "->Left";
						return Output(true, path);
					}
					else {
						ptr = ptr->left;
						path += "->Left";
					}
				}
			}
		}
		return Output(false, path);
	}
	Output search(T value) {
		string path = "Root";
		if (isEmpty()) {
			return Output(false, path);
		}
		else {
			auto ptr = root;
			while (ptr != nullptr) {
				if (value > ptr->value) {
					ptr = ptr->right;
					path += "->Right";
				}
				else if (value < ptr->value) {
					ptr = ptr->left;
					path += "->Left";
				}
				else {
					return Output(true, path);
				}
			}
			return Output(false, path);
		}
	}
};


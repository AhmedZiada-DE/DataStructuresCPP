#pragma once
#include "BSTNode.h"
//Output class to trace the BST 
#include "Output.h"
#include <queue>

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
	Output<T> insert(T value) {
		string path;
		path = "Root";
		if (isEmpty()) {
			root = new BSTNode<T>(value);
			return Output<T> (true, path, value);
		}
		auto ptr = root;
		while (ptr->value != value) {
			if (value > ptr->value) {
				if (ptr->right == nullptr) {
					ptr->right = new BSTNode<T>(value);
					path += "->Right";
					return Output<T> (true, path, value);
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
						return Output<T> (true, path, value);
					}
					else {
						ptr = ptr->left;
						path += "->Left";
					}
				}
			}
		}
		return Output<T> (false, path, value);
	}
	Output<T> search(T value) {
		string path = "Root";
		if (isEmpty()) {
			return Output<T> (false, path, value);
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
					return Output<T> (true, path, value);
				}
			}
			return Output<T> (false, path, value);
		}
	}
	Output<T> erase(T value) {
		auto ptr = root;
		auto parent = ptr;
		string path = "Root";
		while (ptr != nullptr) {
			if (value > ptr->value) {
				parent = ptr;
				ptr = ptr->right;
				path += "->Right";
			}
			else if (value < ptr->value) {
				parent = ptr;
				ptr = ptr->left;
				path += "->Left";
			}
			else {
				if (ptr->left == nullptr && ptr->right == nullptr) {
					if (ptr->value == root->value) {
						delete root;
						root = nullptr;
						return Output<T> (true, path, value);
					}
					else {
						if (ptr == parent->right) {
							delete ptr;
							parent->right = nullptr;
							return Output<T> (true, path, value);
						}
						else {
							delete ptr;
							parent->left = nullptr;
							return Output<T> (true, path, value);
						}
					}
				}
				else if (ptr->left == nullptr || ptr->right == nullptr) {
					if (parent->right != nullptr) {
						parent->right = ptr->right;
						delete ptr;
						return Output<T>(true, path, value);
					}
					else {
						parent->left = ptr->left;
						delete ptr;
						return Output<T> (true, path, value);
					}
				}
				else {
					auto biggestLeft = ptr->left;
					while (biggestLeft->right != nullptr) {
						biggestLeft = biggestLeft->right;
					}
					ptr->value = biggestLeft->value;
					value = biggestLeft->value;
					parent = ptr;
					ptr = ptr->left;
					path += "->Left";
				}

			}
		}
	}
	void DFS(BSTNode<T>* ptr) {
		if (ptr == nullptr) {
			return;
		}
			cout << ptr->value << " ";
			DFS(ptr->left);
			DFS(ptr->right);
	}
	void displayDFS() {
		cout << "DFS: ";
		DFS(root);
		cout << endl;
	}

	void BFS() {
		queue<BSTNode<T>*> qBST;
		qBST.push(root);
		cout << "BFS: ";
		while (!qBST.empty()) {
			auto frontNode = qBST.front();
			if (frontNode->left != nullptr) {
				qBST.push(frontNode->left);
			}
			if (frontNode->right != nullptr) {
				qBST.push(frontNode->right);
			}
			cout << frontNode->value << " ";
			qBST.pop();
		}
		cout << endl;
	}

	void insertBST(BSTNode<T>* ptr) {
		if (ptr == nullptr) {
			return;
		}
		insert(ptr->value);
		insertBST(ptr->left);
		insertBST(ptr->right);
	}
	BST(const BST& copyBST) {
		root = nullptr;
		auto ptr = copyBST.root;
		insertBST(ptr);
	}

	void operator=(BST copyBST) {
		while (!isEmpty()) {
			erase(root->value);
		}
		auto ptr = copyBST.root;
		insertBST(ptr);
	}

	~BST() {
		while (!isEmpty()){
			erase(root->value);
		}
	}
};


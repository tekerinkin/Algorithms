#pragma once
#include <iostream>


template<typename T>
class BST {
public:
	BST() : root_(nullptr)
	{}

	~BST() {
		root_ = MakeEmpty(root_);
	}

	void Insert(T data) {
		root_ = Insert(data, root_);
	}

	void Remove(T data) {
		root_ = Remove(data, root_);
	}

	void Display() {
		InorderTraverse(root_);
		std::cout << std::endl;
	}

	void Search(T data) {
		root_ = Find(data, root_);
	}

private:
	struct Node {
		T data_;
		Node* left_;
		Node* right_;
	};

	Node* root_;

private:
	Node* MakeEmpty(Node* root); // Очищает дерево
	Node* Insert(T data, Node* root);
	Node* FindMin(Node* root);
	Node* FindMax(Node* root);
	Node* Remove(T data, Node* root);
	Node* Find(T data, Node* root);

	void InorderTraverse(Node* root);

};

template<typename T>
typename BST<T>::Node* BST<T>::MakeEmpty(Node* root)
{
	if(root == nullptr)
		return nullptr;
	MakeEmpty(root->left_);
	MakeEmpty(root->right_);
	delete root;

	return nullptr;
}

template<typename T>
typename BST<T>::Node* BST<T>::Insert(T data, Node* root)
{
	if(root == nullptr) {
		root = new Node;
		root->data_ = data;
		root->left_ = root->right_ = nullptr;
	}
	else if(data < root->data_)
		root->left = Insert(data, root->left);
	else if(data > root->data_)
		root->right_ = Insert(data, root->right_);
	return root;
}

template<typename T>
typename BST<T>::Node* BST<T>::FindMin(Node* root)
{
	if(!root)
		return nullptr;
	else if(root->left_ == nullptr)
		return root;
	return FindMin(root->left_);
}

template<typename T>
typename BST<T>::Node* BST<T>::FindMax(Node* root)
{
	if(!root)
		return nullptr;
	else if(root->right_ == nullptr)
		return root;
	return FindMax(root->right_);
}

template<typename T>
typename BST<T>::Node* BST<T>::Remove(T data, Node* root)
{
	Node* temp;
	if(!root)
		return nullptr;
	else if(data < root->data_)
		root->left_ = Remove(data, root->left_);
	else if(data > root->data_)
		root->right_ = Remove(data, root->right_);
	else if(root->left_ && root->right_) {
		temp = FindMin(root->right_);
		root->data_ = temp->data_;
		root->right_ = Remove(data, root->right_);
	} else {
		temp = root;
		if(root->left_ == nullptr)
			root = root->right_;
		else if(root->right_ == nullptr)
			root = root->left_;
		delete temp;
	}

	return root;
}

template<typename T>
void BST<T>::InorderTraverse(Node* root)
{
	if(!root)
		return;
	InorderTraverse(root->left_);
	std::cout << root->data_ << " ";
	InorderTraverse(root->right_);
}

template<typename T>
typename BST<T>::Node* BST<T>::Find(T data, Node* root) {
	if(!root)
		return nullptr;
	else if(data < root->data_)
		return Find(data, root->left_);
	else if(data > root->data_)
		return Find(data, root->right_);
	else
		return root;
}
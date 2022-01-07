#pragma once
#include <iostream>
#include "Nodo.h"
template <class T>
class AVL {
public:
	Node<T>* getRoot();
	int getN();
	void setN(int n);
	void setRoot(Node<T>* root);
	void insert(T x);
	void inorder();
	void remove(T x);
	Node<T>* removeUtil(Node<T>* head, T x);
private:
	Node<T>* root = NULL;
	int n; //dato
	int height(Node<T>* head);
	Node<T>* rightRotation(Node<T>* head);
	Node<T>* leftRotation(Node<T>* head);
	void inorderUtil(Node<T> *head);
	Node<T>* insertUtil(Node<T>*, T);

};
template <typename T>
Node<T>* AVL<T>::getRoot() {
	return root;
}
template <typename T>
int AVL<T>::getN() {
	return n;
}
template <typename T>
void AVL<T>::setRoot(Node<T>* root) {
	this->root = root;
}
template <typename T>
void AVL<T>::setN(int n) {
	this->n = n;
}
template <typename T>
void AVL<T>::insert(T x) {
	root = insertUtil(root, x);
}
template <typename T>
void AVL<T> ::inorder() {
	inorderUtil(root);
	//cout<<endl;
}
template <typename T>
void AVL<T> ::remove(T x) {
	root = removeUtil(root, x);
}
template <class T>
int AVL<T>::height(Node<T> *head)
{
	if (head == NULL) return 0;
	return head->getHeigth();
}
template <class T>
Node<T>* AVL<T>::rightRotation(Node<T>* head)
{
	Node<T>* newhead = head->getLeft();
	head->setLeft(newhead->getRigth());
	newhead->setRigth(head);
	head->setHeigth(1 + std::max(height(head->getLeft()), height(head->getRigth())));
	newhead->setHeigth(1 + std::max(height(newhead->getLeft()), height(newhead -> getRigth())));
return newhead;
}
template<class T>
Node<T>* AVL<T>::leftRotation(Node<T>* head)
{
	Node<T>* newhead = head->getRigth();
	head->setRigth(newhead->getLeft());
	newhead->setLeft(head);
	head->setHeigth(1 + std::max(height(head->getLeft()), height(head->getRigth())));
	newhead->setHeigth(1 + std::max(height(newhead->getLeft()), height(newhead -> getRigth())));
	return newhead;
}
template <class T>
void AVL<T>::inorderUtil(Node<T>* head)
{
	if (head == NULL) return;
	inorderUtil(head->getLeft());
	std::cout << head->getKey() << " ";
	inorderUtil(head->getRigth());
}
template <class T>
Node<T>* AVL<T>::insertUtil(Node<T>* head, T x)
{
	if (head == NULL) {
		n += 1;
		Node<T>* temp = new Node<T>(x);
		return temp;
	}
	if (x < head->getKey())
		head->setLeft(insertUtil(head->getLeft(), x));
	else if (x > head->getKey())
		head->setRigth(insertUtil(head->getRigth(), x));
	head->setHeigth(1 + std::max(height(head->getLeft()), height(head->getRigth())));
	int bal = height(head->getLeft()) - height(head->getRigth());
	if (bal > 1) {
		if (x < head->getLeft()->getKey()) {
			return rightRotation(head);
		}
		else {
			head->setLeft(leftRotation(head->getLeft()));
			return rightRotation(head);
		}
	}
	else if (bal < -1) {
		if (x > head->getRigth()->getKey()) {
			return leftRotation(head);
		}
		else {
			head->setRigth(rightRotation(head->getRigth()));
			return leftRotation(head);
		}
	}
	return head;
}
template <class T>
Node<T>* AVL <T> ::removeUtil(Node<T>* head, T x) {
	if (head == NULL) return NULL;
	if (x < head->getKey()) {
		head->setLeft(removeUtil(head->getLeft(), x));
	}
	else if (x > head->getKey()) {
		head->setRigth(removeUtil(head->getRigth(), x));
	}
	else {
		Node<T>* r = head->getRigth();
		if (head->getRigth() == NULL) {
			Node<T>* l = head->getLeft();
			delete(head);
			head = l;
		}
		else if (head->getLeft() == NULL) {
			delete(head);
			head = r;
		}
		else {
			while (r->getLeft() != NULL) r = r->getLeft();
			head->setKey(r->getKey());
		}
	}
	if (head == NULL) return head;
	head->setHeigth(1 + std::max(height(head->getLeft()), height(head->getRigth())));
	int bal = height(head->getLeft()) - height(head->getRigth());
	if (bal > 1) {
			if (x > head->getLeft()->getKey()) {
				return rightRotation(head);
			}
			else {
				head->setLeft(leftRotation(head->getLeft()));
			}
	}
	else if (bal < -1) {
		if (x < head->getRigth()->getKey()) {
			return leftRotation(head);
		}
		else {
			head->setRigth(rightRotation(head->getRigth()));
			return leftRotation(head);
		}
	}
	return head;
}

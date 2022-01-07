#pragma once
template<class T>
class Node
{
private:
	T key;
	int height;
	Node<T>* left;
	Node<T>* right;
public:
	Node<T>(T k);
	T getKey();
	int getHeigth();
	Node<T>* getLeft();
	Node<T>* getRigth();
	void setKey(T);
	void setHeigth(int);
	void setLeft(Node<T>*);
	void setRigth(Node<T>*);
};
template<class T>
Node<T>::Node(T k)
{
	this->height = 1;
	this->key = k;
	this->left = NULL;
	this->right = NULL;
}
template<class T>
T Node<T>::getKey() {
	return this
		->key;
}
template<class T>
int Node<T>::getHeigth() {
	return this
		->height;
}
template<class T>
Node<T>* Node<T>::getLeft() {
	return this
		->left;
}
template<class T>
Node<T>* Node<T>::getRigth() {
	return this
		->right;
}
template<class T>
void Node<T>::setKey(T key) {
	this
		->key = key;
}
template<class T>
void Node<T>::setHeigth(int h) {
	this
		->height = h;
}
template<class T>
void Node<T>::setLeft(Node<T>* L)
{
	this->left = L;
}
template<class T>
void Node<T>::setRigth(Node<T>* R)
{
	this->right = R;
}
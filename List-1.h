#include <iostream>
using namespace std;

class Node {
public:
	Node(int data){
		this->data = data;
		this->LeftChild = NULL;
		this->RightChild = NULL;
	};
	int data;
	Node* LeftChild;
	Node* RightChild;
};

class BST {
private:
	Node* root;

public:
	BST();
	Node* getRoot(){ return this->root; };
	void printTree(Node* root)
	{
		if (root == nullptr) {
			return; }
		printTree(root->LeftChild);
		printTree(root->RightChild);
		cout << root->data << " ";


	}
	Node* InsertNode(Node* root, int data)
	{
		if (root == nullptr)
		{
			Node* nn = new Node(data);
			root = nn;
			return root;
		}
		if (data < root->data)
		{
			root->LeftChild = InsertNode(root->LeftChild, data);
		}
		else
		{
			root->RightChild = InsertNode(root->RightChild, data);
		}
		return root;
	}
	bool FindNode(Node* root, int data)
	{
		if (root == nullptr || root->data == data)
			return root;
		else if (root->data < data)
			return FindNode(root->RightChild, data);
		else if (root->data > data)
			return FindNode(root->LeftChild, data);
	}
	int Largest(Node* root)
	{
		while (root->RightChild != nullptr)
		{
			root = root->RightChild;
		}
		return root->data;
	}
};

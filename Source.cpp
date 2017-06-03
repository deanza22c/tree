#include <iostream>
#include <string>

using namespace std;

/*
	THIS PROGRAM IS A SIMPLE BINARY SEARCH TREE
	//if data values are the same, the root will be saved to the left
*/

template <class T>
struct BstNode {
	T data;
	BstNode* left;
	BstNode* right;
};

template <class T>
class BstRoot{
private:

	BstNode<T>* root = NULL;

public:

	BstRoot(){
	}

	BstNode<T>* getNewNode(int data){
		BstNode<T>* newNode = new BstNode<T>();
		newNode->data = data;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}

	void insert(int data) {
		if (root == NULL){
			root = getNewNode(data);
		}
		//if data values are the same, the root will be saved to the left
		else if (data <= root->data){
			root->left = insert(data, root->left);
		}
		else {
			root->right = insert(data, root->right);
		}
	}
	BstNode<T>* insert(int data, BstNode<T>* root) {
		if (root == NULL){
			root = getNewNode(data);
		}
		//if data values are the same, the root will be saved to the left
		else if (data <= root->data){
			root->left = insert(data, root->left);
		}
		else {
			root->right = insert(data, root->right);
		}
		return root;
	}

	bool search(int data) {
		if (root == NULL) return false;
		else if (root->data == data) return true;
		else if (data <= root->data) return search(data, root->left);
		else return search(data, root->right);
	}
	bool search(int data, BstNode<T>* root) {
		if (root == NULL) return false;
		else if (root->data == data) return true;
		else if (data <= root->data) return search(data, root->left);
		else return search(data, root->right);
	}
};

int main(){
	BstRoot<int> root; //pointer stores the address of root node
	root.insert(12);
	root.insert(1);
	root.insert(2);
	root.insert(15);
	root.insert(2);
	root.insert(4);
	root.insert(100);


	int number = 0;
	while (number != -1){
		cout << "Enter a positive number to be searched, enter -1 to exit: \n";
		cin >> number;
		if (root.search(number) == true) cout << "Found\n\n";
		else cout << "Not Found\n\n";
	}

	return 0;
}
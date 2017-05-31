#include <iostream>
#include <string>

using namespace std;

/*
	THIS PROGRAM IS A SIMPLE BINARY SEARCH TREE
	//if data values are the same, the root will be saved to the left
*/

struct BstNode {
	int data;
	BstNode* left;
	BstNode* right;
};

BstNode* getNewNode(int data){
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

BstNode* Insert(BstNode* root, int data) {
	if (root == NULL){
		root = getNewNode(data);
	}
	//if data values are the same, the root will be saved to the left
	else if (data <= root->data){
		root->left = Insert(root->left, data);
	}
	else {
		root->right = Insert(root->right, data);
	}
	//root must be returned, this root is currently out of scope
	return root;
}

bool Search(BstNode* root, int data) {
	if (root == NULL) return false3;
	else if (root->data == data) return true;
	else if (data <= root->data) return Search(root->left, data);
	else return Search(root->right, data);
}



int main(){
	BstNode* root = NULL; //pointer stores the address of root node
	root = Insert(root, 12);
	root = Insert(root, 1);
	root = Insert(root, 2);
	root = Insert(root, 15);
	root = Insert(root, 2);
	root = Insert(root, 4);
	root = Insert(root, 100);


	int number = 0;
	while (number != -1){
		cout << "Enter a positive number to be searched, enter -1 to exit: \n";
		cin >> number;
		if (Search(root, number) == true) cout << "Found\n\n";
		else cout << "Not Found\n\n";
	}

	return 0;
}
#include<iostream>
#include<string>
#include"LinkedList.h"
#include"QueueADT.h"
#include"Currency.h"

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


	void levelOrder() {
		if (root == NULL) return;
		
		QueueADT<BstNode<T>*> Q;
		Q.enQueue(root);
		//while there is at least one discovered node
		while (!Q.isQueueEmpty()){
			BstNode<T>* current = Q.getFront();
			cout << current->data << " ";
			if (current->left != NULL) Q.enQueue(current->left);
			if (current->right != NULL) Q.enQueue(current->right);
			Q.deQueue(); // remove the element at the front
		}
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

	root.levelOrder();

	int number = 0;
	while (number != -1){
		cout << "Enter a positive number to be searched, enter -1 to exit: \n";
		cin >> number;
		if (root.search(number) == true) cout << "Found\n\n";
		else cout << "Not Found\n\n";
	}

	return 0;
}


		/*
		QueueADT<string> queuedList;
		LinkedList<double> testList;
		QueueADT<Currency> currencyQueue;
		testList.push_first(11);
		testList.push_first(7);
		testList.push_first(5);
		testList.push_first(3);
		testList.push_first(1);
		testList.displayList();
		cout << "\ninsert '2.2' at posistion 3";
		testList.insert_node(2.2, 3);
		cout << endl;
		testList.displayList();
		cout << "\ndeleting 2.2\n";
		testList.deleteNode(2.2);
		testList.displayList();
		cout << "\ndeleting 11 and 1\n";
		testList.deleteNode(11);
		testList.deleteNode(1);
		testList.displayList();
		cout << "\nfirst returns: " << testList.getFirst() << endl;
		cout << "last returns: " << testList.getLast() << endl;
		cout << "getIndex(0) returns: " << testList.getIndex(0) << endl;
		cout << "getIndex(1) returns: " << testList.getIndex(1) << endl;
		cout << "getIndex(2) returns: " << testList.getIndex(2) << endl;
		cout << "empty the list\n";
		testList.emptyList();
		cout << "display the list\n";
		testList.displayList();
		//cout << "getIndex(4) returns: " << testList.getIndex(4) << endl;  // don't go out of bounds
		//string x;
		//double x;
		//testList.top(x);
		//cout << "\n\n";
		//testList.printLast();
		//cout << "\n\n" << x;
		LinkedList<string> strList;
		strList.push_first("one");
		strList.push_first("three");
		strList.push_first("five");
		strList.push_first("seven");
		strList.push_first("eleven");
		cout << endl << endl;
		strList.displayList();
		cout << endl;
		cout << "\npop first\n";
		strList.pop_first();
		strList.displayList();
		cout << endl;
		cout << "\npop last\n";
		strList.pop_last();
		strList.displayList();
		cout << endl;
		//string y;
		//strList.top(y);
		cout << "getFirst() returns: " << strList.getFirst() << endl;
		cout << "search for seven returns: " << strList.searchNodes("seven") << endl;
		cout << "search for five returns: " << strList.searchNodes("five") << endl;
		cout << "search for eleven returns: " << strList.searchNodes("eleven") << endl;
		LinkedList<string> str2List;
		cout << endl;
		str2List.displayList();
		cout << endl << endl << endl;
		cout << "enqueue 'one' and 'two'" << endl;
		queuedList.enQueue("one");
		queuedList.enQueue("two");
		cout << "display queue:" << endl;
		queuedList.displayQueue();
		cout << "\nenqueue 'three' and 'four'" << endl;
		queuedList.enQueue("three");
		queuedList.enQueue("four");
		cout << "display queue:" << endl;
		queuedList.displayQueue();
		cout << "\nenqueue 'five'" << endl;
		queuedList.enQueue("five");
		cout << "display queue:" << endl;
		queuedList.displayQueue();
		cout << "\ndequeue one item" << endl;
		queuedList.deQueue();
		cout << "display queue" << endl;
		queuedList.displayQueue();
		cout << "\ndequeue one item" << endl;
		queuedList.deQueue();
		cout << "display queue" << endl;
		queuedList.displayQueue();
		cout << endl << "front returns: ";
		queuedList.printFront();
		cout << endl << "rear returns: ";
		queuedList.printRear();
		cout << endl;
		Currency currency1("Dollar", "Cent", 12, 55);
		Currency currency2("Euro", "Pence", 2, 78);
		Currency currency3("Peso", "Cento", 5, 97);
		Currency currency4("Ruble", "Kopecks", 43, 15);
		currencyQueue.enQueue(currency1);
		currencyQueue.enQueue(currency2);
		currencyQueue.enQueue(currency3);
		currencyQueue.enQueue(currency4);
		currencyQueue.displayQueue();
		//int xyz;
		//cout << endl << xyz;
		cout << "\n\npress <Enter> to exit the program...";
		cin.get();
		*/








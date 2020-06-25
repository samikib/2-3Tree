#ifndef __NODE_H
#define __NODE_H

#include <string>
#include <iostream>

using namespace std;

class Node {

	friend class Tree;

private:
	string small;
	string large;

	bool empty;

	Node* left;
	Node* middle;
	Node* right;
	Node* parent;

	// Add additional functions/variables here. Remember, you may not add any
	// Node * or string variables.
public:
	Node(string dat);

	//adds a data element to a 1-node
	void make2Node(string dat);
	//removes a data element from 2-Node
	void make1Node(string dat);
	// removes all data from a node
	void makeEmpty();
	//adds one data element to a empty node
	void makeNotEmpty(string dat);
	// dat = value to be swapped in, replace = value to be replaced
	void swapNode(string replace, string dat);

	bool children(); // returns true if there are no children
	bool TwoNode(); // returns true if node is a 2-node
	bool isEmpty(); //returns true if he node is empty
	bool validNode();
};

#endif

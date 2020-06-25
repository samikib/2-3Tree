#ifndef __TREE_H
#define __TREE_H

#include "Node.h"

class Tree {
private:
	Node* root;

public:
	Tree();
	//~Tree();
	void insert(const string&);
	void preOrder() const;
	void inOrder() const;
	void postOrder() const;
	void remove(const string&); //fix
	bool search(const string&) const;

private:
	// checks that every node is okay
	bool validateTree(Node* curr);

	// Add additional functions/variables here
	void preOrder(Node* curr) const;
	void inOrder(Node* curr) const;
	void postOrder(Node* curr) const;

	//returns the node that contains data element
	Node* find(const string& dat) const;
	//curr= root of subtree where 1st in inorder is successor
	Node* successor(Node* curr);

	//recurrsive insert
	void insert(Node* curr, Node* in);
	//splits a 2-node into a parent with respective child subtrees given the node to be inserted
	Node* splitNode(Node* inserting, Node* curr);
	//split on leaf
	Node* splitNode(const string& dat, Node* curr);

	//Node that is a hole(empty after deletion) returns parent (becomes a hole in 1-node case) only called on leaves
	void merge(Node* hole, bool ranMerge);
	//Node that is a hole(empty after deletion)
	void redistribute(Node* hole);
	//Node that is a hole(empty after deletion) returns parent (becomes a hole in 1-node case) only called on leaves
	void mergeLeaf(Node* hole, bool ranMerge);
	//Node that is a hole(empty after deletion)
	void redistributeLeaf(Node* hole);
	void fix(Node* hole);
	

};

#endif

#include "Tree.h"

Tree::Tree()
{
	root = nullptr;
}

void Tree::insert(const string& dat)
{
	if (root == nullptr)
	{
		root = new Node(dat);
		return;
	}

	Node* curr = root;

	while (curr != nullptr)
	{		

		if (dat < curr->small)
		{
			if (curr->left == nullptr)
			{
				if (!curr->TwoNode())
				{
					curr->make2Node(dat);
				}
				else
				{
					Node* temp = new Node(dat);
					insert(curr, temp);
				}
				return;
			}
			else
			{
				curr = curr->left;
			}
		}
		else if (dat  < curr-> large)
		{
			if (curr->middle == nullptr)
			{
				if (!curr->TwoNode())
				{
					curr->make2Node(dat);

				}
				else
				{
					Node* temp = new Node(dat);
					insert(curr, temp);
				}
				return;
			}
			else
			{
				curr = curr->middle;
			}
		}
		else
		{
			if (curr->right == nullptr)
			{
				if (!curr->TwoNode())
				{
					curr->make2Node(dat);
				}
				else
				{
					Node* temp = new Node(dat);
					insert(curr, temp);
				}
				return;
			}
			else
			{
				curr = curr->right;
			}
		}
	}

	//validateTree(root);
}

void Tree::insert(Node* curr, Node* in)
{
	Node* temp;

	if (curr->children())
	{
		temp = splitNode(in->small, curr);
		if (curr == root)
		{
			root = temp;
		}
		else
		{
			insert(curr->parent, temp);
		}
		
	}
	else
	{
		if (!curr->TwoNode())
		{
			curr->make2Node(in->small);
			if (in->small > curr->small)
			{
				curr->middle = in->left;
				curr->middle->parent = curr;

				curr->right = in->right;
				curr->right->parent = curr;
			}
			else
			{
				curr->middle = in->right;
				curr->middle->parent = curr;

				curr->left = in->left;
				curr->left->parent = curr;
			}
		}
		else
		{

			temp = splitNode(in, curr);
			if (curr == root)
			{
				root = temp;
			}
			else
			{
				insert(curr->parent, temp);
			}
			
		}
	}
}

Node* Tree::splitNode(Node* inserting, Node* curr)
{
	string s, m, l;

	if (inserting->small < curr->small)
	{
		s = inserting->small;
		m = curr->small;
		l = curr->large;
	}
	else if (inserting->small < curr->large)
	{
		s = curr->small;
		m = inserting->small;
		l = curr->large;
	}
	else
	{
		s = curr->small;
		m = curr->large;
		l = inserting->small;
	}

	Node* par = new Node(m);
	Node* tempL = new Node(s);
	Node*tempR = new Node(l);

	if (inserting->small < curr->small)
	{
		tempL->left = inserting->left;
		tempL->middle = inserting->middle;
		tempL->right = inserting->right;

		inserting->left->parent = tempL;
		inserting->right->parent = tempL;

		tempR->left = curr->middle;
		tempR->right = curr->right;

		curr->middle->parent = tempR;
		curr->right->parent = tempR;

	}

	else if (inserting->small < curr->large)
	{
		tempL->left = curr->left;
		tempL->right = inserting->left;

		tempL->left->parent = tempL;
		tempL->right->parent = tempL;

		tempR->left = inserting->right;
		tempR->right = curr->right;

		tempR->left->parent = tempR;
		tempR->right->parent = tempR;

	}
	
	else
	{
		tempR->left = inserting->left;
		tempR->middle = inserting->middle;
		tempR->right = inserting->right;

		inserting->left->parent = tempR;
		inserting->right->parent = tempR;

		tempL->left = curr->left;
		tempL->right = curr->middle;

		curr->middle->parent = tempL;
		curr->right->parent = tempL;
	}

	par->left = tempL;
	tempL->parent = par;

	par->right = tempR;
	tempR->parent = par;

	return par;
}

Node* Tree::splitNode(const string& dat, Node* curr)
{
	string s, m, l;

	if (dat < curr->small)
	{
		s = dat;
		m = curr->small;
		l = curr->large;
	}
	else if (dat < curr->large)
	{
		s = curr->small;
		m = dat;
		l = curr->large;
	}
	else
	{
		s = curr->small;
		m = curr->large;
		l = dat;
	}

	Node* par = new Node(m);
	Node* tempL = new Node(s);
	Node* tempR = new Node(l);

	par->left = tempL;
	tempL->parent = par;

	par->right = tempR;
	tempR->parent = par;

	return par;
}

void Tree::preOrder() const
{
	preOrder(root);
}

void Tree::inOrder() const
{
	inOrder(root);
}

void Tree::postOrder() const
{
	postOrder(root);
}

void Tree::preOrder(Node* curr) const
{
	if (curr != nullptr)
	{
		if (curr->TwoNode())
		{
			cout << curr->small << ", ";
			preOrder(curr->left);
			cout << curr->large << ", ";
			preOrder(curr->middle);
			preOrder(curr->right);
		}
		else
		{
			cout << curr->small << ", ";
			preOrder(curr->left);
			preOrder(curr->right);
		}
		
	}
	else
	{
		return;
	}
}

void Tree::inOrder(Node* curr) const
{
	if (curr != nullptr)
	{
		if (curr->TwoNode())
		{
			inOrder(curr->left);
			cout << curr->small << ", ";
			inOrder(curr->middle);
			cout << curr->large << ", ";
			inOrder(curr->right);
		}
		else
		{
			inOrder(curr->left);
			cout << curr->small << ", ";
			inOrder(curr->right);
		}
	}
	else
	{
		return;
	}
}

void Tree::postOrder(Node* curr) const
{
	if (curr != nullptr)
	{
		if (curr->TwoNode())
		{
			postOrder(curr->left);
			postOrder(curr->middle);
			cout << curr->small << ", ";
			postOrder(curr->right);
			cout << curr->large << ", ";
		}
		else
		{
			postOrder(curr->left);
			postOrder(curr->right);
			cout << curr->small << ", ";			
		}


	}
	else
	{
		return;
	}
}

Node* Tree::successor(Node* curr)
{
	Node* inS = curr;

	while (!inS->children())
	{
		inS = inS->left;
	}

	return inS;
}

bool Tree::search(const string& dat) const
{
	return (find(dat) != nullptr);
}

Node* Tree::find(const string& dat) const
{
	Node* curr = root;

	while (curr != nullptr)
	{
		if (dat < curr->small)
		{
			curr = curr->left;
		}
		else if (dat == curr->small)
		{
			return curr;
		}
		else if (dat < curr->large)
		{
			curr = curr->middle;
		}
		else if (dat == curr->large)
		{
			return curr;
		}
		else if (dat > curr->large)
		{
			curr = curr->right;
		}	
	}
	return nullptr;
}

bool Tree::validateTree(Node* curr)
{
	if (curr != nullptr)
	{
		if (!curr->validNode())
		{
			cout << " small: " << curr->small << " large: " << curr->large;
			return false;
		}
		else
		{
			return true;
		}
		validateTree(curr->left);
		validateTree(curr->middle);
		validateTree(curr->right);
	}
	else
	{
		return true;
	}
}

void Tree::remove(const string& dat)
{
	Node* curr;
	curr = find(dat);

	if (curr != nullptr)
	{
		if (curr==root && root->children())
		{
			if (root->TwoNode())
			{
				root->make1Node(dat);
			}
			else
			{
				root = nullptr;
			}
			return;
		}
		else
		{
			if (!curr->children())
			{
				Node* inS;

				if (curr->TwoNode())
				{
					if (curr->small == dat)
					{
						inS = successor(curr->middle);
					}
					else
					{
						inS = successor(curr->right);
					}
					
				}
				else
				{
					inS = successor(curr->right);
				}
				
				curr->swapNode(dat, inS->small);
				if (inS->TwoNode())
				{
					inS->make1Node(inS->small);
				}
				else
				{
					inS->makeEmpty();
				}
				curr = inS;
			}

			else
			{
				if (curr->TwoNode())
				{
					curr->make1Node(dat);
				}
				else
				{
					curr->makeEmpty();
				}
			}

			fix(curr);
		}
		
	}

	validateTree(root);
}

void Tree::merge(Node* hole, bool ranMerge)
{
	Node* par = hole->parent;

	if (par->TwoNode())
	{
		if (par->left == hole && !par->middle->TwoNode()&& !par->right->TwoNode())
		{
			hole->makeNotEmpty(par->small);
			par->make1Node(par->small);
			hole->make2Node(par->middle->small);
			hole->middle = par->middle->left;
			hole->middle->parent = hole;
			hole->right = par->middle->right;
			hole->right->parent = hole;
			par->middle = nullptr;
			ranMerge = true;
		}
		if (par->right == hole && !par->middle->TwoNode() && !par->left->TwoNode())
		{
			hole->makeNotEmpty(par->large);
			par->make1Node(par->large);
			hole->make2Node(par->middle->small);
			par->middle->makeEmpty();
			hole->right = hole->left;
			hole->middle = par->middle->right;
			hole->middle->parent = hole;
			hole->left = par->middle->left;
			hole->left->parent = hole;
			par->middle = nullptr;
			ranMerge = true;
		}
		if (par->middle == hole && !par->left->TwoNode() && !par->right->TwoNode())
		{
			par->left->make2Node(par->small);
			par->make1Node(par->small);
			par->left->middle = par->left->right;
			par->left->right = hole->left;
			par->left->right->parent = par->left;
			par->middle = nullptr;
			ranMerge = true;
		}
	}
	else
	{
		if (par->left == hole && !par->right->TwoNode())
		{
			hole->makeNotEmpty(par->small);
			par->makeEmpty();
			par->makeNotEmpty(par->right->small);
			hole->make2Node(par->small);
			hole->middle = par->right->left;
			hole->middle->parent = hole;
			hole->right = par->right->right;
			hole->right->parent = hole;
			par->right = nullptr;
			ranMerge = true;
		}
		if (par->right == hole && !par->left->TwoNode())
		{
			par->left->make2Node(par->small);
			par->makeEmpty();
			par->left->right = hole->left;
			par->left->right->parent = par->left;
			par->right = nullptr;
			ranMerge = true;
		}
	}
}

void Tree::redistribute(Node* hole)
{
	Node* par = hole->parent;
	if (par->TwoNode())
	{
		if (par->left == hole)
		{
			if (par->middle->TwoNode())
			{
				hole->makeNotEmpty(par->small);
				par->make1Node(par->small);
				par->make2Node(par->middle->small);
				par->middle->make1Node(par->middle->small);
				hole->right = par->middle->left;
				hole->right->parent = hole;
				par->middle->left = par->middle->middle;
				par->middle->middle = nullptr;
			}
			if (!par->middle->TwoNode()&& par->right->TwoNode())
			{
				hole->makeNotEmpty(par->small);
				par->make1Node(par->small);
				par->make2Node(par->middle->small);
				par->middle->makeEmpty();
				par->middle->makeNotEmpty(par->large);
				par->make1Node(par->large);
				par->make2Node(par->right->small);
				par->right->make1Node(par->right->small);
				hole->right = par->middle->left;
				hole->right->parent = hole;
				par->middle->left = par->middle->right;
				par->middle->right = par->right->left;
				par->middle->right->parent = par->middle;
				par->right->left = par->right->middle;
				par->right->middle = nullptr;
			}
		}
		if (par->right == hole)
		{
			if (par->middle->TwoNode())
			{
				hole->makeNotEmpty(par->large);
				par->make1Node(par->large);
				par->make2Node(par->middle->large);
				par->middle->make1Node(par->middle->large);
				hole->right = hole->left;
				hole->left = par->middle->right;
				hole->left->parent = hole;
				par->middle->right = par->middle->middle;
				par->middle->right->parent = par->middle;
				par->middle->middle = nullptr;
			}
			if (!par->middle->TwoNode() && par->left->TwoNode())
			{
				hole->makeNotEmpty(par->large);
				par->make1Node(par->large);
				par->make2Node(par->middle->large);
				par->middle->makeEmpty();
				par->middle->makeNotEmpty(par->small);
				par->make1Node(par->small);
				par->make2Node(par->left->large);
				par->left->make1Node(par->left->large);
				hole->right = hole->left;
				hole->left = par->middle->right;
				hole->left->parent = hole;
				par->middle->right = par->middle->left;
				par->middle->left = par->left->right;
				par->middle->left->parent = par->middle;
				par->left->right = par->left->middle;
				par->left->middle = nullptr;
			}
		}
		if (par->middle == hole)
		{
			if (par->right->TwoNode())
			{
				hole->makeNotEmpty(par->large);
				par->make1Node(par->large);
				par->make2Node(par->right->small);
				par->right->make1Node(par->right->small);
				hole->right = par->right->left;
				hole->right->parent = hole;
				par->right->left = par->right->middle;
				par->right->middle = nullptr;

			}
			if (!par->right->TwoNode() && par->left->TwoNode())
			{
				hole->makeNotEmpty(par->small);
				par->make1Node(par->small);
				par->make2Node(par->left->large);
				par->left->make1Node(par->left->large);
				hole->right = hole->left;
				hole->left = par->left->right;
				hole->left->parent = hole;
				par->left->right = par->left->middle;
				par->left->middle = nullptr;
			}
		}
	}

	else
	{
		if (par->left == hole)
		{
			if (par->right->TwoNode())
			{
				hole->makeNotEmpty(par->small);
				par->makeEmpty();
				par->makeNotEmpty(par->right->small);
				par->right->make1Node(par->right->small);
				hole->right = par->right->left;
				hole->right->parent = hole;
				par->right->left = par->right->middle;
				par->right->middle = nullptr;
			}
		}
		if (par->right == hole)
		{
			if (par->left->TwoNode())
			{
				hole->makeNotEmpty(par->small);
				par->makeEmpty();
				par->makeNotEmpty(par->left->large);
				par->left->make1Node(par->left->large);
				hole->right = hole->left;
				hole->left = par->left->right;
				hole->left->parent = hole;
				par->left->right = par->left->middle;
				par->left->middle = nullptr;
			}
		}
	}
}

void Tree::mergeLeaf(Node* hole, bool ranMerge)
{
	Node* par = hole->parent;

	if (par->TwoNode())
	{
		if (par->left == hole && !par->middle->TwoNode() && !par->right->TwoNode())
		{
			hole->makeNotEmpty(par->small);
			par->make1Node(par->small);
			hole->make2Node(par->middle->small);
			par->middle = nullptr;
			ranMerge = true;
		}
		if (par->right == hole && !par->middle->TwoNode() && !par->left->TwoNode())
		{
			hole->makeNotEmpty(par->large);
			par->make1Node(par->large);
			hole->make2Node(par->middle->small);
			par->middle = nullptr;
			ranMerge = true;
		}
		if (par->middle == hole && !par->left->TwoNode() && !par->right->TwoNode())
		{
			par->left->make2Node(par->small);
			par->make1Node(par->small);
			par->middle = nullptr;
			ranMerge = true;
		}
	}
	else
	{
		if (par->left == hole && !par->right->TwoNode())
		{
			hole->makeNotEmpty(par->small);
			par->makeEmpty();
			par->makeNotEmpty(par->right->small);
			hole->make2Node(par->small);
			ranMerge = true;
		}
		if (par->right == hole && !par->left->TwoNode())
		{
			par->left->make2Node(par->small);
			par->makeEmpty();
			ranMerge = true;
		}
	}
}

void Tree::redistributeLeaf(Node* hole)
{
	Node* par = hole->parent;
	if (par->TwoNode())
	{
		if (par->left == hole)
		{
			if (par->middle->TwoNode())
			{
				hole->makeNotEmpty(par->small);
				par->make1Node(par->small);
				par->make2Node(par->middle->small);
				par->middle->make1Node(par->middle->small);
			}
			else if (!par->middle->TwoNode() && par->right->TwoNode())
			{
				hole->makeNotEmpty(par->small);
				par->make1Node(par->small);
				par->make2Node(par->middle->small);
				par->middle->makeEmpty();
				par->middle->makeNotEmpty(par->large);
				par->make1Node(par->large);
				par->make2Node(par->right->small);
				par->right->make1Node(par->right->small);
			}
		}
		if (par->right == hole)
		{
			if (par->middle->TwoNode())
			{
				hole->makeNotEmpty(par->large);
				par->make1Node(par->large);
				par->make2Node(par->middle->large);
				par->middle->make1Node(par->middle->large);
			}
			else if (!par->middle->TwoNode() && par->left->TwoNode())
			{
				hole->makeNotEmpty(par->large);
				par->make1Node(par->large);
				par->make2Node(par->middle->small);
				par->middle->makeEmpty();
				par->middle->makeNotEmpty(par->small);
				par->make1Node(par->small);
				par->make2Node(par->left->large);
				par->left->make1Node(par->left->large);
			}
		}
		if (par->middle == hole)
		{
			if (par->right->TwoNode())
			{
				hole->makeNotEmpty(par->large);
				par->make1Node(par->large);
				par->make2Node(par->right->small);
				par->right->make1Node(par->right->small);

			}
			if (!par->right->TwoNode() && par->left->TwoNode())
			{
				hole->makeNotEmpty(par->small);
				par->make1Node(par->small);
				par->make2Node(par->left->large);
				par->left->make1Node(par->left->large);
			}
		}
	}

	else
	{
		if (par->left == hole)
		{
			if (par->right->TwoNode())
			{
				hole->makeNotEmpty(par->small);
				par->makeEmpty();
				par->makeNotEmpty(par->right->small);
				par->right->make1Node(par->right->small);
			}
		}
		if (par->right == hole)
		{
			if (par->left->TwoNode())
			{
				hole->makeNotEmpty(par->small);
				par->makeEmpty();
				par->makeNotEmpty(par->left->large);
				par->left->make1Node(par->left->large);
			}
		}
	}
}

void Tree::fix(Node* hole)
{
	bool ranMerge = false;
	if (hole == root && hole->isEmpty())
	{
		root = root->left;
		root->parent = nullptr;
		return;
	}
	if (hole->isEmpty())
	{
		if (hole->children())
		{
			mergeLeaf(hole, ranMerge);
			if (!ranMerge)
			{
				redistributeLeaf(hole);
			}
		}
		else
		{
			merge(hole, ranMerge);
			if (!ranMerge)
			{
				redistribute(hole);
			}
		}
		fix(hole->parent);
	}
	else
	{
		return;
	}
}
#include "Node.h"

Node::Node(string dat)
{
	small = dat;
	large = "";

	empty = false;

	left = nullptr;
	middle = nullptr;
	right = nullptr;
	parent = nullptr;
}


void Node::make2Node(string dat)
{
	empty = false;

	if (dat > small)
	{
		large = dat;
	}
	else
	{
		large = small;
		small = dat;
	}
}

void Node::make1Node(string dat)
{
	empty = false;

	if (dat == small)
	{
		small = large;
		large = "";
	}

	if (dat == large)
	{
		large = "";
	}
}

void Node::makeEmpty()
{
	small = "";
	large = "";

	empty = true;

}

void Node::makeNotEmpty(string dat)
{
	small = dat;
	empty = false;
}

void Node::swapNode(string replace, string dat)
{
	if (TwoNode())
	{
		make1Node(replace);
		make2Node(dat);
	}
	else
	{
		small = dat;
	}
	
}

bool Node::children()
{
	if (left == nullptr && middle == nullptr && right == nullptr)
	{
		return true;
	}

	else
	{
		return false;
	}
}

bool Node::TwoNode()
{
	if (small != "" && large != "")
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Node::isEmpty()
{
	return empty;
}

bool Node::validNode()
{
	if (children())
	{
		if (small != "" && large != "")
		{
			return true;
		}

	}
	else
	{
		if (TwoNode())
		{
			if (left != nullptr && middle != nullptr && right != nullptr)
			{
				return true;
			}
		}
		else
		{
			if (left != nullptr && right != nullptr && middle == nullptr)
			{
				return true;
			}
		}
	}

	return false;
}
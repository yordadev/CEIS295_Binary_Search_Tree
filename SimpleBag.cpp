#include <iostream>
#include "SimpleBag.h"
#include <sstream>

using namespace std;

SimpleBag::SimpleBag()
{
	root = NULL;
}

SimpleBag::~SimpleBag()
{
	deallocateMemory(root);
}

bool SimpleBag::isEmpty()
{
	return root == NULL;
}

void SimpleBag::print()
{
	bool exit = false;
	string aString = "";

	while (!exit) {
		concat_tree(root, aString, exit);
	}

	aString.pop_back();
	cout << aString << endl;
}

void SimpleBag::clear()
{
	deallocateMemory(root);
}

void SimpleBag::add(int value)
{
	add(value, root);
}

int SimpleBag::count(int value)
{
	int found = 0;
	count(value, found, root);
	return found;
}

void SimpleBag::deallocateMemory(TreeNode*& p)
{
	if (p != NULL)
	{
		deallocateMemory(p->left);
		deallocateMemory(p->right);

		delete p;

		p = NULL;
	}
}

void SimpleBag::concat_tree(TreeNode* p, std::string& aString, bool& exit)
{
	if (p != NULL) {

		int info = p->info;

		std::string element;
		std::stringstream convertToString;
		convertToString << info;
		element = convertToString.str();

		aString = element + "," + aString;

		concat_tree(p->left, aString, exit);
		concat_tree(p->right, aString, exit);
	}
	exit = true;
}

void SimpleBag::add(int value, TreeNode*& p)
{
	if (p == NULL)
	{
		p = new TreeNode;
		p->info = value;
		p->left = p->right = NULL;
	}
	else
	{
		if (value <= p->info) add(value, p->left);
		else add(value, p->right);
	}
}

void SimpleBag::count(int value, int& found, TreeNode* p)
{
	if (p != NULL) {
		
		if (value == p->info) {
			found++;
		}

		count(value, found, p->left);
		count(value, found, p->right);
	}
}





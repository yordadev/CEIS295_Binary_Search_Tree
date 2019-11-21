#pragma once
struct TreeNode
{
	int info;			//element stored in this node
	TreeNode* left;		//link to left child
	TreeNode* right;	//link to right child
};


class SimpleBag
{
public:
	SimpleBag();
	~SimpleBag();
	bool isEmpty();
	void print();
	void clear();
	void add(int);
	int count(int);

private:
	TreeNode* root;

	void deallocateMemory(TreeNode*&);
	void concat_tree(TreeNode*, std::string&, bool&);
	void add(int, TreeNode*&);
	void count(int, int&, TreeNode*);
};


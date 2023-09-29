#pragma once 
#include <unordered_map>


class BinaryTree {
	

public:
	struct node
	{
		int value;
		struct node* left;
		struct node* right;
	};

	BinaryTree(int value)
	{
		treeRoot = insert_integer(treeRoot, value);
	}
	node* get_root() { return treeRoot; }	
	node* insert_integer(node* root, int value);
	void print_tree(node* root);
	void terminate_tree(node* root);
	int most_common_integer(node* root, std::unordered_map<int, int> map = std::unordered_map<int, int>());
	int largest_integer(node* root);
	int sum_of_all_integers(node* root);

private:
	struct node* treeRoot = nullptr;
	node* create_node(node* root, int value);

	
};











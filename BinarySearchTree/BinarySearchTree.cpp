#include "BinarySearchTree.h"
#include <iostream>

using namespace std;


BinaryTree::node* BinaryTree::create_node(node* root, int value)
{
	root = new node();
	root->left = root->right = nullptr;
	root->value = value;
	return root;
}
BinaryTree::node* BinaryTree::insert_integer(node* root, int value)
{

	if (root == nullptr)
	{
		root = create_node(root, value);		
	}

	else if (value > root->value)
	{
		root->right = insert_integer(root->right, value);
	}
	else
	{
		root->left = insert_integer(root->left, value);
	}

	return root;
}

void BinaryTree::print_tree(struct node* root)
{
	if (root == nullptr) return;
	print_tree(root->right);
	cout << root->value << " " << endl;
	print_tree(root->left);	
}


void BinaryTree::terminate_tree(struct node* root)
{
	if (root == nullptr) return;
	terminate_tree(root->left);
	terminate_tree(root->right);
	delete root;
}



int BinaryTree::most_common_integer(struct node* root, unordered_map<int,int> map)
{
	//THIS DOES NOT WORK. RETURN AND FIX. 
	most_common_integer(root->left, map);
	auto iter = map.find(root->value);
	if (iter == map.end())
	{
		map.emplace(root->value, 1);
	}
	else
	{
		iter->second++;
	}
	most_common_integer(root->left, map);
	int currentBiggest = 0;
	int commonNumber = 0;
	for (auto it : map)
	{
		if (it.second > currentBiggest)
		{
			commonNumber = it.first;
			currentBiggest = it.second;
		}
	}
	return commonNumber;

}



int BinaryTree::largest_integer(struct node* root)
{
	while (root->right != nullptr)
	{
		root = root->right;
	}
	return root->value;
}

int BinaryTree::sum_of_all_integers(struct node* root)
{
	if (root == nullptr) return 0;
	return root->value + sum_of_all_integers(root->right) + sum_of_all_integers(root->left);
}

int main()
{
	srand(time(NULL));
	BinaryTree tree = BinaryTree(42);
	tree.insert_integer(tree.get_root(), 1);
	tree.insert_integer(tree.get_root(), rand() % 100);
	tree.insert_integer(tree.get_root(), rand() % 100);
	tree.insert_integer(tree.get_root(), rand() % 100);
	tree.insert_integer(tree.get_root(), rand() % 100);
	tree.insert_integer(tree.get_root(), rand() % 100);
	tree.insert_integer(tree.get_root(), rand() % 100);
	tree.print_tree(tree.get_root());
	cout << tree.largest_integer(tree.get_root()) << endl;
	cout << tree.sum_of_all_integers(tree.get_root()) << endl;
	//cout << tree.most_common_integer(root) << endl;
	tree.terminate_tree(tree.get_root());

	return 0;
}


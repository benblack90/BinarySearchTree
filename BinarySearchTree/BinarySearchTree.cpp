#include "BinarySearchTree.h"
#include <iostream>

using namespace std;

node* createNode(node* tree, int value)
{
	tree = new node();
	tree->left = tree->right = nullptr;
	tree->value = value;
	return tree;
}
node* insert_integer(struct node* tree, int value)
{

	if (tree == nullptr)
	{
		tree = createNode(tree, value);		
	}

	else if (value > tree->value)
	{
		tree->right = insert_integer(tree->right, value);
	}
	else
	{
		tree->left = insert_integer(tree->left, value);
	}

	return tree;
}
void print_tree(struct node* tree)
{
	if (tree == nullptr) return;
	print_tree(tree->right);
	cout << tree->value << " " << endl;
	print_tree(tree->left);	
}


void terminate_tree(struct node* tree)
{
	if (tree == nullptr) return;
	terminate_tree(tree->left);
	terminate_tree(tree->right);
	delete tree;
}



int most_common_integer(struct node* tree, unordered_map<int,int> map)
{
	//THIS DOES NOT WORK. RETURN AND FIX. 
	most_common_integer(tree->left, map);
	auto iter = map.find(tree->value);
	if (iter == map.end())
	{
		map.emplace(tree->value, 1);
	}
	else
	{
		iter->second++;
	}
	most_common_integer(tree->left, map);
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



int largest_integer(struct node* tree)
{
	while (tree->right != nullptr)
	{
		tree = tree->right;
	}
	return tree->value;
}

int sum_of_all_integers(struct node* tree)
{
	if (tree == nullptr) return 0;
	return tree->value + sum_of_all_integers(tree->right) + sum_of_all_integers(tree->left);
}

int main()
{
	srand(time(NULL));
	root = insert_integer(root, 1);
	insert_integer(root,1);
	insert_integer(root, rand() % 100);
	insert_integer(root, rand() % 100);
	insert_integer(root, rand() % 100);
	insert_integer(root, rand() % 100);
	insert_integer(root, rand() % 100);
	insert_integer(root, rand() % 100);
	print_tree(root);
	cout << largest_integer(root) << endl;
	cout << sum_of_all_integers(root) << endl;
	cout << most_common_integer(root) << endl;
	terminate_tree(root);

	return 0;
}


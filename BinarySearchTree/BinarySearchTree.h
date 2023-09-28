#pragma once 
#include <unordered_map>
struct node
{
	int value;
	struct node* left;
	struct node* right;
};
struct node* root = nullptr;
node* insert_integer(struct node* tree, int value);
void print_tree(struct node* tree);
void terminate_tree(struct node* tree);
int most_common_integer(struct node* tree, std::unordered_map<int,int> map = std::unordered_map<int,int>());
int largest_integer(struct node* tree);
int sum_of_all_integers(struct node* tree);










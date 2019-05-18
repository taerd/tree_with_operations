//
// Created by taerd on 30.03.2019.
//

#ifndef TREE_WITH_OPERATIONS_TREE_H
#define TREE_WITH_OPERATIONS_TREE_H
struct node{
    float val = 0;
    int h = 1;
    int cnt = 1;
    node* left = nullptr;
    node* right = nullptr;
};

void add(node*& tree, int x);
node* find_in_tree(node* tree, int x);
void drop(node*& tree);
void remove(node*& tree, int rem_val);
int get_height(node* elem);
void small_left_rotate(node*&root);
void small_right_rotate(node*&root);
void big_left_rotate(node*&root);
void big_right_rotate(node*&root);
void balance(node*&root);
#endif //TREE_WITH_OPERATIONS_TREE_H

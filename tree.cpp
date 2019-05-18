//
// Created by taerd on 30.03.2019.
//

#include "tree.h"
#include <cmath>
void add(node*& root, node* elem){
    if (!elem) return;
    if (!root) root = elem;
    else {
        if (elem->val < root->val){
            add(root->left, elem);
        } else {
            add(root->right, elem);
        }
    }
    balance(root);
    root->h=get_height(root);
}

void add(node*& root, int x){
    node* new_el = new node;
    new_el->val = x;
    add(root, new_el);
}

node* find_in_tree(node* root, int x){
    if (root){
        if (root->val == x) return root;
        if (x < root->val)
            return find_in_tree(root->left, x);
        else
            return find_in_tree(root->right, x);
    }
    return nullptr;
}

void drop(node*& tree){
    if (tree){
        drop(tree->left);
        drop(tree->right);
        delete tree;
        tree = nullptr;
    }
}

node* get_parent(node* tree, node* elem){
    if (!tree || !elem || tree==elem) return nullptr;
    if (
            tree->left == elem ||
            tree->right == elem
            ) return tree;
    if (elem->val<tree->val)
        return get_parent(tree->left, elem);
    else return get_parent(tree->right, elem);
}

void remove(node*& root, int rem_val){
    node* rem_el = find_in_tree(root, rem_val);
    if (rem_el){
        node* ltree = rem_el->left;
        node* rtree = rem_el->right;
        node* parent = get_parent(root, rem_el);
        if (!parent) root = rtree;
        else {
            if (parent->left==rem_el)
                parent->left = rtree;
            else
                parent->right = rtree;
        }
        delete rem_el;
        add(root, ltree);//rtree
    }
}

int get_height(node* elem){
    if (!elem) return 0;
    int lh = (elem->left) ? elem->left->h : 0;
    int rh = (elem->right) ? elem->right->h : 0;
    int k=((rh>lh)?rh:lh);
    k=k+1;
    return k;
}

void balance(node*&root){
    if(!root) return;
    int rh=get_height(root->right);
    int lh=get_height(root->left);
    if(abs(rh-lh)>=2){
        if(rh>lh){
            if(get_height(root->right->left)>get_height(root->right->right)){
                big_left_rotate(root);
            }
            else small_left_rotate(root);
        }
        else if (get_height(root->left->right)>get_height(root->left->left)){
            big_right_rotate(root);
        }
        else small_right_rotate(root);
    }
}

void small_left_rotate(node*&root){
    if(!root) return;
    node* r=root->right;
    root->right=r->left;
    r->left=root;
    root=r;
    root->left->h=get_height(root->left);
}

void small_right_rotate(node*&root){
    if(!root) return;
    node* l=root->left;
    root->left=l->right;
    l->right=root;
    root=l;
    root->right->h=get_height(root->right);
}

void big_left_rotate(node*&root){
    small_right_rotate(root->right);
    small_left_rotate(root);
}

void big_right_rotate(node*&root){
    small_left_rotate(root->left);
    small_right_rotate(root);
}
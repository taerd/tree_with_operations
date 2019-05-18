#include <iostream>
#include "tree.h"
using namespace std;

int main() {
    const int n = 26;
    node* tree = nullptr;
    for (int i = 0; i<n; i++){
        int v;
        cin >> v;
        add(tree, v);
    }
    cout << find_in_tree(tree, 7) << endl;
    cout << find_in_tree(tree, 10) << endl;
    cout << find_in_tree(tree, 2) << endl;
    remove(tree, 10);
    drop(tree);
    return 0;
}
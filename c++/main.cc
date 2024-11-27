#include <iostream>

using namespace std;

// Tree
// level order traversal
// Input:
//    1
//  2   3
// 4 5 6 7
// Output:
// 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
}


// Input:
//    1
//  2   3
//      6 7
// Output:
// 1 -> 2 -> 3 -> 6 -> 7 ->
// Queue: []
void levelOrderTraversal(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode *node = q.front();
        q.pop();

        std::cout << node->val << " -> ";

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}

int main() {
    return 0;
}
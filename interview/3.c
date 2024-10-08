#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 定義樹的節點結構
typedef struct Node {
    char value;
    struct Node* parent;
    struct Node* left;
    struct Node* right;
} Node;

// 建立新節點
Node* create_node(char value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->parent = NULL;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// 連接 parent 和 child 節點
void connect_nodes(Node* parent, Node* left, Node* right) {
    parent->left = left;
    parent->right = right;
    if (left) left->parent = parent;
    if (right) right->parent = parent;
}

// 遞迴尋找路徑，path 用來儲存方向
int find_path(Node* current, Node* target, char* path, int depth) {
    if (current == NULL) {
        return 0;  // 沒有找到路徑
    }
    if (current == target) {
        path[depth] = '\0';  // 終點找到，終止字串
        return 1;  // 找到終點
    }

    // 嘗試往左走
    path[depth] = 'l';
    if (find_path(current->left, target, path, depth + 1)) {
        return 1;
    }
    
    // 嘗試往右走
    path[depth] = 'r';
    if (find_path(current->right, target, path, depth + 1)) {
        return 1;
    }
    
    // 嘗試往上走
    if (current->parent) {
        path[depth] = 'u';
        if (find_path(current->parent, target, path, depth + 1)) {
            return 1;
        }
    }
    
    return 0;  // 找不到路徑
}

int main() { 
    // 建立範例樹
    Node* root = create_node('A');
    Node* B = create_node('B');
    Node* C = create_node('C');
    Node* D = create_node('D');
    Node* E = create_node('E');
    Node* F = create_node('F');
    
    connect_nodes(root, B, C);
    connect_nodes(B, D, E);
    connect_nodes(C, NULL, F);

    // 設定起點和終點
    Node* start = B;
    Node* end = F;
    
    // 儲存路徑的字串
    char path[100];
    
    // 尋找路徑
    if (find_path(start, end, path, 0)) {
        printf("從 %c 到 %c 的路徑是: %s\n", start->value, end->value, path);
    } else {
        printf("找不到從 %c 到 %c 的路徑\n", start->value, end->value);
    }
    
    return 0;
}

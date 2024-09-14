#include <stdio.h>
#include <stdlib.h>
#include "treetrv.h"
#include "stack.h"

void PlaceNode(TreeNode* node, int direction, int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    if (direction == 0) {
        node->left = newNode;
    }
    else {
        node->right = newNode;
    }
}

void GenerateLinkTree(TreeNode* root) {
    PlaceNode(root, 0, 2);
    PlaceNode(root, 1, 9);
    PlaceNode(root->left, 0, 3);
    PlaceNode(root->left, 1, 5);
    PlaceNode(root->left->left, 0, 4);
    PlaceNode(root->left->right, 0, 6);
    PlaceNode(root->left->right, 1, 7);
    PlaceNode(root->right, 0, 10);
    PlaceNode(root->right, 1, 13);
    PlaceNode(root->right->left, 0, 11);
    PlaceNode(root->right->left, 1, 12);
    PlaceNode(root->right->right, 0, 14);
    PlaceNode(root->right->right, 1, 15);
}

void LinkPreOrder(TreeNode* root) {
    Stack stack = { NULL };
    TreeNode* current = root;

    while (current != NULL || !IsEmpty(&stack)) {
        while (current != NULL) {
            printf("%d ", current->data);
            Push(&stack, current);
            current = current->left;
        }
        current = Pop(&stack);
        current = current->right;
    }
    printf("\n");
}

void LinkInOrder(TreeNode* root) {
    Stack stack = { NULL };
    TreeNode* current = root;

    while (current != NULL || !IsEmpty(&stack)) {
        while (current != NULL) {
            Push(&stack, current);
            current = current->left;
        }
        current = Pop(&stack);
        printf("%d ", current->data);
        current = current->right;
    }
    printf("\n");
}

void LinkPostOrder(TreeNode* root) {
    Stack stack1 = { NULL }, stack2 = { NULL };
    Push(&stack1, root);

    while (!IsEmpty(&stack1)) {
        TreeNode* node = Pop(&stack1);
        Push(&stack2, node);

        if (node->left) Push(&stack1, node->left);
        if (node->right) Push(&stack1, node->right);
    }

    while (!IsEmpty(&stack2)) {
        TreeNode* node = Pop(&stack2);
        printf("%d ", node->data);
    }
    printf("\n");
}

void LinkOrders(TreeNode* root) {
    LinkPreOrder(root);
    LinkInOrder(root);
    LinkPostOrder(root);
}
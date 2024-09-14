#pragma once
#ifndef TREETRV_H
#define TREETRV_H

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

void PlaceNode(TreeNode* node, int direction, int data);
void GenerateLinkTree(TreeNode* root);
void LinkOrders(TreeNode* root);

#endif

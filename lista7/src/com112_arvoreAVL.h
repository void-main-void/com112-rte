#ifndef ARVORE_AVL_H
#define ARVORE_AVL_H

typedef struct Node {
  int value;
  struct Node *left;
  struct Node *right;
} Node, *NodePtr;

int treeHeight(NodePtr root);

#endif

#ifndef ARVORE_AVL_H
#define ARVORE_AVL_H

#include <stdlib.h>

typedef unsigned int uint;
typedef struct Node {
  int value;
  struct Node *left;
  struct Node *right;
} Node, *NodePtr;

void treeDestroy(NodePtr root);
int  treeHeight(NodePtr root);
int  treeBalance(NodePtr root);
int  treePrintUtil(NodePtr tree, int is_left, int offset, int depth, char s[20][255]);
void treePrint2D(NodePtr root);
NodePtr treeRightRotate(NodePtr node_root);
NodePtr treeLeftRotate(NodePtr node_root);
NodePtr treeLeftRightRotate(NodePtr node_root);
NodePtr treeRightLeftRotate(NodePtr node_root);

NodePtr nodeCreate(int value);
void    nodeDestroy(NodePtr node);
int     nodeInsert(NodePtr *tree_ref, int value);
int     nodeRemove(NodePtr *tree_ref, int value);

#endif

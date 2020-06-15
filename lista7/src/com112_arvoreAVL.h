#ifndef ARVORE_AVL_H
#define ARVORE_AVL_H

#include <stdlib.h>

typedef unsigned int uint;
typedef struct Node {
  int value;
  struct Node *left;
  struct Node *right;
} Node, *NodePtr;

#ifdef max
  #undef max
#endif
int max(int x, int y) { return x > y ? x : y; }

void treeDestroy(NodePtr root);
int  treeHeight(NodePtr root);
int  treeBalance(NodePtr root);
int  treePrintUtil(NodePtr tree, int is_left, int offset, int depth, char s[20][255]);
void treePrint(NodePtr root);

NodePtr nodeCreate(int value);
void    nodeDestroy(NodePtr node);
int     nodeInsert(NodePtr *tree_root, int value);

#endif

#include "com112_arvoreAVL.h"

#include <stdio.h>

#define COMPACT

/**
 * @brief Compares to integers and returns the bigger.
 * 
 * @param x First number.
 * @param y Second Number.
 * @return int Value of the higher number.
 */
int max(int x, int y) { return x > y ? x : y; }

/**
 * @brief Frees a whole tree structure memory.
 * 
 * @param root Pointer to tree structure root node.
 */
void treeDestroy(NodePtr root) {
  if (!root) { return; } 
    treeDestroy(root->left); 
    treeDestroy(root->right);
    free(root); // TODO(void-main-void): achar bug!!!
}

/**
 * @brief Returns the height of a tree.
 * 
 * @param root Root node of the tree structure.
 * @return int Integer value of tree structure height.
 */
int treeHeight(NodePtr root) {
  if (!root) { return 0; }
  int height_left  = treeHeight(root->left);
  int height_right = treeHeight( root->right);
  if (height_left > height_right) { return height_left + 1; }
  else { return height_right + 1; }
}

/**
 * @brief Calculates AVL tree balance factor.
 * 
 * @param root AVL tree root node.
 * @return int Balance factor integer value.
 */
int treeBalance(NodePtr root) {
  if (!root) { return 0; }
  return treeHeight(root->left) - treeHeight(root->right);
}


int treePrintUtil(NodePtr tree, int is_left, int offset, int depth, char s[20][255])
{
  char b[20];
  int width = 5;
  if (!tree) return 0;
  sprintf(b, "(%03d)", tree->value);
  int left  = treePrintUtil(tree->left,  1, offset,                depth + 1, s);
  int right = treePrintUtil(tree->right, 0, offset + left + width, depth + 1, s);
#ifdef COMPACT
  for (int i = 0; i < width; i++)
    s[depth][offset + left + i] = b[i];
  if (depth && is_left) {
    for (int i = 0; i < width + right; i++)
      s[depth - 1][offset + left + width/2 + i] = '-';
      s[depth - 1][offset + left + width/2] = '.';
  } else if (depth && !is_left) {
      for (int i = 0; i < left + width; i++)
        s[depth - 1][offset - width/2 + i] = '-';
        s[depth - 1][offset + left + width/2] = '.';
  }
#else
  for (int i = 0; i < width; i++)
    s[2 * depth][offset + left + i] = b[i];
  if (depth && is_left) {
    for (int i = 0; i < width + right; i++)
      s[2 * depth - 1][offset + left + width/2 + i] = '-';
      s[2 * depth - 1][offset + left + width/2] = '+';
      s[2 * depth - 1][offset + left + width + right + width/2] = '+';
    } else if (depth && !is_left) {
        for (int i = 0; i < left + width; i++)
          s[2 * depth - 1][offset - width/2 + i] = '-';
        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset - width/2 - 1] = '+';
    }
#endif
    return left + width + right;
}

void treePrint(NodePtr root) {
  char s[20][255];
  for (int i = 0; i < 20; i++) {
    sprintf(s[i], "%80s", " ");
  }
  treePrintUtil(root, 0, 0, 0, s);
  for (int i = 0; i < 20; i++) {
    printf("%s\n", s[i]);
  }
}

/**
 * @brief Allocates memmory to a new node.
 * 
 * @param value Integer value of node.
 * @return NodePtr Pointer to new node allocated data.
 */
NodePtr nodeCreate(int value) {
  NodePtr node_new = 0;
  node_new = (NodePtr) malloc(sizeof node_new);
  node_new->value = value;
  node_new->left = 0;
  node_new->right = 0;
  return node_new;
}

/**
 * @brief Frees a node memory.
 * 
 * @param node Pointer to node to be destroyed.
 */
void nodeDestroy(NodePtr node) {
  if (node) { free(node); }
  node = 0;
}

/**
 * @brief Adds a new node to an AVL tree.
 * 
 * @param tree_root AVL tree root node.
 * @param value New node value.
 * @return int 1 if success, 0 otherwise.
 */
int nodeInsert(NodePtr *tree_root, int value) {
  if (!(*tree_root)) { (*tree_root) = nodeCreate(value); return 1; }
  if (value <= (*tree_root)->value) { nodeInsert((&(*tree_root)->left), value); }
  if (value > (*tree_root)->value) { nodeInsert((&(*tree_root)->right), value); }
  if (!(*tree_root)) { return 0; }
}

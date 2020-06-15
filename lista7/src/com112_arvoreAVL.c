#include "com112_arvoreAVL.h"

#include <stdio.h>

#define COMPACT

/**
 * @brief Frees a whole tree structure memory.
 * 
 * @param root Pointer to tree structure root node.
 */
void treeDestroy(NodePtr root) {
  if (!root) { return; } 
    treeDestroy(root->left); 
    treeDestroy(root->right);
    free(root);
    root = 0;
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
  int height_right = treeHeight(root->right);
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
  return treeHeight(root->right) - treeHeight(root->left);
}

// TODO(void-main-void): mudar tamanho de acordo com a altura da árvore
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

void treePrint2D(NodePtr root) {
  char s[20][255];
  for (int i = 0; i < 20; i++) {
    sprintf(s[i], "%80s", " ");
  }
  treePrintUtil(root, 0, 0, 0, s);
  for (int i = 0; i < 20; i++) {
    printf("%s\n", s[i]);
  }
}

NodePtr treeRightRotate(NodePtr node_root) {
  NodePtr temp = node_root->left; 
  NodePtr temp_2 = temp->right;
  temp->right = node_root; 
  node_root->left = temp_2; 
  return temp;
}

NodePtr treeLeftRotate(NodePtr node_root) {
  NodePtr temp = node_root->right; 
  NodePtr temp_2 = temp->left;  
  temp->left = node_root;  
  node_root->right = temp_2;  
  return temp;
}

NodePtr treeLeftRightRotate(NodePtr node_root) {
  node_root->left = treeLeftRotate(node_root->left);
  node_root = treeRightRotate(node_root);
  return node_root;
}

NodePtr treeRightLeftRotate(NodePtr node_root) {
  node_root->right = treeRightRotate(node_root->right);
  node_root = treeLeftRotate(node_root);
  return node_root;
}

/**
 * @brief Allocates memmory to a new node.
 * 
 * @param value Integer value of node.
 * @return NodePtr Pointer to new node allocated data.
 */
NodePtr nodeCreate(int value) {
  NodePtr node_new = 0;
  node_new = malloc(sizeof *node_new);
  node_new->value = value;
  node_new->left = 0;
  node_new->right = 0;
  return node_new;
}

/**
 * @brief Adds a new node to an AVL tree.
 * 
 * @param tree_root AVL tree root node.
 * @param value New node value.
 * @return int 1 if success, 0 otherwise.
 */
int nodeInsert(NodePtr *tree_ref, int value) {
  if (!(*tree_ref)) { (*tree_ref) = nodeCreate(value); return 1; }
  if (value == (*tree_ref)->value) { return 0; }
  if (value < (*tree_ref)->value) {
    nodeInsert(&((*tree_ref)->left), value);
    if (treeBalance((*tree_ref)) < -1) {
      if (value < ((*tree_ref)->left)->value) { (*tree_ref) = treeRightRotate((*tree_ref)); }
      else { (*tree_ref) = treeLeftRightRotate((*tree_ref)); }
    }
  }
  if (value > (*tree_ref)->value) {
    nodeInsert(&((*tree_ref)->right), value);
    if (treeBalance((*tree_ref)) > 1) {
      if (value > ((*tree_ref)->right)->value) { (*tree_ref) = treeLeftRotate((*tree_ref)); }
      else { (*tree_ref) = treeRightLeftRotate((*tree_ref)); }
    }
  }
}

int nodeRemove(NodePtr *tree_ref, int value) {
  return 0;
}

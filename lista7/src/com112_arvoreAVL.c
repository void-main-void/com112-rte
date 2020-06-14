#include "com112_arvoreAVL.h"

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

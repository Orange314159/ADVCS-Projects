
#include "AVLTree.h"
#include <iostream>

AVLTree::AVLTree() {
	root = nullptr;
}

AVLTree::~AVLTree() {
  clear(root);
}

struct node* AVLTree::get_node(int val) {  
	struct node* new_node = new node;  
	new_node->left = nullptr; 
	new_node->right = nullptr;  
	new_node->key_value = val;  
	new_node->height = 1;			//Initial height of node is 1  
	return new_node;  
} 

int AVLTree::get_height(struct node* tree) {  
    if (tree == nullptr) 
        return 0; 
    return get_height(tree->left) - get_height(tree->right); 

}
 
int AVLTree::get_balance(struct node* tree) {  
   if(!tree)  
     return 0;  
   return (get_height(tree->left) - get_height(tree->right));  
}
  
int AVLTree::max(int a, int b) {  
   return (a > b) ? a : b;  
}
 
struct node* AVLTree::left_rotate(struct node *x) { 
  struct node *y = x->right; 
  struct node *T2 = y->left; 

  // Perform rotation 
  y->left = x; 
  x->right = T2; 

  // Update heights 
  x->height = 1 + max(get_height(x->left), get_height(x->right)); 
  y->height = 1 + max(get_height(y->left), get_height(y->right)); 

  // Return new root 
  return y; 
} 


struct node* AVLTree::right_rotate(struct node* y) {  
    struct node *x = y->left; 
    struct node *T2 = x->right; 

    // Perform rotation 
    x->right = y; 
    y->left = T2; 

    // Update heights 
    y->height = 1 + max(get_height(y->left), get_height(y->right)); 
    x->height = 1 + max(get_height(x->left), get_height(x->right)); 
    // Return new root 
    return x; 
} 
 
 
struct node* AVLTree::insert(struct node *tree, int key) { 
  
  // Perform the normal BST insertion
  if (tree == nullptr) 
      return get_node(key); 
  if (key < tree->key_value) 
      tree->left = insert(tree->left, key); 
  else if (key > tree->key_value) 
      tree->right = insert(tree->right, key); 
  else // Equal keys are not allowed in BST 
      return tree; 

  // Update height of this ancestor node 
  tree->height = 1 + max(get_height(tree->left), get_height(tree->right)); 

  // Get the balance factor of this ancestor node 
  int balance = get_balance(tree); 

  // If this node becomes unbalanced, 
  // then there are 4 cases 

  // Left Left Case 
  if (balance > 1 && key < tree->left->key_value) 
    return right_rotate(tree); 

  // Right Right Case 
  if (balance < -1 && key > tree->right->key_value) 
    return left_rotate(tree); 

  // Left Right Case 
  if (balance > 1 && key > tree->left->key_value) { 
    tree->left = left_rotate(tree->left); 
    return right_rotate(tree); 
  } 

  // Right Left Case 
  if (balance < -1 && key < tree->right->key_value) { 
    tree->right = right_rotate(tree->right); 
    return left_rotate(tree); 
  } 

  // Return the (unchanged) node pointer 
  return tree; 
} 
 
 
 //utility function used in balancing of node  
 //in deletion operation  

struct node* AVLTree::balance_tree(struct node* tree) {  
  int balance = get_balance(tree);

  if(balance > 1 && get_balance(tree->left) >= 0){  
    return right_rotate(tree);
  } else if (balance > 1 && get_balance(tree->left) < 0) {
    tree->left = left_rotate(tree->left);
    return right_rotate(tree);
  } else if (balance < -1 && get_balance(tree->right) <= 0) {
    return left_rotate(tree);
  } else if (balance < -1 && get_balance(tree->right) > 0) {
    tree->right = right_rotate(tree->right);
    return left_rotate(tree);
  }

  return tree;  
}  

 //utility function to find inorder successor   
 //of a given node when it has a right child  
struct node* AVLTree::inorder_succ_right_tree(struct node* tree) {  
  struct node* temp = tree->right;  
  while(temp->left){  
    temp = temp->left;  
  }  
  return temp;  
}
 
struct node* AVLTree::deletion(struct node* tree, int val) {
  //normal deletion
  if (tree == nullptr)
    return tree;
  else if (val < tree->key_value)
    tree->left = deletion(tree->left, val);
  else if (val > tree->key_value)
    tree->right = deletion(tree->right, val);
  else {
    if (tree->left == nullptr) {
      struct node *temp = tree->right;
      delete tree;
      return temp;
    } else if (tree->right == nullptr) {
      struct node *temp = tree->left;
      delete tree;
      return temp;
    }
    struct node* temp = inorder_succ_right_tree(tree);
    tree->key_value = temp->key_value;
    tree->right = deletion(tree->right, temp->key_value);
  }

  if(tree){
    tree->height = 1 + max(get_height(tree->left), get_height(tree->right));
  }

  balance_tree(tree);

  return tree;  
}  

 //function for printing the pre-order of tree  
 void AVLTree::preorder(struct node* tree) {  
  if(!tree)  
    return;  
  printf("%d\t",tree->key_value);  
  preorder(tree->left);  
  preorder(tree->right);  
 }
 
 //function for printing the in-order of tree  
int AVLTree::max_level(struct node* tree, int level, int max) {  
  int depth;
  if(!tree)  
    return level-1;  
  depth = max_level(tree->left, level+1, max);
  if (depth > max)
    max = depth;
  //printf("m%d[%d, %d]\t",tree->key_value, level, max);  
  depth = max_level(tree->right, level+1, max);
  if (depth > max)
    max = depth;
  return max;
}

//function for printing the in-order of tree  
int AVLTree::min_level(struct node* tree, int level, int min) {  
  int depth;
  if((!tree->left) && (!tree->right)) 
    return  (level < min ? level : min);  
  if (tree->left)
    min = min_level(tree->left, level+1, min);

  //printf("m%d[%d, %d]\t",tree->key_value, level, min);  
  if (tree->right)
    min = min_level(tree->right, level+1, min);

  return min;
}

 
 
//function for printing the in-order of tree  
void AVLTree::inorder_level(struct node* tree, int level) {  
    if(!tree)  
      return;  
    inorder_level(tree->left, level+1);  
    printf("%d[%d]\t",tree->key_value, level);  
    inorder_level(tree->right, level+1);  
}


//function for printing the in-order of tree  
void AVLTree::inorder(struct node* tree) {  
  inorder_level(tree,0);
}

  //function for  clearing tree  
void AVLTree::clear(struct node* tree) {  
  if(!tree)  
    return;  
  clear(tree->left);   
  tree->left = NULL;
  clear(tree->right);
  tree->right = NULL;
  if (root == tree)
    root = NULL;
  delete tree;
}  
 
 
  //function for printing the in-order of tree  
int AVLTree::sumorder(struct node* tree) {
  int sum=0;
    if(!tree)  
      return 0;  
  sum += sumorder(tree->left);  

  sum += sumorder(tree->right);

  sum += tree->key_value;
  printf("<%2d, %4d>\t",tree->key_value, sum);  

  return sum;
}  
 

/*
* Display Tree Structure
*/
void AVLTree::display(node *ptr, int level, int dir) {
  int i;
  if (ptr != NULL) {
    display(ptr->left, level+1, 1);
    std::cout<<std::endl;
  if (ptr == root)
    std::cout<<"Root->: ";
  else {
    for (i = 0;i < level+1;i++)
      std::cout<<"      ";
  }
  if (dir == 1)
    std::cout << "/  ";
  else if(dir == 2)
    std::cout << "\\  ";
    std::cout<<ptr->key_value;
    display(ptr->right, level+1, 2);
  }
}


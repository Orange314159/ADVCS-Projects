/*
 * Binary Search Tree class
 * Do not alter the display() function, this will break the Repl.it 
 * tests
 */

 
#include <iostream>
#include <cstdlib>
#include "BSTree.h"

using namespace std;


 
/*
 * Find Element in the Tree
 * find a node by item_key and provide an updated parent node
 *   pointer and location node pointer
 */
 
 
void BST::find(int item_key, node **prnt, node **loc) {
    node *ptr, *ptrsave;
    if (root == NULL) {
        *loc = NULL;
        *prnt = NULL;
        return;
    }
    if (item_key == root->key_value) {
        *loc = root;
        *prnt = NULL;
        return;
    }
    if (item_key < root->key_value)
        ptr = root->p_left;
    else
        ptr = root->p_right;
    ptrsave = root;
    while (ptr != NULL) {
        if (item_key == ptr->key_value) {
            *loc = ptr;
            *prnt = ptrsave;
            return;
        }
        ptrsave = ptr;
        if (item_key < ptr->key_value)
            ptr = ptr->p_left;
	else
	    ptr = ptr->p_right;
    }
    *loc = NULL;
    *prnt = ptrsave;
}
 
/*
 * Inserting Element into the Tree
 */
void BST::insert(node *& tree, node *newnode) {

    // cout << "Inserting " << newnode->key_value << " into " << tree << endl;

    if (tree == nullptr) {
        tree = newnode;
        if (root == nullptr) root = tree; //set root if it is null
        // std::cout << "Inserted " << newnode->key_value << std::endl;
        return;
    }

    // if there is already a node with our key value
    if (tree->key_value == newnode->key_value) {
        std::cout << "Node already exists" << std::endl;
        return;
    }


    //if (the new node is less than the current node)
    if(newnode->key_value < tree->key_value) {
        // cout << "Inserting left" << endl;
        //if (see if something is already a child on the left)
        if(tree->p_left != nullptr) {
            // if so, the recurse insert at this subtree 	
            insert(tree->p_left, newnode);
      	} else {
            // otherwise the new node goes here as a leaf (ie no children)
            tree->p_left = newnode;
            return;
        }
    } else {
        // cout << "Inserting right" << tree->p_right << endl;
        //if (is there already a child on right?)
        if(tree->p_right != nullptr) {
            // if so, the recurse insert at this subtree 
            insert(tree->p_right, newnode);
        } else {
            // otherwise the new node goes here as a leaf (ie no children)
            tree->p_right = newnode;
            return;
        }	
    }

}
 
/*
 * Delete Element from the tree
 */
void BST::remove(int item)
{   
    node *parent, *location;
    if (root == NULL){ //if (tree empty)
        cout<<"Tree empty"<<endl;
        return;
    }
    find(item, &parent, &location);
    if (location == NULL) { //if (item not present in tree)
        cout<<"Item not present in tree"<<endl;
        return;
    }
    //if (there is no child on left or right)
    if(location->p_left == NULL && location->p_right == NULL)
        case_0(parent, location);
    //if (there is one child on left only)
    if(location->p_left != NULL && location->p_right == NULL)
        case_1(parent, location);
    //if (there is one child on right only)
    if(location->p_left == NULL && location->p_right != NULL)
        case_1(parent, location);
    // if (there are childred on left and right)
    if(location->p_left != NULL && location->p_right != NULL)
        case_2(parent, location);

    free(location);
}
 
/*
 * Case 0
 * the node is simply removed no other updates necessary.
 */
void BST::case_0(node *prnt, node *loc ) {
    if (prnt == nullptr) {
        root = nullptr;
    } else if (loc == prnt->p_left) {
        prnt->p_left = nullptr;
    } else {
        prnt->p_right = nullptr;
    }
}
 
/*
 * Case 1
 * We have only one child so promote the child and replace the target
 * node
 */
void BST::case_1(node *prnt, node *loc) {
    
    // temporary pointer for the child node
    node *child = (loc->p_left != nullptr) ? loc->p_left : loc->p_right;    
        
    if (prnt == nullptr) {
        root = child;
    } else if (prnt == prnt->p_left) {
        prnt->p_left = child;
    } else {
        prnt->p_right = child;
    }
}
 
/*
 * Case case_2
 * We have to find and promote a successor or predecessor
*/
void BST::case_2(node *prnt, node *loc) {
    // temporary pointers for node we are manipulating

    node *successor = loc->p_right;
    node *successorParent = loc;

    while (successor->p_left != nullptr) { // traverce to the leftmost node to find smallest value (to the right)
        successorParent = successor;
        successor = successor->p_left;
    }

    loc->key_value = successor->key_value; 

    if (successorParent == loc) { 
        case_1(loc, successor); 
    } else {
        case_1(successorParent, successor); 
    }
}
 

/*
 * Display Tree Structure
 */
void BST::display(node *ptr, int level)
{
    int i;
    if (ptr != NULL)
    {
        display(ptr->p_right, level+1);
        cout<<endl;
        if (ptr == root)
            cout<<"Root->: ";
        else
        {
            for (i = 0;i < level;i++)
                cout<<"  ";
	}
        cout<<ptr->key_value;
        display(ptr->p_left, level+1);
    }
    cout<<endl;
}
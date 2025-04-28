/*
 * C++ Program To Implement BST
 */
#ifndef BSTREE_H
#define BSTREE_H


/*
 * Node Declaration
 */
struct node
{
    int key_value = 0;
    struct node *p_left  = nullptr;
    struct node *p_right = nullptr;
};
 
/*
 * Class Declaration
 */
class BST
{
public:
		node* root;
        void find(int, node **, node **);    
        void insert(node *&, node *);
        void remove(int);
        void case_0(node *,node *);
        void case_1(node *,node *);
        void case_2(node *,node *);
        void display(node *, int);
        BST()
        {
            root = NULL;
        }
};


#endif	//BSTREE_H
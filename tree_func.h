#ifndef _TREE_H_
#define _TREE_H_

typedef int tree_elem_t;

enum TreeFuncStatus 
{
    STAT_OK,
    STAT_FAIL
};

struct Node
{
    tree_elem_t data;

    Node *left_son;
    Node *right_son;
};

struct Root 
{
    Node *root;
};

TreeFuncStatus tree_ctor( Node* node, Root* root );
TreeFuncStatus tree_dtor( Node* node, Root* root );
TreeFuncStatus insert_in_tree( Node* node, tree_elem_t value );
Node* create_node ( void );

#endif
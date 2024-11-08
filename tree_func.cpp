#include <stdlib.h>
#include <stdio.h>

#include "tree_func.h"
#include "log_file_func.h"

TreeFuncStatus tree_ctor( Node* node, Root* root )
{
    if( !node )
        return STAT_FAIL;

    if ( !root )
        return STAT_FAIL;

    root->root = create_node();

    node->left_son = create_node();
    node->right_son = create_node();

    return STAT_OK;
}

TreeFuncStatus tree_dtor( Node* node, Root* root )
{
    VERIFY( node );

    node->data = 0;

    free( node->left_son );
    free( node->right_son );

    free( node );

    free( root );

    return STAT_OK;
}

TreeFuncStatus insert_in_tree( Node* node, tree_elem_t value )
{

    if ( value < node->data )
    {
        if( node->left_son )
            insert_in_tree( node->left_son, value) ;
        else
            node->left_son = create_node( );
    } 
    else
    {
        if( node->right_son )
            insert_in_tree( node->right_son, value );
        else
            node->right_son = create_node( );
    }

    return STAT_OK;
}

Node* create_node ( void ) 
{
    Node* node_ptr = ( Node* )calloc( 1, sizeof ( Node ) );

    return node_ptr;
}
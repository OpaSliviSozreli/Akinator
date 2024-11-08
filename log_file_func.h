#ifndef _LOG_FILE_FUNC_H_
#define _LOG_FILE_FUNC_H_

#include <stdio.h>

#include "tree_func.h"

#define VERIFY( node ) if ( tree_verify( node, root ) != TREE_SUCCES ) \
                       {                                               \
                            tree_dump( node );                         \
                            return STAT_FAIL;                          \
                       }

enum TreeErrors
{
    TREE_SUCCES      = 0    ,
    NODE_IS_ZERO = ( 1<< 2 ),
    ROOT_IS_ZERO = ( 1<< 3 )
};

FILE* create_log_file( const char* log_file_name );
void close_log_file( void );
long long tree_verify( Node* node, Root* root );
TreeFuncStatus tree_dump( Node* node );
TreeFuncStatus make_nodes( Node* node );
TreeFuncStatus link_nodes( Node* node );
TreeFuncStatus tree_print_inorder( Node* node );
TreeFuncStatus tree_print_postorder( Node* node );
TreeFuncStatus tree_print_preorder( Node* node );

#endif
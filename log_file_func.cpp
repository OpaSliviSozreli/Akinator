#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "log_file_func.h"

FILE* log_file = create_log_file( "list_log.dot" );

FILE* create_log_file( const char* log_file_name ) 
{
    assert( log_file_name );

    FILE *log_file_ptr = fopen ( "list_log.dot", "w" );

    atexit( close_log_file );

    return log_file_ptr;
}

void close_log_file( void ) 
{
    if ( !log_file )
        fprintf( stderr, "log_file is nullptr" );

    fclose ( log_file );
}

long long tree_verify( Node* node, Root* root )
{
    long long error = TREE_SUCCES;

    if ( !node )
    {
        error |= NODE_IS_ZERO;
        fprintf( log_file, "NODE IS ZERO" );
    }
    
    if ( !root )
    {
        error |= ROOT_IS_ZERO;
        fprintf( log_file, "ROOT IS ZERO" );
    }

    return error;
}

TreeFuncStatus tree_dump( Node* node ) // мб void?
{
    fprintf( log_file, "digraph G{\n"
                       "rankdir = TB;\n"
                       "graph [bgcolor = white];\n" );

    make_nodes( node );
    link_nodes( node );

    fprintf( log_file, "\n}\n" );

    return STAT_OK;
}

TreeFuncStatus make_nodes( Node* node )
{
     if ( node != NULL ) 
     {
        fprintf ( log_file, "\tnode%p [shape=record, "
                            "style = filled, fillcolor = lightgreen, "
                            "fontsize = 16, fontname = \"times bold\", "
                            "label = \"{<f0> data = %d  |{<f1> %s | <f2> %s}} \"];\n",
                            node,
                            node->data,
                            "Left",
                            "Right" );
    }

    if ( node->left_son )
        make_nodes( node->left_son );

    if ( node->right_son )
        make_nodes( node->right_son );
    
    return STAT_OK;
}

TreeFuncStatus link_nodes( Node* node )
{
    if ( node->left_son )
    {
        fprintf( log_file, "\tnode%p:<f1> -> node%p:<f0> [weight = 52; color = \"#1D638B\";];\n",\
                           node, node->left_son );

        link_nodes( node->left_son );
    }
        
    if ( node->right_son )
    {
        fprintf( log_file, "\tnode%p:<f2> -> node%p:<f0> [weight = 52; color = \"#1D638B\";];\n",\
                           node, node->right_son );
        
        link_nodes(node->right_son );
    }

    return STAT_OK;
}

TreeFuncStatus tree_print_preorder( Node* node )
{
    printf( "(" );

    printf( "%d", node->data );

    if ( node->left_son )
        tree_print_preorder( node->left_son );
    else
        printf( "{}" );
    
    if ( node->right_son )
        tree_print_preorder( node->right_son );
    else
        printf( "{}" );

    printf( ")" );

    return STAT_OK;
}

TreeFuncStatus tree_print_postorder( Node* node )
{
    printf( "(" );

    if ( node->left_son )
        tree_print_postorder( node->left_son );
    else
        printf( "{}" );
    
    if ( node->right_son )
        tree_print_postorder( node->right_son );
    else
        printf( "{}" );

    printf( "%d", node->data );

    printf( ")" );

    return STAT_OK;
}

TreeFuncStatus tree_print_inorder( Node* node )
{
    printf( "(" );

    if ( node->left_son )
        tree_print_inorder( node->left_son );
    else
        printf( "{}" );
    
    printf( "%d", node->data );

    if ( node->right_son )
        tree_print_inorder( node->right_son );
    else
        printf( "{}" );

    printf( ")" );

    return STAT_OK;
}
//"C:\Users\elena\OneDrive\Документы\GitHub\Graphviz\bin\dot" -Tpng list_log.dot -o list_log.png
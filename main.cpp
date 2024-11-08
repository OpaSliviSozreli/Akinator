#include "tree_func.h"
#include "log_file_func.h"

int main()
{
    Node node = {};
    Root root = {};

    tree_ctor( &node, &root );

    insert_in_tree( ( &root )->root, 52 );
    
    insert_in_tree( &node, 8 );
    insert_in_tree( &node, 88 );
    insert_in_tree( &node, 888 );

    tree_dump( &node );
}
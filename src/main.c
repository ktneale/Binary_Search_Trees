/*
 * Written by Kevin Neale (C) 2015.
 *
 * Implementation of a set of functions allowing the creation of Binary Search Trees.
 *
 * At present, the data stored within these nodes is a simply integer value, however it
 * can be easily adapted to take a pointer to a data structure containing anything you like.
 * You will then need to implement a comparison function to work with that data structure.
 */
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define false 0
#define true 1

typedef struct node_t {
    int value;
    struct node_t * parent;
    struct node_t * left;
    struct node_t * right;
}node_t;


node_t * create_node(const int value)
{
    node_t * node = (node_t *)malloc(sizeof(node_t));

    if(!node) {
        printf("Error, bad alloc\n");
        exit(1);
    }

    memset(node,0,sizeof(node_t));
    node->value = value;

    return node;
}

//Adds a node to a Binary Search Tree.
void add_node(node_t * curr_node, node_t * new_node)
{
    if(!curr_node) {
        printf("Error, bad input\n");
        return;
    }

    if((curr_node->value > new_node->value) == true) {
        if(curr_node->left == NULL) {
            curr_node->left = new_node;
        } else {
            add_node(curr_node->left, new_node);
        }
    } else {
        if(curr_node->right == NULL) {
            curr_node->right = new_node;
        } else {
            add_node(curr_node->right, new_node);
        }
    }
}

//Tranversal algorithms
void pre_order(node_t * temp)
{
    if(temp!=NULL) {
        printf("Element: %d\n",temp->value);
        pre_order(temp->left);
        pre_order(temp->right);
    }
}

void in_order(node_t * temp)
{
    if(temp!=NULL) {
        in_order(temp->left);
        printf("Element: %d\n",temp->value);
        in_order(temp->right);
    }
}

void post_order(node_t * temp)
{
    if(temp!=NULL) {
        post_order(temp->left);
        post_order(temp->right);
        printf("Element: %d\n",temp->value);
    }
}

int main()
{
    //Definition of BST starts here!
    node_t * root = create_node(5);

    //Add subsequent nodes here.
    node_t * new_node;

	new_node = create_node(6);
	add_node(root,new_node);

	new_node = create_node(4);
	add_node(root,new_node);

	new_node = create_node(1);
	add_node(root,new_node);

	new_node = create_node(8);
	add_node(root,new_node);

	new_node = create_node(2);
	add_node(root,new_node);

	new_node = create_node(17);
	add_node(root,new_node);

    //Transverse the BST using 3 'Depth First' approaches.
    printf("\npre-order [START]\n");
    pre_order(root);
    printf("pre-order [END]\n");

    printf("\nin-order [START]\n");
    in_order(root);
    printf("in-order [END]\n");

    printf("\npost-order [START]\n");
    post_order(root);
    printf("post-order [END]\n\n");

    return 0;
}

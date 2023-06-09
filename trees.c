#include<stdio.h>
#include<stdlib.h>

// Made by Husain Abugosh - 2023

/*

A tree is a widely used abstract data type (ADT) or data structure implementing this ADT that simulates a hierarchical tree structure,
 with a set of connected nodes.

Here are some important concepts and terminologies associated with trees:

~Node: Each element of a tree is called a node. A node is an entity that holds data.
~Root: The node at the top of the tree is called the root. There is only one root in a tree.
~Edge: The connection between one node and another is called an edge.
~Parent: Any node (except the root) is connected by an edge upward to exactly one other node. This node is called the parent of that node.
~Child: The node below a given node connected by its edge downward is called its child node.
~Leaf: The node which does not have any child node is called the leaf node.
~Subtree: Subtree represents the descendants of a node.
~Siblings: Nodes that belong to the same parent are called siblings.
~Level: The level of a node represents the generation of a node. If the root node is at level 0, 
~then its next child node is at level 1, its grandchild is at level 2, and so on...
~Height of tree: The height of a tree is the number of edges on the longest path in the tree.

// ~BINARY TREE:
A binary tree is a tree data structure where each node can have at most two children,
 which are referred to as the left child and the right child. This is what makes it binary.
 
 It is widely used due to its straightforward implementation and efficient operations. */

 // STRUTURE //

// structure of the node:
 typedef struct tnode{

    int data;        //<-- will held the data in it 
    struct tnode *right;   //<-- pointer that point to left sub nodes(children nodes).
    struct tnode *left;   //<-- pointer that point to right sub nodes(children nodes).

 }tnode;

 tnode* createTnode(int data){

     tnode* newNode = (tnode*)malloc(sizeof(tnode)); //<-- will search about a space in the memo
     if (newNode == NULL){
        printf("memory allocation failed");
        return NULL;
     }

     newNode->data = data;     //<-- set the data inside the node.
     newNode->left = NULL;    //<-- set the lift pointer to null temprorey.
     newNode->right = NULL;  //<-- set the right pointer to null temprorey.

     return(newNode);
 }


//function to insert the data inside the node:
 tnode* insertTnode(tnode* node, int data){
    
    // if the root is null then we will create a tree :
    if(node == NULL){
        return createTnode(data);
    }else{
        // if the node is not null then insert the data by resurion 
        // resurion will used to reach the leafs (most left or right node ) to insert the data:

        if(data < node->data){
        //if the data is less than the node data -> insert into the left subtree:
            node->left = insertTnode(node->left,data);
        }else{
        ///if the data is bigger than the node data -> insert into the right subtree:
             node->right = insertTnode(node->right,data);
        }
    }

   return node;
 }


// this function will use to Traversal the tree depending on op (1:in-order // 2:post-order //3:pre-order):
void Traversal(tnode* root, int op){

// to print the in-order(left , visit_Root, Right) traversal:
    if (root != NULL && op == 1) { 
        Traversal(root->left,1);     //<--  move to the most left node .
        printf("%d ", root->data);       //<-- when u reach the most left node print the data inside it.
        Traversal(root->right,1);  //<-- after finish all of these get back to the right.

// to print the post-order(left, Right,visit_Root) traversal:
    }else if(root != NULL && op == 2){
        Traversal(root->left,2);     //<--  move to the most left node .
        Traversal(root->right,2);    //<-- move to the right.
        printf("%d ", root->data);       //<-- visit the root.

// to print the pre-order(visit_Root,left, Right) traversal:
    }else if(root != NULL && op == 3){

        printf("%d ", root->data);       //<-- visit the root.
        Traversal(root->left,3);     //<--  move to the most left node .
        Traversal(root->right,3);    //<-- move to the right.
    }
}
/*this function used for searching about an element in the tree by:
1- checking if the target is larger or less than the root data
2- keep moving to the most left ot right till found it 
 */ 
tnode* find(tnode* root, int target){

    if(root ==  NULL || root->data == target){
        return root;
    }else if(target < root->data) {
        return find(root->left, target);
    }else{
        return find(root->right, target);
    }

}

// delete Function:


// this function: to find the maximum value in the binary tree:
int maxValue(tnode*  root) {

// checking if the tree is null
    if (root == NULL) {
        printf("*Error tree is empty*\n");
        return -1; 

    // if there is no Right nodes left return the current root.
    }else if (root->right == NULL) {
        return root->data;
    // else: we will keep moving right till the most right:
    }else {
        return maxValue(root->right);
    }

}


// this function: to find the maximum value in the binary tree:
int minValue(tnode*  root) {

// checking if the tree is null
    if (root == NULL) {
        printf("*Error tree is empty*\n");
        return -1; 

    // if there is no left nodes lefts return the current root.
    }else if (root->left == NULL) {
        return root->data;

    // else: we will keep moving left till the most left:
    }else {
        return minValue(root->left);
    }

}




int main(){

    
    tnode *root = NULL;   //<-- declear a tree.

    root = insertTnode(root, 10); //<-- we need to add this first time.
    insertTnode(root, 20); 
    insertTnode(root, 30); 
    insertTnode(root, 40); 
    insertTnode(root, 50);

    printf("Inorder traversal: ");
    Traversal(root,1); 


    printf("\n");


   // to find the maximum value:
    int max_value = maxValue(root);
    if (maxValue != -1) {
        printf("The maximum value in the binary tree is: %d\n", max_value);
    }


    // to find the minmum value:
    int min_value = minValue(root);
    if (maxValue != -1) {
        printf("The minmum value in the binary tree is: %d\n", min_value);
    }



    return 0;
}
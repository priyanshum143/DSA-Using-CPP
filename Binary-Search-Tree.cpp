#include <iostream>
using namespace std;

// Creating a class 'Node' for BST
class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to print BST in inorder traversal
void inorder(Node* root){
    if(root == NULL) return;

    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

// Function to print BST in preorder traversal
void preorder(Node* root){
    if(root == NULL) return;

    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
}

// Function to insert a node in BST
Node* insertBST(Node* root, int val){
    Node* nodeToInsert = new Node(val);
    if(root == NULL) return nodeToInsert;

    if(nodeToInsert -> data < root -> data) root -> left = insertBST(root -> left, val);
    else if(nodeToInsert -> data > root -> data) root -> right = insertBST(root -> right, val);
    return root;
}

// Function to search a node in BST
bool searchBST(Node* root, int targetEle){
    if(root == NULL) return false;

    if(targetEle == root -> data) return true;
    else if(targetEle < root -> data) return searchBST(root -> left, targetEle);
    return searchBST(root -> right, targetEle);
}

// Function to delete a node of BST
Node* inorderSucc(Node* root){
    Node* curr = root;
    while(curr != NULL && curr -> left != NULL){
        curr = curr -> left;
    }
    return curr;
}

Node* deleteBST(Node* root, int val){
    if(val < root -> data) root -> left = deleteBST(root -> left, val);
    else if(val > root -> data) root -> right = deleteBST(root -> right, val);
    else{
        if(root -> left == NULL){
            Node* temp = root -> right;
            free(root);
            return temp;
        }
        else if(root -> right == NULL){
            Node* temp = root -> left;
            free(root);
            return temp;
        }
        Node* temp = inorderSucc(root -> right);
        root -> data = temp -> data;
        root -> right = deleteBST(root -> right, temp -> data);
    }
    return root;
}

// Function to construct a BST from a preorder seq
Node* construcBST(int *preorder, int size){
    Node* root = new Node(preorder[0]);
    for(int i=1; i<size; i++){
        insertBST(root, preorder[i]);
    }
    return root;
}

// Function to check if a given binary tree is BST or not
bool checkBST(Node* root, Node* min, Node* max){
    if(root == NULL) return true;
    
    if(min != NULL && root->data <= min->data) return false;
    if(max != NULL && root->data >= max->data) return false;

    bool leftValid = checkBST(root->left, min, root);
    bool rightValid = checkBST(root->right, root, max);
    return (leftValid and rightValid);
}
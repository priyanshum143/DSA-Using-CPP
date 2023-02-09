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

// Function to print BST in zig zag level order traversal
#include <stack>
#include <queue>
void zigzagTraversal(Node* root){
    queue <Node*> que;
    stack <Node*> st;
    int level = 0;

    que.push(root);
    que.push(NULL);

    while(!que.empty()){
        if(level % 2 == 0){
            Node* node = que.front();
            que.pop();

            if(node != NULL){
                cout << node -> data << " ";
                if(node -> left) que.push(node -> left);
                if(node -> right) que.push(node -> right);
            }
            else{
                if(!que.empty()){ 
                    que.push(NULL);
                    level++;
                }
            }
        }
        else{
            Node* node = que.front();
            que.pop();
            
            if(node != NULL){
                st.push(node);
                if(node -> left) que.push(node -> left);
                if(node -> right) que.push(node -> right);
            }
            else{
                while(!st.empty()){
                    cout << st.top() -> data << " ";
                    st.pop();
                }
                if(!que.empty()){
                    que.push(NULL);
                    level++;
                }
            }
        }
    }
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

// function to create a height balanced BST from a sorted array
Node* arrayToBST(int *arr, int start, int end){
    if(start > end) return NULL;

    int mid = (start + end)/2;
    Node* root = new Node(arr[mid]);
    root -> left = arrayToBST(arr, start, mid-1);
    root -> right = arrayToBST(arr, mid+1, end);
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

// Function to check if two BST's are identical or not
bool isIdentical(Node* root1, Node* root2){
    if(root1 == NULL && root2 == NULL) return true;
    else if(root1 == NULL || root2 == NULL) return false;

    else{
        bool cond1 = root1->data == root2->data;
        bool cond2 = isIdentical(root1->left, root2->left);
        bool cond3 = isIdentical(root1->right, root2->right);

        if(cond1 && cond2 && cond3) return true;
        return false;
    }
}

// Function to find catalan number 
/*
int catalan(int n){
    if(n <= 1) return 1;

    int res = 0;
    for(int i=0; i<n; i++){
        res += catalan(i)*catalan(n-i-1);
    }
    return res;
}
*/ // Ignore this

#include <iostream>
using namespace std;

// Creating a class "Node" for tree
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

// Function to print all elements of tree using preorder traversal
void preorder(Node* &root){
    if(root == NULL){
        return;
    }
    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
}

// Function to print all elements of tree using inorder traversal
void inorder(Node* &root){
    if(root == NULL){
        return;
    }
    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

// Function to print all elements of tree using postorder traversal
void postorder(Node* &root){
    if(root == NULL){
        return;
    }
    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << " ";
}

// Function to print all elements of tree using level order traversal
#include <queue>
void levelorder(Node* root){
    if(root == NULL){
        return;
    }

    queue <Node*> que;
    que.push(root);
    que.push(NULL);
    
    while(!que.empty()){
        Node* node = que.front();
        que.pop();

        if(node != NULL){
            cout << node -> data << " ";
            if(node -> left != NULL){
                que.push(node -> left);
            }
            if(node -> right != NULL){
                que.push(node -> right);
            }
        }
        else if(!que.empty()){
            que.push(NULL);
        }
    }
}

// Function to find sum of nodes at Kth level
#include <queue>
int levelSum(Node* &root, int level){
    if(root == NULL){
        return 0;
    }

    int k = 0;
    queue <Node*> que;
    que.push(root);
    que.push(NULL);

    while(k < level){
        Node* node = que.front();
        que.pop();

        if(node != NULL){
            if(node -> left != NULL){
                que.push(node -> left);
            }
            if(node -> right != NULL){
                que.push(node -> right);
            }
        }
        else if(!que.empty()){
            que.push(NULL);
            k++;
        }
    }

    int sum = 0;
    Node* node = que.front();
    while(node != NULL){
        sum = sum + node -> data;
        que.pop();
        node = que.front();
    }

    return sum;
}

// Function to build a tree using preorder and inorder array
int search(int *inorder, int start, int end, int targetEle){
    for(int i=start; i<=end; i++){
        if(inorder[i] == targetEle){
            return i;
        }
    }
    return -1;
}

Node* buildTree(int *preorder, int* inorder, int start, int end){
    if(start > end){
        return NULL;
    }

    static int idx = 0;
    int curr = preorder[idx];
    idx++;
    Node* root = new Node(curr);

    if(start == end){
        return root;
    }
    int pos = search(inorder, start, end, curr);
    root -> left = buildTree(preorder, inorder, start, pos-1);
    root -> right = buildTree(preorder, inorder, pos+1, end);

    return root;
}

// Function to build a tree using postorder and inorder array
Node* makeTree(int *postorder, int *inorder, int start, int end){
    if(start > end){
        return NULL;
    }

    static int idx = end;
    int curr = postorder[idx];
    idx--;
    Node* root = new Node(curr);

    if(start == end){
        return root;
    } 
    int pos = search(inorder, start, end, curr);
    root -> right = makeTree(postorder, inorder, pos+1, end);
    root -> left = makeTree(postorder, inorder, start, pos-1);

    return root;
}
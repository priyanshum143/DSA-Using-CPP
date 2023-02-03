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

// Function to count the number of nodes in a binary tree
int countNodes(Node* root){
    if(root == NULL){
        return 0;
    }
    return countNodes(root -> left) + countNodes(root -> right) + 1;
}

// Function to find sum of all nodes in a binary tree
int sumNodes(Node* root){
    if(root == NULL){
        return 0;
    }
    return sumNodes(root -> left) + sumNodes(root -> right) + root -> data;
}

// Function to find the max height of the binary tree
int calHeight(Node* root){
    if(root == NULL){
        return 0;
    }
    int lHeight = calHeight(root -> left);
    int rHeight = calHeight(root -> right);
    return max(lHeight, rHeight) + 1;
}

// Function to find the diameter of a binary tree
int calDiamter(Node* root){
    if(root == NULL){
        return 0;
    }

    int lheight = calHeight(root -> left);
    int rheight = calHeight(root -> right);
    int curr_diameter = lheight + rheight + 1;

    int ldiameter = calDiamter(root -> left);
    int rdiameter = calDiamter(root -> right);

    return max(curr_diameter, max(ldiameter, rdiameter)); 
}

// Sum replacement in binary tree
void sumReplacement(Node* root){
    if(root == NULL){
        return;
    }

    root -> data = sumNodes(root -> left) + sumNodes(root -> right) + root -> data;
    sumReplacement(root -> left);
    sumReplacement(root -> right);

}

// Function to check if a binary tree is balanced or not
bool isBalanced(Node* root){
    if(root == NULL) return true;

    if(isBalanced(root -> left) == false) return false;
    if(isBalanced(root -> right) == false) return false;

    int lh = calHeight(root -> left);
    int rh = calHeight(root -> right);
    if(abs(rh - lh) <= 1){
        return true;
    }
    else{
        return false;
    } 
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

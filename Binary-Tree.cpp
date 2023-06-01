#include <bits/stdc++.h>
using namespace std;

// Creating a class "Node" for tree
class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

// Function to print all elements of tree using preorder traversal
void preorder(Node* &root){
    if(root == NULL) return;

    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
}

// Function to print all elements of tree using inorder traversal
void inorder(Node* &root){
    if(root == NULL) return;
    
    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

// Function to print all elements of tree using postorder traversal
void postorder(Node* &root){
    if(root == NULL) return;
    
    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << " ";
}

// Function to print all elements of tree using level order traversal
void levelorder(Node* root){
    if(root == NULL) return;

    queue <Node*> que;
    que.push(root);
    que.push(NULL);
    
    while(!que.empty()){
        Node* node = que.front();
        que.pop();

        if(node != NULL){
            cout << node -> data << " ";
            if(node -> left != NULL) que.push(node -> left);
            if(node -> right != NULL) que.push(node -> right);
        }
        else if(!que.empty()){
            cout << endl;
            que.push(NULL);
        } 
    }
}

// Function to print all element of tree using zig-zag traversal
void zigzagTraversal(Node* root){
    if(root == NULL) return;

    int level = 0;
    stack<Node*> st;

    queue<Node*> que;
    que.push(root);
    que.push(NULL);

    while(!que.empty()){
        Node* node = que.front();;
        que.pop();

        if(node != NULL){
            if(node->left) que.push(node->left);
            if(node->right) que.push(node->right);

            if(level % 2 == 0) cout << node -> data << " ";
            else st.push(node);
        }
        else if(!que.empty()){
            level++;
            que.push(NULL);
        }

        if(node == NULL){
            while(!st.empty()){
                cout << st.top() -> data << " ";
                st.pop();
            }
        }
    }
}

// Function to find the max height of the binary tree
int calcHeight(Node* root){
    if(root == NULL){
        return 0;
    }

    int lHeight = calcHeight(root -> left);
    int rHeight = calcHeight(root -> right);

    int maxHeight =  max(lHeight, rHeight) + 1;
    return maxHeight;
}

// Function to find sum of nodes at Kth level
int levelSum(Node* &root, int level){
    if(root == NULL) return 0;

    int height = calcHeight(root);
    if(level >= height) return 0;

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

// Function to find lowest common ancestor in a binary tree
Node* LCA(Node* root, int n1, int n2){
    if(root == NULL) return NULL;

    if(root->data == n1 || root->data == n2) return root;

    Node* leftAns = LCA(root->left, n1, n2);
    Node* rightAns = LCA(root->right, n1, n2);

    if(leftAns && rightAns) return root;
    if(leftAns && !rightAns) return leftAns;
    if(!leftAns && rightAns) return rightAns;
    if(!leftAns && !rightAns) return NULL;
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

// Function to find the diameter of a binary tree
int calcDiamter(Node* root){
    if(root == NULL){
        return 0;
    }

    int lheight = calcHeight(root -> left);
    int rheight = calcHeight(root -> right);
    int curr_diameter = lheight + rheight + 1;

    int ldiameter = calcDiamter(root -> left);
    int rdiameter = calcDiamter(root -> right);

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

    bool left = isBalanced(root -> left);
    bool right = isBalanced(root -> right);

    bool diff = abs(calcHeight(root->left) - calcHeight(root->right)) <= 1;

    if(left && right && diff) return true;
    return false;
}

// Function to determin if two trees are identical or not
bool isIdentical(Node* root1, Node* root2){
    if(!root1 && !root2) return true;
    if(!root1 && root2) return false;
    if(root1 && !root2) return false;

    bool left = isIdentical(root1->left, root2->left);
    bool right = isIdentical(root1->right, root2->right);

    bool value = root1->data == root2->data;

    if(left && right && value) return true;
    return false;
}

// Function to build a tree using preorder and inorder array
class buildTreePreIn{
private:
    int findPos(int *inorder, int start, int end, int targetEle){
        for(int i=start; i<=end; i++){
            if(inorder[i] == targetEle) return i;
        }
        return -1;
    }

    Node* solve(int* preorder, int* inorder, int start, int end){
        if(start > end) return NULL;

        static int idx = 0;
        int curr = preorder[idx++];

        Node* root = new Node(curr);
        if(start == end) return root;

        int pos = findPos(inorder, start, end, curr);
        root -> left = solve(preorder, inorder, start, pos-1);
        root -> right = solve(preorder, inorder, pos+1, end);

        return root;
    }

public: 
    Node* buildTree(int *preorder, int* inorder, int size){
        int start = 0;
        int end = size - 1;

        return solve(preorder, inorder, start, end); 
    }
};

// Function to build a tree using postorder and inorder array
class buildTreePostIn{
private:
    int findPos(int *inorder, int start, int end, int targetEle){
        for(int i=start; i<=end; i++){
            if(inorder[i] == targetEle) return i;
        }
        return -1;
    }

    Node* solve(int *postorder, int *inorder, int start, int end){
        if(start > end) return NULL;

        static int idx = end;
        int curr = postorder[idx--];

        Node* root = new Node(curr);
        if(start == end) return root;

        int pos = findPos(inorder, start, end, curr);
        root -> right = solve(postorder, inorder, pos+1, end);
        root -> left = solve(postorder, inorder, start, pos-1);

        return root;
    }

public:
    Node* buildTree(int *postorder, int *inorder, int size){
        int start = 0;
        int end = size - 1;

        return solve(postorder, inorder, start, end); 
    }
};

// Function to find right view of a binary tree
void rightView(Node* root){
    if(root == NULL) return;

    queue <Node*> que;
    que.push(root);

    while(!que.empty()){
        int size = que.size();
        for(int i=0; i<size; i++){
            Node* curr = que.front();
            que.pop();

            if(i == size-1) cout << curr -> data << " ";

            if(curr -> left) que.push(curr -> left);
            if(curr -> right ) que.push(curr -> right);
        }
    }                                                                                                                                                                                                                                                                                                                             
}

// Function to find left view of a binary tree
void leftView(Node* root){
    if(root == NULL) return;

    queue <Node*> que;
    que.push(root);

    while(!que.empty()){
        int size = que.size();
        for(int i=0; i<size; i++){
            Node* curr = que.front();
            que.pop();

            if(i == 0) cout << curr -> data << " ";

            if(curr -> left) que.push(curr -> left);
            if(curr -> right ) que.push(curr -> right);
        }
    }                                                                                                                                                                                                                                                                                                                             
}

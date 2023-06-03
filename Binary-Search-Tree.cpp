#include <bits/stdc++.h>
using namespace std;

// Creating a class "Node" for BST
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

// Function to print BST in postorder traversal
void postorder(Node* root){
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

// Function to print BST in zig zag level order traversal
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

// Function to find the minimum value of the BST
int minVal(Node* root){
    Node* pointer = root;
    while(pointer->left){
        pointer = pointer -> left;
    }
    return pointer->data;
}

// Function to find the maximum value of the BST
int maxVal(Node* root){
    Node* pointer = root;
    while(pointer->right){
        pointer = pointer->right;
    }
    return pointer->data;
}

// Function to insert a node in BST
Node* insertBST(Node* &root, int val){
    if(root == NULL){
        root = new Node(val);
        return root;
    }

    if(val < root -> data) root -> left = insertBST(root -> left, val);
    else if(val > root -> data) root -> right = insertBST(root -> right, val);
    return root;
}

// Function to search a node in BST
bool searchBST(Node* root, int targetEle){
    if(root == NULL) return false;

    if(targetEle == root -> data) return true;
    else if(targetEle < root -> data) return searchBST(root -> left, targetEle);
    return searchBST(root -> right, targetEle);
}

// Function to delete a node from BST
Node* deleteBST(Node* root, int val){
    if(root == NULL) return root;

    if(root->data == val){
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }

        if(root->left && !root->right){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        if(!root->left && root->right){
            Node* temp = root->right;
            delete root;
            return temp;
        } 

        if(root->left && root->right){
            int mini = minVal(root->right);
            root->data = mini;
            root->right = deleteBST(root->right, mini);
            return root;
        }
    }
    else if(root->data > val) root->left = deleteBST(root->left, val);
    else root->right = deleteBST(root->right, val);
}

// Function to check if a given binary tree is BST or not
class CheckBST{
private:
    bool isBST(Node* root, int max, int min){
        if(root == NULL) return true;

        if(root->data > min && root->data < max){
            bool left = isBST(root->left, min, root->data);
            bool right = isBST(root->right, root->data, max);
            return left && right;
        }
        else return false;
    }

public:
    bool isBSTValid(Node* root){
        int min = INT_MIN;
        int max = INT_MAX;

        return isBST(root, min, max);
    }
};

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

// Function to find the LCA of two given nodes in a BST
Node* LCA(Node* root, int n1, int n2){
    if(root == NULL) return NULL;

    if(root->data < n1 && root->data < n2){
        return LCA(root->right, n1, n2);
    }

    if(root->data > n1 && root->data > n2){
        return LCA(root->left, n1, n2);
    }
    return root;
}

// Two Sum in BST
class TwoSum{
private:
    void inorder(Node* root, vector<int> &inorderVec){
        if(root == NULL) return;

        inorder(root->left, inorderVec);
        inorderVec.push_back(root->data);
        inorder(root->right, inorderVec);
    }

public:
    bool twoSum(Node* root, int targetSum){
        vector<int> inorderVec;
        inorder(root, inorderVec);

        int i = 0;
        int j = inorderVec.size() - 1;

        while(i <= j){
            int sum = inorderVec[i] + inorderVec[j];

            if(sum == targetSum) return true;
            else if(sum < targetSum) i++;
            else j--;
        }
        return false;
    }
};

// Function to convert normal BST into balanced BST
class BalancedBST{
private:
    void inorder(Node* root, vector<int> &inorderVec){
        if(root == NULL) return;

        inorder(root->left, inorderVec);
        inorderVec.push_back(root->data);
        inorder(root->right, inorderVec);
    }

    Node* solve(int start, int end, vector<int> inorderVec){
        if(start > end) return NULL;

        int mid = (start + end) / 2;

        Node* newRoot = new Node(inorderVec[mid]);
        newRoot->left = solve(start, mid-1, inorderVec);
        newRoot->right = solve(mid+1, end, inorderVec);

        return newRoot;
    }

public:
    Node* balancedBST(Node* root){
        vector<int> inorderVec;
        inorder(root, inorderVec);

        int start = 0;
        int end = inorderVec.size() - 1;

        Node* newRoot = solve(start, end, inorderVec);
        return newRoot;
    }
};

// Function to merge two BSTs
class MergeBST{
private:
    void inorder(Node* root, vector<int> &inorderVec){
        if(root == NULL) return;

        inorder(root->left, inorderVec);
        inorderVec.push_back(root->data);
        inorder(root->right, inorderVec);
    }

    vector<int> mergeVector(vector<int> vec1, vector<int> vec2){
        int size1 = vec1.size();
        int size2 = vec2.size();

        vector<int> ans;

        int i = 0, j = 0;
        while(i<size1 && j<size2){
            if(vec1[i] < vec2[j]) ans.push_back(vec1[i++]);
            else ans.push_back(vec2[j++]);
        }

        while(i<size1) ans.push_back(vec1[i++]);

        while(j<size2) ans.push_back(vec2[j++]);

        return ans;
    }

    Node* createBST(vector<int> inorderVec, int start, int end){
        if(start > end) return NULL;

        int mid = (start + end) / 2;

        Node* root = new Node(inorderVec[mid]);
        root->left = createBST(inorderVec, start, mid-1);
        root->right = createBST(inorderVec, mid+1, end);

        return root;
    }

public:
    Node* mergeBST(Node* root1, Node* root2){
        vector<int> vec1;
        inorder(root1, vec1);

        vector<int> vec2;
        inorder(root2, vec2);

        vector<int> mergedVec = mergeVector(vec1, vec2);
        int start = 0;
        int end = mergedVec.size() - 1;

        Node* newRoot = createBST(mergedVec, start, end);
        return newRoot;
    }
};

// Function to find the size of given tree's largest subtree that is a BST
class LargestBST{
private:
    struct info{
        int maxi;
        int mini;
        bool isBST;
        int size;
    };

    info solve(Node* root, int &count){
        if(root == NULL) return {INT_MIN, INT_MAX, true, 0};

        info left = solve(root->left, count);
        info right = solve(root->right, count);

        info currNode;
        currNode.maxi = max(root->data, right.maxi);
        currNode.mini = min(root->data, left.mini);
        currNode.size = left.size + right.size + 1;

        if((left.isBST && right.isBST) && (root->data > left.maxi && root->data < right.mini)){
            currNode.isBST = true;
        }
        else currNode.isBST = false;

        if(currNode.isBST) count = max(count, currNode.size);

        return currNode;
    }

public:
    int largestBST(Node* root){
        int count = 0;
        solve(root, count);

        return count;
    }
};

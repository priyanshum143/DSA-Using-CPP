#include <bits/stdc++.h>                   
#include "Linked-List.cpp"
using namespace std;

// Creating Stack using Array
/*
class Stack
{
private:
    int top;
    int size;
    int *arr;

public:
    Stack(int val){
        size = val;
        top = -1;
        arr = new int[val];
    }

    void push(int val){
        if(top == size-1){
            cout << "Stack Overflow" << endl;
        }
        else{
            top++;
            arr[top] = val;
        }
    }

    void pop(){
        if(top < 0){
            cout << "Stack Underflow" << endl;
        }
        else{
            top--;
        }
    }

    int peek(){
        if(top < 0){
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty(){
        if(top < 0){
            return true;
        }
        return false;
    }
};
*/

// Creating stack using Linked list
/*
class Stack
{
private:
    int top;
    Node* head;
    Node* tail;

public:
    Stack(){
        top = -1;
        head = NULL;
        tail = NULL; 
    }

    void push(int val){
        insertAtHead(head, tail, val);
    }

    void pop(){
        if(head == NULL){
            cout << "Stack Underflow" << endl;
        }
        else{
            deletion(head, tail, 0);
        }
    }

    int peek(){
        if(head == NULL){
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return head -> data;
    }

    bool isEmpty(){
        if(head == NULL){
            return true;
        }
        return false;
    }
};
*/

// Using STL for stack
/*
#include <stack>                       // Library to use stacks
int main(){
    stack <int> st;                    // Declaration of a stack using STL

    st.push(0);                        // Function to add elements in a stack 
    st.push(10);

    cout << st.top() << endl;          // Function to print top element of a stack

    st.pop();                          // Function to remove top element from the stack

    cout << st.empty() << endl;        // Function to check if a stack is empty or not
}
*/

// Prefix Evaluation
int prefixEvaluation(string prefixStr){
    stack <int> st;
    
    int len = prefixStr.length();
    for(int i=len-1; i>=0; i--){
        if(prefixStr[i] >= '0'  &&  prefixStr[i] <= '9'){
            st.push(prefixStr[i] - '0');
        }
        else if(prefixStr[i] == '+' || prefixStr[i] == '-' || prefixStr[i] == '*' || prefixStr[i] == '/'){
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();

            int result;
            char ch = prefixStr[i];
            switch(ch){
                case '+':
                    result = op1 + op2;
                    break;

                case '-':
                    result = op1 - op2;
                    break;

                case '*':
                    result = op1 * op2;
                    break;

                case '/':
                    result = op1 / op2;
                    break;
                }
            st.push(result);
        }
    }
    return st.top();
}

// Postfix Evaluation
int postfixEvaluation(string postfixStr){
    stack <int> st;

    int len = postfixStr.length();
    for(int i=0; i<len; i++){
        if(postfixStr[i] >= '0'  &&  postfixStr[i] <= '9'){
            st.push(postfixStr[i] - '0');
        }
        else if(postfixStr[i] == '+' || postfixStr[i] == '-' || postfixStr[i] == '*' || postfixStr[i] == '/'){
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();

            int result;
            char ch = postfixStr[i];
            switch(ch){
                case '+':
                    result = op2 + op1;
                    break;

                case '-':
                    result = op2 - op1;
                    break;

                case '*':
                    result = op2 * op1;
                    break;

                case '/':
                    result = op2 / op1;
                    break;
            }
            st.push(result);
        }
    }
    return st.top();
}

// Infix to postfix
class InToPost{
private:
    int prec(char op){
        if(op == '^') return 3;
        else if(op == '/' || op == '*') return 2;
        else if(op == '+' || op == '-') return 1;
        return 0;
    }

public:
    string infixToPostfix(string infixStr){
        stack <char> st;
        string postfixStr;

        for(int i=0; i<infixStr.length(); i++){
            if(infixStr[i] == '(') st.push(infixStr[i]);
            else if(infixStr[i] >= 'a' && infixStr[i] <= 'z' || infixStr[i] >= 'A' && infixStr[i] <= 'Z') postfixStr += infixStr[i];   
            else if(infixStr[i] == ')'){
                while(!st.empty() && st.top() != '('){
                    postfixStr += st.top();
                    st.pop();
                } 
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                while(!st.empty() && prec(st.top()) > prec(infixStr[i])){
                    postfixStr += st.top();
                    st.pop();
                }
                st.push(infixStr[i]);
            }
        }
        
        while(!st.empty()){
            postfixStr += st.top();
            st.pop();
        }
        return postfixStr;
    }
};

// Infix to prefix
class InToPre{
private:
    int prec(char op){
        if(op == '^') return 3;
        else if(op == '/' || op == '*') return 2;
        else if(op == '+' || op == '-') return 1;
        return 0;
    }

public:
    string infixToPrefix(string infixStr){
        string reversedInfixStr;
        for(int i=infixStr.length()-1; i>=0; i--) reversedInfixStr += infixStr[i];

        for(int i=0; i<reversedInfixStr.length(); i++){
            if(reversedInfixStr[i] == ')') reversedInfixStr[i] = '('; 
            else if(reversedInfixStr[i] == '(') reversedInfixStr[i] = ')';
        }

        stack <char> st;
        string prefixStr;

        for(int i=0; i<reversedInfixStr.length(); i++){
            if(reversedInfixStr[i] == '(') st.push(reversedInfixStr[i]);
            else if(reversedInfixStr[i] >= 'a' && reversedInfixStr[i] <= 'z' || reversedInfixStr[i] >= 'A' && reversedInfixStr[i] <= 'Z') prefixStr += reversedInfixStr[i];
            else if(reversedInfixStr[i] == ')'){
                while(!st.empty() && st.top() != '('){
                    prefixStr += st.top();
                    st.pop();
                } 
                if(!st.empty()) st.pop();
            }
            else{
                while(!st.empty() && prec(st.top()) > prec(reversedInfixStr[i])){
                    prefixStr += st.top();
                    st.pop();
                }
                st.push(reversedInfixStr[i]);
            }
        }
    
        while(!st.empty()){
            prefixStr += st.top();
            st.pop();
        }

        string finalPrefixStr;
        for(int i=prefixStr.length()-1; i>=0; i--) finalPrefixStr += prefixStr[i];
        return finalPrefixStr;
    }
};

// Balanced Paranthesis Problem
bool balancedParanthesis(string str){
    stack <char> st;
    for(int i=0; i<str.length(); i++){
        if(str[i] == '[' || str[i] == '{' || str[i] == '('){
            st.push(str[i]);
        }
        else if(str[i] == ']' || str[i] == '}' || str[i] == ')'){
            if(!st.empty() && str[i] == ')' && st.top() == '('){
                st.pop();
            }
            else if(!st.empty() && str[i] == '}' && st.top() == '{'){
                st.pop();
            }
            else if(!st.empty() && str[i] == ']' && st.top() == '['){
                st.pop();
            }
            else{
                return false;
            }
        }
    }

    if(st.empty()){
        return true;
    }
    return false;
}

// Delete middle element from a stack
class DeleteMiddle{
private:
    void solve(stack<int> &st, int size, int count){
        if(count == size/2){
            st.pop();
            return;
        }

        int num = st.top();
        st.pop();

        solve(st, size, count+1);
        st.push(num);
    }

public:
    void deleteMiddle(stack<int> &st, int size){
        solve(st, size, 0); 
    }
};

// Insert an element at the bottom of the stack
void insertAtBottom(stack<int> &st, int val){
    if(st.size() == 0){
        st.push(val);
        return;
    }

    int num = st.top();
    st.pop();

    insertAtBottom(st, val);
    st.push(num);
}

// Reverse a stack
void reverseStack(stack<int> &st){
    if(st.empty()) return;

    int num = st.top();
    st.pop();

    reverseStack(st);
    insertAtBottom(st, num);
}

// Sort a stack
class SortStack{
private:
    void sortedInsert(stack<int> &st, int num){
        if(st.empty() || st.top() < num){
            st.push(num);
            return;
        }

        int n = st.top();
        st.pop();

        sortedInsert(st, num);
        st.push(n);
    }

public:
    void sortStack(stack<int> &st){
        if(st.empty()) return;

        int num = st.top();
        st.pop();

        sortStack(st);
        sortedInsert(st, num);
    }
};

// Next Smaller Element
vector<int> nextSmallerElement(vector<int> vec, int size){
    vector<int> ans(size);

    stack<int> st;
    st.push(-1);

    for(int i=size-1; i>=0; i--){
        int curr = vec[i];
        while(st.top() != -1 && st.top() > curr) st.pop();
        ans[i] = st.top();
        st.push(curr);
    }

    return ans;
}

// The celebrity problem
int celebrity(vector<vector<int>> &vec, int n) {
    stack<int> st;
    for(int i=0; i<n; i++) st.push(i);
        
    while(st.size() > 1){
        int per1 = st.top();
        st.pop();
            
        int per2 = st.top();
        st.pop();
            
        if(vec[per1][per2] == 1) st.push(per2);  // Person 1 knows Person 2
        else st.push(per1);
    }
    int candidate = st.top();
        
    bool rowCheck = false;
    int zeroCount = 0;
    for(int i=0; i<n; i++){
        if(vec[candidate][i] == 0) zeroCount++;
    }
    if(zeroCount == n) rowCheck = true;
        
    bool colCheck = false;
    int oneCount = 0;
    for(int i=0; i<n; i++){
        if(vec[i][candidate] == 1) oneCount++;
    }
    if(oneCount + 1 == n) colCheck = true;
        
    if(rowCheck && colCheck) return candidate;
    return -1;
}

// Special Stack
class SpecialStack{
private:
    stack<int> st;
    int mini;

public:
    void push(int data){
        if(st.empty()){
            st.push(data);
            mini = data;
        }
        else{
            if(data < mini){
                int val = 2*data - mini;
                st.push(val);
                mini = data;
            }
            else st.push(data);
        }
    }

    int pop(){
        if(st.empty()) return -1;

        int curr = st.top();
        st.pop();
        if(curr > mini) return curr;
        else{
            int prevMini = mini;
            int val = 2*mini - curr;
            mini = val;
            return prevMini;
        }
    }

    bool isEmpty(){
        return st.empty();
    }

    int top(){
        if(st.empty()) return -1;

        int curr = st.top();
        if(curr < mini) return mini;
        return curr;
    }

    int getMin(){
        if(st.empty()) return -1;
        return mini;
    }
};

#include <bits/stdc++.h>
#include <stack>    // Declaration of header file for stack
#include "linked-list.cpp"
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

// function to covert infix expression to postfix
int prec(char op){
    if(op == '^'){
        return 3;
    }
    else if(op == '/' || op == '*'){
        return 2;
    }
    else if(op == '+' || op == '-'){
        return 1;
    }
    else{
        return 0;
    }
};

string infixToPostfix(string infixStr){
    stack <char> st;
    string postfixStr;

    for(int i=0; i<infixStr.length(); i++){
        if(infixStr[i] == '('){
            st.push(infixStr[i]);
        }
        else if(infixStr[i] >= 'a' && infixStr[i] <= 'z' || infixStr[i] >= 'A' && infixStr[i] <= 'Z'){
            postfixStr += infixStr[i];   
        }
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

// Infix to prefix
string infixToPrefix(string infixStr){
    string reversedInfixStr;
    for(int i=infixStr.length()-1; i>=0; i--){
        reversedInfixStr += infixStr[i];
    }

    for(int i=0; i<reversedInfixStr.length(); i++){
        if(reversedInfixStr[i] == ')'){
            reversedInfixStr[i] = '('; 
        }
        else if(reversedInfixStr[i] == '('){
            reversedInfixStr[i] = ')';
        }
    }

    stack <char> st;
    string prefixStr;

    for(int i=0; i<reversedInfixStr.length(); i++){
        if(reversedInfixStr[i] == '('){
            st.push(reversedInfixStr[i]);
        }
        else if(reversedInfixStr[i] >= 'a' && reversedInfixStr[i] <= 'z' || reversedInfixStr[i] >= 'A' && reversedInfixStr[i] <= 'Z'){
            prefixStr += reversedInfixStr[i];   
        }
        else if(reversedInfixStr[i] == ')'){
            while(!st.empty() && st.top() != '('){
                prefixStr += st.top();
                st.pop();
            } 
            if(!st.empty()){
                st.pop();
            }
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
    for(int i=prefixStr.length()-1; i>=0; i--){
        finalPrefixStr += prefixStr[i];
    }
    return finalPrefixStr;    
}

// Function to check if the given string is valid or not (string must only contain Bracetts)
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

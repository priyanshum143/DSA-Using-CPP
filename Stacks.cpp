#include <iostream>
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
#include <stack>

int main(){
    stack <int> st;                    // Declaration of a stack using STL

    st.push(0);                        // Function to add elements in a stack 
    st.push(10);

    cout << st.top() << endl;          // Function to print top element of a stack

    st.pop();                          // Function to remove top element from the stack

    cout << st.empty() << endl;        // Function to check if a stack is empty or not
}
*/
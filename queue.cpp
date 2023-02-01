#include <iostream>
#include "linked-list.cpp"
using namespace std;

// Creating queue using Array
/*
class queue{
private:
    int *arr;
    int size;
    int front;
    int rear;

public:
    queue(int val){
        arr = new int[val];
        size = val;
        front = 0;
        rear = 0;
    }

    void push(int val){
        if(rear == size){
            cout << "Queue Overflow" << endl;
        }
        else{
            arr[rear] = val;
            rear++;
        }
    }

    void pop(){
        if(rear == front){
            cout << "Queue Underflow" << endl;
        }
        else{
            arr[front] = -1;
            front++;
            if(front == rear){
                front = 0;
                rear = 0;
            }
        }
    }

    int peek(){
        if(rear == front){
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return arr[front];
    }

    bool isEmpty(){
        if(rear == front){
            return true;
        }
        return false;
    }
};
*/

// Creating Circular queue using array
/*
class circularQueue{
private:
    int *arr;
    int size;
    int front;
    int rear;

public:
    circularQueue(int val){
        arr = new int[val];
        size = val;
        front = -1;
        rear = -1;
    }

    void push(int val){
        if((front == 0 && rear == size-1) || (rear == (front-1)%(size-1))){
            cout << "Queue Overflow" << endl;
        }
        else if(front == -1 && rear == -1){
            front = rear = 0;
            arr[rear] = val;
        }
        else if(rear == size-1 && front != 0){
            rear = 0;
            arr[rear] = val;
        }
        else{
            rear++;
            arr[rear] = val;
        }
    }

    void pop(){
        if(front == -1 && rear == -1){
            cout << "Queue Underflow" << endl;
        }
        else if(front == rear){
            arr[front] = -1;
            front = rear = -1;
        }
        else if(front == size - 1){
            arr[front] = -1;
            front = 0;
        }
        else{
            arr[front] = -1;
            front++;
        }
    }

    int peek(){
        if(front == -1){
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return arr[front];
    }

    bool isEmpty(){
        if(front == -1){
            return true;
        }
        return false;
    }
};
*/

// Creating queue using linked list
/*
class Queue{
private:
    Node* front;
    Node* rear;
    int size;

public:
    Queue(){
        front = NULL;
        rear = NULL;
        size = 0;
    }

    void push(int val){
        insertAtTail(front, rear, val);
        size++;
    }

    void pop(){
        if(front == NULL){
            cout << "Queue Underflow" << endl;
        }
        else{
            deletion(front, rear, 0);
            size--;
        }

        if(size == 0){
            front = rear = NULL;
        }
    }

    int peek(){
        if(front == NULL){
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return front -> data;
    }

    bool isEmpty(){
        if(front == NULL){
            return true;
        }
        return false;
    }
};
*/

// Creating queue using stack
/*
#include <stack>
class Queue{
private:
    stack <int> st1;
    stack <int> st2;

public:
    void enqueue(int val){
        if(!st2.empty()){
            while(!st2.empty()){
                st1.push(st2.top());
                st2.pop();
            }
        }
        st1.push(val);
    }

    void dequeue(){
        if(st1.empty() && st2.empty()){
            cout << "Queue Underflow" << endl;
        }
        else if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            st2.pop();
        }
        else if(!st2.empty()){
            st2.pop();
        }
    }

    int front(){
        if(st1.empty() && st2.empty()){
            cout << "Queue is Empty" << endl;
            return -1;
        }
        else if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            return st2.top();
        }
        else if(!st2.empty()){
            return st2.top();
        }
        else{
            return -1;
        }
    }

    bool isEmpty(){
        if(st1.empty() && st2.empty()){
            return true;
        }
        return false;
    }
};
*/

#include <iostream>
using namespace std;

// Creating a class names "Node"
class Node
{
public:
    Node* prev;
    int data;
    Node* next;

    Node(int val){
        prev = NULL;
        data = val;
        next = NULL;
    }
};

// Function to insert an element at head
void insertAtHead(Node* &head, Node* &tail, int val){
    Node* nodeToInsert = new Node(val);
    if(head == NULL){
        head = nodeToInsert;
        tail = nodeToInsert;
    }
    else{
        nodeToInsert -> next = head;
        head -> prev = nodeToInsert;
        head = nodeToInsert;
    }
}

// Function to insert an element at tail
void insertAtTail(Node* &head, Node* &tail, int val){
    Node* nodeToInsert = new Node(val);
    if(tail == NULL){
        head = nodeToInsert;
        tail = nodeToInsert;
    }
    else{
        tail -> next = nodeToInsert;
        nodeToInsert -> prev = tail;
        tail = nodeToInsert;
    }
}

// Function to find the length of list
int lengthOfList(Node* &head, Node* &tail){
    int len = 0;
    Node* pointer = head;
    while(pointer != NULL){
        len++;
        pointer = pointer -> next;
    }
    return len;
}

// Function to print the list
void printList(Node* &head){
    Node* pointer = head;
    while(pointer != NULL){
        cout << pointer -> data << " ";
        pointer = pointer -> next;
    }
    cout << endl;
}

// Function to insert the element at given position
void insertion(Node* &head, Node* &tail, int val, int pos){
    if(pos <= 0){
        insertAtHead(head, tail, val);
        return;
    }

    int len = lengthOfList(head, tail);
    if(pos > len){
        insertAtTail(head, tail, val);
        return;
    }

    Node* pointer = head;
    int curPos = 0;
    while(curPos < pos-1){
        pointer = pointer -> next;
        curPos++;
    }

    if(pointer -> next == NULL){
        insertAtTail(head, tail, val);
        return;
    }
    else{
        Node* nodeToInsert = new Node(val);
        nodeToInsert -> next = pointer -> next;
        pointer -> next = nodeToInsert;
    }
}

// Function to insert elements via input
void insertionViaInput(Node* &head, Node* &tail, int size){
    for(int curPos = 0; curPos < size; curPos++){
        int eleToInsert;
        cin >> eleToInsert;
        insertAtTail(head, tail, eleToInsert);
    }
}

// Function to delete element the element of given position
void deletion(Node* &head, Node* &tail, int pos){
    if(pos <= 0){
        head = head -> next;
        return;
    }

    int len = lengthOfList(head, tail);
    if(pos > len - 1){
        cout << "This position does not exist in the given linked list" << endl;
        return;
    }

    Node* pointer = head;
    int curPos = 0;
    while(curPos < pos-1){
        pointer = pointer -> next;
        curPos++;
    }

    if(pointer -> next -> next == NULL){
        pointer -> next = NULL;
        tail = pointer;
    }
    else{
        pointer -> next = pointer -> next -> next;
    }
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head, tail, 0);
    insertAtTail(head, tail, 5);
    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 15);
    insertAtTail(head, tail, 20);

    insertion(head, tail, 99, 0);
    deletion(head, tail, 2);

    printList(head);
}
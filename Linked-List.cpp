#include <iostream>
using namespace std;

// creating a class named "Node"
class Node{
public:
    int data;
    Node* next;

    Node(int val){
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
        tail = nodeToInsert;
    }
}

// Function to print the linked list
void printList(Node* &head, Node* &tail){
    Node* pointer = head;
    while(pointer != NULL){
        cout << pointer -> data << " ";
        pointer = pointer -> next;
    }
    cout << endl;
}

// Function to find the length of list
int lengthOfList(Node* &head, Node* &tail){
    int len = 0;
    Node* pointer = head;
    while(pointer){
        len++;
        pointer = pointer -> next;
    }
    return len;
}

// Function to insert the element at given position
void insertion(Node* &head, Node* &tail, int val, int pos){
    if(pos <= 0){
        insertAtHead(head, tail, val);
        return;
    }

    int len = lengthOfList(head, tail);
    if(pos >= len){
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
    for(int curPos = 0; curPos<size; curPos++){
        int eleToInsert;
        cin >> eleToInsert;
        insertAtTail(head, tail, eleToInsert);
    }
}

// Function to delete element the element of given position
void deletion(Node* &head, Node* &tail, int pos){
    int len = lengthOfList(head, tail);
    if(pos < 0 || pos >= len){
        cout << "This position does not exist in the given linked list" << endl;
        return;
    }

    if(pos == 0){
        head = head -> next;
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

// Function to reverse the given list
void reverseList(Node* &head, Node* &tail){
    Node* pointer1 = NULL;
    Node* pointer2 = head;
    Node* pointer3 = head -> next;

    while(pointer3 != NULL){
        pointer2 -> next = pointer1;
        pointer1 = pointer2;

        pointer2 = pointer3;
        pointer3 = pointer3 -> next;
    }
    pointer2 -> next = pointer1;
    
    tail = head;
    head = pointer2;
}

// Function to find the max Element of the list
int findMax(Node* head, Node* &tail){
    Node* pointer = head;
    int maxEle = INT16_MIN;

    while(pointer != NULL){
        if(pointer -> data > maxEle){
            maxEle = pointer -> data;
        }
        pointer = pointer -> next;
    }
    return maxEle;
}

// Function to find the minimum element of the list
int findMin(Node* head, Node* &tail){
    Node* pointer = head;
    int minEle = INT16_MAX;

    while(pointer != NULL){
        if(pointer -> data < minEle){
            minEle = pointer -> data;
        }
        pointer = pointer -> next;
    }
    return minEle;
}

// Function to find the middle element of the list
int findMiddle(Node* &head, Node* &tail){
    int len = lengthOfList(head, tail);
    int middlePos = len/2;

    int curPos = 0;
    Node* pointer = head;
    while(curPos < middlePos){
        pointer = pointer -> next;
        curPos++;
    }
    return pointer->data;
}

// Function to merge two sorted linked list
pair<Node*, Node*> mergeList(Node* &head1, Node* &head2){
    Node* pointer1 = head1;
    Node* pointer2 = head2;

    Node* newHead = NULL;
    Node* newTail = NULL;

    while(pointer1 != NULL && pointer2 != NULL){
        if(pointer1 -> data < pointer2 -> data){
            insertAtTail(newHead, newTail, pointer1 -> data);
            pointer1 = pointer1 -> next;
        }
        else{
            insertAtTail(newHead, newTail, pointer2 -> data);
            pointer2 = pointer2 -> next;
        }
    }

    while(pointer1 != NULL){
        insertAtTail(newHead, newTail, pointer1 -> data);
        pointer1 = pointer1 -> next;
    }

    while(pointer2 != NULL){
        insertAtTail(newHead, newTail, pointer2 -> data);
        pointer2 = pointer2 -> next;
    }
    
    pair<Node*, Node*> newList = make_pair(newHead, newTail);
    return newList;
}

// Function to detect cycles in list
bool detectCycle(Node* &head){
    Node* slowPointer = head;
    Node* fastPointer = head;

    bool flag = true;
    while(fastPointer != NULL && fastPointer -> next != NULL){
        slowPointer = slowPointer -> next;
        fastPointer = fastPointer -> next -> next;

        if(slowPointer == fastPointer){
            return true;
        }
    }
    return false;
}

// Function to create a cycle in list
void makeCycle(Node* &head, int pos){
    Node* startNode;
    Node* pointer = head;
    int curPos = 1;
    while(pointer -> next != NULL){
        if(curPos == pos){
            startNode = pointer;
            pointer = pointer -> next;
            curPos++;
        }
        else{
            pointer = pointer -> next;
            curPos++;
        }
    }
    pointer -> next = startNode;
}

// Function to remove cycle from list
void removeCycle(Node* &head){
    Node* slowPointer = head;
    Node* fastPointer = head;

    do{
        slowPointer = slowPointer -> next;
        fastPointer = fastPointer -> next -> next;
    }
    while(slowPointer != fastPointer);

    fastPointer = head;
    while(fastPointer -> next != slowPointer -> next){
        slowPointer = slowPointer -> next;
        fastPointer = fastPointer -> next;
    }
    slowPointer -> next = NULL;
}

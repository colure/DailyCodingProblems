
// Problem6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cinttypes>

using namespace std;

//Class 1
//Helper Node Structure class
class Node {
    public: int data;
    //Xor of next node and previous node
    Node* xnode;
};

//XOR value of node address
Node* Xor(Node* x, Node* y) {
    return reinterpret_cast<Node*>(
        reinterpret_cast<uintptr_t>(x) ^ reinterpret_cast<uintptr_t>(y));
}

//insert node at start of XOR linked list and mark new node as head
void insert(Node** head_ref, int data) {
    //memory for new node
    Node* new_node = new Node();
    new_node->data = data;

    //xnode of new node will be XOR of current head and null
    new_node->xnode = *head_ref;

    //if not empty, xnode of head node will be xor of new node and
    //node next to current head
    if (*head_ref != NULL) {
        //*(head_ref)0>xnode is xor of null and next
        //if xor null w next get next
        (*head_ref)->xnode = Xor(new_node, (*head_ref)->xnode);
    }

    //change head
    *head_ref = new_node;
}

//print out contents of doubly linked list
void printList(Node* head) {
    Node* curr = head;
    Node* prev = NULL;
    Node* next;

    cout << "Nodes of Linked List are: \n";

    while (curr != NULL) {
        //print current node
        cout << curr->data << " ";
        //get addr of next node: curr->node is next^prev, curr->xnode^prev will
        //be next^prev^prev which is next
        next = Xor(prev, curr->xnode);
        //update prev and curr for next iteration
        prev = curr;
        curr = next;
    }
}

int main()
{
    Node* head = NULL;
    insert(&head, 10);
    insert(&head, 100);
    insert(&head, 1000);
    insert(&head, 10000);

    //print created list!
    printList(head);
    return(0);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu


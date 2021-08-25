//Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
//k is a positive integer and is less than or equal to the length of the linked list.
//If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
//You may not alter the values in the list's nodes, only nodes themselves may be changed.

#include<iostream>

struct Node{
    int data;
    Node* next;
};

class Solution{
public:
    head;
public:
    Node* createNewNode(int num){
        Node* newNode = new Node();
        newNode->data = num;
        newNode->next = NULL;
        return newNode;
    }
    void insertAtEnd(int num){
        Node* newNode = createNewNode(num);
        if(head == NULL){
            head = newNode;
        }
        else{
            Node* ptr = head;
            while(ptr->next != NULL){
                ptr = ptr->next;
            }
            ptr->next = newNode;
        }
    }
    void reverseKNodes(){
        Node* preptr = NULL;
        Node* ptr = head;
        Node* postptr = head;
        while(ptr!=NULL){}
    }
    void printLinkedList(){
        Node* ptr = head;
        while(ptr!=NULL){
            std::cout << ptr->data << " ";
            ptr = ptr->next;
        }
        std::cout << endl;
    }
};

int main(){

    return 0;
}

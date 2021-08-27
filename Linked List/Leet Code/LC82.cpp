//Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
//Return the linked list sorted as well.

#include<iostream>

struct Node{
    int data;
    Node* next;
};

class Solution{
public:
    Node* head;
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
            while(ptr->next!=NULL){
                ptr = ptr->next;
            }
            ptr->next = newNode;
        }
    }
    void deleteDuplicates(){
        Node* ptr = head;
        while(ptr!=NULL){
            Node* tempPtr = ptr->next;
            Node* preTempPtr = ptr;
            while(tempPtr!=NULL){
                if(ptr->data == tempPtr->data){
                    preTempPtr->next = tempPtr->next;
                    tempPtr->next = NULL;
                    free(tempPtr);
                    tempPtr = preTempPtr->next;
                }
                else{
                    preTempPtr = tempPtr;
                    tempPtr = tempPtr->next;
                }
            }
            ptr = ptr->next;
        }
    }
    void printLinkedList(){
        Node* ptr = head;
        while(ptr!=NULL){
            std::cout << ptr->data << " ";
            ptr = ptr->next;
        }
        std::cout << std::endl;
    }
};

int main(){
    Solution list = Solution();
    list.head = NULL;
    list.insertAtEnd(1);
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(2);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.printLinkedList();
    list.deleteDuplicates();
    list.printLinkedList();
    return 0;
}

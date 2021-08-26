//Given the head of a linked list, rotate the list to the right by k places.

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
    void rotateByKToRight(int k){
        for(int i=0;i<k;i++){
            Node* ptr = head;
            while(ptr->next->next != NULL){
                ptr = ptr->next;
            }
            Node* lastNode = ptr->next;
            ptr->next = NULL;
            lastNode->next = head;
            head = lastNode;
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
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.insertAtEnd(5);
    list.insertAtEnd(6);
    list.insertAtEnd(7);
    list.insertAtEnd(8);
    list.insertAtEnd(9);
    list.printLinkedList(); //1 2 3 4 5 6 7 8 9
    list.rotateByKToRight(3);
    list.printLinkedList(); //7 8 9 1 2 3 4 5 6
    return 0;
}

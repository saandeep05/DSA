//Given a linked list, swap every two adjacent nodes and return its head.
//You must solve the problem without modifying the values in the list's nodes
//(i.e., only nodes themselves may be changed.)
#include <iostream>

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
    void swapNodes(){
        if(head==NULL || head->next==NULL){
            std::cout << "List has less than 2 nodes" << std::endl;
        }
        else{
            Node* preptr = NULL;
            Node* ptr = head;
            Node* postptr = head->next;
            while(postptr!=NULL){
                ptr->next = postptr->next;
                postptr->next = ptr;
                preptr = ptr;
                if(ptr == head){
                    head = postptr;
                }
                ptr = ptr->next;
                if(ptr==NULL){
                    break;
                }
                else{
                    postptr = ptr->next;
                    if(postptr != NULL){
                        preptr->next = postptr;
                    }
                }
            }
        }
    }
    void printLinkedList(){
        Node* ptr = head;
        while(ptr!=NULL){
            std::cout << ptr->data << " ";
            ptr = ptr->next;
        }
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
    list.insertAtEnd(10);
    //list.printLinkedList();
    list.swapNodes();
    list.printLinkedList();

    return 0;
}

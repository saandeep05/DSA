//Given the head of a linked list, remove the nth node from the end of the list and return its head.
#include<iostream>

//using class

struct Node{
    int data;
    Node* next;
};
Node* head;
int count;

class Solution{
    int count = 0;
public:
    Node* createNewNode(int num){
        Node* newNode = new Node();
        newNode->data = num;
        newNode->next = NULL;
        return newNode;
    }
    void insertAtBeginning(int num){
        Node* newNode = createNewNode(num);
        if(head == NULL){
            head = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
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

    void NthFromLast(Node* node,int n){
        if(node == NULL){
            return;
        }
        else{
            NthFromLast(node->next,n);
            count++;
            if(count == n+1){
                Node* temp = node->next; // to free the memory allocated to this node, later;
                node->next = node->next->next;
                node->next->next = NULL;
                free(temp);
                //std::cout << node->data;
                return;
            }
        }
    }
};

void printLinkedList(Node* node){
    if(node == NULL){
        return;
    }
    else{
        std::cout << node->data << " ";
        printLinkedList(node->next);
    }
}

int main(){
    head = NULL;
    Solution obj = Solution();
    obj.insertAtEnd(1);
    obj.insertAtEnd(2);
    obj.insertAtEnd(3);
    obj.insertAtEnd(4);
    obj.insertAtEnd(5);
    obj.NthFromLast(head,2);
    printLinkedList(head);
    return 0;
}

//without using class

/*
Node* createNewNode(int num){
    Node* newNode = new Node();
    newNode->data = num;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(int num){
    Node* newNode = createNewNode(num);
    newNode->data = num;
    if(head == NULL){
        head = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
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

void NthFromLast(Node* node,int n){
    if(node == NULL){
        return;
    }
    else{
        NthFromLast(node->next,n);
        count++;
        if(count == n){
            std::cout << node->data;
        }
    }
}

int main() {
    head = NULL;
    count = 0;
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(3);
    insertAtEnd(4);
    insertAtEnd(5);
    NthFromLast(head,2);
    return 0;
}
*/

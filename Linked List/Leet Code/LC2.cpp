//You are given two non-empty linked lists representing two non-negative integers.
//The digits are stored in reverse order, and each of their nodes contains a single digit.
//Add the two numbers and return the sum as a linked list.
#include<iostream>

struct Node{
    int data;
    Node* next;
};
Node* head1;
Node* head2;

int count1;
int count2;

int num1;
int num2;

Node* createNewNode(int num){
    Node* newNode = new Node();
    newNode->data = num;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning1(int num){
    Node* newNode = createNewNode(num);
    newNode->data = num;
    if(head1 == NULL){
        head1 = newNode;
    }
    else{
        newNode->next = head1;
        head1 = newNode;
    }
}

void insertAtBeginning2(int num){
    Node* newNode = createNewNode(num);
    newNode->data = num;
    if(head2 == NULL){
        head2 = newNode;
    }
    else{
        newNode->next = head2;
        head2 = newNode;
    }
}

int findNumber1(Node* node){
    if(node == NULL){
        return 0;
    }
    else{
        num1 = findNumber1(node->next)*10 + node->data;
        return num1;
    }
}

int findNumber2(Node* node){
    if(node == NULL){
        return 0;
    }
    else{
        num2 = findNumber2(node->next)*10 + node->data;
        return num2;
    }
}

int Sum(Node* head1,Node* head2){
    num1 = findNumber1(head1);
    num2 = findNumber2(head2);
    return num1 + num2;
}

int main(){
    insertAtBeginning1(1);
    insertAtBeginning1(2);
    insertAtBeginning1(3);

    insertAtBeginning2(4);
    insertAtBeginning2(5);
    insertAtBeginning2(6);

    std::cout << Sum(head1,head2);
    return 0;
}

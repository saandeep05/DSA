//merge 2 sorted lists;
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
    void printLinkedList(){
        Node* ptr = head;
        while(ptr!=NULL){
            std::cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }
};

Solution mergeLists(Node* head1,Node* head2){
    Solution list3 = Solution();
    list3.head = NULL;
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    while(ptr1 != NULL || ptr2 != NULL){
            if(ptr1 != NULL && ptr2 == NULL){
                list3.insertAtEnd(ptr1->data);
                ptr1 = ptr1->next;
            }
            else if(ptr1 == NULL && ptr2 != NULL){
                list3.insertAtEnd(ptr2->data);
                ptr2 = ptr2->next;
            }
            else if(ptr1->data < ptr2->data){
                list3.insertAtEnd(ptr1->data);
                ptr1 = ptr1->next;
            }
            else if(ptr1->data > ptr2->data){
                list3.insertAtEnd(ptr2->data);
                ptr2 = ptr2->next;
            }
            else if(ptr1->data == ptr2->data){
                list3.insertAtEnd(ptr1->data);
                list3.insertAtEnd(ptr2->data);
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
    }
    return list3;
}

int main(){
    Solution list1 = Solution();
    Solution list2 = Solution();
    list1.head = NULL;
    list2.head = NULL;

    list1.insertAtEnd(1);
    list1.insertAtEnd(2);
    list1.insertAtEnd(3);

    list2.insertAtEnd(1);
    list2.insertAtEnd(3);
    list2.insertAtEnd(4);

    list1.printLinkedList();
    std::cout << std::endl;
    list2.printLinkedList();
    std::cout << std::endl;

    Solution list3 = mergeLists(list1.head,list2.head);
    list3.printLinkedList();
    return 0;
}

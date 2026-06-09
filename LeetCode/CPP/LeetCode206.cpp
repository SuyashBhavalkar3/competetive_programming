#include<iostream>
#include<vector>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int datad){
        data = datad;
        next = nullptr;
    }
};

Node* head = nullptr;

Node* reverseLinkedList(Node* head){
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;
    while (curr!=nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
};

int main(){
    Node* newNode = new Node(1);
    newNode->next = new Node(2);
    newNode->next->next = new Node(3);
    newNode->next->next->next = new Node(4);
    newNode->next->next->next->next = new Node(5);
    Node* newHead = reverseLinkedList(newNode);
    cout<<"[";
    while(newHead!=nullptr){
        cout<<newHead->data;
        newHead = newHead->next;
        if(newHead!=nullptr)
        cout<<", ";
    }
    cout<<"]";
    return 0;
}
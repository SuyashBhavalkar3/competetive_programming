// There is a singly-linked list head and we want to delete a node node in it.

// You are given the node to be deleted node. You will not be given access to the first node of head.

// All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.

// Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:

// The value of the given node should not exist in the linked list.
// The number of nodes in the linked list should decrease by one.
// All the values before node should be in the same order.
// All the values after node should be in the same order.

// Look For Reference In the Book-2 On Pg No 147


#include<iostream>

using namespace std;

struct ListNode{
    ListNode* next;
    int val;
    ListNode(int v){
        val = v;
        next = nullptr;
    };
};

void nodeToDel(ListNode* node){
    ListNode* nodeToDel = node->next;
    node->val = node->next->val;
    node->next = node->next->next;
    delete nodeToDel;
}

int main(){
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);
    ListNode* head2 = head;
    cout<<"Linked List Before : "<<endl;
    while(head2!=nullptr){
        cout<<head2->val<<" ";
        head2 = head2->next;
    }
    cout<<endl;
    nodeToDel(head->next);
    head2 = head;
    cout<<"Linked List After : "<<endl;
    while(head2!=nullptr){
        cout<<head2->val<<" ";
        head2 = head2->next;
    }
    return 0;
}
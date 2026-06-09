// Given the head of a singly linked list, return the middle node of the linked list.

// If there are two middle nodes, return the second middle node.

// Look For Reference In the Book On Pg No 41-42


#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
    ListNode* next;
    int val;
    ListNode(int v){
        val = v;
        next = nullptr;
    }
};

ListNode* findMiddle(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
};

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);

    ListNode* res = findMiddle(head);
    cout<<"[";
    while(res!=nullptr){
        cout<<res->val;
        res= res->next;
        if(res!=nullptr)
        cout<<", ";
    }
    cout<<"]";
    return 0;
}
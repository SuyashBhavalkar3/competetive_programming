// You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists into one sorted list.
// The list should be made by splicing together the nodes of the first two lists.

// Return the head of the merged linked list.

// Look For Reference In the Book On Pg No 58-59


#include<iostream>
#include<vector>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int v){
        val = v;
        next = nullptr;
    }
};

ListNode* mergeTwoLists(ListNode* head1, ListNode* head2){
    ListNode* dummy = new ListNode(0);
    ListNode* res = dummy;
    if(head1 == nullptr)    return head2;
    if(head2 == nullptr)    return head1;
    while(head1!=nullptr && head2!=nullptr){
        if(head1->val<head2->val){
            res->next = head1;
            head1 = head1->next;
        }
        else{
            res->next = head2;
            head2 = head2->next;
        }
        res = res->next;
    }
    if(head1!=nullptr){
        res->next = head1;
    }
    if(head2!=nullptr){
        res->next = head2;
    }
    return dummy->next;
};

int main(){
    ListNode* head1 = new ListNode(1);
    ListNode* head2 = new ListNode(1);
    head1->next = new ListNode(2);
    head2->next = new ListNode(3);
    head1->next->next = new ListNode(4);
    head2->next->next = new ListNode(4);
    ListNode* newTemp = mergeTwoLists(head1, head2);
    while(newTemp!=nullptr){
        cout<<newTemp->val<<" ";
        newTemp = newTemp->next;
    }
    return 0;
};
// Given the head of a linked list, rotate the list to the right by k places.

// Look For Reference In the Book-3 On Pg No 8-9


#include<iostream>
#include<vector>

using namespace std;

struct ListNode{
    ListNode* next;
    int val;
    ListNode(int v){
        val = v;
        next = nullptr;
    };
};

ListNode* rotate_list(ListNode* head, int k){
    if(head==nullptr||head->next==nullptr||k==0)    return head;
    ListNode* temp = head;
    int count = 1;
    while(temp->next!=nullptr){
        temp = temp->next;
        count++;
    }
    temp->next = head;
    k = k%count;
    if(k==0){
        temp->next = nullptr;
        return head;
    }
    int stepSToK = count - k;
    ListNode* tail = head;
    for(int i=1;i<stepSToK;i++){
        tail = tail->next;
    }
    ListNode* newHead = tail->next;
    tail->next = nullptr;
    return newHead;
};

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    ListNode* res = rotate_list(head, 2);
    while(res!=nullptr){
        cout<<res->val<<" ";
        res = res->next;
    }
    return 0;
}
// Problem Statement: Given a linked list containing ‘N’ head nodes where every node in the linked list contains two pointers:

// ‘Next’ points to the next node in the list
// ‘Child’ pointer to a linked list where the current node is the head

// Each of these child linked lists is in sorted order and connected by a 'child' pointer.
// Your task is to flatten this linked list such that all nodes appear in a single layer or level in a 'sorted order'.

// Look For Reference In the Book-3 On Pg No 4-5


#include<iostream>
#include<vector>

using namespace std;

struct ListNode{
    ListNode* next;
    ListNode* child;
    int val;
    ListNode(int v){
        val = v;
        next = nullptr;
        child = nullptr;
    }
};

ListNode* mergeLL(ListNode* l1, ListNode* l2){
    ListNode* dummy = new ListNode(-1);
    ListNode* res = dummy;
    while(l1!=nullptr && l2!=nullptr){
        if(l1->val<=l2->val){
            res->child = l1;
            res = res->child;
            l1 = l1->child;
        }
        else{
            res->child = l2;
            res = res->child;
            l2 = l2->child;
        }
        res->next = nullptr;
    };
    if(l1!=nullptr){
        res->child = l1;
    }
    else{
        res->child = l2;
    }
    return dummy->child;
};

ListNode* flattenLL(ListNode* head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    ListNode* mergeHead = flattenLL(head->next);
    head = mergeLL(head, mergeHead);
    return head;
};

int main(){
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->child = new ListNode(10);
    head->next->next = new ListNode(1);
    head->next->next->child = new ListNode(7);
    head->next->next->child->child = new ListNode(11);
    head->next->next->child->child->child = new ListNode(12);
    head->next->next->next = new ListNode(4);
    head->next->next->next->child = new ListNode(9); 
    head->next->next->next->next = new ListNode(5); 
    head->next->next->next->next->child = new ListNode(6);  
    head->next->next->next->next->child->child = new ListNode(8); 
    ListNode* result = flattenLL(head);
    while(result!=nullptr){
        cout<<result->val<<endl;
        result = result->child;
    }
    return 0;
}
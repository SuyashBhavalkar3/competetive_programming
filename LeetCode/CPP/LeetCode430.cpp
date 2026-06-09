// You are given a doubly linked list, which contains nodes that have a next pointer, a previous pointer, and an additional child pointer.
// This child pointer may or may not point to a separate doubly linked list, also containing these special nodes.
// These child lists may have one or more children of their own, and so on, to produce a multilevel data structure as shown in the example below.

// Given the head of the first level of the list, flatten the list so that all the nodes appear in a single-level, doubly linked list.
// Let curr be a node with a child list. The nodes in the child list should appear after curr and before curr.next in the flattened list.

// Return the head of the flattened list. The nodes in the list must have all of their child pointers set to null.


// Look For Reference In the Book-2 On Pg No 22-23



#include<iostream>
#include<vector>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode* prev;
    ListNode* child;
    ListNode(int v){
        val = v;
        next = nullptr;
        prev = nullptr;
        child = nullptr;
    }
};

ListNode* dfs(ListNode* curr){
    ListNode* last = nullptr;
    while(curr!=nullptr){
        ListNode* next_ = curr->next;
        if(curr->child!=nullptr){
            ListNode* childTail = dfs(curr->child);
            ListNode* childHead = curr->child;
            curr->next = childHead;
            childHead->prev = curr;
            curr->child = nullptr;
            if(next_!=nullptr){
                childTail->next = next_;
                next_->prev = childTail;
            }
            last = childTail;
            curr = childTail;
        }else{
            last = curr;
        }
        curr = curr->next;
    }
    return last;
};

ListNode* flatten(ListNode* head){
    dfs(head);
    return head;
};

int main(){
    ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->prev = head;
        head->next->next = new ListNode(3);
        head->next->next->prev = head->next;
        head->next->next->child = new ListNode(7);
        head->next->next->child->next = new ListNode(8);
        head->next->next->child->next->prev = head->next->next->child;
        head->next->next->child->next->child = new ListNode(11);
        head->next->next->child->next->child->next = new ListNode(12);
        head->next->next->child->next->child->next->prev = head->next->next->child->next->child;
        head->next->next->child->next->next = new ListNode(9);
        head->next->next->child->next->next->prev = head->next->next->child->next;
        head->next->next->child->next->next->next = new ListNode(10);
        head->next->next->child->next->next->next->prev = head->next->next->child->next->next;
        head->next->next->next = new ListNode(4);
        head->next->next->next->prev = head->next->next;
        head->next->next->next->next = new ListNode(5);
        head->next->next->next->next->prev = head->next->next->next;
        head->next->next->next->next->next = new ListNode(6);
        head->next->next->next->next->next->prev = head->next->next->next->next;

    ListNode* res = flatten(head);
    while(res!=nullptr){
        cout<<res->val<<" ";
        res = res->next;
    }
    return 0;
}
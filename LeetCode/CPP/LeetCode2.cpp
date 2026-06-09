// You are given two non-empty linked lists representing two non-negative integers.
// The digits are stored in reverse order, and each of their nodes contains a single digit.
// Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Look For Reference In the Book-2 On Pg No 148-149


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

ListNode* ll_after_add_two(ListNode* list1, ListNode* list2){
    ListNode* res = new ListNode(-1);
    ListNode* dummy = res;
    int carry = 0;
    while(list1!=nullptr||list2!=nullptr||carry!=0){
        int sum = 0;
        if(list1!=nullptr){
            sum+=list1->val;
            list1 = list1->next;
        }
        if(list2!=nullptr){
            sum+=list2->val;
            list2 = list2->next;
        }
        sum+=carry;
        carry = sum/10;
        ListNode* node = new ListNode(sum%10);
        dummy->next = node;
        dummy = dummy->next;
    }
    return res->next;
}

int main(){
    ListNode* list1Head = new ListNode(2);
    list1Head->next = new ListNode(4);
    list1Head->next->next = new ListNode(3);
    ListNode* list2Head = new ListNode(5);
    list2Head->next = new ListNode(6);
    list2Head->next->next = new ListNode(4);
    ListNode* res = ll_after_add_two(list1Head, list2Head);
    cout<<"List1 : "<<endl;
    while(list1Head!=nullptr){
        cout<<list1Head->val<<" ";
        list1Head = list1Head->next;
    }
    cout<<endl;
    cout<<"List2 : "<<endl;
    while(list2Head!=nullptr){
        cout<<list2Head->val<<" ";
        list2Head = list2Head->next;
    }
    cout<<endl;
    ListNode* res1 = res;
    cout<<"Linked List After Adding : "<<endl;
    while(res1!=nullptr){
        cout<<res1->val<<" ";
        res1 = res1->next;
    }
    return 0;
}
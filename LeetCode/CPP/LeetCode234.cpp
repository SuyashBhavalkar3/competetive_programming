// Given the head of a singly linked list, return true if it is a palindrome or false otherwise->
// Look For Reference In the Book On Pg No 82-83

#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int v){
        val = v;
        next = nullptr;
    }
};

ListNode* reverse(ListNode* head){
    ListNode* prev = nullptr;
    ListNode* nextNode;
    ListNode* curr = head;
    while(curr!=nullptr){
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

bool isPalindrome(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast!=nullptr&&fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* secondHalf = reverse(slow);
    ListNode* firstHalf = head;
    while(secondHalf!=nullptr){
        if(firstHalf->val!=secondHalf->val){
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    return true;
}

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    bool res = isPalindrome(head);
    cout<<boolalpha;
    cout<<"The Linked List Is Palindrome : "<<res<<endl;
    return 0;
}
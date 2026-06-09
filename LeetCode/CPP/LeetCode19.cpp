// Given the head of a linked list, remove the nth node from the end of the list and return its head.

// Look For Reference In the Book-2 On Pg No 150 - 151


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

ListNode* remove_nth_from_rear(ListNode* head, int n){
    ListNode* fast = head;
    for(int i=0;i<n;i++){
        fast = fast->next;
    }
    if(fast==nullptr)   return head->next;
    ListNode* slow = head;
    while(fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next;
    }
    ListNode* nodeToDel = slow->next;
    slow->next = slow->next->next;
    delete nodeToDel;
    return head;
};

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    cout<<"LinkedList Before : "<<endl;
    ListNode* temp1 = head;
    while(temp1!=nullptr){
        cout<<temp1->val<<" ";
        temp1 = temp1->next;
    }
    cout<<endl;
    ListNode* result = remove_nth_from_rear(head, 2);
    cout<<"LinkedList After : "<<endl;
    ListNode* temp = result;
    while(temp!=nullptr){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    return 0;
}
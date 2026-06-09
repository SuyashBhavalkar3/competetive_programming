// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

// k is a positive integer and is less than or equal to the length of the linked list.
// If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

// You may not alter the values in the list's nodes, only nodes themselves may be changed.

// Look For Reference In the Book-3 On Pg No 6-7


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

ListNode* findKthNode(ListNode* head, int k){
    k--;
    while(head!=nullptr && k>0){
        head = head->next;
        k--;
    }
    return head;
}

ListNode* reverseLinkedList(ListNode* head){
    ListNode* prev = nullptr;
    while(head!=nullptr){
        ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

ListNode* reverseInGroupK(ListNode* head, int k){
    ListNode* temp = head;
    ListNode* prevNode = nullptr;
    while(temp!=nullptr){
        ListNode* KthNode = findKthNode(temp, k);
        if(KthNode==nullptr){
            if(prevNode!=nullptr){
                prevNode->next = temp;
            }
            break;
        }

        ListNode* nextNode = KthNode->next;
        KthNode->next = nullptr;

        ListNode* newHead = reverseLinkedList(temp);

        if(temp==head){
            head = newHead;
        }
        else{
            prevNode->next = newHead;
        }
        prevNode = temp;
        temp = nextNode;
    }
    return head;
}

int main(){
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for(int i = 1; i <= 10; i++){
        ListNode* newNode = new ListNode(i);
        if(head == nullptr){
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    ListNode* res = reverseInGroupK(head, 3);
    ListNode* temp2 = res;
    while(temp2!=nullptr){
        cout<<temp2->val<<" ";
        temp2 = temp2->next;
    }
    cout<<endl;
    return 0;
};
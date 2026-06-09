// Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
// Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed).
// It is -1 if there is no cycle. Note that pos is not passed as a parameter.

// Do not modify the linked list.

// Look For Reference In the Book-2 On Pg No 15


#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int v){
        val = v;
        next = nullptr;
    }
};

ListNode* detectNode(ListNode* head){
    if(head == nullptr) return nullptr;
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            slow = head;
            while(slow!=fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return nullptr;
};

int main(){
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head;
    unordered_map<ListNode*, int> map;
    int cnt=0;
    while(head!=nullptr){
        if(map.count(head)){
            break;
        }
        map[head] = cnt++;
        head = head->next;
    }
    ListNode* result = detectNode(head);
    cout<<"Cycle Is At Node "<<map[result]<<endl;
    return 0;
}
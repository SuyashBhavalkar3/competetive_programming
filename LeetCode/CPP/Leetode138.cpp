#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

struct Node{
    int val;
    Node* next;
    Node* random;
    Node(int v){
        val = v;
        next = nullptr;
        random = nullptr;
    }
};

Node* cloneLL(Node* head){
    if(head == nullptr){
        return head;
    }
    unordered_map<Node*, Node*> map;
    Node* newHead = new Node(head->val);
    Node* oldTmp = head->next;
    Node* newTmp = newHead;
    map[head] = newHead;
    while(oldTmp!=nullptr){
        Node* copyNode = new Node(oldTmp->val);
        map[oldTmp] = copyNode;
        newTmp->next = copyNode;
        oldTmp = oldTmp->next;
        newTmp = newTmp->next;
    }
    oldTmp = head;
    newTmp = newHead;
    while(oldTmp!=nullptr){
        newTmp->random = map[oldTmp->random];
        oldTmp = oldTmp->next;
        newTmp = newTmp->next;
    }
    return newHead;
};

int main(){
    Node* head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(1);
    head->random = nullptr;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head;
    Node* newHead = cloneLL(head);
    Node* tmp = newHead;
    while(tmp!=nullptr){
        cout<<"Node val: "<<tmp->val<<", Random val: ";
        if(tmp->random!=nullptr){
            cout<<tmp->random->val<<endl;
        }else{
            cout<<"nullptr"<<endl;
        }
        tmp = tmp->next;
    }
    return 0;
};

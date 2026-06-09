// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

// Implement the LRUCache class:

// LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
// int get(int key) Return the value of the key if the key exists, otherwise return -1.
// void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
// The functions get and put must each run in O(1) average time complexity.


// Look For Reference In the Book-2 On Pg No 58-59


#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

struct Node{
    int key, val;
    Node* next;
    Node* prev;
    Node(int k, int v){
        key = k;
        val = v;
        next = prev = nullptr;
    };
};

class LRUCache{
    public:
        unordered_map<int, Node*> map;
        int limit;
        Node* head = new Node(-1, -1);
        Node* tail = new Node(-1, -1);
        LRUCache(int capacity){
            limit = capacity;
            head->next = tail;
            tail->prev = head;
        };
        void addNode(Node* nodeToAdd){
            Node* oldNext = head->next;
            oldNext->prev = nodeToAdd;
            head->next = nodeToAdd;
            nodeToAdd->next = oldNext;
            nodeToAdd->prev = head;
        };
        void deleteNode(Node* nodeToDel){
            Node* prevOfDel = nodeToDel->prev;
            Node* nextOfDel = nodeToDel->next;
            prevOfDel->next = nextOfDel;
            nextOfDel->prev = prevOfDel;
        };
        int get(int key){
            if(map.find(key)==map.end()){
                return -1;
            }
            Node* ansNode = map[key];
            int ans = ansNode->val;
            deleteNode(ansNode);
            addNode(ansNode);
            return ans;
        };
        void put(int key, int val){
            if(limit==0) return;
            if(map.find(key)!=map.end()){
                Node* existing = map[key];
                deleteNode(existing);
                map.erase(existing->key);
                delete existing;
            }
            if(map.size()==limit){
                Node* lru = tail->prev;
                deleteNode(lru);
                map.erase(lru->key);
                delete lru;
            }
            Node* newNode = new Node(key, val);
            addNode(newNode);
            map[key]=newNode;
        };
};

int main(){
    int capacity;
    cout<<"Enter capacity of LRU Cache: ";
    cin>>capacity;
    LRUCache* lru = new LRUCache(capacity);
    lru->put(1, 1);
    lru->put(2, 2);
    cout<<lru->get(1)<<endl;
    lru->put(3, 3);
    cout<<lru->get(2)<<endl;
    lru->put(4, 4);
    cout<<lru->get(1)<<endl;
    cout<<lru->get(3)<<endl;
    cout<<lru->get(4)<<endl;
    return 0;
};
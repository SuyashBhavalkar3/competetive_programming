#include<iostream>
#include<unordered_map>

using namespace std;

struct Node{
    int key, val, cnt;
    Node* next;
    Node* prev;
    Node(int key_, int val_){
        key = key_;
        val = val_;
        cnt = 1;
        next = nullptr;
        prev = nullptr;
    }
};

struct List{
    int size;
    Node* head;
    Node* tail;
    List(){
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        size = 0;
        head->next = tail;
        tail->prev = head;
    }
    void addNode(Node* node){
        Node* temp = head->next;
        head->next = node;
        node->next = temp;
        node->prev = head;
        temp->prev = node;
        size++;
    }
    void removeNode(Node* node){
        Node* prevDel = node->prev;
        Node* nexDel = node->next;
        prevDel->next = nexDel;
        nexDel->prev = prevDel;
        size--;
    }
};

class LFU_cache{
    private:
        unordered_map<int, Node*> keyNode;
        unordered_map<int, List*> freqListMap;
        int maxCapacity;
        int minFreq;
        int currSize;
    public:
        LFU_cache(int capacity){
            maxCapacity = capacity;
            minFreq = 0;
            currSize = 0;
        }
    void updateFreqListMap(Node* node){
        freqListMap[node->cnt]->removeNode(node);
        if(node->cnt==minFreq && freqListMap[node->cnt]->size==0){
            minFreq++;
        }
        node->cnt++;
        if(freqListMap.find(node->cnt)==freqListMap.end()){
            freqListMap[node->cnt] = new List();
        }
        freqListMap[node->cnt]->addNode(node);
    }
    int get(int key){
        if(keyNode.find(key)!=keyNode.end()){
            Node* node = keyNode[key];
            int val = node->val;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }
    void put(int key, int value){
        if(maxCapacity==0){
            return;
        }
        if(keyNode.find(key)!= keyNode.end()){
            Node* node = keyNode[key];
            node->val = value;
            updateFreqListMap(node);
            return;
        }
        else{
            if(currSize==maxCapacity){
                List* list = freqListMap[minFreq];
                Node* lru = list->tail->prev;
                keyNode.erase(lru->key);
                list->removeNode(lru);
                delete lru;
                currSize--;
            }
            currSize++;
            minFreq = 1;
            if(freqListMap.find(minFreq)==freqListMap.end()){
                freqListMap[minFreq] = new List();
            }
            List* listFreq = freqListMap[minFreq];
            Node* node = new Node(key, value);
            listFreq->addNode(node);
            keyNode[key] = node;
        }
    }
};

int main(){
    LFU_cache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << " ";
    cache.put(3, 3);
    cout << cache.get(2) << " ";
    cout << cache.get(3) << " ";
    cache.put(4, 4);
    cout << cache.get(1) << " ";
    cout << cache.get(3) << " ";
    cout << cache.get(4) << " ";
    return 0;
};
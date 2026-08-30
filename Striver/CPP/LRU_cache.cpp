#include <iostream>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
  struct Node {
    int key, value;
    Node *next;
    Node *prev;
    Node(int key_, int val_) {
      key = key_;
      value = val_;
      next = nullptr;
      prev = nullptr;
    }
  };
  int capacity;
  Node *head;
  Node *tail;
  unordered_map<int, Node *> map;
  LRUCache(int cap_) {
    capacity = cap_;
    head = new Node(-1, -1);
    tail = new Node(-1, -1);
    head->next = tail;
    tail->prev = head;
  }
  void addNode(Node *node) {
    Node *temp = head->next;
    head->next = node;
    node->next = temp;
    temp->prev = node;
    node->prev = head;
  }
  void removeNode(Node *node) {
    Node *prevDel = node->prev;
    Node *nextDel = node->next;
    prevDel->next = nextDel;
    nextDel->prev = prevDel;
  }
  int get(int key) {
    if (map.find(key) == map.end()) {
      return -1;
    }
    Node *node = map[key];
    removeNode(node);
    addNode(node);
    return node->value;
  }
  void put(int key, int value) {
    if (map.find(key) != map.end()) {
      Node *node = map[key];
      removeNode(node);
      map.erase(key);
      delete node;
    }
    if (map.size() == capacity) {
      Node *lru = tail->prev;
      map.erase(lru->key);
      removeNode(lru);
      delete lru;
    }
    Node *newNode = new Node(key, value);
    addNode(newNode);
    map[key] = newNode;
  }
};

int main() {
  LRUCache lru(2);
  lru.put(1, 1);
  lru.put(2, 2);
  cout << lru.get(1) << endl;
  lru.put(3, 3);
  cout << lru.get(2) << endl;
  lru.put(4, 4);
  cout << lru.get(1) << endl;
  cout << lru.get(3) << endl;
  cout << lru.get(4) << endl;
  return 0;
}
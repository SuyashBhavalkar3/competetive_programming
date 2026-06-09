// Given a reference of a node in a connected undirected graph.

// Return a deep copy (clone) of the graph.

// Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

// class Node {
//     public int val;
//     public List<Node> neighbors;
// }

// Look For Reference In the Book-2 On Pg No 9


#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

struct Node{
    int val;
    vector<Node*> neighbours;
    Node(){
        val = 0;
        neighbours = vector<Node*>();
    };
    Node(int _val){
        val = _val;
        neighbours = vector<Node*>();
    };
    Node(int _val, vector<Node*> _neighbours){
        val = _val;
        neighbours = _neighbours;
    };
};

Node* dfs(Node* node, unordered_map<Node*, Node*>& visited){
    if(visited.find(node)!=visited.end()){
        return visited[node];
    }
    Node* clone = new Node(node->val);
    visited[node] = clone;
    for(Node* neigh : node->neighbours){
        clone->neighbours.push_back(dfs(neigh, visited));
    }
    return clone;
};

Node* clone_graph(Node* node){
    if(node == nullptr){
        return nullptr;
    }
    unordered_map<Node*, Node*> visited;
    return dfs(node, visited);
};

int main(){
    Node* root1 = new Node(1);
    Node* root2 = new Node(2);
    root1->neighbours.push_back(root2);
    root2->neighbours.push_back(root1);
    Node* clone = clone_graph(root1);
    cout<<"Original : "<<"Node is "<<root1->val<<" And Neighbour Is "<<root1->neighbours[0]->val<<endl;
    cout<<"Cloned : "<<"Node Is "<<clone->val<<" And Neighbour Is "<<clone->neighbours[0]->val<<endl;
    return 0;
};


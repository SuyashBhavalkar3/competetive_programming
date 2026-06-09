// Given a reference of a node in a connected undirected graph.

// Return a deep copy (clone) of the graph.

// Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

// class Node {
//     public int val;
//     public List<Node> neighbors;
// }

// Look For Reference In the Book-2 On Pg No 9


import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class LeetCode133 {
    public static class Node{
        int val;
        List<Node> neighNodes = new ArrayList<>();
        Node(int v, List<Node> neigh){
            val = v;
            neighNodes = (neigh==null)? new ArrayList<>() : neigh;
        }
    }
    public static Node dfs(Node nodeRoot, HashMap<Node, Node> visited){
        if(visited.containsKey(nodeRoot)){
            return visited.get(nodeRoot);
        }
        Node clone = new Node(nodeRoot.val, new ArrayList<>());
        visited.put(nodeRoot, clone);
        for(Node neigh : nodeRoot.neighNodes){
            clone.neighNodes.add(dfs(neigh, visited));
        }
        return clone;
    }
    public static Node cloneGraph(Node nodeRoot){
        if(nodeRoot==null){
            return null;
        }
        HashMap<Node, Node> visited = new HashMap<>();
        return dfs(nodeRoot, visited);
    }
    public static void main(String[] args) {
        Node root1 = new Node(1, new ArrayList<>());
        Node root2 = new Node(2, new ArrayList<>());
        root1.neighNodes.add(root2);
        root2.neighNodes.add(root1);
        Node clone = cloneGraph(root1);
        System.out.println("Original: " + root1.val + ", neighbors: " + root1.neighNodes.get(0).val);
        System.out.println("Cloned:   " + clone.val + ", neighbors: " + clone.neighNodes.get(0).val);
    }
}

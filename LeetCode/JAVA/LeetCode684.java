// In this problem, a tree is an undirected graph that is connected and has no cycles.

// You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added.
// The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed.
// The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

// Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

// Look For Reference In the Book On Pg No 142



import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class LeetCode684{
    public static int findParent(int u, int[] parent){
        if(parent[u]!=u){
            parent[u] = findParent(parent[u], parent);
        }
        return parent[u];
    }
    public static boolean union(int u, int v, int[] parent){
        int pu = findParent(u, parent);
        int pv = findParent(v, parent);
        if(pu==pv){
            return false;
        }
        parent[pv] = pu;
        return true;
    }
    public static int[] findRedundant(int V, List<int[]> edges){
        int[] parent = new int[V+1];
        for(int i=1;i<=V;i++){
            parent[i] = i;
        }
        for(int[] edge : edges){
            int u = edge[0];
            int v = edge[1];
            if(!union(u, v, parent)){
                return edge;
            }
        }
        return new int[0];
    }
    public static void main(String[] args) {
        try(Scanner sc = new Scanner(System.in)){
            System.out.print("Enter Vertices : ");
            int V = sc.nextInt();
            System.out.print("Enter Edges : ");
            int E = sc.nextInt();
            List<int[]> Edges = new ArrayList<>();
            for(int i=0;i<E;i++){
                int u = sc.nextInt();
                int v = sc.nextInt();
                Edges.add(new int[]{u, v});
            }
            System.out.println("Redundant Edge Is : ");
            int[] res = findRedundant(V, Edges);
            for(int num : res){
                System.out.print(num+" ");
            }
        }
    }
}
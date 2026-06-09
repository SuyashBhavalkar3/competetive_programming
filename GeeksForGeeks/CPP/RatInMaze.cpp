// Consider a rat placed at position (0, 0) in an n x n square matrix maze[][]. The rat's goal is to reach the destination at position (n-1, n-1). The rat can move in four possible directions: 'U'(up), 'D'(down), 'L' (left), 'R' (right).

// The matrix contains only two possible values:

// 0: A blocked cell through which the rat cannot travel.
// 1: A free cell that the rat can pass through.
// Your task is to find all possible paths the rat can take to reach the destination, starting from (0, 0) and ending at (n-1, n-1), under the condition that the rat cannot revisit any cell along the same path. Furthermore, the rat can only move to adjacent cells that are within the bounds of the matrix and not blocked.
// If no path exists, return an empty list.

// Note: Return the final result vector in lexicographically smallest order.


// Look For Reference In the Book-2 On Pg No 54-55


#include<iostream>
#include<vector>
#include<string>

using namespace std;

void helper(vector<vector<int>>& maze, int r, int c, vector<string>& paths, string path, int n){
    if(r<0||c<0||r>n-1||c>n-1||maze[r][c]!=1){
        return;
    }
    if(r==n-1 && c==n-1){
        paths.push_back(path);
        return;
    }
    maze[r][c] = 0;
    helper(maze, r-1, c, paths, path+"U", n);
    helper(maze, r+1, c, paths, path+"D", n);
    helper(maze, r, c-1, paths, path+"L", n);
    helper(maze, r, c+1, paths, path+"R", n);
    maze[r][c] = 1;
}

vector<string> getAns(vector<vector<int>>& maze){
    int n = maze.size();
    vector<string> paths;
    string path = "";
    helper(maze, 0, 0, paths, path, n);
    return paths;
};

int main()
{
    vector<vector<int>> maze = {{1, 0, 0, 0},
                                {1, 1, 0, 1},
                                {1, 1, 0, 0},
                                {0, 1, 1, 1}};
    vector<string> paths = getAns(maze);
    for(string path : paths){
        cout<<path<<endl;
    }
    return 0;
};
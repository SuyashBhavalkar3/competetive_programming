#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

void helper(int i, int j, int n, int m,vector<vector<int>>& image, int newColor, int ogColor, vector<vector<bool>>& visited){
    if(i<0||j<0||i>=n||j>=m||image[i][j]!=ogColor||visited[i][j]==true){
        return;
    }
    visited[i][j] = true;
    image[i][j] = newColor;
    helper(i+1, j, n, m, image, newColor, ogColor, visited);
    helper(i-1, j, n, m, image, newColor, ogColor, visited);
    helper(i, j+1, n, m, image, newColor, ogColor, visited);
    helper(i, j-1, n, m, image, newColor, ogColor, visited);
    return;
}

vector<vector<int>> flood_fill_algo(vector<vector<int>>& image, int sr, int sc, int newColor){
    int ogColor = image[sr][sc];
    if(ogColor==newColor){
        return image;
    }
    int n = image.size();
    int m = image[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    helper(sr, sc, n, m, image, newColor, ogColor, visited);
    return image;
}

int main(){
    vector<vector<int>> image = { {0, 1, 0}, 
                                  {1, 1, 0}, 
                                  {0, 0, 1} };
    int sr = 1;
    int sc = 1;
    int newColor = 2;
    vector<vector<int>> floodfill = flood_fill_algo(image, sr, sc, newColor);
    for(auto arr : floodfill){
        for(int num : arr){
            cout<<num<<" ";
        }
        cout<<endl;
    }
}
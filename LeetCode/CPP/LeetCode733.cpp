// You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image.
// You are also given three integers sr, sc, and color.
// Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

// Look For Reference In the Book On Pg No 130-131



#include<iostream>
#include<vector>
using namespace std;
void dfs(int sr,int sc,int color,int og,vector<vector<int>>& image){
    if(sr<0||sc<0||sr>=image.size()||sc>=image[0].size())   return;
    if(image[sr][sc]!=og||image[sr][sc]==color) return;
    image[sr][sc]=color;
    dfs(sr+1,sc,color,og,image);
    dfs(sr-1,sc,color,og,image);
    dfs(sr,sc+1,color,og,image);
    dfs(sr,sc-1,color,og,image);
}
vector<vector<int>> floodfill(int sr,int sc,vector<vector<int>>& image,int color){
    int og = image[sr][sc];
    if(og!=color){
        dfs(sr,sc,color,og,image);
    }
    return image;
}
int main(){
    vector<vector<int>> image= {{1,1,0},
                                {1,1,0},
                                {1,0,1}};
    cout<<"New Image Dimensions Are : "<<endl;
    for(auto &row: floodfill(1,1,image,2)){
        for(int ele : row){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}
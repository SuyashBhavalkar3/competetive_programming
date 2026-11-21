#include <iostream>
#include <vector>

using namespace std;

void dfs(int city, vector<bool>& visited, vector<vector<int>>& component){
    visited[city] = true;
    int n = component.size();
    for(int nextCity=0;nextCity<n;nextCity++){
        if(component[city][nextCity]==1 && visited[nextCity]==false){
            dfs(nextCity, visited, component);
        }
    }
};

int find_provinces(vector<vector<int>>& components){
    int n = components.size();
    vector<bool> visited(n, false);
    int provinces = 0;
    for(int city = 0; city<n ; city++){
        if(visited[city]==false){
            provinces++;
            dfs(city, visited, components);
        }
    }
    return provinces;
};

int main(){
    vector<vector<int>> components = {{1,1,0},{1,1,0},{0,0,1}};
    int cnt = find_provinces(components);
    cout<<"The Number Of Provinces Are : "<<cnt<<endl;
    return 0;
}
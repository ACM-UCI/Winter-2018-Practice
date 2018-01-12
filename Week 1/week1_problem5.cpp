// ACM @ UCI
// Week 1 Problem 6
// https://www.hackerrank.com/challenges/even-tree

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;

int removes = 0;
int n,m;

int dfs( int node){
    int count = 0;    
    vis[node] = true;

    for(int i=0;i<adj[node].size();i++){
        int next = adj[node][i];
        
        if(!vis[next]){
            int cc = dfs(next);
            count += cc;
            if(cc % 2 == 0)
               removes++;       
        }    
    }
    
    return count + 1;
}


int main() {
    cin >> n >> m;
    adj = vector<vector<int>>(n);
    vis = vector<bool>(n);
    
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        u--; v--;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(0);
    
    if(n % 2 == 1)
        cout << 0 << endl;
    else
        cout << removes << endl;
    
    return 0;
}

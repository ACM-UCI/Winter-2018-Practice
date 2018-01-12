// ACM @ UCI
// Week 1 Problem 6
// https://www.hackerrank.com/challenges/bfsshortreach
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<queue>
using namespace std;


int main() {
    int q;
    cin >> q;
    while(q--){
        
        int n,m;
        cin >> n >> m;
        
        vector<vector<int> > adj (n);
        vector<int> dist(n, -1);
        
        for(int i=0;i<m;i++){
            int u,v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
            
        }
        int s;
        cin >> s;
        s--;
        
        queue<int> q;
        q.push(s);
        dist[s] = 0;
        while(q.size() > 0){
            
            int node = q.front();
            q.pop();
            
            for(int j=0;j<adj[node].size(); j++){
                int next = adj[node][j];
                if (dist[next] < 0){
                    dist[next] = dist[node] + 6;
                    q.push(next);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(i != s)
                cout << dist[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

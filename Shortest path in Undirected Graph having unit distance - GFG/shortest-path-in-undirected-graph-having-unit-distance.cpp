//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int M, int src){
        // code here
        vector<vector<int>> adjList(n);
        for (auto it:edges){
            int u=it[0];
            int v=it[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        vector<int> vis(n,0);
        vector<int> dist(n,-1);
        queue<pair<int,int>> q;
        q.push({src,0});
        vis[src]=1;
        dist[src]=0;
        while(!q.empty()){
            auto node=q.front().first;
            auto currD=q.front().second;
            q.pop();
            for (auto it:adjList[node]){
                if (!vis[it]){
                    vis[it]=1;
                    q.push({it,currD+1});
                    dist[it]=currD+1;
                }
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
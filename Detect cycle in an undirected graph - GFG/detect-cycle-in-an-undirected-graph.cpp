//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool BFS(vector<int> adj[],vector<int> &vis,int V,int src){
        vector<int> parent(V,0);
        queue<int> q;
        q.push(src);
        vis[src]=1;
        parent[src]=-1;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            for (auto it:adj[node]){
                if (!vis[it]){
                    q.push(it);
                    vis[it]=1;
                    parent[it]=node;
                }
                else if (vis[it] and it!=parent[node]) return true;
            }
        }
        return false;
        
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        for (int it=0;it<V;it++){
            if (!vis[it]) {
               int ans = BFS(adj,vis,V,it);
               if (ans) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
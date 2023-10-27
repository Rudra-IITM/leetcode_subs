//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    void findBridge(int src, int parent, int &timer, vector<int> &tin, vector<int> &low, vector<int> &vis, vector<int> adj[], vector<vector<int>> &ans){
        vis[src]=1;
        tin[src]=timer,low[src]=timer;
        timer++;
        for (auto nbr: adj[src]){
            if (nbr==parent) continue;
            if (!vis[nbr]){
                findBridge(nbr, src, timer, tin, low, vis, adj, ans);
                low[src]=min(low[src], low[nbr]);
                if (tin[src] < low[nbr]) {
                    vector<int> temp={src,nbr};
                    sort(temp.begin(),temp.end());
                    ans.push_back(temp);
                }
            }
            else low[src]=min(low[src], low[nbr]);
        }
    }
	vector<vector<int>>criticalConnections(int V, vector<int> adj[]){
	    // Code here
	    vector<vector<int>> ans;
	    vector<int> vis(V,0), tin(V), low(V);
	    int timer=1;
	    findBridge(0, -1, timer, tin, low, vis, adj, ans);
	    sort(ans.begin(),ans.end());
	    return ans;
	}
};

//{ Driver Code Starts.

int main(){
	int tc;
    cin >> tc;
    while(tc--){
        int V, E;
        cin >> V >> E;
        vector<int>adj[V];
        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<vector<int>>ans = obj.criticalConnections(V, adj);
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
	return 0;
}
// } Driver Code Ends
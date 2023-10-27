//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int node, vector<vector<int>> &adjList, vector<int> &vis){
        vis[node]=1;
        for (auto it: adjList[node]){
            if (!vis[it]) dfs(it,adjList,vis);
        }
    }
    int numProvinces(vector<vector<int>> mat, int V) {
        // code here
        int n=mat.size(), cnt=0;
        vector<vector<int>> adjList(n);
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (mat[i][j]==1){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        vector<int> vis(n,0);
        for (int i=0; i<n; i++){
            if (!vis[i]) dfs(i,adjList,vis),cnt++;
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends
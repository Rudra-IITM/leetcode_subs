//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
       void bfs(int i, int j, vector<vector<int>> &vis, vector<vector<char>>& grid){
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j]=1;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int r=node.first, c=node.second;
            int dRow[]={0,1,0,-1,1,1,-1,-1};
            int dCol[]={1,0,-1,0,1,-1,-1,1};
            for (int i=0; i<8; i++){
                int currR=r+dRow[i];
                int currC=c+dCol[i];
                if (currR>=0 and currR<vis.size() and currC>=0 and currC<vis[0].size() and !vis[currR][currC] and grid[currR][currC]=='1'){
                    q.push({currR,currC});
                    vis[currR][currC]=1;
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size(), m=grid[0].size(), cnt=0;
        vector<vector<int>> vis(n,vector<int> (m,0));
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (grid[i][j]=='1' and !vis[i][j]) bfs(i, j, vis, grid),cnt++;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends
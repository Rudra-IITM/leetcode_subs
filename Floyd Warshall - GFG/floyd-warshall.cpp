//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&dist){
	    // Code here
	    int n=dist.size();
	    for (int src=0; src<n; src++){
	            for (int dest=0; dest<n; dest++){
	                if (dist[src][dest]==-1) dist[src][dest]=1e9;
	            }
	    }
	    for (int hlpr=0; hlpr<n; hlpr++){
	        for (int src=0; src<n; src++){
	            for (int dest=0; dest<n; dest++){
	                if (dist[src][hlpr]!=-1)
	                    dist[src][dest]=min(dist[src][dest], dist[src][hlpr]+dist[hlpr][dest]);
	            }
	        }
	    }
	     for (int src=0; src<n; src++){
	            for (int dest=0; dest<n; dest++){
	                if (dist[src][dest]==1e9) dist[src][dest]=-1;
	            }
	    }
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
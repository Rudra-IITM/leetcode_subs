//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int util(int W, int wt[], int val[], int n, vector<vector<int>> &dp){
        if (n == 0){
            if (W-wt[n] >= 0) return val[n];
            else return 0;
        }
        if (dp[n][W] != -1) return dp[n][W];
        int inc=0;
        if (W-wt[n]>=0) inc = val[n] + util( W-wt[n], wt, val, n-1, dp );
        int exc=util(W, wt, val, n-1, dp);
        return dp[n][W] = max(inc,exc);
    }
    
    
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n, vector<int> (W+1, 0));
       for (int w=wt[0]; w<=W; w++){
            if (W - wt[0] >= 0) dp[0][w] = val[0];
            else dp[0][w] = 0;
       }
       
       for (int it=1;it<n;it++){
           for (int w=0; w<=W ;w++){
                int inc=0;
                if (w-wt[it]>=0) inc = val[it] + dp[it-1][w-wt[it]];
                int exc=dp[it-1][w];
                dp[it][w]=max(inc,exc);
           }
        }
        
        return dp[n-1][W];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
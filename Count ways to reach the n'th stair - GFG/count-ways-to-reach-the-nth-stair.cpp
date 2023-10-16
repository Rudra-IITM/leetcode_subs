//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    long long mod=1000000007;
    
    int util(int n,vector<int> &dp){
        if (n<=1) return 1;
        if (dp[n]!=-1) return dp[n];
        int a = util(n-1,dp) % mod;
        int b = util(n-2,dp) % mod;
        dp[n] = (a+b) % mod;
        return dp[n];
    }
    int countWays(int n)
    {
        // your code here
        vector<int> dp(n+1,-1);
        return util(n,dp);
        
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends
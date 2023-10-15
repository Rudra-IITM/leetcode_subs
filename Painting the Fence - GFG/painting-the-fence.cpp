//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long mod=1000000007;
    long long util(int n,int k,vector<long long> &dp){
        if (n==1) return k % mod;
        if (n==2) return (k*k) % mod;
        if (dp[n]!=-1) return dp[n];
        long long a=util(n-2,k,dp) % mod;
        long long b=util(n-1,k,dp) % mod;
        return dp[n]=((a+b)*(k-1)) % mod;
    }
    long long countWays(int n, int k){
        // code here
        vector<long long> dp(n+1,-1);
        return util(n,k,dp) % mod;
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends
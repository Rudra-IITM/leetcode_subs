//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool util(vector<int> &arr, int sum, int i,vector< vector<int>> &dp){
        if (sum==0) return true;
        if (i>=arr.size() or sum<0) return false;
        if (dp[sum][i]!=-1) return dp[sum][i];
        bool inc = util(arr, sum-arr[i], i+1, dp);
        bool exc = util(arr, sum, i+1, dp);
        dp[sum][i] = (inc || exc);
        return inc or exc;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        if (arr.empty() and sum!=0) return false;
        int n=arr.size();
        vector< vector<int>> dp(sum+1, vector<int>(n+1,-1));
        return util(arr,sum,0,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends
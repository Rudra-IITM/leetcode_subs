//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int util(string &s1, string &s2,int i, int j,vector<vector<int>> &dp){
        if (i<0 or j<0) return 0;
        if (s1[i]==s2[j]) return 1 + util(s1,s2,i-1,j-1,dp);
        if (dp[i][j]!=-1) return dp[i][j];
        int a=util(s1,s2,i-1,j,dp);
        int b=util(s1,s2,i,j-1,dp);
        return dp[i][j]=max({a,b});
    }
    int countMin(string s1){
    //complete the function here
        string s2=s1;
        reverse(s2.begin(),s2.end());
        int n=s1.length();
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        return n-util(s1,s2,n-1,n-1,dp);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends
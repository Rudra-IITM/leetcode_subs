//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
    bool utilR(string &s, string &p, int i, int j, vector<vector<int>> &dp){
        if (i==s.length() && j==p.length()) return true;
        if (i==s.length() && j<p.length()){
            while(j<p.length()){
                if (p[j]!='*') return false;
                j++;
            }
            return true;
        }
        if (dp[i][j]!=-1) return dp[i][j];
        if (s[i]==p[j] or p[j]=='?') return dp[i][j]=utilR(s, p, i+1, j+1, dp);
        if (p[j]=='*'){
            bool exc = utilR(s, p, i, j+1, dp);
            bool inc = utilR(s, p, i+1, j, dp);
            return dp[i][j]=exc || inc;
        }
        return dp[i][j]=false;
    }

    int wildCard(string p,string s)
    {
        int n=s.length();
        int m=p.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return utilR(s, p, 0, 0, dp);
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends
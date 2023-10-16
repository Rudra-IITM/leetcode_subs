//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        int pre[n]={0},suff[n]={0};
        pre[0]=arr[0],suff[n-1]=arr[n-1];
        for (int i=1;i<n;i++) {
            pre[i]=max(pre[i-1],arr[i]);
            suff[n-i-1]=max(suff[n-i],arr[n-i-1]);
        }
        long long sm=0;
        for (int i=0;i<n;i++){
            long long val = min(pre[i],suff[i])-arr[i];
            sm+=val;
        }
        return sm;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends
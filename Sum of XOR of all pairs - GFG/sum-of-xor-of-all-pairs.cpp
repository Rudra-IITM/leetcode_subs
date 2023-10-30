//{ Driver Code Starts
// An efficient C++ program to compute 
// sum of bitwise OR of all pairs
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
long long int sumXOR(int arr[], int n)
{
    long long int sum = 0;
    
    for(int bit = 0;bit<32;bit++){
        long long ones = 0, zeros = 0; // at every bit we count the number of 1s present in array at that postion and 0
        
        for(int i=0;i<n;i++){
            if(arr[i] & (1<<bit)) ones++;
            else zeros++;
        }
        
        sum += (ones * zeros * (1<<bit)) ; // ones * zeroes will give all the permutations and we multiply by 2^i
    }
    
    return sum;
}
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	 int n ;
	 cin>>n;
	 int arr[n+1];
	 for( int i=0;i<n;i++)
	    cin>>arr[i];
	 Solution ob;
	 cout<<ob.sumXOR(arr, n)<<endl;
	}	
	return 0;
}

// } Driver Code Ends
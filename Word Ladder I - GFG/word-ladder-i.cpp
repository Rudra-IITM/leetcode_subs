//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Code here
        queue<pair<string,int>> q;
        unordered_set<string> st(wordList.begin(),wordList.end());
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty()){
            auto fNode=q.front();
            q.pop();
            string currW=fNode.first;
            int currCnt=fNode.second;
            if (currW==endWord) return currCnt;
            for (int i=0;i<currW.length();i++){
                string temp=currW;
                for (char ch='a'; ch<='z'; ch++){
                    currW[i]=ch;
                    if (st.find(currW)!=st.end()){
                        q.push({currW,currCnt+1});
                        st.erase(currW);
                    }
                }
                currW=temp;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
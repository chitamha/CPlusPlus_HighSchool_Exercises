//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<int>& A) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        int n=A.size(); long long ans=0;
        for (int i=0; i<n; i++) pq.push(A[i]);
        while (pq.size()>1){
            int tmp1=pq.top();
            pq.pop();
            int tmp2=pq.top();
            pq.pop();
            pq.push(tmp1+tmp2);
            ans+=tmp1+tmp2;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends

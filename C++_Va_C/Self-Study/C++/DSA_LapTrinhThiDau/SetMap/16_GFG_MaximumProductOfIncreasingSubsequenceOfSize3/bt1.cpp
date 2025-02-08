//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find the max product subsequence of size 3
// arr: given input array
// n: size of array
// res: array which contains the output
void maxProductSubsequence(int *A , int n, int res[])
{
    int Max[100005], MinMax[100005], ans=0;
    for (int i=n-2; i>=0; i--) Max[i]=max(Max[i+1], A[i+1]);
    multiset<int> mse;
    mse.insert(A[0]);
    for (int i=1; i<n; i++){
        mse.insert(A[i]);
        auto it=mse.lower_bound(A[i]);
	    if (it==mse.begin()) continue;
	    it--;
	    MinMax[i]=*it;
    }
    for (int i=1; i<=n-2; i++){
        if (Max[i]>A[i] && Max[i]!=0 && MinMax[i]!=0){
            if (Max[i]+MinMax[i]+A[i]>=ans){
                ans=Max[i]+MinMax[i]+A[i];
                res[0]=MinMax[i];
                res[1]=A[i];
                res[2]=Max[i];
            }
        }
    }
}


//{ Driver Code Starts.

// Driver Program
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

	int T;
	cin>>T;
	while(T--){
	    int num;
	    cin>>num;
	    int arr[num];
	    for(int i = 0; i<num; ++i)
	        cin>>arr[i];

	    int res[3] = {0};
	    maxProductSubsequence(arr, num, res);

	    if(res[0] == 0)
	        cout<<"-1" << endl;
	    else{
    	    for(int i = 0; i<3; ++i)
    	        cout<<res[i]<<" ";
    	    cout << endl;
	    }

cout << "~" << "\n";
}
}


// } Driver Code Ends

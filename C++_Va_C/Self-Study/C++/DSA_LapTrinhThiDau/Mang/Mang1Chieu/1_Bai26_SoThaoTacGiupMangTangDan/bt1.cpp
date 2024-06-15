#include <bits/stdc++.h>
using namespace std;
int main(){
    int dem=0;
    vector<int> A;
    int x;
    while (cin>> x)
        A.push_back(x);
    for (int i=1; i<A.size(); i++){
        if (A[i]<=A[i-1])
            dem+=A[i-1]+1-A[i];
    }
    cout<< dem;
    return 0;
}

/*#include <bits/stdc++.h>
using namespace std;

int n, K, ans=0;
set<int> se;
vector<int> A(100005);
int danhDau[100005];

int main(){
    cin>> n>> K;
    for (int i=1; i<=n; i++){
        cin>> A[i];
    }
    int l=1, r=1;
    for (l; l<=n; l++){
        while (se.size()<=K && r<=n){
            se.insert(A[r]);
            danhDau[A[r]]++;
            r++;
        }
        if (l>=n-K+1){
            ans+=r-l;
        } else ans+=r-l-1;
        if (danhDau[A[l]]!=1){
            danhDau[A[l]]--;
        } else{
            se.erase(A[l]);
            danhDau[A[l]]--;
        }
    }
    cout<< ans;
    return 0;
}*/
#include <bits/stdc++.h>
using namespace std;

int n, K, ans=0;
set<int> se;
vector<int> A(100005);
int danhDau[100005];

int main(){
    cin>> n>> K;
    for (int i=1; i<=n; i++){
        cin>> A[i];
    }
    int l=1, r=0;
    for (l; l<=n; l++){
        while (se.size()<=K && r<=n){
            r++;
            se.insert(A[r]);
            danhDau[A[r]]++;
        }
        ans+=r-l;
        if (danhDau[A[l]]!=1){
            danhDau[A[l]]--;
        } else{
            se.erase(A[l]);
            danhDau[A[l]]--;
        }
    }
    cout<< ans;
    return 0;
}


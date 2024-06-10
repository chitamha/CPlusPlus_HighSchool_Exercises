#include <bits/stdc++.h>
using namespace std;

int n, s;
vector<pair<int, int>> A;

int main(){
    cin>> s>> n;
    for (int i=0; i<n; i++){
        int level, gift;
        cin>> level>> gift;
        A.push_back({level, gift});
    }
    sort(A.begin(), A.end());
    for (int i=0; i<n; i++){
        if (s>A[i].first){
            s+=A[i].second;
        } else{
            cout<< "NO";
            return 0;
        }
    }
    cout<< "YES";
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin>> n;
    vector<pair<int, int>> C;
    for (int i=0; i<n; i++){
        int in, out;
        cin>> in>> out;
        C.push_back({in, 1});
        C.push_back({out, -1});
    }
    sort(C.begin(), C.end());
    //sort boi vi ta xet tai 1 thoi diem
    //nhu 1h, 2h, 3h (tang dan)... coi thoi
    //diem nao thi luong khach dong nhat
    int res=0, ans=-1e9;
    for (int i=0; i<2*n; i++){
        res+=C[i].second;
        ans=max(ans, res);
    }
    cout<< ans;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> hop, giao;
vector<int> v1, v2;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("HG.INP", "r", stdin);
    freopen("HG.OUT", "w", stdout);
    /*
    cin>> n>> m;
    v1.resize(n); v2.resize(m);
    for (int i=0; i<n; i++){
        cin>> v1[i];
        hop.push_back(v1[i]);
    }
    for (int i=0; i<m; i++){
        cin>> v2[i];
        if (binary_search(v1.begin(), v1.end(), v2[i])){
            giao.push_back(v2[i]);
        } else hop.push_back(v2[i]);
    }
    sort(hop.begin(), hop.end());
    for (int x:hop) cout<< x<< " ";
    cout<< endl;
    for (int x:giao) cout<< x<< " ";
    */
    // O(n+m)
    cin>> n>> m;
    v1.resize(n); v2.resize(m);
    for (int i=0; i<n; i++) cin>> v1[i];
    for (int j=0; j<m; j++) cin>> v2[j];
    int i=0, j=0;
    // sai chi khi mang v1 v2 khong duoc sap xep tang dan
    // va cac phan tu khong tang chat (khac nhau doi mot)
    // truong hop xau nhat O(n+m)
    while (i<n && j<m){
        if (v1[i]==v2[j]){
            giao.push_back(v1[i]);
            hop.push_back(v1[i]);
            i++;
            j++;
        } else if (v1[i]>v2[j]){
            hop.push_back(v2[j]);
            j++;
        } else{
            hop.push_back(v1[i]);
            i++;
        }
    }
    while (i<n){
        hop.push_back(v1[i]);
        i++;
    }
    while (j<m){
        hop.push_back(v2[j]);
        j++;
    }
    for (int x:hop) cout<< x<< " ";
    cout<< endl;
    for (int x:giao) cout<< x<< " ";
    return 0;
}

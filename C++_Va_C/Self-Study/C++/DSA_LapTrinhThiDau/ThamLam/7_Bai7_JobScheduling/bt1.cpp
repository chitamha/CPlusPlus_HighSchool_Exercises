#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> v;

int main(){
    cin>> n;
    for (int i=0; i<n; i++){
        int st, en;
        cin>> st>> en;
        v.push_back({en, st});
    }
    sort(v.begin(), v.end());
    for (int i=0; i<n; i++)
        cout<< "End: "<< v[i].first<< "; Start: "<< v[i].second<< endl;
    cout<< "Answer"<< endl;
    int endtime=v[0].first;
    int ans=1, i=1;
    cout<< "End: "<< v[0].first<< "; Start: "<< v[0].second<< endl;
    while (i<n){
        if (endtime<v[i].second){
            cout<< "End: "<< v[i].first<< "; Start: "<< v[i].second<< endl;
            ans++;
            endtime=v[i].first;
        }
        i++;
    }
    cout<< ans;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int n, l;
vector<double> v;
double ans=0;

double max_distance(vector<double> v, int n){
    double Max=0;
    for (int i=0; i<n-1; i++){
        Max=max(Max, v[i+1]-v[i]);
    }
    return Max;
}

int main(){
    cin>> n>> l;
    v.resize(n);
    for (int i=0; i<n; i++) cin>> v[i];
    sort(v.begin(), v.end());
    if (!binary_search(v.begin(), v.end(), 0) || !binary_search(v.begin(), v.end(), l)){
        ans=max({l-v[n-1], v[0], max_distance(v, n)/2});
    } else{
        ans=max_distance(v, n)/2;
    }
    cout<< fixed<< setprecision(10)<< ans;
    return 0;
}

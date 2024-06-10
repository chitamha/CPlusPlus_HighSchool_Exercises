#include <bits/stdc++.h>
using namespace std;

int n, m, k, ans=0;
vector<int> Person;
vector<int> Apartment;

int main(){
    cin>> n>> m>> k;
    for (int i=1; i<=n; i++){
        int x; cin>> x;
        Person.push_back(x);
    }
    for (int i=1; i<=m; i++){
        int x; cin>> x;
        Apartment.push_back(x);
    }
    sort(Person.begin(), Person.end());
    sort(Apartment.begin(), Apartment.end());
    int l=0, r=0;
    while (l<n && r<m){
        if (abs(Person[l]-Apartment[r])<=k){
            ans++;
            l++;
            r++;
        } else if (Person[l]-Apartment[r]>k){
            r++;
        } else{
            l++;
        }
    }
    cout<< ans;
    return 0;
}

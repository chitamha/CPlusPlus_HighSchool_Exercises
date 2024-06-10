#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n;
char A[10];
ll B[10];
ll used[10]={false};
vector<string> v1;
vector<string> v2;

void Ql1(ll i){
    for (ll j=1; j<=n; j++){
        if (!used[j]){
            A[i]=j;
            used[j]=true;
            if (i==n){
                string s="";
                for (ll h=1; h<=n; h++)
                    s+=char(A[h]+64);
                v1.push_back(s);
            } else Ql1(i+1);
            used[j]=false;
        }
    }
}

void Ql2(ll i){
    for (ll j=1; j<=n; j++){
        B[i]=j;
        if (i==n){
            string s="";
            for (ll h=1; h<=n; h++)
                s+=to_string(B[h]);
            v2.push_back(s);
        } else Ql2(i+1);
    }
}

int main(){
    cin>> n;
    Ql1(1);
    Ql2(1);
    for (string s1:v1)
        for (string s2:v2)
            cout<< s1<< s2<< endl;
    return 0;
}

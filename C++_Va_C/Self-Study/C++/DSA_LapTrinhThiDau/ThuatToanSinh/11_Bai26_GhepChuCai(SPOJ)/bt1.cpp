#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll n; char c;
ll A[100];
ll used[100]={false};

bool check(string s){
    ll left=0;
    while (left<s.size()){
        if (s[left]=='A' || s[left]=='E'){
            if (left-1>=0 && left+1<n && s[left-1]!='A' && s[left-1]!='E' && s[left+1]!='A' && s[left+1]!='E'){
                return false;
            }
        }
        left++;
    }
    return true;
}

void Ql(ll i){
    for (ll j=1; j<=n; j++){
        if (!used[j]){
            A[i]=j;
            used[j]=true;
            if (i==n){
                string s="";
                for (ll h=1; h<=n; h++)
                    s+=char(A[h]+64);
                if (check(s)) cout<< s<< endl;
            } else Ql(i+1);
            used[j]=false;
        }
    }
}

int main(){
    cin>> c;
    n=c-'A'+1;
    Ql(1);
    return 0;
}

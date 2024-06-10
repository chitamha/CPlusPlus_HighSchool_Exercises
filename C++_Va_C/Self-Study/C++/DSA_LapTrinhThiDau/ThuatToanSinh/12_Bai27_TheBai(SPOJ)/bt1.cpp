#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll n;
ll A[100];
ll used[100]={false};

bool check(string s){
    ll left=0;
    while (left<s.size()-1){
        if (abs(s[left]-s[left+1])==1) return false;
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
                    s+=to_string(A[h]);
                if (check(s)) cout<< s<< endl;
            } else Ql(i+1);
            used[j]=false;
        }
    }
}

int main(){
    cin>> n;
    Ql(1);
    return 0;
}

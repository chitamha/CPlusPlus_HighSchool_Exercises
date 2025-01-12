#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
using namespace std;

int siz, Le[]={1, 3, 7, 9}, F[20];

bool isprime(int x){
    for (int i=2; i<=sqrt(x); i++){
        if (x%i==0) return 0;
    }
    return x>=2;
}

int main(){
    freopen("SNGTO.INP", "r", stdin);
    freopen("SNGTO.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    deque<int> A1, A2;
    A1.push_back(2); A1.push_back(3);
    A1.push_back(5); A1.push_back(7);
    F[1]=4;
    siz=2;
    while (siz<=9){
        while (!A1.empty()){
            int x=A1.back(); A1.pop_back();
            for (int i=0; i<4; i++){
                int num=x*10+Le[i];
                if (isprime(num)) A2.push_back(num);
            }
        }
        for (int x:A2) A1.push_back(x);
        A2.clear();
        F[siz]=A1.size();
        siz++;
    }
    int t; cin>> t;
    while (t--){
        int n; cin>> n;
        cout<< F[n]<< endl;
    }
    return 0;
}

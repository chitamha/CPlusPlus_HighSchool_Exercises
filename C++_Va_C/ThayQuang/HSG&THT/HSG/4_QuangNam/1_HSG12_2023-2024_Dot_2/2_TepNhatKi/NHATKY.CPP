#include <bits/stdc++.h>
#define ll long long
#define maxn 1000006
using namespace std;

int n;
vector<ll> A; ll x, ans=0;
string s;

void process(){
    int siz=s.size();
    for (int i=0; i<siz; i++){
        if ((s[i]>='a' && s[i]<='z') || s[i]==' ') continue;
        int dau=1;
        if (s[i]=='-') dau=-1, i++;
        int so=0;
        while (s[i]>='0' && s[i]<='9'){
            so=so*10+s[i]-'0';
            i++;
        }
        A.push_back(so*dau);
    }
    //for (int x:A) cout<< x<< " "; cout<< endl;
    sort(A.begin(), A.end());
    for (int i=0; i<n; i++) ans+=upper_bound(A.begin()+i+1, A.end(), x-A[i])-lower_bound(A.begin()+i+1, A.end(), x-A[i]);
    cout<< ans;
}

int main(){
    freopen("NHATKY.INP", "r", stdin);
    freopen("NHATKY.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n; cin.ignore();
    getline(cin, s);
    cin>> x;
    process();
    return 0;
}

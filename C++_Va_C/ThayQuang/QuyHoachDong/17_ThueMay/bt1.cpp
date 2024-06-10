#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 10005
using namespace std;

int n, F[maxn], vet[maxn];
struct tim{
    int st, en, c, id;
    friend bool operator < (tim a, tim b){
        if (a.en!=b.en)
            return a.en<b.en;
        else return a.st<b.st;
    }
};
vector<tim> A(maxn);

int main(){
    //freopen("THUEMAY.INP", "r", stdin);
    //freopen("THUEMAY.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    for (int i=1; i<=n; i++){
        cin>> A[i].st>> A[i].en>> A[i].c;
        A[i].id=i;
    }
    sort(A.begin()+1, A.begin()+n+1);
    int en=1;
    for (int i=1; i<=n; i++){
        F[i]=A[i].c;
        for (int j=1; j<i; j++){
            if (A[i].st>=A[j].en && F[j]+A[i].c>F[i]){
                F[i]=F[j]+A[i].c;
                vet[i]=j;
            }
        }
        if (F[en]<F[i]) en=i;
    }
    /*
    for (int i=1; i<=n; i++) cout<< A[i].st<< " "<< A[i].en<< " "<< A[i].id<< endl;
    for (int i=1; i<=n; i++) cout<< vet[i]<< " ";
    cout<< endl;
    */
    int tmp=en;
    vector<int> tv;
    while (en>0){
        tv.push_back(en);
        en=vet[en];
    }
    cout<< tv.size()<< " "<< F[tmp]<< endl;
    for (int i=tv.size()-1; i>=0; i--) cout<< A[tv[i]].id<< " ";
    return 0;
}

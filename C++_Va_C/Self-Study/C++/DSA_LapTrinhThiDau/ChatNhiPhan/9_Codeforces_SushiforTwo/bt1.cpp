#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 100006
using namespace std;

int n;
vector<int> A;
int L[3][maxn], R[3][maxn];
//Ca ngu: 1; Ca hoi: 2

void dp(){
    for (int i=1; i<=n; i++) L[A[i]][i]=L[A[i]][i-1]+1;
    for (int i=n; i>=1; i--) R[A[i]][i]=R[A[i]][i+1]+1;
}

bool check(int le){
    for (int i=1; i<=n; i++){
        if ((L[1][i-1]>=le/2 && R[2][i]>=le/2) || (L[2][i-1]>=le/2 && R[1][i]>=le/2)) return 1;
        if ((L[1][i]>=le/2 && R[2][i+1]>=le/2) || (L[2][i]>=le/2 && R[1][i+1]>=le/2)) return 1;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    A.resize(n+10);
    for (int i=1; i<=n; i++) cin>> A[i];
    dp();
    /*
    cout<< "Left"<< endl;
    for (int i=1; i<=2; i++){
        for (int j=1; j<=n; j++) cout<< L[i][j]<< " ";
        cout<< endl;
    }
    cout<< "Right"<< endl;
    for (int i=1; i<=2; i++){
        for (int j=1; j<=n; j++) cout<< R[i][j]<< " ";
        cout<< endl;
    }
    */
    int l=1, r=n/2, ans=2, mid;
    while (l<=r){
        mid=(l+r)/2;
        //cout<< 2*mid<< " "<< check(2*mid)<< endl;
        if (check(2*mid)){
            ans=2*mid;
            l=mid+1;
        } else r=mid-1;
    }
    cout<< ans;
    return 0;
}
#include <bits/stdc++.h>
#define maxn 1000006
using namespace std;

long long A[maxn];
long long n, k, tong=0;

int main(){
    freopen("TRUCTUYEN.INP", "r", stdin);
    freopen("TRUCTUYEN.OUT", "w", stdout);
    cin>> n>> k;
    for (int i=1; i<=n; i++){
        cin>> A[i];
        tong+=A[i];
    }
    if (tong<k){
        cout<< -1;
        return 0;
    }
    long long key=1e9;
    long long songay;
    for (int i=1; i<=n; i++){
        tong=0;
        songay=0;
        int idx=i;
        while (tong<k && idx>=1){
            tong+=A[idx];
            songay++;
            idx--;

        }
        if (tong>=k)
            key=min(key, songay);
    }
    cout<< key;
    return 0;
}

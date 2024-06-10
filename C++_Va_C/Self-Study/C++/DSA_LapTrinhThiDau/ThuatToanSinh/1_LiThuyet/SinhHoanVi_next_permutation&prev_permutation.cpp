#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll n, A[100], cnt=1;

int main(){
    cin>> n;
    for (int i=1; i<=n; i++) A[i]=i;
    cout<< "IN"<< endl;
    do{
        cout<< cnt++<< ": ";
        for (ll i=1; i<=n; i++) cout<< A[i];
        cout<< endl;
    } while (next_permutation(A+1, A+n+1));
    cout<< "IN NGUOC"<< endl;
    reverse(A+1, A+n+1);
    cnt--;
    do{
        cout<< cnt--<< ": ";
        for (ll i=1; i<=n; i++) cout<< A[i];
        cout<< endl;
    } while (prev_permutation(A+1, A+n+1));
    return 0;
}

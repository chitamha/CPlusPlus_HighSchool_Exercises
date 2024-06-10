#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n=1;
ll A[100];
bool check=false;

void sinh(){
    //tim so tu nhien lon hon nho nhat voi so hien tai
    //tu nhung chu so da cho
    ll i=n-1;
    while (i>=1 && A[i]>A[i+1]){
        i--;
    }
    if (i==0) check=true;
    else{
        sort(A+i+1, A+n+1);
        auto it=upper_bound(A+i+1, A+n+1, A[i]);
        swap(A[i],*it);
    }
}

int main(){
    while (n!=0){
        cin>> n;
        ll giaithua=1;
        for (ll i=1; i<=n; i++){
            A[i]=i;
            giaithua*=i;
        }
        cout<< n<< "! = "<< giaithua<< endl;
        ll cnt=1;
        while (!check){
            cout<< cnt++<< ": ";
            for (ll i=1; i<=n; i++) cout<< A[i]<< " ";
            cout<< endl;
            sinh();
        }
        check=false;
    }
    return 0;
}

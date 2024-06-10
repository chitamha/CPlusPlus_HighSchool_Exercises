#include <bits/stdc++.h>
using namespace std;

bool check(int n){
    for (int i=2; i<=sqrt(n); i++){
        if (n%i==0){
            return 0;
        }
    }
    return n>1;
}
void ham(int l, int r){
    vector<int> prime(r-l+1, 1);
    for (int i=2; i<=sqrt(r); i++){
        for (int j=(l+i-1)/i*i; j<=r; j+=i){
            prime[j-l]=0;
        }
    }
    int dem=0;
    for (int i=l; i<=r; i++){
        int tong=0;
        if (prime[i-l]){
            bool checkNt=1;
            int so=i;
            while (so){
                tong+=so%10;
                if (!check(so%10)){
                    checkNt=0;
                    break;
                }
                so/=10;
            }
            if (checkNt && check(tong)){
                dem++;
                cout<< i<< endl;
            }
        }
    }
    cout<< dem;
}
int main(){
    int l, r;
    cin>> l>> r;
    ham(l, r);
}

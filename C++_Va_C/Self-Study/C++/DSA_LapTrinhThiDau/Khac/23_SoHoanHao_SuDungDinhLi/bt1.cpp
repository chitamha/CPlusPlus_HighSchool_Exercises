#include <bits/stdc++.h>
#define maxn 100000001
using namespace std;

long long n;
vector<long long> prime(maxn, 1);
vector<long long> chua;
void sang(){
    prime[1]=prime[0]=0;
    for (int i=2; i<=sqrt(maxn); i++){
        if (prime[i]){
            for (int j=i*i; j<=maxn; j+=i){
                prime[j]=0;
            }
        }
    }
}
bool checknt(long long n){
    for (int i=2; i<=sqrt(n); i++){
        if (n%i==0){
            return 0;
        }
    }
    return n>1;
}
int main(){
    freopen("nhap.inp", "r", stdin);
    freopen("xuat.out", "w", stdout);
    sang();
    for (int i=2; i<=32; i++){
        int tam=pow(2, i)-1;
        if (checknt(i) && checknt(tam)){
            cout<< pow(2, i-1)*tam<< endl;
        }
    }
    return 0;
}

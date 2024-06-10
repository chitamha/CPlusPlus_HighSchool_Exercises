#include <bits/stdc++.h>
using namespace std;

int n, ans=0;
int tien[]={1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};

int main(){
    cin>> n;
    for (int i=9; i>=0; i--){
        int cnt=n/tien[i];
        n=n-cnt*tien[i];
        ans+=cnt;
    }
    cout<< ans;
    return 0;
}

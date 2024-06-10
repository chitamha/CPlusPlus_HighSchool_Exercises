#include <bits/stdc++.h>
using namespace std;
int n;
double kq(int n){
    if (n==1){
        return 1;
    }
    else
    {
        return 1.0/n+kq(n-1);
    }
}
int main(){
    cin>> n;
    cout<< setprecision(4)<< kq(n);
}

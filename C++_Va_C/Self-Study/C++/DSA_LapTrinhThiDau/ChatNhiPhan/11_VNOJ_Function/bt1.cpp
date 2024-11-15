#include <bits/stdc++.h>
using namespace std;

int m, n, p;
long double a, b;

long double func(long double x){
    return m*pow(x, 3)+n*pow(x, 2)+p;
}

bool check(long double x, long double y){
    //cout<< func(x)<< " "<< func(y)<< " "<< func(x)*func(y)<< " "<< (func(x)*func(y)<0.0)<< endl;
    return func(x)*func(y)<0.0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> m>> n>> p>> a>> b;
    long double mid;
    for (int i=1; i<=200; i++){
        mid=1.0*(a+b)/2;
        if (check(mid, a)) b=mid;
        else a=mid;
    }
    cout<< fixed<< setprecision(4)<< mid;
    return 0;
}

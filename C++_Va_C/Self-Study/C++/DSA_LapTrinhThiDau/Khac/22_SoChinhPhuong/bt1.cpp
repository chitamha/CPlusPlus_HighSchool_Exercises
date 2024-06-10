#include <bits/stdc++.h>
using namespace std;

long long n;

// kiem tra xem la so chinh phuong hay khong
bool checkchinhphuong(long long n){
    long long a=sqrt(n);
    if (a*a==n){
        return 1;
    }
    return 0;
}

// dem so uoc cua n
long long dem(long long n){
    long long cnt=0;
    for (int i=1; i<=sqrt(n); i++){
        if (n%i==0){
            cnt++;
            if (i!=n/i){
                cnt++;
            }
        }
    }
    return cnt;
}

// tong uoc khac n
long long tonguoc(long long n){
    long long tong=1;
    for (int i=2; i<=sqrt(n); i++){
        if (n%i==0){
            tong+=i;
            if (i!=n/i){
                tong+=n/i;
            }
        }
    }
    return ((tong==n)&&(n>1));
}

int main(){
    int t; cin>> t;
    while (t--){
        cin>> n;
        if (checkchinhphuong(n)) cout<< n<< " la so chinh phuong"<< endl;
        else cout<< n<< " khong phai la so chinh phuong"<< endl;
        //cout<< n<< " co " << dem(n)<< " uoc"<< endl;
        if (tonguoc(n)) cout<< n<< " la so hoan hao"<< endl;
        else cout<< n<< " khong phai la so hoan hao"<< endl;
    }
}

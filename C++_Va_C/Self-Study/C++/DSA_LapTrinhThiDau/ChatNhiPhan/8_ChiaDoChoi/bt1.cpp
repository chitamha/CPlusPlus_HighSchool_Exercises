#include <bits/stdc++.h>
using namespace std;

int tong, n, m, maxA;
int A[300001];

void Nhap(){
    cin>> n>> m;
    for (int i=1; i<=m; i++){
        cin>> A[i];
        maxA=max(maxA, A[i]);
    }
}

bool check(int so){
    int sum=0;
    for (int i=1; i<=m; i++) sum+=(A[i]/so);
    return sum==n;
}

void Done(){
    int l=1, r=maxA, ans;
    while (l<=r){
        int mid=(l+r)/2;
        //cout<< "Truoc "<< l<< " "<< r<< " "<< mid<< " "<< ans<< endl;
        if (check(mid)){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
        //cout<< "Sau "<< l<< " "<< r<< " "<< mid<< " "<< ans<< endl;
    }
    int sum=0;
    for (int i=1; i<=m; i++) sum=max(sum, ans+A[i]%r);
    cout<< sum;
}

int main(){
    Nhap();
    Done();
    return 0;
}
/*
Input:
5 2
4 7
Output: 3
l r mid ans
Truoc 1 7 4 0
Sau 1 3 4 0
Truoc 1 3 2 0
Sau 3 3 2 2
Truoc 3 3 3 2
Sau 3 2 3 2
Toi dong 34:
sum=max(sum, ans+A[i]%r)
i=1; sum=max(0, 2+4%2)=2
i=2; sum=max(2, 2+7%2)=3
*/

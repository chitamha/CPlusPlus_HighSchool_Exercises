#include <bits/stdc++.h>
using namespace std;

int A[]={1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
int q, n, sl;
/*
    sotien=2352
    soluong=0
    + 1000
        soluong+=sotien/menhgia=2352/1000=2
        thua=2352%1000=352
        sotien=thua=352
    + 500
        soluong+=sotien/menhgia=352/500=0
        thua=352%500=352
        sotien=thua=352
    + 200
        soluong+=sotien/menhgia=352/200=1
        thua=352%200=152
        sotien=thua=152
    + 100
        soluong+=sotien/menhgia=152/100=1
        thua=152%100=52
        sotien=thua=52
    ...
    52=50+2 (2 to nua)
    Tong cong: 6
*/
int main(){
    cin>> q;
    while(q--){
        sl=0;
        int i=0;
        cin>> n;
        while (n!=0){
            sl+=n/A[i];
            n=n%A[i];
            i++;
        }
        cout<< sl<< endl;
    }
    return 0;
}

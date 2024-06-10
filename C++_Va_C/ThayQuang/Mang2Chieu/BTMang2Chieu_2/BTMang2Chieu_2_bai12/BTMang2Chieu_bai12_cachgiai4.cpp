#include <bits/stdc++.h>
using namespace std;

int a[1000][1000];
int n,m,k;

int main()
{
    cin>> n>> m;
    k=1;
    for(int i=1; i<=n; i++){
        if(i%2==0){
            for(int j=m; j>=1; j--){
                a[i][j]=k;
                k++;
            }
        }
        else{
            for(int j=1; j<=m; j++){
                a[i][j]=k;
                k++;
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout<< a[i][j]<< " ";
        }
        cout<< endl;
    }
    return 0;
}

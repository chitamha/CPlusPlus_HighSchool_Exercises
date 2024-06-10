#include <iostream>
using namespace std;
long long fibo[100];

void init(){
    fibo[0]=0;
    fibo[1]=1;
    for (int i=2; i<=90; i++){
        fibo[i]=fibo[i-1]+fibo[i-2];
    }
}

int main(){
    int n;
    cin>> n;
    init();
    int h1=0, c1=0, h2=n-1, c2=n-1, cnt=0;
    long long A[n][n];
    while (c1<=c2 && h1<=h2){
        for (int i=c1; i<=c2; i++){
            A[h1][i]=fibo[cnt];
            ++cnt;
        }
        ++h1;
        for (int i=h1; i<=h2; i++){
            A[i][c2]=fibo[cnt];
            ++cnt;
        }
        --c2;
        if (c2>=c1){
            for (int i=c2; i>=c1; i--){
                A[h2][i]=fibo[cnt];
                cnt++;
            }
            --h2;
        }
        if (h2>=h1){
            for (int i=h2; i>=h1; i--){
                A[i][c1]=fibo[cnt];
                cnt++;
            }
            ++c1;
        }
    }
    for (int i=0; i<n; i++){
                for (int j=0; j<n; j++){
                    cout<< A[i][j]<< " ";
                }
                cout<< endl;
            }
}

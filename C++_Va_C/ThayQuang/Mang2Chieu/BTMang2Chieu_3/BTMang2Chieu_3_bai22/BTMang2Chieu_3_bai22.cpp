#include <iostream>
#include <math.h>
using namespace std;
int A[1000][1000];
bool checkhang(int x, int i, int n, int A[][1000]){
    int nn=A[i][0];
    for (int j=0; j<n; j++){
        nn=fmin(A[i][j], nn);
    }
    return x==nn;
}

bool checkcot(int x, int j, int m, int A[][1000]){
    int ln=A[0][j];
    for (int i=0; i<m; i++){
        ln=fmax(A[i][j], ln);
    }
    return x==ln;
}

int main(){
    freopen("PTYN.INP", "r", stdin);
    freopen("PTYN.OUT", "w", stdout);
    int m, n;
    cin>> m>> n;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            cin>> A[i][j];
        }
    }
    bool kt=false;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (checkhang(A[i][j], i, n, A) && checkcot(A[i][j], j, m, A)){
                cout<< "("<< i+1<< ","<< j+1<< ")";
                kt=true;
            }
        }
    }
    if (!kt) cout<< "Khong co phan tu yen ngua";
}

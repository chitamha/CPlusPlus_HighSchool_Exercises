#include <iostream>
using namespace std;

/*void nhapMang(int n, int m, A[][1000000]){
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin>> A[i][j];
        }
    }
}

void xuatMang(int n, int m, A[][1000000]){
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout<< A[i][j]<< " ";
        }
        cout<< endl;
    }
}*/
int n, m, dem=1;
int main(){
    cin>> n>> m;
    int A[n][m];
    //nhapMang(n, m, A);
    //xuatMang(n, m, A);
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (i%2==0){
                cout<< dem<< " ";
                ++dem;
            } else{
                if (j==0){
                    dem+=m-1;
                }
                cout<< dem<< " ";
                --dem;
                if (j==m-1){
                    dem+=m+1;
                }
            }
        }
        cout<< endl;
    }
}

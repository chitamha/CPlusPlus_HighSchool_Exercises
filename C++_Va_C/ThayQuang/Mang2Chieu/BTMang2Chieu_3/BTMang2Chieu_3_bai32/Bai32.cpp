#include <bits/stdc++.h>
using namespace std;
int n, dem=0;
int main(){
    ifstream fin("SAPXEP.INP");
    ofstream fout("SAPXEP.OUT");
    fin>> n;
    int A[n][n], B[n][n], tam[n*n];
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            fin>> B[i][j];
            tam[dem]=B[i][j];
            dem++;
        }
    }
    sort(tam, tam+dem);
    dem=0;
    int h1=0, h2=n-1, c1=0, c2=n-1;
    while (h1<=h2 && c1<=c2){
        for (int i=c1; i<=c2; i++){
            A[h1][i]=tam[dem];
            ++dem;
        }
        ++h1;
        for (int i=h1; i<=h2; i++){
            A[i][c2]=tam[dem];
            ++dem;
        }
        --c2;
        for (int i=c2; i>=c1; i--){
            A[h2][i]=tam[dem];
            ++dem;
        }
        --h2;
        for (int i=h2; i>=h1; i--){
            A[i][c1]=tam[dem];
            ++dem;
        }
        ++c1;
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            fout<< A[i][j]<< " ";
        }
        fout<< endl;
    }
    fin.close();
    fout.close();
    return 0;
}

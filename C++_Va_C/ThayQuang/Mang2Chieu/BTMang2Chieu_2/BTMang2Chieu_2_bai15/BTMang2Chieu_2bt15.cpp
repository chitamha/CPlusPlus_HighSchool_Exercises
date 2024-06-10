/*#include <iostream>
#include <algorithm>
using namespace std;
int n, cnt=0;
int main(){
    freopen("SORT.INP", "r", stdin);
    freopen("SORT.OUT", "w", stdout);
    cin>> n;
    int A[n][n];
    int B[n*n];
    int dem=0;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin>> A[i][j];
            B[dem]=A[i][j];
            dem+=1;
        }
    }
    sort(B, B+n*n);
    int h1=0, h2=n-1, c1=0, c2=n-1;
    while (h1<=h2 && c1<=c2){
        for (int i=c1; i<=c2; i++){
            A[h1][i]=B[cnt];
            ++cnt;
        }
        ++h1;
        for (int i=h1; i<=h2; i++){
            A[i][c2]=B[cnt];
            ++cnt;
        }
        --c2;
        if (c1<=c2){
            for (int i=c2; i>=c1; i--){
                A[h2][i]=B[cnt];
                ++cnt;
            }
            --h2;
        }
        if (h1<=h2){
            for (int i=h2; i>=h1; i--){
                A[i][c1]=B[cnt];
                ++cnt;
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
*/
#include <iostream>
#include <algorithm>
using namespace std;

void nhapMang(int n, long long  A[][1000], long long B[]){
    int dem=0;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin>> A[i][j];
            B[dem]=A[i][j];
            dem+=1;
        }
    }
}

void sapXep(int n, long long B[]){
    sort(B, B+n*n);
}

int n, cnt=0;
int main(){
    /*freopen("SORT.INP", "r", stdin);
    freopen("SORT.OUT", "w", stdout);*/
    cin>> n;
    long long A[1000][1000];
    long long B[1000000];
    nhapMang(n, A, B);
    sapXep(n, B);

    int h1=0, h2=n-1, c1=0, c2=n-1;
    while (h1<=h2 && c1<=c2){
        for (int i=c1; i<=c2; i++){
            A[h1][i]=B[cnt];
            ++cnt;
        }
        ++h1;
        for (int i=h1; i<=h2; i++){
            A[i][c2]=B[cnt];
            ++cnt;
        }
        --c2;
        if (c1<=c2){
            for (int i=c2; i>=c1; i--){
                A[h2][i]=B[cnt];
                ++cnt;
            }
            --h2;
        }
        if (h1<=h2){
            for (int i=h2; i>=h1; i--){
                A[i][c1]=B[cnt];
                ++cnt;
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

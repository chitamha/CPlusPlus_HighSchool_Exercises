#include <iostream>
using namespace std;
int n, m;
int dx[]={-1, 0, 0, 1};
int dy[]={0, -1, 1, 0};
int A[100][100];
int dem=0;
int loang(int A[][100], int i, int j)
{   int check=0;
    if (A[i][j]==1){
        check=1;
        A[i][j]=0;
        for (int k=0; k<4; k++){
            int inew=i+dx[k];
            int jnew=j+dy[k];
            if (inew>=0 && inew<n && jnew>=0 && jnew<m) loang(A, inew, jnew);
        }
    }
    return check;
}
int main()
{
    cin>> n>> m;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin>> A[i][j];
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            dem+=loang(A, i, j);
        }
    }
    cout<< dem;
    return 0;
}

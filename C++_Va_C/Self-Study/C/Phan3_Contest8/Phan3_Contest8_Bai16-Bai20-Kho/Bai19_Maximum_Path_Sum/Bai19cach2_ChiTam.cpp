#include <bits/stdc++.h>
using namespace std;
int n, m;
int main()
{
    cin>> n>> m;
    int A[n+1][m+1];
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cin>> A[i][j];
        }
    }
    for (int i=0; i<m; i++) A[n][i]=0;
    for (int i=0; i<n; i++) A[i][m]=0;
    int i=0, j=0, sum=A[0][0];
    while (i<n && j<m){
        if(A[i][j+1]>=A[i+1][j])
        {
            sum+=A[i][j+1];
            j++;
        }
        else
        {
            sum+=A[i+1][j];
            i++;
        }
    }
    cout<< sum;
    return 0;
}

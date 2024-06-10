#include <iostream>
using namespace std;
void inXuoi(int A[], int n, int i)
{
    if (i==n-1){
        cout<< A[i];
    }
    else
    {
        cout<< A[i]<< " ";
        ++i;
        inXuoi(A, n, i);
    }
}
void inNguoc(int A[], int n, int i)
{
    if (i==0){
        cout<< A[i];
    }
    else
    {
        cout<< A[i]<< " ";
        --i;
        inNguoc(A, n, i);
    }
}
void inNguoc2(int A[], int n, int i)
{
    if (i==n-1){
        cout<< A[i]<< " ";
    }
    else
    {   ++i;
        inNguoc2(A, n, i);
        cout<< A[i-1]<< " ";
    }
}
int main()
{
    int n;
    cin>> n;
    int A[n];
    for (int i=0; i<n; i++){
        cin>> A[i];
    }
    int k=0;
    inXuoi(A, n, k);
    cout<< endl;
    k=n-1;
    inNguoc(A, n, k);
    k=0;
    cout<< endl;
    inNguoc2(A, n, k);
}

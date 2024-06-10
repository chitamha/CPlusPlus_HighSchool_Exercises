#include <iostream>
#include <math.h>
using namespace std;
int A[100001];
// A[i] la uoc so nguyen to nho nhat cua i
void sang(){
    for (int i=1; i<=100001; i++){
        A[i]=i;
    }
    for (int i=2; i<=sqrt(100001); i++){
        if (A[i]==i){
            for (int j=i*i; j<=100001; j+=i){
                if (A[j]==j){
                    A[j]=i;
                }
            }
        }
    }
}
int main()
{
    int n;
    cin>> n;
    sang();
    for (int i=1; i<n+1; i++){
        cout<< A[i]<< endl;
    }
}

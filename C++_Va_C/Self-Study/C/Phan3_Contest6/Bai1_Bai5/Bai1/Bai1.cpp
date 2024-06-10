#include <iostream>
#include <math.h>
using namespace std;
int NT[1000001];
void sangSo(){
    for (int i=0; i<1000001; i++){
        NT[i]=1;
    }
    NT[0]=NT[1]=0;
    for (int i=2; i<=sqrt(1000001); i++){
        if (NT[i]==1){
            for (int j=i*i; j<1000001; j+=i){
                NT[j]=0;
            }
        }
    }
}
int n, x;
int main()
{
    cin>> n;
    int A[n];
    sangSo();
    for (int i=0; i<n; i++){
        cin>> x;
        if (NT[x]) A[i]=1;
    }
    for (int i=0; i<n; i++){
        if (A[i]==1) cout<< "YES"<< endl;
        else cout<< "NO"<< endl;
    }
}

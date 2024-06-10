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
long long n;
int dem=0;
int main()
{
    cin>> n;
    sangSo();
    for (int h=1; h<=sqrt(n); h++){
        if (NT[h]){
            ++dem;
        }
    }
    cout<< dem;
}

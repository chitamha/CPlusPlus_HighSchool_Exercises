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
    for (int h=0; h<n; h++){
        cin>> x;
        for (int i=2; i<=x/2; i++){
            /*for (int j=x-1; j>=x/2; j--){
                if (NT[i] && NT[j] && (i+j)==x)
                    cout<< i<< " "<< j<< endl;
            }*/
            if (NT[i] && NT[x-i]){
                cout<< i<< " "<< x-i<< endl;
            }
        }
    }

}

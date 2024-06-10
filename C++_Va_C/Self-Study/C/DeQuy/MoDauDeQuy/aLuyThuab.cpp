#include <iostream>
#include <math.h>
using namespace std;
const int mod=1000000007;
long long lt(int a, int b){
    if (b==0){
        return 1;
    }
    else
    {   /*
        long long tam=lt(a, b/2);
        if (b%2==1){
            return (tam%mod)*(tam%mod)*(a%mod)%mod;
        }
        else
        {
            return (tam%mod)*(tam%mod)%mod;
        }
        */
         if (b%2==1){
            return (lt(a, b/2)%mod)*(lt(a, b/2)%mod)*(a%mod)%mod;
        }
        else
        {
            return (lt(a, b/2)%mod)*(lt(a, b/2)%mod)%mod;
        }
    }

}
int main(){
    int a, b;
    a=1;
    while(a!=0){
        cin>> a>> b;
        cout<< pow(a, b)<< endl;
        cout<< lt(a, b)<< endl;
    }
}

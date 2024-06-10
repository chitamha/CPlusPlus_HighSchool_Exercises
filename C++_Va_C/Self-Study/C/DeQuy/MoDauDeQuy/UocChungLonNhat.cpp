#include <iostream>
using namespace std;

int ucln(int a, int b){
    /*if (a==b){
        return a;
    }
    else
    {
        if (a>b){
            a=a-b;
            return ucln(a, b);
        }
        else{
            b=b-a;
            return ucln(a, b);
        }
    }*/
    if (b==0){
        return a;
    }
    else
    {
        return ucln(b, a%b);
    }
}
int main(){
    int a, b;
    cin>> a>> b;
    cout<< "Uocchunglonnhat la: "<< ucln(a, b);
}

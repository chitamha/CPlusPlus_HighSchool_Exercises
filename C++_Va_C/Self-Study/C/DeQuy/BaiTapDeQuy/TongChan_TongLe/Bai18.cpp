#include <iostream>
using namespace std;
bool chan(long long n){
    if (n%2==0) return true;
    else return false;
}
int sumchan=0, sumle=0;
int tongchan(long long n){
    if (n<10){
        if (chan(n)) return n;
    }
    else
    {
        if (chan(n%10))
            return n%10+tongchan(n/10);
        else return tongchan(n/10);
    }
}
int tongle(long long n){
    if (n<10){
        if (!chan(n)) return n;
    }
    else
    {
        if (!chan(n%10))
            return n%10+tongle(n/10);
        else return tongle(n/10);
    }
}
int main()
{
    long long n;
    cin>> n;
    cout<< tongchan(n)<< " "<< tongle(n);
}

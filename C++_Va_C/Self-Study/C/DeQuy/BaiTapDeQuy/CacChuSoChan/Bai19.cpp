#include <iostream>
using namespace std;
bool chan(long long n){
    if (n%2==0){
        return true;
    }
    else return false;
}
bool check(long long n){
    if (n<10){
        if (!chan(n))
            return false;
        else return true;
    }
    else
    {
        if (!chan(n%10))
            return false;
        else
        {
            return check(n/10);
        }
    }
}
int main(){
    int n;
    cin>> n;
    if (!check(n)){
        cout<< "NO";
    } else cout<< "YES";
}

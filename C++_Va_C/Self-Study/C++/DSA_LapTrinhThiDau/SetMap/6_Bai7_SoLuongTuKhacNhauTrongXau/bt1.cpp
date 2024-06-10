#include <bits/stdc++.h>
using namespace std;
int main(){
    string xau;
    set<string> s;
    while(cin>> xau){
        s.insert(xau);
    }
    cout<< s.size()<< endl;
    cout<< *(s.begin())<< " "<< *(s.rbegin());
    return 0;
}

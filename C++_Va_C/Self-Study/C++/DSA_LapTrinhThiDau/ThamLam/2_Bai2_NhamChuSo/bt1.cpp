#include <bits/stdc++.h>
#define ll long long
using namespace std;

string a, b;

string changeto6(string s){
    bool check=false;
    while (!check){
        if (s.find('5')==string::npos)
            check=true;
        else s[s.find('5')]='6';
    }
    return s;
}

string changeto5(string s){
    bool check=false;
    while (!check){
        if (s.find('6')==string::npos)
            check=true;
        else s[s.find('6')]='5';

    }
    return s;
}

ll Min(string x, string y){
    return stoll(changeto5(x))+stoll(changeto5(y));
}

ll Max(string x, string y){
    return stoll(changeto6(x))+stoll(changeto6(y));
}

int main(){
    cin>> a>> b;
    cout<< Min(a, b)<< " "<< Max(a, b);
    return 0;
}

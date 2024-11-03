#include <bits/stdc++.h>
#define maxn 100007
#define ll long long
using namespace std;

long double eps=0.00001;
long double Fac[maxn], P;

long double to_longdouble(string s){
    int i=0;
    long double x=0;
    while (i<=s.size()-1){
        x=x*10.0+1.0*(s[i]-'0');
        i++;
    }
    return x;
}

long double logstr(string s){
    if (s.size()<=15) return log(to_longdouble(s));
    else return log(to_longdouble(s.substr(0, 14)))+1.0*log(10)*(s.size()-15+1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; cin>> s;
    //cout<< to_longdouble(s)<< " "<< logstr(s);
    for (int i=1; i<=maxn; i++) Fac[i]=Fac[i-1]+log(i);
    P=logstr(s);
    /*
    cout<< P<< endl;
    for (int i=1; i<=10; i++) cout<< i<< " "<< Fac[i]<< endl;
    */
    for (int i=1; i<=100000; i++){
        auto it1=lower_bound(Fac+i, Fac+100001, Fac[i]+P);
        auto it2=upper_bound(Fac+i, Fac+100001, Fac[i]+P)-1;
        //cout<< *it1-Fac[i]-P<< " "<< *it2-Fac[i]-P<< endl;
        if (abs(*it1-Fac[i]-P)<=eps) return cout<< i+1<< " "<< it1-Fac, 0;
        if (abs(*it2-Fac[i]-P)<=eps) return cout<< i+1<< " "<< it2-Fac, 0;
    }
    return 0;
}

#include <bits/stdc++.h>
#define ll long long
using namespace std;

string s;

int main(){
    cin>> s;
    if (next_permutation(s.begin(), s.end()))
        for (char x:s) cout<< x;
    else cout<< 0;
}

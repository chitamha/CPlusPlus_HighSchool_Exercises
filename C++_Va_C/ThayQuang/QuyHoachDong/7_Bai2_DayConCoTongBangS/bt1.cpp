#include <bits/stdc++.h>
using namespace std;
int n, S;
bool F[10005];
int before[10005];
int main(){
    cin>> n>> S;
    vector<int> v(n+1);
    for (int i=1; i<=n; i++) cin>> v[i];
    F[0]=1;
    for (int i=1; i<=n; i++){
        for (int j=S; j>=1; j--){
            if (F[j]==false && j-v[i]>=0 && F[j-v[i]]==true){
                F[j]=true;
                before[j]=i;
            }
        }
    }
    if (F[S]) cout<< "YES"<< endl;
    else cout<< "NO"<< endl;
    vector<int> path;
    while (S!=0){
        //cout<< S<< " "<< before[S]<< endl;
        path.push_back(before[S]);
        S=S-v[before[S]];
    }
    for (int i=path.size()-1; i>=0; i--)
        cout<< path[i]<< " ";
    return 0;
}

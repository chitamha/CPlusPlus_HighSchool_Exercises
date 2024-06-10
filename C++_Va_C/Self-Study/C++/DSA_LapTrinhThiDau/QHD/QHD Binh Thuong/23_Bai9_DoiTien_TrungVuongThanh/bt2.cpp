#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, S;
    cin>> n>> S;
    vector<int> v(n);
    for (int i=0; i<n; i++)
        cin>> v[i];
    int F[S+1];
    memset(F, 62, sizeof F);
    int vet[S+1];
    memset(vet, 0, sizeof vet);
    F[0]=0;
    for (int i=0; i<n; i++){
        for (int j=v[i]; j<=S; j++){
            if (F[j]>=F[j-v[i]]+1){
                F[j]=F[j-v[i]]+1;
                vet[j]=j-v[i];
            }
        }
    }
    cout<< F[S]<< endl;
    //Truy vết
    int Dem[S+1];
    memset(Dem, 0, sizeof Dem);
    int i=S;
    while (i>0){
        Dem[i-vet[i]]++;
        i=vet[i];
    }
    /*
    for (int j=0; j<=S; j++)
        cout<< j<< " ";
    cout<< endl;
    for (int j=0; j<=S; j++)
        cout<< vet[j]<< " ";
    cout<< endl;
    */
    for (int j=0; j<n; j++)
        cout<< Dem[v[j]]<< " ";
    return 0;
}

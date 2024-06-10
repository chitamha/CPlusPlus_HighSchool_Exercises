#include <bits/stdc++.h>
using namespace std;

int w, v;
int A[1005][1005], F[1005][1005];

int main(){
    cin>> w>> v;
    for (int i=1; i<=w; i++){
        for (int j=1; j<=v; j++) cin>> A[i][j];
    }
    if (w==v){
        int sum=0;
        for (int i=1; i<=w; i++) sum+=A[i][i];
        return cout<< sum, 0;
    }
    for (int i=1; i<=w; i++){
        for (int j=i; j<=v; j++){
            if (i==j) F[i][j]=F[i-1][j-1]+A[i][j];
            else F[i][j]=max(F[i-1][j-1]+A[i][j], F[i][j-1]);
        }
    }
    cout<< F[w][v]<< endl;
    vector<pair<int, int>> truyvet;
    while (F[w][v]>0){
        if (F[w][v]==F[w][v-1]) v--;
        else truyvet.push_back({w--, v--});
    }
    for (int i=truyvet.size()-1; i>=0; i--)
        cout<< "Bo hoa thu "<< truyvet[i].first<< " vao lo thu "<< truyvet[i].second<< endl;
    return 0;
}

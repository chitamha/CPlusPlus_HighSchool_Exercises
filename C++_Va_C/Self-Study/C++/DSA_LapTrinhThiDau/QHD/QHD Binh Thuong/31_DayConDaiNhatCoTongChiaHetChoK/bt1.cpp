#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, k, sum=0;
ll F[1005][55], A[1005], B[1005];

int main(){
    cin>> n>> k;
    for (int i=1; i<=n; i++){
        cin>> A[i];
        B[i]=A[i];
        A[i]%=k;
        sum+=A[i];
    }
    //F[i][j]: số phần tử tối thiểu phải chọn trong dãy A[1... i] để có
    //tổng chia k dư t
    memset(F, 62, sizeof F);
    F[0][0]=0;
    for (int i=1; i<=n; i++){
        for (int j=0; j<k; j++){
            F[i][j]=min(F[i-1][j], F[i-1][(j-A[i]+k)%k]+1);
        }
    }
    cout<< n-F[n][sum%k];
    //Truy vết
    vector<int> vet;
    int mod=sum%k;
    while (F[n][mod]>0){
        if (F[n][mod]==F[n-1][mod]){
            vet.push_back(n);
            n--;
        } else{
            mod=(mod-A[n]+k)%k;
            n--;
        }
    }
    cout<< endl;
    for (int i=vet.size()-1; i>=0; i--)
        cout<< B[vet[i]]<< " "<< vet[i]<< endl;
    return 0;
}

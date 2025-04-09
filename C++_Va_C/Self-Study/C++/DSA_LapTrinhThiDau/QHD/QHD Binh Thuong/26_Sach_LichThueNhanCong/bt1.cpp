#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
using namespace std;

int T, chiphithue, luong, chiphisathai, SCN[200], C[200][200];
pair<int, int> before[200][200];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> T;
    cin>> chiphithue>> luong>> chiphisathai;
    for (int i=1; i<=T; i++) cin>> SCN[i];
    memset(C, 62, sizeof C);
    for (int i=0; i<=155; i++) C[0][i]=0;
    for (int i=0; i<=T; i++) C[i][0]=0;
    for (int i=1; i<=T; i++) for (int j=1; j<SCN[i]; j++) C[i][j]=0;
    for (int j=SCN[1]; j<=155; j++) C[1][j]=(chiphithue+luong)*j;
    for (int i=2; i<=T; i++){
        for (int j=SCN[i]; j<=155; j++){
            for (int k=SCN[i-1]; k<=155; k++){
                if (k>=j){
                    if (C[i-1][k]+(k-j)*chiphisathai+j*luong<C[i][j]){
                        C[i][j]=C[i-1][k]+(k-j)*chiphisathai+j*luong;
                        before[i][j]={i-1, k};
                    }
                }
                else{
                    if (C[i-1][k]+(j-k)*chiphithue+j*luong<C[i][j]){
                        C[i][j]=C[i-1][k]+(j-k)*chiphithue+j*luong;
                        before[i][j]={i-1, k};
                    }
                }
            }
        }
    }
    int ans=1e9, cnt=0;
    for (int j=SCN[T]; j<=155; j++){
        if (ans>C[T][j]+j*chiphisathai){
            ans=C[T][j]+j*chiphisathai;
            cnt=j;
        }
    }
    cout<< ans<< endl;
    stack<int> st;
    for (int i=T; i>0;){
        st.push(cnt);
        pair<int, int> p=before[i][cnt];
        i=p.fi; cnt=p.se;
    }
    while (!st.empty()){
        cout<< st.top()<< " ";
        st.pop();
    }
    return 0;
}

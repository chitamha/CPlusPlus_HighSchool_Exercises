#include <iostream>
using namespace std;
int dx[]={-1, 0, 0, 1};
int dy[]={0, -1, 1, 0};
int A[100][100];
int m, n;
bool ccheck=false;
void check(int i, int j, int u, int v){
    if (i!=u || j!=v){
        A[i][j]=0;
        for (int k=0; k<4; k++){
            int inew=i+dx[k]; int jnew=j+dy[k];
            if (inew>=0 && inew<n && jnew>=0 && jnew<m && A[inew][jnew]==1){
                //cout<< "Loang den "<< "A["<< inew<< "]["<< jnew<< "]"<< endl;
                check(inew, jnew, u, v);
            }
        }
    } else ccheck=true;
}
int main(){
    int k, h, u, v;
    cin>> n>> m;
    cin>> k>> h>> u>> v;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin>> A[i][j];
        }
    }
    --k; --h; --u; --v;
    check(k, h, u, v);
    /*cout<< ccheck<< endl;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout<< A[i][j]<< " ";
        }
        cout<< endl;
    }*/
    if(ccheck){
        cout<< "YES";
    } else cout<< "NO";
}

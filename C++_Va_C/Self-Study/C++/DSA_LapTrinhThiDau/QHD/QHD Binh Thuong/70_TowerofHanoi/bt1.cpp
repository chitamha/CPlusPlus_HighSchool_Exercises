#include <bits/stdc++.h>
using namespace std;
void moving(int n, int A, int B, int C, int &dem){
    if (n==1){
        cout<< A<< " to "<< C<< endl;
        dem++;
        return;
    }
    moving(n-1, A, C, B, dem);
    moving(1, A, B, C, dem);
    moving(n-1, B, A, C, dem);
}
int main(){
    int n; cin>> n;
    int dem=0;
    cout<< pow(2, n)-1<< endl;
    moving(n, 1, 2, 3, dem);
    cout<< dem;
}

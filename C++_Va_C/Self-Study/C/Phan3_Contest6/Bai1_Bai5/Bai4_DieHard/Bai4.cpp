#include <iostream>
using namespace std;
int check(int A[], int n){
    int dem25=0, dem50=0;
    for (int i=0; i<n; i++){
        if (A[i]==25){
            ++dem25;
        }
        else if (A[i]==50){
            if (dem25==0) return 0;
            --dem25; ++dem50;
        }
        else if (A[i]==100){
            if (dem25==0 || (dem25*25+dem50*50<75)) return 0;
            if (dem50>0){
                --dem25; --dem50;
            }
            else if (dem50==0 && dem25>3){
                dem25-=3;
            }
        }
    }
    return 1;
}
int main(){
    int n;
    cin>> n;
    int A[n];
    for (int i=0; i<n; i++){
        cin>> A[i];
    }
    if (check(A,n)){
        cout<< "YES";
    } else cout<< "NO";
    /* Sai
    int sum=0;
    if (A[0]>25)
    {
        cout<< "NO";
        return 0;
    }
    int check=0;
    for (int i=1; i<n; i++){
        sum+=A[i-1];
        if (A[i]>sum+25)
        {
            cout<< "NO";
            return 0;
        }
        else check=1;
    }
    if (check) cout<< "YES";*/
}

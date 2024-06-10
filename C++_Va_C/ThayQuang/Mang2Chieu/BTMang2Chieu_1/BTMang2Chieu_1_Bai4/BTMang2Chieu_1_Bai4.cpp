#include <iostream>
using namespace std;
int cow1, cow2, col1, col2;
int maxcow, maxcol;
int arr2[1000][1000];
int arr1[1000][1000];
int main(){
    cin>> cow1>> col1;
    for (int i=0; i<cow1; i++){
        for (int j=0; j<col1; j++){
            cin>> arr1[i][j];
        }
    }
    for (int i=0; i<cow1; i++){
        for (int j=0; j<col1; j++){
            cout<< arr1[i][j]<< "\t";
        }
        cout<< endl;
    }
    cin>> cow2>> col2;
    maxcow=(cow1>cow2 ? cow1 : cow2);
    maxcol=(col1>col2 ? col1 : col2);
    for (int i=0; i<cow2; i++){
        for (int j=0; j<col2; j++){
            cin>> arr2[i][j];
        }
    }
    for (int i=0; i<cow2; i++){
        for (int j=0; j<col2; j++){
            cout<< arr2[i][j]<< "\t";
        }
        cout<< endl;
    }
    cout<< endl<< "Ma tran moi la"<< endl;
    for (int i=0; i<maxcow; i++){
        for (int j=0; j<maxcol; j++){
            cout<< arr1[i][j]+arr2[i][j];
            cout<< "\t";
        }
        cout<< endl;
    }
    return 0;
}

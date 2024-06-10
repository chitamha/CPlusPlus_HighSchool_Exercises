#include <bits/stdc++.h>
using namespace std;

//Một số là số may mắn nếu biểu diễn thập phân của nó chỉ
//chứa các chữ số may mắn là 4 và 7. Ví dụ, các số 47,
//744, 4 là số may mắn và 5, 17, 467 không phải

/*Yêu cầu: tìm số may mắn bé nhất có tổng các chữ số bằng n
- Tư tưởng: tổng bằng n => n=4x+7y
            số may mắn bé nhất => ít chữ số nhất và bé nhất
*/

/*
Test 1           Test 2
    16               14
    2 0              2 0
    1 0              77
    0 0
    4444
*/

int n;

int main(){
    cin>> n;
    int d7=0, d4=0;
    for (d7=n/7; d7>=0; d7--){
        cout<< d7<< " "<< d4<< endl;
        if ((n-d7*7)%4==0){
            d4=(n-d7*7)/4;
            break;
        }
    }
    for (int i=0; i<d4; i++) cout<< 4;
    for (int j=0; j<d7; j++) cout<< 7;
    return 0;
}

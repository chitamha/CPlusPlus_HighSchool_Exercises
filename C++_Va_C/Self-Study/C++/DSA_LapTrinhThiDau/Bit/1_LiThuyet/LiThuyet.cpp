#include <bits/stdc++.h>
using namespace std;

/*
    1) Dịch bit shift left/right
    2) Hàm builtin_popcount, builtin_clz, builtin_ctz
    3) Độ ưu tiên của toán tử bit
    4) Bitset
    5) Bitmask: xâu bit trạng thái
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //1)
    /*
    int n=13;
    cout<< bitset<5>(n)<< endl;
    cout<< "Dich trai"<< endl;
    for (int i=0; i<11; i++)
        cout<< i<< " "<< (n<<i)<< " "<< bitset<5>(n<<i)<< endl;
    cout<< "Dich phai"<< endl;
    for (int i=0; i<11; i++)
        cout<< i<< " "<< (n>>i)<< " "<< bitset<5>(n>>i)<< endl;
    */

    //2)
    /*
    int n=100;
    cout<< n<< " "<< bitset<32>(n)<< endl;
    cout<< __builtin_popcount(n)<< endl;
    cout<< __builtin_ctz(n)<< endl; //count tail zero
    cout<< __builtin_clz(n)<< endl; //count lead zero
    */

    //3) Độ ưu tiên của toán tử bit: &, ^, |, ! là thấp nhất

    //4)
    /*
    bitset<10> b("101010100"); //Kích thước là hằng số
    long long n=b.to_ullong();
    cout<< n; // 340
    */

    //5)
    //Tìm/đếm dãy con có tổng bằng K
    int n, k, cnt=0; cin>> n>> k;
    int A[n];
    for (int i=0; i<n; i++) cin>> A[i];
    for (int mask=1; mask<(1<<n); mask++){
        int sum=0;
        for (int i=0; i<n; i++)
            if ((mask>>i)&1) sum+=A[i];
        if (sum==k) cnt++;
    }
    return 0;
}

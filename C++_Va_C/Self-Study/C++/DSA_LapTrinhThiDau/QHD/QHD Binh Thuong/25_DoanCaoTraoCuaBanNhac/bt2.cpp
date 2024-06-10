/*
Đoạn cao trào của bản nhạc
https://oj.vnoi.info/problem/theme
INPUT:
30
25 27 30 34 39 45 52 60 69 79 69 60 52 45 39 34 30 26 22 18 82
78 74 70 66 67 64 60 65 80
OUTPUT:
5
*/
#include <bits/stdc++.h>
#define fi first
#define se second
#define ii pair<int, int>
#define ll long long
#define maxn 5005
using namespace std;

int n, A[maxn];
int F[maxn][maxn];
//Gọi F[i][j] là đoạn cao trào dài nhất của bản nhạc xét từ 1... i và i+5... j
//Với tư tưởng của bài “xâu con chung dài nhất” ta có thể giải quyết bài toán trên!
//Kết quả là Max(F[i][j])

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>> n;
    for (int i=1; i<=n; i++) cin>> A[i];
    for (int i=1; i<=n; i++) F[1][i]=1;
    //Bài toán con nhỏ nhất: Độ dài đoạn cao trào là 1
    int res=1;
    //2 vòng lặp for này đảm bảo đoạn cao trào dài nhất xuất hiện ít nhất 2 lần
    for (int i=1; i<=n-5; i++){
        for (int j=i+5; j<=n; j++){
            if (A[i]-A[i-1]==A[j]-A[j-1]){
                F[i][j]=F[i-1][j-1]+1;
                res=max(res, min(F[i][j], j-i));
                //Các đoạn không được chồng lên nhau nên j-i
            } else F[i][j]=1;
        }
    }
    //Đoạn cao trào phải có từ 5 nốt nhạc trở lên
    if (res>=5) cout<< res;
    else cout<< 0;
    return 0;
}

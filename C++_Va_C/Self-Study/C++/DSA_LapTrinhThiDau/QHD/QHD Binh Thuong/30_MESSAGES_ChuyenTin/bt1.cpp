#include <bits/stdc++.h>
using namespace std;
const int mn = 101;
const char * fn = "messages.inp";
const char * gn = "messages.out";

int c[mn][mn]; //Ma tran chi phi
int SoGoi[mn][mn];//SoGoi[i][j] - so goi tin chuyen theo kenh j
int n, m;
int p[mn];

void Doc();
void Print();
void XuLi();
void Tinhp(int, int);
void Ghi();

int main() {
    Doc(); Print();
    XuLi(); Ghi();
    cout << endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}

void Ghi(){
    ofstream g(gn);
    g << p[n]; //Chi phi min
    int i = n, j;
    for (j = m; j > 0; --j) {
        p[j] = SoGoi[i][j];
        i = i - SoGoi[i][j]; //So goi con lai
    }
    for (i = 1; i <= m; ++i)
        g << endl << p[i];
    g.close();
}

//Chi phi chuyen het i goi tin theo j kenh dau tien: 1, 2,... j
void Tinhp(int i, int j) {
    int k;
    SoGoi[i][j] = 0;
    for (k = 1; k <= i; ++k) //Thu chuyen k goi theo kenh j
        if (p[i] > p[i-k] + c[k][j]) {
            p[i] = p[i-k] + c[k][j]; //Cap nhat min
            SoGoi[i][j] = k; //So goi can chuyen theo kenh j
        }
}

void XuLi() {
    int i, j, k;
    memset(SoGoi, 0, sizeof(SoGoi));
    //Khoi tao cho kenh 1
    //i goi tin chi chuyen tren kenh 1 voi chi phi c[i][1]
    p[0] = 0; //Chuyen 0 goi tin tren kenh 1
    for (i = 1; i <= n; ++i) {
        p[i] = c[i][1];
        SoGoi[i][1] = i;
    }
    for (j = 2; j < m; ++j) //Xet kenh j = 2... m-1
        for (i = n; i > 0; --i) //Chuyen i goi tin tren kenh j
            Tinhp(i,j);
    //Xu li buoc cuoi, kenh m
    SoGoi[n][m] = 0;
    for (k = 1; k <= n; ++k) //Thu chuyen k goi theo kenh m
        if (p[n] > p[n-k] + c[k][m]) {
        p[n] = p[n-k] + c[k][m];
        SoGoi[n][m] = k;
    }
}

void Print() {
    int i, j;
    cout << n << " goi tin, " << m << " kenh";
    for (i = 1; i <= n; ++i) {
        cout << endl;
        for (j = 1; j <= m; ++j) cout << c[i][j] << " ";
    }
}

void Doc() {
    ifstream f(fn);
    memset(c, 0, sizeof(c));
    f >> n >> m; //n goi tin, m kenh
    int i, j;
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= m; ++j)
            f >> c[i][j];
    f.close();
}

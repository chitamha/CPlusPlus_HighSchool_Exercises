#include <iostream>
using namespace std;

const int MAX_N = 100;

int n, v, vt;
int m[MAX_N + 1], s[MAX_N + 1], c[MAX_N + 1];

void Doc() {
    cin>> n>> v;
    for (int i=1; i<=n; i++) cin>> m[i];
    for (int i=1; i<=n; i++) cin>> s[i];
}

int Min(int a, int b) {
    return (a > b) ? b : a;
}

bool Next() {
    int i = n;
    while (c[i] == s[i]) {
        vt -= c[i] * m[i];
        c[i] = 0;
        i--;
    }
    if (i == 0) return false;
    c[i]++;
    vt += m[i];
    return true;
}

bool Duyet() {
    for (int i = 1; i <= n; ++i) {
        s[i] = Min(s[i], v / m[i]);
        c[i] = 0;
    }
    c[0] = -1;
    vt = 0;
    do {
        if (vt == v) return true;
    } while (Next());
    return false;
}

void Run() {
    Doc();
    if (Duyet()) {
        for (int i = 1; i <= n; ++i) {
            cout << c[i] << " ";
        }
    } else {
        cout << 0;
    }
}

int main() {
    Run();
    return 0;
}

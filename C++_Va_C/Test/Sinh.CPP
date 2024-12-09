#include <bits/stdc++.h>
using namespace std;

// Sinh một test ngẫu nhiên
void generateTest(int testNum, int maxN, int maxR, int maxH) {
    // Tạo tên file theo định dạng "TOWERx.INP"
    string fileName = "TOWER" + to_string(testNum) + ".INP";
    freopen(fileName.c_str(), "w", stdout); // Mở file để ghi

    srand(time(0) + testNum); // Tạo seed khác nhau cho mỗi test
    int n = rand() % maxN + 1; // Số lượng cặp (r, h)
    cout << n << "\n";

    for (int i = 0; i < n; i++) {
        int r = rand() % maxR + 1; // Bán kính (r)
        int h = rand() % maxH + 1; // Chiều cao (h)
        cout << r << " " << h << "\n";
    }

    fclose(stdout); // Đóng file
}

int main() {
    int numTests = 10;       // Số lượng test
    int maxN = 15;          // Giới hạn số lượng cặp (r, h)
    int maxR = 10;         // Giới hạn bán kính r
    int maxH = 10;          // Giới hạn chiều cao h

    for (int t = 1; t <= numTests; t++) {
        generateTest(t, maxN, maxR, maxH);
    }

    cout << "Generated 10 test cases using freopen!\n";
    return 0;
}

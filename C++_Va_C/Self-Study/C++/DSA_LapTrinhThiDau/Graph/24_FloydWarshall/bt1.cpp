#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

const int N = 100010;
int n;
int adj[N][N];
//Mảng lưu trữ khoảng cách ngắn nhất giữa các đỉnh
int dist[N][N];

void floyd() {
    //Khởi tạo khoảng cách bằng trọng số của các cạnh
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = adj[i][j];
        }
    }
    //Giải các bài toán con bằng cách sử dụng thuộc tính cấu trúc con tối ưu
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                //Cập nhật cạnh (i, j) sử dụng đỉnh k làm đỉnh trung gian
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
            if (adj[i][j] == 0) {
                //Không có cạnh giữa các đỉnh
                adj[i][j] = numeric_limits<int>::max();
                //adj[i][j] có giá trị infinity thuộc kiểu int
            }
        }
    }
    //Giải bài toán đường đi ngắn nhất
    floyd();
    //In khoảng cách ngắn nhất giữa các đỉnh
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << i << " " << j << " " << dist[i][j] << endl;
        }
    }
    return 0;
}

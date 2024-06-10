#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

const int INF = 1000000;

int bt(std::vector<int> t, int s) {
    // Tìm thời gian tốt nhất từ vector t mà lớn hơn hoặc bằng s
    for (int i = 0; i < t.size(); i++)
        if (t[i] >= s)
            return t[i];
    return INF;
}

int int_comp(const void *a, const void *b) {
    // Hàm so sánh hai số nguyên
    int x = *(const int *)a;
    int y = *(const int *)b;
    if (x < y)
        return -1;
    else if (x > y)
        return 1;
    else
        return 0;
}

class Boxing {
public:
    int maxCredit(std::vector<int> a, std::vector<int> b, std::vector<int> c, std::vector<int> d, std::vector<int> e) {
        int count = 0;
        // Duyệt qua tất cả các khoảng thời gian từ 0 đến 180000 giây
        for (int s = 0; s <= 180000; s++) {
            // Tạo một mảng chứa thời gian tốt nhất của mỗi người chơi
            int best_time[5];
            best_time[0] = bt(a, s);
            best_time[1] = bt(b, s);
            best_time[2] = bt(c, s);
            best_time[3] = bt(d, s);
            best_time[4] = bt(e, s);
            // Sắp xếp thời gian tốt nhất theo thứ tự tăng dần
            qsort(best_time, 5, sizeof(int), int_comp);
            // Nếu thời gian tốt thứ ba không vượt quá s + 1000, tăng số lượng trận đấu
            if (best_time[2] <= s + 1000) {
                count++;
                s = best_time[2];
            }
        }
        return count;
    }
};

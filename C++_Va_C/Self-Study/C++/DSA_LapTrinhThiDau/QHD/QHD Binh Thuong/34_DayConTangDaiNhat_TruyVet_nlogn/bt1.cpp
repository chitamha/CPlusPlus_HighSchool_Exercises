#include <bits/stdc++.h>
#define task "LIQ."
#define int long long

using namespace std;

const int maxn = 1e6 + 10;

void enter(int &n, vector < int > &a)
{
    cin >> n;

    a.resize(n + 1, 0);

    for (int i = 1; i <= n; ++i)
        cin >> a[i];
}

// In kết quả và truy vết dãy con tăng dài nhất.
void print_result(int n, vector < int > &a, vector < int > &dp, vector < int > &trace)
{
    int best = 1;
    for (int i = 2; i <= n; ++i)
        if (dp[i] > dp[best])
            best = i;

    cout << dp[best] << endl;

    vector < int > elements;
    while (best)
    {
        elements.push_back(a[best]);
        best = trace[best];
    }

    for (int i = elements.size() - 1; i >= 0; --i)
        cout << elements[i] << ' ';
}

/**
  * Tìm kiếm nhị phân giá trị p lớn nhất mà a[end_pos[p]] < a[i].
  * max_length: Độ dài dãy con tăng dài nhất đã ghi nhận được
                trong đoạn a[1...i - 1].
  * a: Dãy số ban đầu.
  * val: Tham số đại diện cho a[i].
*/
int binary_searching(int max_length, vector < int > &a, vector < int > &end_pos, int val)
{
    int p = 0;

    int l = 1, r = max_length;
    while (l <= r)
    {
        int mid = (l + r) >> 1;

        if (a[end_pos[mid]] < val)
        {
            p = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }

    return p;
}

void solution(int n, vector < int > &a)
{
    vector < int > dp(n + 1, 0);
    vector < int > end_pos(n + 1, 0);
    vector < int > trace(n + 1, 0);

    int res = 1;
    end_pos[1] = 1;

    for (int i = 1; i <= n; ++i)
    {
        // Tìm kiếm nhị phân độ dài p tốt nhất để ghép a[i] vào phía sau
        // dãy con tăng dài nhất kết thúc tại a[end_pos[p]].
        int p = binary_searching(res, a, end_pos, a[i]);
        int k = p + 1;

        // Cập nhật độ dài dãy con tăng dài nhất hiện tại.
        // Luôn giữ cho phần tử kết thúc của các dãy con tăng là nhỏ nhất có thể.
        if (k > res)
        {
            res = k;
            end_pos[k] = i;
        }
        else if (a[end_pos[k]] > a[i])
            end_pos[k] = i;

        // Cập nhật các kết quả ở vị trí i.
        dp[i] = k;
        trace[i] = end_pos[p];
    }

    print_result(n, a, dp, trace);
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    vector < int > a;

    enter(n, a);
    solution(n, a);

    return 0;
}

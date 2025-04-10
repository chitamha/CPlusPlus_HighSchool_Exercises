#include <bits/stdc++.h>
#define task "LIQ."
#define ll long long

using namespace std;

const ll maxn = 1e6 + 10;

void enter(ll &n, vector < ll > &a)
{
    cin >> n;

    a.resize(n + 1, 0);

    for (ll i = 1; i <= n; ++i)
        cin >> a[i];
}

// In kết quả và truy vết dãy con tăng dài nhất.
void print_result(ll n, vector < ll > &a, vector < ll > &dp, vector < ll > &trace)
{
    ll best = 1;
    for (ll i = 2; i <= n; ++i)
        if (dp[i] > dp[best])
            best = i;

    cout << dp[best] << endl;

    vector < ll > elements;
    while (best)
    {
        elements.push_back(a[best]);
        best = trace[best];
    }

    for (ll i = elements.size() - 1; i >= 0; --i)
        cout << elements[i] << ' ';
}

/**
  * Tìm kiếm nhị phân giá trị p lớn nhất mà a[end_pos[p]] < a[i].
  * max_length: Độ dài dãy con tăng dài nhất đã ghi nhận được
                trong đoạn a[1...i - 1].
  * a: Dãy số ban đầu.
  * val: Tham số đại diện cho a[i].
*/
ll binary_searching(ll max_length, vector < ll > &a, vector < ll > &end_pos, ll val)
{
    ll p = 0;

    ll l = 1, r = max_length;
    while (l <= r)
    {
        ll mid = (l + r) >> 1;

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

void solution(ll n, vector < ll > &a)
{
    vector < ll > dp(n + 1, 0);
    vector < ll > end_pos(n + 1, 0);
    vector < ll > trace(n + 1, 0);

    ll res = 1;
    end_pos[1] = 1;

    for (ll i = 1; i <= n; ++i)
    {
        // Tìm kiếm nhị phân độ dài p tốt nhất để ghép a[i] vào phía sau
        // dãy con tăng dài nhất kết thúc tại a[end_pos[p]].
        ll p = binary_searching(res, a, end_pos, a[i]);
        ll k = p + 1;

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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n;
    vector < ll > a;

    enter(n, a);
    solution(n, a);

    return 0;
}

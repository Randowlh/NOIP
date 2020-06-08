#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
const ll mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
inline void out(int a)
{
    if (a)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
char mp[100][100];
bool book[100][100];
int n, m;
bool ck(int x, int y)
{
    if (x < 0 || x >= n)
        return false;
    if (y < 0 || y >= m)
        return false;
    return true;
}
int biao[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
void work()
{
    cin >> n >> m;
    int tol = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> mp[i][j];
            if (mp[i][j] == 'G')
                tol++;
        }
    memset(book, 0, sizeof(book));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (mp[i][j] == 'B')
            {
                // cout << "dadas" << endl;
                for (int k = 0; k < 4; k++)
                {
                    if (ck(i + biao[k][0], j + biao[k][1]))
                    {
                        if (mp[i + biao[k][0]][j + biao[k][1]] == 'G')
                        {
                            out(0);
                            return;
                        }
                        else if (mp[i + biao[k][0]][j + biao[k][1] != 'B'])
                            mp[i + biao[k][0]][j + biao[k][1]] = '#';
                    }
                }
            }
        }
    int cnt = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(n - 1, m - 1));
    book[n - 1][m - 1] = 1;
    if (mp[n - 1][m - 1] == 'G')
        cnt++;
    if (mp[n - 1][m - 1] == '#')
    {
        out(tol == 0);
        return;
    }
    while (!q.empty())
    {
        pair<int, int> t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            if (ck(t.first + biao[i][0], t.second + biao[i][1]) && book[t.first + biao[i][0]][t.second + biao[i][1]] == 0 && (mp[t.first + biao[i][0]][t.second + biao[i][1] == 'G'] || mp[t.first + biao[i][0]][t.second + biao[i][1]] == '.'))
            {
                if (mp[t.first + biao[i][0]][t.second + biao[i][1]] == 'G')
                    cnt++;
                q.push(make_pair(t.first + biao[i][0], t.second + biao[i][1]));
                book[t.first + biao[i][0]][t.second + biao[i][1]] = 1;
            }
        }
    }
    out(cnt >= tol);
    return;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}
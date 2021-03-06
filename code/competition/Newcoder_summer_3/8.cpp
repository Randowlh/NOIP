#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
vector<int> mp[800100];
int n, m;
inline ll read()
{
    ll x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
int fl[801000];
int fa[801000];
void work()
{
    n = read();
    m=read();
    int a, b;
    for (int i = 0; i <= n;i++){
        mp[i].clear();
        fa[i] = -1;
    }
    for (int i = 0; i < m; i++)
    {
            a = read();
            b = read();
            mp[a].push_back(b);
            mp[b].push_back(a);
    }
    int q = read();
    int tt;
    for (int i = 0; i < q;i++){
        tt = read();
        if(fa[tt]!=-1)
            continue;
        for (int i = 0;i<mp[tt].size();i++){
            fa[mp[tt][i]] = tt;
        }
    }
    for (int i = 0; i < n;i++){
        if(fa[i]==-1){
            printf("%d ", i);
        }else
            printf("%d ", fa[i]);
    }
    printf("\n");
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    int t = 1;
    t = read();
    while (t--)
    {
        work();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#pragma optimize(2)
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
const int inf = 0x7FFFFFFF;
typedef long long ll;
typedef double db;
typedef long double ld;
template<class T>inline void MAX(T &x,T y){if(y>x)x=y;}
template<class T>inline void MIN(T &x,T y){if(y<x)x=y;}
template<class T>inline void rd(T &x){
   x=0;char o,f=1;
   while(o=getchar(),o<48)if(o==45)f=-f;
   do x=(x<<3)+(x<<1)+(o^48);
   while(o=getchar(),o>47);
   x*=f;
}
template<class T>
void wt(T x){
   if(x < 0) putchar('-'), x = -x;
   if(x >= 10) wt(x / 10);
   putchar('0' + x % 10);
}
#define MP make_pair
#define pb push_back
#define pt putchar
#define yx_queue priority_queue
#define lson(pos) (pos<<1)
#define rson(pos) (pos<<1|1)
#define y1 code_by_Rand0w
#define yn A_muban_for_ACM
#define j1 it_is just_an_eastegg
#define lr hope_you_will_be_happy_to_see_this
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll llinf = 4223372036854775807;
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const int maxm= 100;
const int maxn = 50;
struct edge{
   int w1,w2,to,nxt;
}eg[maxm];
int head[maxn];
int ecnt=0;
inline void add(int u,int v,int w,int ww){
   	eg[++ecnt].nxt=head[u];
	eg[ecnt].w1=w;	
	eg[ecnt].w2=ww;
   	eg[ecnt].to=v;
   	head[u]=ecnt;
}
inline void cl(int n){
	for(int i=0;i<=n;i++)
		head[i]=0;
	ecnt=0;
}
vector<vector<int>> v;
vector<int>tmp;
int ans=llinf;
int lim=3000;
void dfs(int now,int tol,int sj){
	if(sj>ans){
		return;
	}
	if(tol>lim){
		if(ans>sj){
			ans=sj;
			v.clear();
		}
		v.push_back(tmp);
		return;
	}
	for(int i=head[now];i;i=eg[i].nxt){
		tmp.push_back(eg[i].to);
		dfs(eg[i].to,tol+eg[i].w1,sj+eg[i].w2);
		tmp.pop_back();
	}
}
void work()
{
	cl(4);
	add(1,2,530,380);
	add(2,1,530,380);
	add(2,3,610,450);
	add(3,2,610,450);
	add(1,4,380,370);
	add(4,1,380,370);
	add(3,4,530,460);
	add(4,3,530,460);
	for(int i=1;i<=4;i++){
		tmp.push_back(i);
		dfs(i,0,0);
		tmp.pop_back();
	}
	cout<<"the minial distants="<<ans<<endl;
	cout<<"there are "<<v.size()<<" way(s)"<<endl;
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v[i].size()-1;j++){
			cout<<v[i][j]<<"->";
		}
		cout<<v[i][v[i].size()-1]<<endl;
	}
}
signed main()
{
   #ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif
//std::ios::sync_with_stdio(false);
//cin.tie(NULL);
int t = 1;
//cin>>t;
while (t--)
{
work();
}
return 0;
}
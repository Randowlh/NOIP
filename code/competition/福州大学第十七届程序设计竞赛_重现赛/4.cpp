#include<stdio.h> 
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<stack>
#include<cmath>
#include<vector>
#include<set>
#include<cstdio>
#include<string>
#include<deque>
#include<iostream>
using namespace std;
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
#define y1 code_by_Rand0w
#define yn A_muban_for_ACM
#define j1 it_is just_an_eastegg
#define lr hope_you_will_be_happy_to_see_this
const int maxn = 510000;
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const int maxm= 1;
int in[101000];
int date[101000];
int tmp[101000];
int res=0;
int ans=0;
void mergesort(int l,int r)
{
    if(l>=r)    return;
    int m=(l+r)/2;
    int i=l,j=m+1,k=0;
    while(i<=m&&j<=r){
        if(date[i]>date[j]){
            tmp[k++]=date[j++];
            res+=m-i+1;
        }
        else{
            tmp[k++]=date[i++];
        }
    }
    while(i<=m) tmp[k++]=date[i++];
    while(j<=r) tmp[k++]=date[j++];
    for(i=0;i<k;i++)    date[i+l]=tmp[i];
}

void merge(int l,int r){
    if(l>=r)    return;
    int m=(l+r)/2;
    merge(l,m);
    merge(m+1,r);
    mergesort(l,r);
}
void work()
{
    int n;
    while(cin>>n){
        ans=0;
        //res=0;
        for(int i=1;i<=n;i++)
            cin>>in[i];
        for(int i=1;i<=n-1;i++)
            date[i]=in[i];
        res=0;
        merge(1,n-1);
        ans=res;
        res=0;
        for(int i=1;i<=n-1;i++)
            date[i]=in[i+1];
        merge(1,n-1);
        ans=max(res,ans);
        cout<<ans<<endl;
    }
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
const ll md =  998244353;
inline long long extend_gcd(long long a,long long b,long long &x,long long &y)
{
    if(a==0&&b==0)
        return -1ll;
    if(b==0)
    {
        x=1ll;
        y=0ll;
        return a;
    }
    long long d=extend_gcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
inline long long mod_reverse(long long a,long long n)
{
    long long x,y,d=extend_gcd(a,n,x,y);
    if(d==1)
        {
                    if(x%n<=0)return x%n+n;
                    else return x%n;
                 }
    else
        return -1ll;
}
int date[1000010];
void work(){
    int n;
    cin>>n;
    set<int> s;
    ll tol=0;
    for(int i=0;i<n;i++){
        int tmp;
        scanf("%d",&tmp);
        int cnt=0;
        int t;
        for(int j=0;j<tmp;j++){
            scanf("%d",&t);
            if(s.count(t)==0){
                s.insert(t);
                tol++;
            }
            //cnt++;
        }
        date[i]=tmp;
    }
    ll x=0;
    for(int i=0;i<n;i++){
        //tol=tol*tol%md;
        x+=date[i]%md;
    }
    tol*=n;
    int k,y;
    y=mod_reverse(tol,md);
   // cout<<x*y%md<<endl;
    //cout<<mod_reverse(4,md)%md*3%md<<endl;
    
    for(int i=1;i<10;i++){
        cout<<(md+1)%(124780545/i)<<endl;
      //  cout<<mod_reverse(i,md)*6%md<<endl;
    }
    //int date[] 
}
int main(){
    freopen("in.txt","r",stdin);
    int t=1;
    //cin>>t;
    while(t--){
        work();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
// BEGIN LIB
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
#define print_grid(x) for(auto &r:x){for(auto &c:r)cout<<c<<" ";cout<<endl;}cout<<endl;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> grid;
typedef pair<ll, ll> pll;
int mod = 998244353;
// END LIB

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin>>N;
    vll A(N), result(10,0), tmp(10); cin>>A;
    result[(A[0]+A[1])%10]++;
    result[A[0]*A[1]%10]++;
    for(int i=2; i<N; i++){
        rep(j,0,10) tmp[j]=0;
        for(int x=0, y=A[i]; x<10; x++){
            tmp[(x+y)%10]=(tmp[(x+y)%10]+result[x])%mod;
            tmp[x*y%10]=(tmp[x*y%10]+result[x])%mod;
        }
        rep(i,0,10) result[i]=tmp[i];
    }
    for(auto r:result)  cout << r << endl;

    return 0;
}
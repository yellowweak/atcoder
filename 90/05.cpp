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
int mod = 1000000007;
// END LIB
ll N;
int B,K;
// O(NBK)
void solve1(vi &c){
    vi remain(B,0);
    rep(i,0,K)  remain[c[i]%B]++;
    rep(n,0,N-1){
        vi tmp(B,0);
        rep(b,0,B){
            rep(k,0,K){
                tmp[(b*10+c[k])%B] = (tmp[(b*10+c[k])%B] + remain[b])%mod;
            }
        }
        swap(remain, tmp);
    }
    cout << remain[0];
}
// B=3, c=1-9
// t0 = (c=3,6,9)r0 + (c=2,5,8)r1 + (c=1,4,7)r2
// t1 = (c=1,4,7)r0 + (c=3,6,9)r1 + (c=2,5,8)r2
// t2 = (c=2,5,8)r0 + (c=1,4,7)r1 + (c=3,6,9)r2
// B=5, c=1-9
// t0 = (c=5)r0 + (c=5)r1 + (c=5)r2 + (c=5)r3 + (c=5)r4
// t1 = (c=1,6)r0 + (c=1,6)r1 + (c=1,6)r2 + (c=1,6)r3 + (c=1,6)r4
// t2 = (c=2,7)r0 + (c=2,7)r1 + (c=2,7)r2 + (c=2,7)r3 + (c=2,7)r4
// t3 = (c=3,8)r0 + (c=3,8)r1 + (c=3,8)r2 + (c=3,8)r3 + (c=3,8)r4
// t4 = (c=4,9)r0 + (c=4,9)r1 + (c=4,9)r2 + (c=4,9)r3 + (c=4,9)r4
// B=4, c=1-9
// t0 = (c=4,8)r0 + (c=2,6)r1 + (c=)r2 + (c=)r3
// t1 = (c=1,5,9)r0 + (c=3,7)r1 + (c=)r2 + (c=)r3
// t2 = (c=2,6)r0 + (c=4,8)r1 + (c=)r2 + (c=)r3
// t3 = (c=3,7)r0 + (c=1,5,9)r1 + (c=)r2 + (c=)r3
void AxB(grid &A, grid &B){
    if(A[0].size()!=B.size())   {cout << "djuihfuier"<<endl; assert("matrix multiply: size doesn't match\n");}
    grid result(A.size(), vll(B[0].size(), 0));
    rep(r,0,result.size()) rep(c,0,result[0].size()) rep(i,0,A[0].size()){
        result[r][c] = (A[r][i]*B[i][c]%mod + result[r][c])%mod;
    }
    swap(B, result);
}
void AxxN(grid &A, ll N){
    if(A[0].size()!=A.size())   assert("matrix power: size doesn't match\n");
    grid result(A.size(), vll(A[0].size(), 0));
    for(int i=0; i<A.size(); i++)   result[i][i]=1;
    for(int i=62; i>=0; i--){
        AxB(result, result); // 0x101 -> 0x1010
        if((1LL<<i)&N)  AxB(A, result); // 0x1010 -> 0x1011
    }
    swap(A, result);
}
// O((B^3)log(N))
void solve2(vi &c){
    grid remainT(B,vll(1,0));
    rep(i,0,K)  remainT[c[i]%B][0]++;
    grid A(B, vll(B,0));
    rep(b,0,B){
        rep(k,0,K){
            int dist = (b*10+c[k])%B;
            A[dist][b]++;
        }
    }
    AxxN(A, N-1);
    AxB(A, remainT);
    cout << remainT[0][0];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N>>B>>K;
    vi c(K); cin>>c;
    // solve1(c);
    // solve2(c);

    // N=7 => 2^2+2^1+2^0 => abcd/ef/g
    // N=10^18 => 2^(a+b+c+...) => a..a/b..b/c..c/...
    grid dp(64, vll(B,0));
    vi p10modB(64); // 10^(2^0)%B, 10^(2^1)%B, 10^(2^2)%B, ...
    p10modB[0]=10%B;
    for(int i=1; i<p10modB.size(); i++) p10modB[i] = p10modB[i-1]*p10modB[i-1]%B;

    rep(i,0,K)  dp[0][c[i]%B]++;
    // a..(2^i)..ab..(2^i)..b
    rep(i,1,dp.size()) rep(bi,0,B) rep(bj,0,B){
        int dist = (bi*p10modB[i-1]+bj)%B;
        dp[i][dist] += dp[i-1][bi]*dp[i-1][bj];
        dp[i][dist] %= mod;
    }
    
    // N = 2^(a+b+c+...)
    vll ans(B,0), prev(B,0); // 2d-dp -> 1d-vector x2
    ll prefix_len=0;
    for(int i=0; i<63; i++){
        if((1LL<<i)&N){ // add dp[i] as POSTFIX
            fill(all(ans), 0);
            if(prefix_len>0){
                rep(bi,0,B) rep(bj,0,B){
                    int dist = (bi*p10modB[i]+bj)%B; // a..(prefix_len)..ab..(2^i)..b
                    ans[dist] += prev[bi]*dp[i][bj];
                    ans[dist] %= mod;
                }
                prev = ans;
            }
            else{
                ans = prev = dp[i];
            }
            prefix_len |= (1LL<<i);
        }
    }

    cout << ans[0];

    return 0;
}
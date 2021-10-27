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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N,X,Y;cin>>N>>X>>Y;
    vector<array<int,2>> box(N);
    vvi dp(X+1, vi(Y+1, INT_MAX/2));
    vvi tmp = dp;
    rep(i,0,N)  cin>>box[i][0]>>box[i][1];
    rep(x,0,min(X,box[0][0])+1)
        rep(y,0,min(Y,box[0][1])+1)    dp[x][y]=1;
    dp[0][0]=0;
    rep(ith,1,N){
        rep(x,0,X+1)rep(y,0,Y+1){
            if(x==0&&y==0)  tmp[x][y]=0;
            else{
                int newx=max(0,x-box[ith][0]);
                int newy=max(0,y-box[ith][1]);
                tmp[x][y] = min(dp[newx][newy]+1,dp[x][y]);
            }
        }
        swap(tmp,dp);
    }
    cout << (dp[X][Y]==(INT_MAX/2)? -1:dp[X][Y]);
    
    return 0;
}
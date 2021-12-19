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

    int ans=1;
    int H,W;cin>>H>>W;
    vector<string> board(H); cin >> board;
    vvi dp(H, vi(W, 0));
    dp[0][0]=1;
    for(int i=1; i<W; i++){
        dp[0][i] = (board[0][i]=='#'||dp[0][i-1]==0)? 0:dp[0][i-1]+1;
        ans = max(ans, dp[0][i]);
    }
    for(int i=1; i<H; i++){
        dp[i][0] = (board[i][0]=='#'||dp[i-1][0]==0)? 0:dp[i-1][0]+1;
        ans = max(ans, dp[i][0]);
    }
    for(int i=1; i<H; i++){
        for(int j=1; j<W; j++){
            if(board[i][j]=='#')    dp[i][j] = 0;
            else{
                int from_left = (dp[i][j-1]==0)? 0:dp[i][j-1]+1;
                int from_top = (dp[i-1][j]==0)? 0:dp[i-1][j]+1;
                dp[i][j] = max(from_left, from_top);
                ans = max(ans, dp[i][j]);
            }
        }
    }
    cout << ans;

    return 0;
}
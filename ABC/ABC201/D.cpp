#include <bits/stdc++.h>
using namespace std;
// BEGIN LIB
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> matrix;
typedef pair<ll, ll> pll;
// END LIB
int p(vector<string> &board, int i, int j){
    return (board[i][j]=='+')? 1:-1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int H,W; cin>>H>>W;
    string tmp;
    vector<string> board(H);
    vvi dp(H, vi(W)); dp[H-1][W-1]=0;
    rep(i,0,H){
        cin>>board[i];
    }
    for(int i=H-1; i>=0; i--){
        for(int j=W-1; j>=0; j--){
            if(i==H-1&&j==W-1)  continue;
            if((i+j)%2==0){ // self
                if(i==H-1) dp[i][j] = dp[i][j+1] + p(board, i, j+1);
                else if(j==W-1) dp[i][j] = dp[i+1][j] + p(board, i+1, j);
                else dp[i][j] = max(dp[i][j+1] + p(board, i, j+1), dp[i+1][j] + p(board, i+1, j));
            }
            if((i+j)%2==1){ // opposite
                if(i==H-1) dp[i][j] = dp[i][j+1] - p(board, i, j+1);
                else if(j==W-1) dp[i][j] = dp[i+1][j] - p(board, i+1, j);
                else dp[i][j] = min(dp[i][j+1] - p(board, i, j+1), dp[i+1][j] - p(board, i+1, j));
            }
        }
    }
    if(dp[0][0]==0) cout<<"Draw"<<endl;
    else if(dp[0][0]>0) cout<<"Takahashi"<<endl;
    else cout << "Aoki"<<endl;

    return 0;
}
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

char dfs(vi &T, vector<vector<char>> &dp, int i, int target){
    if(target==0)   return 'O';
    if(target<0 || i>=sz(dp))    return 'X';

    if(dp[i][target]=='-'){
        char choose_ith = dfs(T, dp, i+1, target-T[i]);
        char discard_ith = dfs(T, dp, i+1, target);
        dp[i][target] = (choose_ith=='O'||discard_ith=='O')? 'O':'X';
    }
    return dp[i][target];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin>>N;
    int r=N-1, sum=0;
    vi T(N);
    rep(i,0,N){
        cin >> T[i];
        sum+=T[i];
    }
    sort(all(T));
    vector<vector<char>> dp(N, vector<char>(sum+1, '-'));

    // check if it exist a subset that sum up to "test"
    for(int test= sum/2 + sum%2; test<=sum; test++){
        if(dfs(T,dp,0,test)=='O'){
            cout << test << endl;
            break;
        }
    }
    return 0;
}
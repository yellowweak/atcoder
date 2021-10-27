#include <bits/stdc++.h>
using namespace std;
// BEGIN NO SAD
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
// END NO SAD
ll c[61][31];
ll C(int n, int k){
    if(n==0)    return 0;
    k = min(n-k, k);
    if(c[n][k]==0){
        if(k==0)    c[n][k]=1;
        else        c[n][k] = C(n-1,k)+C(n-1,k-1);
    } 
    
    return c[n][k];
}

void dfs(int a, int b, ll k){
    if(a==0&&b==0)  return;
    if(b==0){
        cout << 'a';
        dfs(a-1, b, k);
        return;
    }
    if(a==0){
        cout<<'b';
        dfs(a, b-1, k);
        return;
    }
    ll comb = C(a+b-1, a-1);
    if(comb<k){
        cout<<'b';
        dfs(a, b-1, k-comb);
    } else {
        cout << 'a';
        dfs(a-1, b, k);
    }
    return;
}
int main(){
    ll A, B, K;
    cin>>A>>B>>K;
    dfs(A, B, K);
    return 0;
}
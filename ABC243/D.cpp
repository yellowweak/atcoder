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

    ll N,X; cin>>N>>X;
    string S; cin>>S;
    vector<char> moves;

    for(auto c:S){
        if(c=='L'||c=='R')  moves.emplace_back(c);
        else{
            if(moves.size()>0 && (moves.back()=='L'||moves.back()=='R')){
                moves.pop_back();
            }
            else moves.emplace_back(c);
        }
    }

    for(auto c:moves){
        if(c=='U') X/=2;
        else if (c=='L') X*=2;
        else X = X*2+1;
    }

    cout << X;

    return 0;
}
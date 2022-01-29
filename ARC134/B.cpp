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

    int N; cin>>N;
    string s; cin>>s;
    vvi cnt(N+1, vi(26, 0));
    for(int i=0; i<sz(s); i++){
        for(int j=0; j<26; j++) cnt[i+1][j] = cnt[i][j];
        cnt[i+1][s[i]-'a']++;
    }
    int l=0, r=N-1;
    while(l<r){
        int mv=-1;
        for(int i=0; i<s[l]-'a'&&mv==-1; i++){
            if(cnt[r+1][i]-cnt[l][i]) mv = i;
        }
        if(mv==-1){
            l++;
            continue;
        }
        int mi;
        for(int i=r; ; i--){
            if((s[i]-'a')==mv){
                mi = i;
                break;
            }
        }
        if(l<mi)   swap(s[l], s[mi]);
        r = mi-1; l++;
    }

    cout << s << endl;

    return 0;
}
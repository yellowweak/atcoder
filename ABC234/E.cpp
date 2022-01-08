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
void dfs(vll &nums, string s, int len, int d){
    if(s.size()>len){
        // cout << s<<endl;
        nums.emplace_back(stoll(s));
        return;
    }
    char next_c = s.back() + d;
    if(next_c>'9'||next_c<'0')  return;
    dfs(nums, s+next_c, len, d);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll N; cin >> N;
    vll nums;
    for(int i=1; i<=99; i++)    nums.emplace_back(i);
    for(int l=2; l<=17; l++){
        for(int d=-9; d<=9; d++){
            for(char first='1'; first<='9'; first++){
                string tmp = "";
                dfs(nums, tmp+first, l, d);
            }
        }
    }
    sort(all(nums));
    auto it = lower_bound(all(nums), N);
    cout << *it;

    return 0;
}
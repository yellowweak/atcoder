#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, K, ans=INT_MAX;
    cin >>N>>K;
    int Midian=(K*K)/2+1, maxv=0, minv=INT_MAX;
    int grid[N][N], acc[N+1][N+1];
    for(int i=0; i<=N; i++) acc[i][0] = acc[0][i] = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> grid[i][j];
            maxv=max(maxv, grid[i][j]);
            minv=min(minv, grid[i][j]);
        }
    }
    int l=minv, r=maxv;
    while(l<r){
        int m = l+(r-l)/2;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                acc[i][j] = acc[i-1][j] + acc[i][j-1] - acc[i-1][j-1] + ((grid[i-1][j-1]>m)? 1:0);
            }
        }
        bool cont=true, valid=false;
        for(int i=0; i<N-K+1 && cont; i++){
            for(int j=0; j<N-K+1 && cont; j++){
                if(acc[i+K][j+K] - acc[i][j+K] - acc[i+K][j] + acc[i][j] < Midian){
                    valid=true;
                    cont=false;
                }
            }
        }
        if(valid)   r=m;
        else        l=m+1;
    }

    cout << l;
    return 0;
}
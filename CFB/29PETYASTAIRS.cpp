/*
    Author: Rishabh Saxena
    All the best!!
*/
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define XLL __int128
#define pii pair<int,int>
#define pll pair<LL,LL>
#define vi vector<int>
#define MATRIX vector<vector<int>>
#define MATRIXB vector<vector<bool>>
#define MATRIXC vector<vector<char>>
#define MATRIXLL vector<vector<LL>>
#define MATRIX3D vector<vector<vector<int>>>
#define MAX(A,B,C) max(A,max(B,C))
#define MIN(A,B,C) min(A,min(B,C))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
int main(){
    FASTIO;
    int n,m;
    cin >> n >> m;
    vi arr(m);
    for(int &i : arr)
        cin >> i;
    sort(arr.begin(),arr.end());
    bool notPos = false;
    for(int i=0;i+2<m;i++){
        if(arr[i] == arr[i+1]-1 && arr[i] == arr[i+2]-2){
            notPos = true;
            break;
        }
    }
    bool lastDirty = false,firstDirty = false;;
    if(m > 0){
        if(arr[m-1] == n)
            lastDirty = true;
        if(arr[0] == 1)
            firstDirty = true;
    }
    cout<<((!notPos && !lastDirty && !firstDirty)?"YES":"NO")<<'\n';
}

#include <bits/stdc++.h>

using namespace std;
int tmp;
void dfs(int a,int b){
    if(b==0){
        tmp=INT_MAX;
        return;
    }else if(b==1){
        tmp += a - 1;
        return;
    }
    tmp += a/b;
    dfs(b,a%b);
}
int main() {
    int n;
    cin >> n;
    int res=n - 1;
    for(int i = 1;i < n;i++){
        tmp=0;
        dfs(n,i);
        res=min(res,tmp);
    }
    return 0;
}

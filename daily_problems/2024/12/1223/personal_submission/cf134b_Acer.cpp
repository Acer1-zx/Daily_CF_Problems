#include <bits/stdc++.h>

using namespace std;
int main() {
    int t;
    cin>>t;
    cout << fixed << setprecision(10);
    while(t--){
            int a,b;
            cin>>a>>b;
            if(b==0)cout<<1<<endl;
            else if(a==0)cout<<0.5<<endl;
            else if(4*b>a)cout<<0.5 + 1.0 * a/16/b<<endl;
            else cout<< 1-1.0*b/a<<endl;
    }
    return 0;
}

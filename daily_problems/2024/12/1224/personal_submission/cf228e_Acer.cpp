#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> g(n+1);
    for(int i=0;i<m;i++){
        int a=0,b=0,c=0;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    //颜色数组，-1i表示未着色，0表示黑色，1表示白色
    vector<int> color(n+1,-1);
    vector<int> operations;//需要进行操作的城市
    bool possible=true;
    //遍历所有城市，处理所有连通分量
    for(int i=1;i<=n&&possible;i++){
      if(color[i] == -1){
          //使用BFS着色
          queue<int> q;
          q.push(i);
          color[i] = 0;//初始颜色设为0
          while(!q.empty() && possible){
              int u=q.front();
              q.pop();

              for(auto& [v,c]:g[u]){
                  if(c == 1){//已经铺设，要求颜色相同
                      if(color[v] == -1){
                          color[v] = color[u];
                          q.push(v);
                      }else if(color[v] != color[u]){
                          possible = false;
                          break;
                      }
                  }else{//未铺设要求颜色不同
                      if(color[v] == -1){
                          color[v] = 1-color[u];
                          q.push(v);
                      }else if(color[v] == color[u]){
                          possible=false;
                          break;
                      }
                  }
              }
          }
      }
    }
    if(!possible)
    {
      cout<<"Impossible"<<endl;
      return 0;
    }
    for(int i=1;i<=n;i++){
        if(color[i] == 1){
            operations.push_back(i);
        }
    }
    cout<<operations.size()<<endl;
    for(auto& op:operations){
      cout<<op<<" ";
    }
    cout<<endl;
    return 0;
}

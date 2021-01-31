#include <iostream>
#include <queue>
#include <vector>
#define MAX 1001
using namespace std;

vector<int> singer[MAX];
int inDegree[MAX];
int result[MAX];
int main()
{
        cin.tie(NULL);
        cout.tie(NULL);
        ios_base::sync_with_stdio(false);

        int n,m;
        cin>>n>>m;

        for(int i=0;i<m;i++){
                int cnt,first,second;

                cin>>cnt;
                if(cnt==0){
                        continue;
                }

                cin>>first;

                for(int i=0;i<cnt-1;i++){
                        cin>>second;
                        singer[first].push_back(second);
                        inDegree[second]++;
                        first=second;
                }
        }

        queue<int> q;

        for(int i=1;i<=n;i++){
                if(inDegree[i]==0){
                        q.push(i);
                }
        }

        for(int i=1;i<=n;i++){
                if(q.empty()){
                        cout<<0<<'\n';
                        return 0;
                }

                int cur=q.front();
                q.pop();
                result[i]=cur;

                for(int i=0;i<singer[cur].size();i++){
                        int backSinger=singer[cur][i];
                        inDegree[backSinger]--;
                        if(inDegree[backSinger]==0){
                                q.push(backSinger);
                        }
                }
        }

        for(int i=1;i<=n;i++){
                cout<<result[i]<<'\n';
        }
        cout<<'\n';
        return 0;
}

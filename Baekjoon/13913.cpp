#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 100000;

bool visited[MAX];
int path[MAX];
vector<int> where;

void bfs(int start, int end)
{
        queue<pair<int, int> > q;

        q.push(make_pair(start, 0));
        visited[start] = true;

        while(!q.empty()){
                int here = q.front().first;
                int cnt = q.front().second;
                q.pop();

                if(here == end){
                        cout<<cnt<<'\n';

                        int tmp = end;
                        while(tmp!=start){
                                where.push_back(tmp);
                                tmp = path[tmp];
                        }
                        where.push_back(start);
                    
                        for(int i=where.size()-1;i>=0;i--){
                                cout<<where[i]<<" ";
                        }
                        
                        return;
                }

                if(here+1<=MAX && !visited[here+1]){
                        visited[here+1] = true;
                        q.push(make_pair(here+1, cnt+1));
                        path[here+1] = here;
                }

                if(here-1>=0 && !visited[here-1]){
                        visited[here-1] = true;
                        q.push(make_pair(here-1, cnt+1));
                        path[here-1] = here;
                }

                if(here*2<=MAX && !visited[here*2]){
                        visited[here*2] = true;
                        q.push(make_pair(here*2, cnt+1));
                        path[here*2] = here;
                }

        }

}

int main()
{
        cin.tie(NULL);
        cout.tie(NULL);
        ios_base::sync_with_stdio(false);

        int n,k;
        cin>>n>>k;

        bfs(n,k);

        return 0;
}


#include <iostream>
#include <stack>
#include <vector>
#define N 1001
using namespace std;

vector<int> map[N];
bool visited[N]={false,};

void bfs(int v)
{
	stack<int> st;
	
	visited[v]=true;
	st.push(v);

	while(!st.empty()){
		int cur=st.top();
		st.pop();
		
		for(int i=0;i<map[cur].size();i++){
			int next=map[cur][i];
			if(!visited[next]){
				visited[next]=true;
				st.push(next);
			}
		}
	}
}
			
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n,m;
	cin>>n>>m;

	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		map[u].push_back(v);
		map[v].push_back(u);
	}

	int cnt=0;

	for(int i=1;i<=n;i++){
		if(!visited[i]){
			cnt++;
			bfs(i);
		}
	}

	cout<<cnt<<'\n';
	return 0;
}


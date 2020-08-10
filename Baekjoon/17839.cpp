#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

map<string,vector<string> > dic;
map<string,bool> visited;
vector<string> result;

void bfs(string str)
{
	queue<string> q;
	q.push(str);

	while(!q.empty()){
		string cur=q.front();
		q.pop();

		for(int i=0;i<dic[cur].size();i++){
			if(!visited[dic[cur][i]]){
				visited[dic[cur][i]]=true;
				q.push(dic[cur][i]);
				result.push_back(dic[cur][i]);
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin>>n;

	while(n--)
	{
		string p,is,q;
		cin>>p>>is>>q;

		if(p!=q){
			dic[p].push_back(q);
		}
	}

	bfs("Baba");
	
	sort(result.begin(),result.end());

	for(int i=0;i<result.size();i++){
		cout<<result[i]<<'\n';
	}

	return 0;
}

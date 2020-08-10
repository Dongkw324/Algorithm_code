#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <string>
using namespace std;

map<string,vector<string> > dic;
map<string,bool> visited;
vector<string> result;

void dfs(string str)
{
	stack<string> st;
	visited[str]=true;
	st.push(str);
	
	while(!st.empty()){
		string cur=st.top();
		st.pop();

		for(int i=0;i<dic[cur].size();i++){
			if(!visited[dic[cur][i]]){
				visited[dic[cur][i]]=true;
				st.push(dic[cur][i]);
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

	while(n--){
		string p,is,q;
		cin>>p>>is>>q;

		dic[p].push_back(q);
	}

	dfs("Baba");

	sort(result.begin(),result.end());

	for(int i=0;i<result.size();i++){
		cout<<result[i]<<'\n';
	}

	return 0;
}


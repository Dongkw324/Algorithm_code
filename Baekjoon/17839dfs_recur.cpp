#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

map<string,vector<string> > dic;
map<string,bool> visited;
vector<string> result;

void dfs(string str)
{
	visited[str]=true;

	for(int i=0;i<dic[str].size();i++){
		if(!visited[dic[str][i]]){
			result.push_back(dic[str][i]);
			dfs(dic[str][i]);
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
		
		if(p!=q){
			dic[p].push_back(q);
		}
	}
	

	dfs("Baba");
	
	sort(result.begin(),result.end());

	for(int i=0;i<result.size();i++){
		cout<<result[i]<<'\n';
	}

	return 0;
}

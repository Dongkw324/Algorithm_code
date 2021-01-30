#include <iostream>
#include <vector>
#include <queue>
#define MAX 32000
using namespace std;

vector<int> height[MAX];
int inDegree[MAX];

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n,m;
	cin>>n>>m;

	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;

		height[a].push_back(b);
		inDegree[b]++;
	}

	queue<int> q;

	for(int i=1;i<=n;i++){
		
		if(inDegree[i]==0){
			q.push(i);
		}
	}

	while(!q.empty()){
		int cur=q.front();
		q.pop();
		
		cout<<cur<<" ";
		for(int i=0;i<height[cur].size();i++){
			int cur2=height[cur][i];
			inDegree[cur2]--;
			if(inDegree[cur2]==0){
				q.push(cur2);
			}
		}
	}

	cout<<'\n';
	return 0;
}
		


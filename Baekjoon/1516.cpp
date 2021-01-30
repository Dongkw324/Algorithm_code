#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 500

using namespace std;

vector<int> game[MAX]; //그래프
int inDegree[MAX]; //진입차수
int build_time[MAX]; //건물 짓는 시간
int result[MAX]; //결과값

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin>>n;

	for(int i=1;i<=n;i++){
		cin>>build_time[i];

		while(true){
			int pri_build;
			cin>>pri_build;

			if(pri_build==-1){
				break;
			}

			game[pri_build].push_back(i);
			inDegree[i]++;
		}
	}

	queue<int> q;

	for(int i=1;i<=n;i++){
		if(inDegree[i]==0){
			q.push(i);
			result[i]=build_time[i];
		}
	}

	while(!q.empty()){
		int cur=q.front();
		q.pop();
		
		for(int i=0;i<game[cur].size();i++){
			int theBuild=game[cur][i];
			inDegree[theBuild]--;
			
			result[theBuild]=max(result[theBuild],result[cur]+build_time[theBuild]);
			if(inDegree[theBuild]==0){
				q.push(theBuild);
			}
		}
	}

	for(int i=1;i<=n;i++){
		cout<<result[i]<<'\n';
	}
	cout<<'\n';
	return 0;
}




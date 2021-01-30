#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define MAX 1001
using namespace std;

vector<int> acm[MAX];
int inDegree[MAX];
int build_time[MAX];
int result[MAX];
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin>>T;

	while(T--){
		int N,K;
		cin>>N>>K;

		for(int i=1;i<=N;i++){
			cin>>build_time[i];
		}

		for(int i=1;i<=K;i++){
			int X,Y;
			cin>>X>>Y;

			acm[X].push_back(Y);
			inDegree[Y]++;
		}

		int W;
		cin>>W;

		queue<int> q;

		for(int i=1;i<=N;i++){
			if(inDegree[i]==0){
				q.push(i);	
			}
			result[i]=build_time[i];
		}

		while(!q.empty()){
			int cur=q.front();
			q.pop();

			for(int i=0;i<acm[cur].size();i++){
				int num=acm[cur][i];
				inDegree[num]--;

				result[num]=max(result[num],result[cur]+build_time[num]);

				if(inDegree[num]==0){
					q.push(num);
				}
			}
		}

		cout<<result[W]<<'\n';

		for(int i=0;i<MAX;i++){
			acm[i].clear();
		}

		memset(build_time,0,sizeof(build_time));
		memset(inDegree,0,sizeof(inDegree));
		memset(result,0,sizeof(result));

	}
	return 0;
}


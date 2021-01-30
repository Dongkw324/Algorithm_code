#include <iostream>
#include <vector>
#include <queue>
#define MAX 32001
using namespace std;

vector<int> problem[MAX];
int inDegree[MAX];

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N,M;
	cin>>N>>M;

	for(int i=1;i<=M;i++){
		int A,B;
		cin>>A>>B;

		problem[A].push_back(B);
		inDegree[B]++;
	}

	priority_queue<int,vector<int>,greater<int> > pq;

	for(int i=1;i<=N;i++){
		if(inDegree[i]==0){
			pq.push(i);
		}
	}

	while(!pq.empty()){
		int cur=pq.top();
		pq.pop();

		cout<<cur<<" ";

		for(int i=0;i<problem[cur].size();i++){
			int num=problem[cur][i];
			inDegree[num]--;

			if(inDegree[num]==0){
				pq.push(num);
			}
		}
	}

	cout<<'\n';
	return 0;
}



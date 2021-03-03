#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 100000;
int main()
{
	int v,e;
	cin>>v>>e;
	
	int start;
	cin>>start;

	vector<pair<int,int> > graph[v+1];

	for(int i=0;i<e;i++){
		int from, to, weight;
		cin>>from>>to>>weight;

		graph[from].push_back(make_pair(to, weight));
	}

	vector<int> dist;
	dist.resize(v+1, INF);
	dist[start] = 0;

	priority_queue<pair<int, int>> pq;
	
	pq.push(make_pair(0, start));
	
	while(!pq.empty()){
		int cost = -pq.top().first;
		int here = pq.top().second;

		pq.pop();

		if(dist[here]<cost){
			continue;
		}

		for(int i=0;i<graph[here].size();i++){
			int next = graph[here][i].first;
			int nextCost = graph[here][i].second;

			if(dist[next]>cost+nextCost){
				dist[next] = cost+nextCost;
				pq.push(make_pair(-dist[next], next));
			}
		}
	}

	for(int i=1;i<=v;i++){
		if(dist[i]==INF){
			cout<<"INF"<<'\n';
		}
		else
			cout<<dist[i]<<'\n';
	}

	return 0;
}


	

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 99999999;
const int MAX_CITY = 1010;

int n,m;

vector<pair<int, int> > city[MAX_CITY];
vector<int> route;
int path[MAX_CITY];

void dijk(int start, int end)
{
	vector<int> dist;
	dist.resize(n+1, INF);

	priority_queue<pair<int, int> > pq;
	
	pq.push(make_pair(0, start));
	dist[start] = 0;

	while(!pq.empty()){
		int cost = -pq.top().first;
		int here = pq.top().second;

		pq.pop();

		for(auto i:city[here]){
			int next = i.first;
			int nextCost = i.second;

			if(dist[next]>dist[here]+nextCost){
				dist[next] = dist[here]+nextCost;
				pq.push(make_pair(-dist[next], next));
				path[next] = here;
			}
		}
	}
	
	cout<<dist[end]<<'\n';
	
	int tmp = end;
	
	while(tmp){
		route.push_back(tmp);
		tmp = path[tmp];
	}

	cout<<route.size()<<'\n';

	for(int i=route.size()-1;i>=0;i--){
		cout<<route[i]<<" ";
	}
	cout<<'\n';
}
	

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin>>n;
	cin>>m;

	for(int i=0;i<m;i++){
		int from, to, value;
		cin>>from>>to>>value;

		city[from].push_back(make_pair(to, value));
	}

	int start, end;
	cin>>start>>end;

	dijk(start, end);
	
	return 0;
}


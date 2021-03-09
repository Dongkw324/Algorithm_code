#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 100001;
const int MAX_CITY = 101;

int city[MAX_CITY][MAX_CITY];
int path[MAX_CITY][MAX_CITY];
vector<int> shortest;

void findPath(int start, int end)
{
	if(path[start][end]==0){
		shortest.push_back(start);
		shortest.push_back(end);
		return;
	}
	findPath(start, path[start][end]);
	shortest.pop_back();
	findPath(path[start][end], end);
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n,m;
	cin>>n>>m;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j){
				city[i][j]=0;
			}
			else{
				city[i][j]=INF;
			}
		}
	}

	for(int i=0;i<m;i++){
		int from, to, value;
		cin>>from>>to>>value;

		city[from][to] = min(city[from][to], value);
	}

	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j){
					continue;
				}
				
				if(city[i][j]>city[i][k]+city[k][j]){
					path[i][j]=k;
				}
				city[i][j] = min(city[i][j], city[i][k]+city[k][j]);
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(city[i][j]==INF || city[i][j]==0){
				cout<<0<<" ";
			}
			else{
				cout<<city[i][j]<<" ";
			}
		}
		cout<<'\n';
	}
	

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(city[i][j]==0 || city[i][j]==INF){
				cout<<0;
			}
			else{
				shortest.clear();
				findPath(i,j);
				cout<<shortest.size()<<" ";
				for(int k=0;k<shortest.size();k++){
					cout<<shortest[k]<<" ";
				}
			}
			cout<<'\n';
		}
	}
	return 0;
}

#include <iostream>
#include <queue>
#include <algorithm>
#define MAX_SIZE 10001
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n,l,p;
	pair<int,int> oil[MAX_SIZE];

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>oil[i].first>>oil[i].second;
	}

	cin>>l>>p;
	sort(oil,oil+n);	
	
	priority_queue<int> pq;

	int cur=0;
	int cnt=0;
	while(p<l){
		while(p>=oil[cur].first){
			pq.push(oil[cur++].second);
		}

		if(cur==n){
			break;
		}
		
		if(pq.empty()){
			break;
		}

		cnt++;
		p+=pq.top();
		pq.pop();
	}
	
	cnt=(p<l)?-1:cnt;

	cout<<cnt<<'\n';
	return 0;
}


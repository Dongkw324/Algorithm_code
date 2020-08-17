#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N,K;
	cin>>N>>K;

	queue<int> q;
	vector<int> result;

	for(int i=1;i<=N;i++){
		q.push(i);
	}

	while(!q.empty()){
		for(int i=1;i<=N;i++){
			int temp=q.front();
			q.pop();

			if(i==K){
				result.push_back(temp);
				break;
			}
			else{
				q.push(temp);
			}
		}
	}

	cout<<'<';
	for(int i=0;i<result.size()-1;i++){
		cout<<result[i]<<", ";
	}
	cout<<result[result.size()-1]<<'>'<<'\n';

	return 0;
}

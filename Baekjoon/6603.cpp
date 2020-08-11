#include <iostream>
#include <vector>
using namespace std;

vector<int> input(14);
vector<int> lotto;
const int MAX=6;
int T;

void dfs(int start)
{
	if(lotto.size()==MAX){
		for(int i=0;i<MAX;i++){
			cout<<lotto[i]<<" ";
		}
		cout<<'\n';
		return;
	}
	
	for(int i=start;i<T;i++){
		lotto.push_back(input[i]);
		dfs(i+1);
		lotto.pop_back();
	}
}
	

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	while(1){
		cin>>T;

		if(T==0)
			break;

		for(int i=0;i<T;i++){
			cin>>input[i];
		}

		dfs(0);
		cout<<'\n';
		input.clear();
	}
	return 0;
}

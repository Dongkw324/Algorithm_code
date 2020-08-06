#include <iostream>
#include <queue>
#define MAX_SIZE 100001
using namespace std;

bool visited[MAX_SIZE]={false,}; //방문 지점 표시 배열

int bfs(int n,int k)//bfs 탐색 이용해서 문제 해결
{
	queue<pair<int,int> > q;
	visited[n]=true;//수빈이의 위치를 true로 저장
	
	q.push(make_pair(n,0)); //시작점의 위치와 횟수를 queue에 삽입

	while(1){
		int cur=q.front().first; //수빈이의 위치 저장
		int cnt=q.front().second; //방문 횟수 저장
		q.pop(); //queue pop

		if(cur==k){ //동생의 위치와 수빈이의 위치가 같으면 방문 횟수 리턴
			return cnt;
		}
		
		//걷기 2번과 순간이동 1번을 고려하여 최소 방문 횟수 세기
		if(cur-1>=0&&!visited[cur-1]){
			visited[cur-1]=true;
			q.push(make_pair(cur-1,cnt+1));
		}
		if(cur+1<MAX_SIZE&&!visited[cur+1]){
			visited[cur+1]=true;
			q.push(make_pair(cur+1,cnt+1));
		}
		if(cur*2<MAX_SIZE&&!visited[2*cur]){
			visited[2*cur]=true;
			q.push(make_pair(cur*2,cnt+1));
		}

		
	}
}
		
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n,k;
	cin>>n>>k;

	int cnt=bfs(n,k);

	cout<<cnt<<'\n';
	return 0;
}

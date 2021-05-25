//백준 1931번 회의실 배정 문제풀이
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
        if(a.second == b.second)
                return a.first<b.first;

        return a.second<b.second;
}

int main()
{
        cin.tie(NULL);
        cout.tie(NULL);
        ios_base::sync_with_stdio(false);

        int N;
        cin>>N;

        vector<pair<int, int>> meeting;

        for(int i=0;i<N;i++){
                int start, end;
                cin>>start>>end;

                meeting.push_back(make_pair(start, end));
        }

        sort(meeting.begin(), meeting.end(), comp);

        int t = meeting[0].second;
        int answer = 1;
        for(int i=1;i<N;i++){
                if(t<=meeting[i].first){
                        t = meeting[i].second;
                        answer++;
                }
        }

        cout<<answer<<'\n';
}


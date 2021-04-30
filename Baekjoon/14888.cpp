//백준 14888번 연산자 끼워넣기 문제풀이
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_CNT = 11;
const int MAX_NUM = 1000000000+1;

int n, min_res = MAX_NUM, max_res = -MAX_NUM;
int A[MAX_CNT];
int opt[4];

void dfs(int val, int cnt)
{
        if(cnt == n)
        {
                min_res = (min_res<val) ? min_res : val;
                max_res = (max_res>val) ? max_res : val;
                return;
        }

        for(int i=0;i<4;i++){
                if(opt[i]>0){
                        opt[i]--;
                        switch(i){
                                case 0:
                                        dfs(val+A[cnt], cnt+1);
                                        break;
                                case 1:
                                        dfs(val-A[cnt], cnt+1);
                                        break;
                                case 2:
                                        dfs(val*A[cnt], cnt+1);
                                        break;
                                case 3:
                                        dfs(val/A[cnt], cnt+1);
                                        break;
                        }
                        opt[i]++;
                }
        }

}

int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        cin>>n;

        for(int i=0;i<n;i++){
                cin>>A[i];
        }

        for(int i=0;i<4;i++){
                cin>>opt[i];
        }

        dfs(A[0], 1);

        cout<<max_res<<'\n';
        cout<<min_res<<'\n';

        return 0;
}

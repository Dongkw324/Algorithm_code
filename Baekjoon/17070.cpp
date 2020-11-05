#include <iostream>
using namespace std;
int house[16][16];
const int dirX[3]={1,0,1};
const int dirY[3]={0,1,1};
int cnt=0;

void pip(int x,int y,int state,int n)
{

        if(x==n-1&&y==n-1){
                cnt++;
                return;
        }

        for(int i=0;i<=2;i++){
                if((i==0&&state==1)||(i==1&&state==0)){
                        continue;
                }
                int nx=x+dirX[i];
                int ny=y+dirY[i];

                if(nx>=n||ny>=n||house[ny][nx]==1){
                        continue;
                }

                if(i==2&&(house[y+1][x]==1||house[y][x+1]==1)){
                        continue;
                }
                pip(nx,ny,i,n);
        }
}

int main()
{
        cin.tie(NULL);
        cout.tie(NULL);
        ios_base::sync_with_stdio(false);

        int n;
        cin>>n;

        for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                        cin>>house[i][j];
                }
        }

        pip(1,0,0,n);

        cout<<cnt<<'\n';
        return 0;
}

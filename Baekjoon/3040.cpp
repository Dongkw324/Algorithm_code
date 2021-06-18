//백준 3040번 백설 공주와 일곱 난쟁이 문제풀이
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
        int height[9];
        int sum = 0;
        bool flag = true;

        for(int i=0;i<9;i++){
                cin>>height[i];
                sum += height[i];
        }

        for(int i=0;i<8&&flag;i++){
                for(int j=1;j<9&&flag;j++){
                        if(sum-(height[i]+height[j])==100){
                                height[i]=9999;
                                height[j]=9999;
                                flag = false;
                                break;
                        }
                }
        }

        sort(height, height+9);

        for(int i=0;i<7;i++){
                cout<<height[i]<<'\n';
        }

        return 0;
}

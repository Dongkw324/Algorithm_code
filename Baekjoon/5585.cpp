//백준 5585번 거스름돈 문제풀이
#include <iostream>

using namespace std;

int main()
{
        int payment;
        cin>>payment;

        int changes = 1000-payment;
        int cnt = 0;
        int opt[6]={500,100,50,10,5,1};

        for(int i=0;i<6;i++){
                while(changes-opt[i] >= 0){
                        cnt++;
                        changes -= opt[i];

                        if(changes == 0){
                                break;
                        }
                }
        }

        cout<<cnt<<'\n';
}

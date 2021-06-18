//백준 2501번 약수 구하기 문제풀이
#include <iostream>

using namespace std;

int main()
{
        int n,k;
        int cnt=0;
        cin>>n>>k;

        for(int i=1;i<=n;i++){

                if(n%i==0){
                        cnt++;

                        if(cnt == k){
                                cout<<i<<'\n';
                                return 0;
                        }
                }
        }
        cout<<0<<'\n';
}

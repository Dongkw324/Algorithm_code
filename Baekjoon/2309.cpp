//백준 일곱 난쟁이 문제풀이
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
        int dwarf[9];
        int sum = 0;
        bool flag = true;
    
        for(int i=0;i<9;i++){
                cin>>dwarf[i];
                sum += dwarf[i];
        }

        for(int i=0;i<8&&(flag == true);i++){
                for(int j=i+1;j<9 && (flag == true);j++){
                        if(sum - (dwarf[i] + dwarf[j]) == 100){
                                dwarf[i] = 100;
                                dwarf[j] = 100;
                                flag = false;
                                break;
                        }
                }
        }

        sort(dwarf, dwarf+9);

        for(int i=0;i<7;i++){
                cout<<dwarf[i]<<'\n';
        }

        return 0;
}

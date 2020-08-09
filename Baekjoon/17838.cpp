#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin>>T;

	while(T--){
		string str;
		cin>>str;

		if(str.length()!=7){
			cout<<0<<'\n';
		}
		else{
			if(str[0]==str[1]&&str[1]!=str[2]&&str[2]==str[3]&&str[3]!=str[4]&&str[4]!=str[5]&&str[5]==str[6]){
				cout<<1<<'\n';
			}
			else{
				cout<<0<<'\n';
			}
		}
	}

	return 0;
}

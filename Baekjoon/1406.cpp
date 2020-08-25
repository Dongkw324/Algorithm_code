#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string text;
	int M;
	
	cin>>text>>M;

	list<char> ch;

	for(int i=0;i<text.size();i++){
		ch.push_back(text[i]);
	}

	list<char>::iterator cur=ch.end();

	while(M--){
		char command;
		cin>>command;

		switch(command){
			case 'L':
				if(cur==ch.begin()){
					continue;
				}
				cur--;
				break;
			case 'D':
				if(cur==ch.end()){
					continue;
				}
				cur++;
				break;
			case 'B':
				if(cur==ch.begin()){
					continue;
				}
				cur=ch.erase(--cur);
				break;
			case 'P':
				char c;
				cin>>c;
				ch.insert(cur,c);
				break;
		}
	}

	for(char c:ch){
		cout<<c;
	}
	cout<<'\n';
	return 0;
}

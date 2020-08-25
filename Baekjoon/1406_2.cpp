#include <iostream>
#include <stack>
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

	stack<char> first,end;

	for(int i=0;i<text.length();i++){
		first.push(text[i]);
	}

	while(M--){
		char command;
		cin>>command;

		switch(command){
			case 'L':
				if(first.empty()){
					continue;
				}
				end.push(first.top());
				first.pop();
				break;
			case 'D':
				if(end.empty()){
					continue;
				}
				first.push(end.top());
				end.pop();
				break;
			case 'B':
				if(first.empty()){
					continue;
				}
				first.pop();
				break;
			case 'P':
				char ch;
				cin>>ch;
				first.push(ch);
				break;
		}
	}

	while(!first.empty()){
		end.push(first.top());
		first.pop();
	}

	string result;
	while(!end.empty()){
		result+=end.top();
		end.pop();
	}

	cout<<result<<'\n';
	return 0;
}

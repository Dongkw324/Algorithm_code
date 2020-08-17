#include <iostream>
#include <stack>
#include <string>
using namespace std;

const int MAX_SIZE=26;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin>>N;

	string exp;
	cin>>exp;
	
	int val[MAX_SIZE];

	for(int i=0;i<N;i++){
		cin>>val[i];
	}
	
	stack<double> st;

	for(int i=0;i<exp.length();i++){
		if(exp[i]!='+'&&exp[i]!='-'&&exp[i]!='*'&&exp[i]!='/'){
			st.push(val[exp[i]-'A']);
		}
		else{
			double a=st.top();
			st.pop();
			double b=st.top();
			st.pop();

			switch(exp[i]){
				case '+':
					st.push(b+a);
					break;
				case '-':
					st.push(b-a);
					break;
				case '*':
					st.push(b*a);
					break;
				case '/':
					st.push(b/a);
					break;
			}
		}
	}

	double result=st.top();
	cout<<fixed;
	cout.precision(2);
	cout<<result<<'\n';

	return 0;
}

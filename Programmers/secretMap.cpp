#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<int> arr(n);
    
    for(int i=0;i<arr.size();i++){
        arr[i]=arr1[i]|arr2[i];
    }
    for(int i=0;i<n;i++){
        string temp="";
        
        for(int j=0;j<n;j++){
            if(arr[i]%2==1){
                temp+="#";
            }
            else{
                temp+=" ";
            }
            arr[i]/=2;
        }
        
        reverse(temp.begin(),temp.end());
        answer.push_back(temp);
    }
    return answer;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin>>n;

	vector<int> arr1(n);
	vector<int> arr2(n);

	for(int i=0;i<arr1.size();i++){
		cin>>arr1[i];
	}

	for(int i=0;i<arr2.size();i++){
		cin>>arr2[i];
	}

	vector<string> answer=solution(n,arr1,arr2);

	for(int i=0;i<answer.size();i++){
		cout<<answer[i]<<'\n';
	}

	return 0;
}

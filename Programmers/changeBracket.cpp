#include <string>
#include <vector>
#include <stack>
using namespace std;

bool checkString(string ans){
    stack<char> st;
    
    for(int i=0;i<ans.length();i++){
        if(ans[i]=='('){
            st.push(ans[i]);
        }
        else if(ans[i]==')'){
            if(st.empty()){
                return false;
            }
            else{
                st.pop();
            }
        }
    }
    
    if(!st.empty())
        return false;
    else
        return true;
}

string solution(string p) {
    if(p.length()==0){
        return "";
    }
    
    string u="";
    string v="";
    string answer="";
    
    int left=0;
    int right=0;
    int index=0;
    
    for(int i=0;i<p.length();i++){
        if(p[i]=='('){
            left++;
        }
        else if(p[i]==')'){
            right++;
        }
        index++;
        if(left==right){
            break;
        }
    }
    
    u=p.substr(0,index);
    v=p.substr(index);
    
    if(checkString(u)){
        answer+=u;
        answer+=solution(v);
    }
    else{
        string temp="";
        temp+="(";
        temp+=solution(v);
        temp+=")";
        
        int len=u.length()-2;
        u=u.substr(1,len);
        
        for(int i=0;i<u.length();i++){
            if(u[i]=='('){
                u[i]=')';
            }
            else if(u[i]=')'){
                u[i]='(';
            }
        }
        temp+=u;
        answer=temp;
    }
    
    return answer;
}

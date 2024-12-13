#include<bits/stdc++.h>
using namespace std;

int checkpred(char ch){
    if(ch == '^'){
        return 3;
    }
    else if(ch == '/' || ch == '*'){
        return 2;
    }
    else if(ch == '+' || ch == '-'){
        return 1;
    }
    else{
        return -1;
    }
}

void infixToPostfix(string str){
    stack<char> st;
    string res = "";
    
    for(int i = 0 ;i < str.length();i++){
        if(str[i] == '(' ){
            st.push(str[i]);
        }
        else if(str[i] >= 'A' && str[i] <= 'Z'){
            res += str[i];
        }
        else if(str[i] == ')'){
            while(st.top() != '('){
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            while(!st.empty() && checkpred(str[i]) < checkpred(st.top())  || !st.empty() && checkpred(str[i]) == checkpred(st.top())){
                res += st.top();
                st.pop();
            }
            st.push(str[i]);
        }
    }

    while(!st.empty()){
        res += st.top();
        st.pop();
    }

    cout<<res<<endl;
}


int main(){
    string str = "(A*B)+(C/D)";
    infixToPostfix(str);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int calculate(int x, int y , char op){
    switch(op){
        case '+':
            return x + y;
        case '-':
            return x - y;
        case '*':
            return x * y;
        case '/':
            return x / y;

    }
    return 0;
}

int checkPred(char pred){
    if(pred == '/' || pred == '*'){
        return 3;
    }
    else if(pred == '+' || pred == '-'){
        return 2;
    }
    return -1;
}

int reversePolishNotation(string str){
    stack<int> operands;
    stack<char> operators;

    for(int i = 0 ; i < str.length(); i++){

        if(isdigit(str[i])){
            int num = 0;
            while(i < str.length() && isdigit(str[i])){
                num = (num * 10) + (str[i] -'0');
                i++;
            }
            operands.push(num);
            i--;
        }

        else if(str[i] == '('){
            operators.push(str[i]);
        }

        else if(str[i] == ')'){
            while(!operators.empty() && operators.top() != '(' ){
                char op = operators.top();
                operators.pop();
                int y = operands.top();
                operands.pop();
                int x = operands.top();
                operands.pop();

                operands.push(calculate(x,y,op));
            }
            operators.pop();
        }
        else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'){
            while(!operators.empty() && checkPred(str[i]) <= checkPred(operators.top())){
                char op = operators.top();
                operators.pop();
                int y = operands.top();
                operands.pop();
                int x = operands.top();
                operands.pop();

                operands.push(calculate(x,y,op));
            }
            operators.push(str[i]);
        }

    }

    while(!operators.empty()){
        char op = operators.top();
        operators.pop();
        int y = operands.top();
        operands.pop();
        int x = operands.top();
        operands.pop();

        operands.push(calculate(x,y,op));
    }

    return operands.top();
}

int main(){
    string str = "(1222+52)*(10-4)";
    int x = reversePolishNotation(str);
    cout<<x<<endl;
    return 0;
}
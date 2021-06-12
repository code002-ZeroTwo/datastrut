#include<iostream>
#include<ctype.h>
#include<stack>

using namespace std;

int prec(char a){
    if(a=='('){
        return 3;
    }
    else if(a=='$'){
        return 2;
    }
    else if(a=='*'||a=='/'){
        return 1;
    }
    else return 0;
}


int opera(string exp){
    stack<int> op;
    stack<int> po;
    int n;
    n=exp.length();
    for(int i=n-1;i>=0;i--){
        if(exp[i]==')'){
            op.push(exp[i]);
        }
        else if(isalnum(exp[i])){
            po.push(exp[i]);
        }
        else if(exp[i]=='('){
            while(op.top()!=')'){
                char i;
                i=op.top();
                op.pop();
                op.push(i);
            }
            op.pop();
        }
        else{
            if(!op.empty()){
                while(prec(op.top())>prec(exp[i])){
                    char i;
                    i=op.top();
                    op.pop();
                    po.push(i);
                    if(op.empty()){
                        break;
                    }
                }
                op.push(exp[i]);
            }
            else{
                op.push(exp[i]);
            }
        }
    }
    while(!op.empty()){
        char a;
        a=op.top();
        op.pop();
        po.push(a);
    }
    string temp;
    int count=0;
    while(!po.empty()){
        temp+=po.top();
        po.pop();
        count++;
    }
    cout<<"expression is: ";
    for(int i=0;i<count;i++){
        cout<<temp[i];
    }
    cout<<endl;
    return 0;

}

int main(){
    string exp;
    cout<<"enter expression: ";
    cin>>exp;
    opera(exp);
    return 0;
}
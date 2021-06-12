#include<iostream>
#include<stack>
#include<math.h>

using namespace std;

int operation(char a,int b,int c){
    if(a=='+'){
        return b+c;
    }
    else if(a=='-'){
        return b-c;
    }
    else if(a=='*'){
        return b*c;
    }
    else if(a=='/'){
        return b/c;
    }
    else return pow(b,c);
}

int main(){
    stack<int> vs;
    string exp;
    int a,n;
    cout<<"enter prefix expression: ";
    cin>>exp;
    n=exp.length();
    for(int i=n-1;i>=0;i--){
        if(isalnum(exp[i])){
            int g;
            cout<<"enter value of "<<exp[i]<<": ";
            cin>>g;
            vs.push(g);
        }
        else{
            int e,f,result;
            e=vs.top();
            vs.pop();
            f=vs.top();
            vs.pop();
            result=operation(exp[i],e,f);
            vs.push(result);
        }
    }
    a=vs.top();
    vs.pop();
    cout<<"calcualted value is: "<<a<<endl;
    return 0;
}
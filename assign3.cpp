#include<iostream>
#include<ctype.h>
#include<stack>
#include<cmath>

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
    int n,b;
    cout<<"enter the expression: ";
    cin>>exp;
    n=exp.length(); 
    for(int i=0;i<n;i++){
        if(isalnum(exp[i])){
            int a;
            cout<<"enter value of "<<exp[i]<<": ";
            cin>>a;
            vs.push(a);
        }
        else{
            int c,d,e,result;
            c=vs.top();
            vs.pop();
            d=vs.top();
            vs.pop();
            result=operation(exp[i],c,d);
            vs.push(result);
        }
    }  
    b=vs.top();
    vs.pop();
    cout<<b<<endl;
    return 0;
}
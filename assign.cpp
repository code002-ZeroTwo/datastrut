#include<iostream>
#include<stack>
#include<ctype.h>
#include<cstring>

using namespace std;


int prec(char a){
   if(a=='$'){
      return 3;
   }
   else if(a=='/'||a=='*'){
      return 2;
   }
   else{
      return 1;
   }
}



int main(){
   stack<int> op;
   stack<int> po;
   string exp,last;
   int a;
   cout<<"enter expression: "<<endl;
   cin>>exp;
   a=exp.length();
   for(int i=0;i<a;i++){
      if(exp[i]=='('){
         op.push(exp[i]);
      }
      else if(isalnum(exp[i])){
         po.push(exp[i]);
      }
      else if(exp[i]==')'){
         while(op.top()!='('){
            char e;
            e=op.top();
            op.pop();
            po.push(e);
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
      char temp;
      temp=op.top();
      op.pop();
      po.push(temp);
   }
   int j=0;
   while(!po.empty())
   {
      last+=po.top();
      po.pop();
   }
   cout<<"postfix expression is :";
   for(int i=last.length()-1;i>=0;i--){
      cout<<last[i];
   }
   cout<<endl;
   return 0;
}
#include<iostream>
#include<stack>

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
   string exp;
   int a;
   cout<<"enter expression: "<<endl;
   cin>>exp;
   a=exp.length();
   for(int i=0;i<a;i++){
      if(exp[i]=='('){
         op.push(exp[i]);
      }
      else if(isalnum(exp[i]) || isdigit(exp[i])){
         po.push(exp[i]);
      }
      else if(exp[i]==')'){
         char e;
         while(e!='('){
            e=op.top();
            op.pop();
            po.push(e);

         }
         if(op.top()=='('){
            op.pop();
         }

      }
      else{
         if(!op.empty()){
            while(prec(op.top())>prec(exp[i])){
               char i;
               i=op.top();
               op.pop();
               po.push(i);
            }
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
   return 0;

}
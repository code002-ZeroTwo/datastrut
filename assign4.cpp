#include<iostream>

using namespace std;

int fact(int a){
    if(a==0){
        return 1;
    }
    else{
        return a*fact(a-1);
    }
}


int main(){
    int n,x;
    cout<<"enter number: ";
    cin>>n;
    x=fact(n);
    cout<<"factorial of number "<<n<<" is: "<<x<<endl;
    return 0;
}
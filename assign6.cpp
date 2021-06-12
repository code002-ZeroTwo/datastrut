#include<iostream>

using namespace std;

int toh(int a,string b,string c,string d){
    if(a>0){
        toh(a-1,b,d,c);
        cout<<"move disk "<<a<<" from "<<b<<" to "<<c<<"."<<endl;
        toh(a-1,d,c,b);
    }
    return 0;
}

int main(){
    int n;
    cout<<"enter number of disks: ";
    cin>>n;
    toh(n,"origin","destination","temp");
    return 0;
}
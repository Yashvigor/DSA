#include<iostream>
using namespace std;
int Factorial(int num)
{
    int fact=1;
    if(num==0 || num==1)
        return 1;

    for(int i=2;i<=num;i++){
        fact=fact*i;
    }
     return fact;

}
int main(){

int num;
cout<<"Enter the number to find factorial of:";
cin>>num;

int fact=Factorial(num);
cout<<"The factorial of "<<num<<" is "<<fact;

}

#include<iostream>
using namespace std;

int decimalToBinary(int num){
    int rem, pow=1, ans=0;
    while(num>0){
        rem = num%2;
        num = num/2;
        ans += (rem * pow);
        pow *= 10;
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    int num , result;
    cout<<"Enter a number = ";
    cin>>num;
    result=decimalToBinary(num);
    cout<<"Answer = "<<result;
    return 0;
}

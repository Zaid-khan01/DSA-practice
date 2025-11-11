#include<iostream>
using namespace std;

int binaryToDecimal(int num){
    int rem, ans=0, pow=1;
    while(num>0){
        rem = num%10;
        ans += rem*pow;
        num /= 10;
        pow *= 2;
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    int num;
    cout<<"Enter a number = ";
    cin>>num;
    cout<<binaryToDecimal(num);
    return 0;
}

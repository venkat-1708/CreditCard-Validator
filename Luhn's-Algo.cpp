#include<iostream>
#include <string>
using namespace std;
bool isNumberString(const string &s)
{
    
    for(int i=0;i<s.length();i++)
    {
        if(s[i]<'0' || s[i]>'9')
         return false;
    }
    return true;
}
int main(){
 string Card_number;
 cout<<"\n\n This program uses the Luhn algorithm to valid a Credit cardnumber!"<<endl;
 cout<<"\n\n Enter 'quit' at anytime to quit!\n\n"<<endl;
 
 while(1)
 {
   
    cout<<"Enter a Credit Card Number to validate: ";
    cin>>Card_number;
    if(Card_number=="quit")
    break;
    else if(!isNumberString(Card_number) || Card_number.length()>16)
    {
        cout<<"Enter a valid input!";
        continue;
    }
    int Sum_even_doubled=0;
    //Step 1 – Starting from the rightmost digit, double the value of every second digit. 
    for(int i=Card_number.length()-2;i>=0;i-=2)
    {
       int x=(Card_number[i]-'0')*2;
       // If doubling of a number results in a two digit number i.e greater than 9, then add the digits of the product  to get a single digit number. 
       if(x>9)
       {
         x=(x/10)+(x%10);
       }
       Sum_even_doubled+=x;
    }
    // Now take the sum of all the digits.Since we have already added odd placed digits from end, we should now add even placed digits.
    for(int i=Card_number.length()-1;i>=0;i-=2)
    {
        Sum_even_doubled+=(Card_number[i]-'0');
    }
// If the total modulo 10 is equal to 0 (if the total ends in zero) then the number is valid according to the Luhn formula; else it is not valid
   if(Sum_even_doubled%10==0)
    cout<<"Valid Number!";
    else cout<<"Invalid Number!";
    cout<<endl;
 }

 return 0; 
}
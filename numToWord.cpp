#include <iostream>
#include <string.h>

using namespace std;
int main()
{
    int num;
    cout<<"Enter Num: ";
    cin>>num;
    string colWord[27] = {
    "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
    "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen", "Twenty",
    "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    if(num==0)
        cout<<"Zero";
    else if(num <=20)
        cout<<colWord[num-1];
    else
    {
        int nameInInd1 = num/10;
        cout<<colWord[20+(nameInInd1-3)]<<" ";
        nameInInd1 = num%10;
        cout<<colWord[nameInInd1-1]<<" ";
    }

}

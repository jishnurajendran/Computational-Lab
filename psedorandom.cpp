#include<fstream>
#include<iostream>
using namespace std;

int fun()
{
    int S[300],key[]={1,2,3,4},K[300],i=0,j=0,n=0,temp=0;
    for(i=0;i<256;i++)
        S[i]=i;
    //for(i=0;i<256;i++)
      // cout<<S[i]<<" ";
    for(i=0;i<256;i++)
    {
        j=(j+S[i]+key[i%sizeof(key)])%256;
        temp=S[i];
        S[i]=S[j];
        S[j]=temp;
    }
    i=j=0;
    while(i<6)
    {
        i=(i+1)%256;
        j=(j+S[i])%256;
        temp=S[i];
        S[i]=S[j];
        S[j]=temp;
        K[i]=S[S[i]+S[j]]%256;
    }

    for(i=0;i<5;i++)
        cout<<K[i]<<" ";
    return K[0];
}
int main()
{

    fun();
    fstream fff;
    //fff.open("gffg.dat");
}

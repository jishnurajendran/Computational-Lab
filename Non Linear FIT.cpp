#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
int main()
{
    int n,m,i,j,k,n1;
    cout<<"# of data points are \n";
    cin>>n;
    double A[n][4],x[n],y[n],s[n],b[n];
    fstream ifile("problem_3_data.m",ios::in);
    for(i=0;i<n;i++)
    {
        ifile>>x[i]>>y[i];
    }
    for(i=0;i<n;i++)
    {
        s[i]=1;
    }
    cout<<"enter the # of parameters : "; cin>>n1;
    for(i=0;i<n;i++)
    {
      A[i][0] = x[i]/s[i];
      A[i][1] = 1/((x[i])*s[i]);
      A[i][2] = exp(x[i]/10)/s[i];
      A[i][3] = pow(x[i],2)/s[i];
    }
    for(i=0;i<n;i++)
    {
       b[i] = y[i]/s[i];
    }
    double At[n1][n];
    for(i=0;i<n1;i++)
    {
       for(j=0;j<n;j++)
       {At[i][j] = A[j][i];}
    }
    double beta[n1][1];
    for(i=0;i<n1;i++)
    {
      for(j=0;j<1;j++)
      {
         double sum=0;
         for(k=0;k<n;k++)
        {
           sum=sum + At[i][k]*b[k];
        }
        beta[i][j]= sum;
      }
    }
    double alpha[n1][n1];
    for(i=0;i<n1;i++)
    {
      for(j=0;j<n1;j++)
     {
       double sx = 0;
       for(k=0;k<n;k++)
      {
         sx = sx + At[i][k]*A[k][j];
      }
      alpha[i][j] = sx;
    }
   }
   double c,A_[n1][2*n1],x_[n1][n1],d_[n1][n1],b_[n1][n1];
   for(i=0;i<n1;i++)
   {
      for(j=0;j<n1;j++)
      {
        A_[i][j]=alpha[i][j];
      }
   }
  for(i=0;i<n1;i++)
  {
     for(j=n1;j<2*n1;j++)
    {
      if((j-i)==n1)
      A_[i][j]=1;
      else A_[i][j]=0;
    }
  }
  k=0;
  while(k<n1-1)
    {
     for(i=k+1;i<n1;i++)
    {
      c = A_[i][k]/A_[k][k];
      for(j=0;j<2*n1;j++)
      {
         A_[i][j] = A_[i][j] - A_[k][j]*c;
      }
    }
    k++;
    }
   for(i=0;i<n1;i++)
   {
     for(j=0;j<n1;j++)
    {
       b_[i][j]=A_[i][j+n1];
    }
   }
   for(j=0;j<n1;j++)
   {
     x_[n1-1][j] = b_[n1-1][j]/A_[n1-1][n1-1];
   }
   for(j=0;j<n1;j++)
   {
    for(i=1;i<n1;i++)
    {
        double sum=0;
        for(k=1;k<=i;k++)
        {
           sum=sum+A_[(n1-1)-i][(n1-1)-(i-k)]*x_[(n1-1)-(i-k)][j];
        }
        x_[(n1-1)-i][j] = (b_[(n1-1)-i][j]-sum)/(A_[(n1-1)-i][(n1-1)-i]);
       }
     }
    double a[n1][1];
    for(i=0;i<n1;i++)
    {
        for(j=0;j<1;j++)
        {
            double sum=0;
        for(k=0;k<n1;k++)
        {
            sum=sum+x_[i][k]*beta[k][j];
        }
        a[i][j]=sum;
        }
    }
    cout<<"\n the coefficient parameters are \n";
    for(i=0;i<n1;i++)
    {
        for(j=0;j<1;j++)
        {
            cout<<"parameter["<<i<<"] = "<<a[i][j]<<"   ";
        }
        cout<<"\n";
    }
  for(i=0;i<n1;i++)
 {
   cout<<"error in parameter ["<<i<<"] = "<<x_[i][i]<<"\n";
 }
  return 0;
}

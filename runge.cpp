#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
double F(double x,double y)
{
return 1/(y*y) + x + 2;
}
int main()
{
  fstream inf("dat",ios::out);
  double y0,x0,y1,n,h,f,er,k1,k2,k3,k4;
  int j;
  x0=0;
  y0=1;
  h=0.1;
  n=1;
  cout<<"Enter the step size";
  cin>>h;
  cout<<"\n\n For h= "<<h;
    cout<<"\nPress 1 for 4th order runge-kutta \n 2 for 2nd order runge-kutta \n 3 for 3rd order runge-kutta \n";
  cin>>j;
  switch (j)
  {
  case 1:
    while(x0<n)
  {
    k1=F(x0,y0);
    k2=F(x0+(h/2),y0+(h*k1/2));
    k3=F(x0+(h/2),y0+(h*k2/2));
    k4=F(x0+h,y0+(h*k1));
    f=k1+2*k2+2*k3+2*k4;
    y1 = y0 + h * f/6;
    er=exp(-2*(x0+h))-y1;
    cout<<"\n\n"<<x0<<"    "<<y1<<"   "<<er;
    y0=y1;
    x0=x0+h;
  }
  break;

  case 2:
     while(x0<n)
  {
    k1=F(x0,y0);
    k2=F(x0+(h/2),y0+(h*k1/2));

    f=k1+k2;
    y1 = y0 + h * f/2;
    er=exp(-2*(x0+h))-y1;
 cout<<"\n\n"<<x0<<"    "<<y1<<"   "<<er;
    y0=y1;
    x0=x0+h;
  }
 break;
  case 3:
        while(x0<n)
  {
    k1=F(x0,y0);
    k2=F(x0+(h/2),y0+(h*k1/2));
    k3=F(x0+(h),y0-k1+k2*2);
    f=k1+k2;
    y1 = y0 + h * f/2;
    er=exp(-2*(x0+h))-y1;
 cout<<"\n\n"<<x0<<"    "<<y1<<"   "<<er;
    y0=y1;
    x0=x0+h;
  }
  }


inf.close();

  return 0;
}

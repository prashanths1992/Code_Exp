#include<iostream>
using namespace std;
int main()
{
    int a[100];
    int n;
    cin>> n;
    for(int i=0;i<n;i++)
    cin>>a[i];

    int h=1;
    while(h<n/3)
        h=h*3+1;
    while(h>=1)
    {

    for(int i=h;i<=n;i++)
    {
        for(int j=i;j>=h;j-=h)
        {
            if(a[j-h]>a[j])
            {
                int temp=a[j];
                a[j]=a[j-h];
                a[j-h]=temp;
            }
            else
                break;
        }
    }

    h=h/3;
    }

    for(int i=0;i<n;i++)
    cout<<a[i]<< " ";
    cout<<endl;
return 0;
}

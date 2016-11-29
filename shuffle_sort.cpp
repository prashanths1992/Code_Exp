#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
    int a[11]={0,1,2,3,4,5,6,7,8,9,10};

    for(int i=1;i<=10;i++)
    {
        int j=rand()%i;
        int temp=a[j];
        a[j]=a[i];
        a[i]=temp;
    }
    for(int i=0;i<10;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}

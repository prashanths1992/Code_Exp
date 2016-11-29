#include<iostream>
using namespace std;
void heapify(int *a,int i,int n)
{
    if(2*i+1>n) return ;
    else if(2*i+2>n)
    {
        if(a[i]<a[2*i+1])
        {
            int temp=a[i];
            a[i]=a[2*i+1];
            a[2*i+1]=temp;
        }
      //   cout<<"dasda "<<i<<" "<<2*i+1<<" "<<2*i+2<<endl;
        return;

    }

    heapify(a,2*i+1,n);
    heapify(a,2*i+2,n);

     cout<<i<<" "<<2*i+1<<" "<<2*i+2<<endl;



   int c=max(a[i],max(a[2*i+1],a[2*i+2]));
   int temp=a[i];
   a[i]=c;
   if(a[2*i+1]==c)
   {
    a[2*i+1]=temp;
    heapify(a,2*i+1,n);
   }
   if(a[2*i+2]==c)
   {
    a[2*i+2]=temp;
    heapify(a,2*i+2,n);
   }



}
int main()
{
    int a[10]={10,2,4,3,6,5,8,7,9,1};
    heapify(a,0,9);
    for(int i=0;i<10;i++)
    cout<<a[i]<<" ";
    return 0;
}

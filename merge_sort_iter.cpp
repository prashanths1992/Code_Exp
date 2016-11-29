#include<iostream>
#include<string.h>
using namespace std;
char temp[20];
void merge_quick(char *a,int low,int high,int mid)
{
    int i=low;
    int j=mid+1;
    int k=0;
    while(i<=mid&&j<=high)
    {
        if(a[i]<=a[j])
        {
            temp[k]=a[i];
            i++;

        }
        else
        {
            temp[k]=a[j];
            j++;

        }
        k++;

    }

    if(i<=mid)
    for(;i<=mid;i++)
    {
     temp[k]=a[i];
     k++;
    }
    else
    for(;j<=high;j++)
    {
     temp[k]=a[j];
     k++;
    }
    k=0;
    for(int p=low;p<=high;p++)
    {
      a[p]=temp[k];
      k++;
    }


}
int main()
{
    char a[20];
    cin>>a;


    int n=strlen(a)-1;

    for(int i=2;i<=n+1;i=2*i)
    {
       int j=0;
       int k=i-1;

       while(k<=n)
       {
          if(k+i<=n)
           merge_quick(a,j,k,(j+k)/2);
          else
            merge_quick(a,j,n,(j+n)/2);
 cout<<j<<" "<<(j+k)/2<<" "<<k<<endl;
            j=k+1;
            k+=i;




       }
    }

    for(int i=0;i<=n;i++)cout<<a[i]<<" ";
return 0;
}

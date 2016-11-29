#include<iostream>
using namespace std;
int temp[10];
void merge_quick(int *a,int low,int high,int mid)
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
void merge_sort(int *a,int low,int high)
{
    if(low<high)
    {
        int mid=(high+low)/2;
        merge_sort(a,low,mid);
        cout<<low<<" "<<high<<" "<<mid<<endl;
        merge_sort(a,mid+1,high);


        merge_quick(a,low,high,mid);
    }
}
int main()
{
    int q[10]={10,4,3,5,7,6,9,8,2,1};
    merge_sort(q,0,9);
     for(int i=0;i<10;i++)
            cout<<q[i]<<" ";
            cout<<endl;
    return 0;
}

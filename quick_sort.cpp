#include<iostream>
using namespace std;
int part_quick(int *a,int low,int high)
{
    int mid=(high+low)/2;
    int temp=a[0];
    a[0]=a[mid];
    a[mid]=temp;
    int i=low+1;
    int j=high;



    while(true)
    {
            while(a[i]<a[0]) i++;
            while(a[j]>a[0]) j--;

            if(i>j) break;

            int temp1=a[i];
            a[i]=a[j];
            a[j]=temp1;






    }
    int temp2=a[0];
    a[0]=a[j];
    a[j]=temp2;



    return j;
}
void quick_sort(int *a,int low,int high)
{
    if(low<high)
    {
        int mid=part_quick(a,low,high);
      //  cout<<low<<" "<<mid<<" "<<high<<endl;
        quick_sort(a,low,mid-1);
        quick_sort(a,mid+1,high);
    }
}
int main()
{
    int q[10]={10,4,3,5,7,6,9,8,2,1};
    quick_sort(q,0,9);
     for(int i=0;i<10;i++)
            cout<<q[i]<<" ";
            cout<<endl;
    return 0;
}

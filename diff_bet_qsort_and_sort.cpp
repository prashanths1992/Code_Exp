#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
int a[10]={1,2,3,4,5,6,7,8,9,10};
int compare1(const void* a,const void* b)
{
    int* a1= (int*)a;
    int* b1= (int*)b;
    return (*a1>*b1)?1:-1;
}
bool compare(int a,int b)
{
    return a>b?true:false;
}
int main()
{
    qsort(a,10,sizeof(int),compare1);
    int i;
    for(i=0;i<10;i++)
        cout<<a[i]<<" ";
    cout<<endl;

    sort(a,a+10,compare);

    for(i=0;i<10;i++)
        cout<<a[i]<<" ";
    cout<<endl;


    return 0;
}

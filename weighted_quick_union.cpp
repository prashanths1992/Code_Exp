#include<iostream>
using namespace std;
struct node
{
    int num;
    int s;
} a[100];
pair<int ,int > find_root(int b1)
{
    if(a[b1].num==b1)
    {
        return make_pair(a[b1].num,a[b1].s);
    }
    else
    find_root(a[b1].num);
}
void add_union(int b1,int b2)
{
    pair<int ,int > k1=find_root(b1);
    pair<int ,int > k2=find_root(b2);

    if(k1.second>=k2.second)
    {
        a[k1.first].s+=a[k2.first].s;
        a[k2.first].num=a[k1.first].num;
    }
    else
    {
        a[k2.first].s+=a[k1.first].s;
        a[k1.first].num=a[k2.first].num;
    }
}
int main()
{
    int t;
    int in1,in2;
    int i=0;
    while(i<101)
    {
        a[i].num=i;
        a[i].s=1;
        i++;
    }
    while(1)
    {
        cout<< " Enter option : ";
        cin>>t;
        switch(t)
        {
            case 1: cout<<"adding union between 2 numbers ";
                    cin>>in1>>in2;
                    add_union(in1,in2);
                    break;
            case 2: cout<<"finding connectedness between 2 numbers ";
                    cin>>in1>>in2;
                    if(find_root(in1).first==find_root(in2).first)
                        cout<<"Is Connected..!"<<endl;
                    else
                        cout<<"Not Connected..!"<<endl;
                    break;
            default: cout<<"Enter valid option"<<endl;
        }
        for(int i=0;i<10;i++)
        cout<<a[i].num<<" ";
        cout<<endl;

    }

return 0;

}

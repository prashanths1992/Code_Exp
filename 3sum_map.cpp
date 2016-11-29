#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
	map<long int , int> map1;
	pair<int,int> p;
	map<long int ,pair<int,int> > map2;
	long int a[20];
	int n;
	int num;
	cin >> n>>num;
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
		map1[a[i]]++;
	}
	sort(a,a+n);
	int i,j;
    for(i=0;i<n;i++)
    {
       map1[a[i]]--;
       for(j=i+1;j<n;j++)
        {
           map1[a[j]]--;
           if(map1.find(num-(a[i]+a[j]))!=map1.end())
            {
                int c=num-(a[i]+a[j]);
                if(c>=max(a[i],a[j])&&map1[c])
                map2[a[i]]=make_pair(a[j],c);
            }
            map1[a[j]]++;
        }
        map1[a[i]]++;
    }
    for(map<long int , pair<int,int> > :: iterator it=map2.begin();it!=map2.end();++it)
    {
        cout<<it->first<<" "<<it->second.first<<" "<<it->second.second<<endl;
    }
return 0;
}




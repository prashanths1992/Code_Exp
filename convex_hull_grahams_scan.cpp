#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
struct point
{
    int x;
    int y;
}p[8];
stack<point> s;
int orientation(point p,point q,point r)
{
    int o=(r.y-q.y)*(q.x-p.x)-(q.y-p.y)*(r.x-q.x);
    if(o==0)
        return 0; //collinear
    return o>0?1:2; //1:ccw;2:cw
}
int dist(point a,point b)
{
    return (b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y);
}
point nxt_top()
{
    point temp=s.top();
    s.pop();
    point temp1=s.top();
    s.push(temp);
    return temp1;
}
bool compare(point a, point b)
{
    int o=orientation(p[0],a,b);
    if(o==0)
        return dist(p[0],a)>dist(p[0],b)?false:true;
    return o==1?true:false;
}

void print_convex_points()
{
    int ymin_index=0;
    point temp;
    temp.x=p[0].x;
    temp.y=p[0].y;

    for(int i=1;i<8;i++)
    {
        if(p[i].y<temp.y||(p[i].y==temp.y&&p[i].x>temp.x))
        {
            temp.x=p[i].x;
            temp.y=p[i].y;
            ymin_index=i;

        }

    }
    //swap points
    point temp1=p[0];
    p[0]=p[ymin_index];
    p[ymin_index]=temp1;

    sort(p+1,p+8,compare);

    for(int i=0;i<8;i++)
        cout<<p[i].x<<" "<<p[i].y<<endl;


    s.push(p[0]);
    s.push(p[1]);
    s.push(p[2]);

   for(int i=3;i<8;i++)
    {
            while(orientation(nxt_top(),s.top(),p[i])!=1)
            s.pop();

            s.push(p[i]);
    }

    while(!s.empty())
    {
        cout<<"( "<<s.top().x<<" , "<<s.top().y<<" )"<<endl;
        s.pop();
    }
}
int main()
{

    for(int i=0;i<8;i++)
    {
        cin>>p[i].x>>p[i].y;
    }
    print_convex_points();

return 0;
}

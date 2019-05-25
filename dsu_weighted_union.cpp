//Time Complexity: union,find:O((log*n)m) where log*n is mostly 5.

#include<bits/stdc++.h>
using namespace std;
struct node{
    int data,size,parent;
};
struct node arr[1000];
void initialise(int n)
{
    for(int i=0;i<n;i++)
        arr[i].data=i,arr[i].size=1,arr[i].parent=i;
    // Assuming data is in the range of 1 to n.
}
int find(int a)
{
    while(1)
    {
        if(arr[a].parent==a)
            return a;
        arr[a].parent=arr[arr[a].parent].parent;    //Kind of Path Compression as the parent is changed,
        a=arr[a].parent;                            //to its grand parent.
    }
}
// Time complexity of find() is log*n =log(log(log(log......(n)))) which equals to 5 for n=2^65536
void _union(int a,int b)
{
    a--,b--;//0-based Indexing
    int parent_a=find(a);
    int parent_b=find(b);
    if(parent_a==parent_b)
        return ;
    // cout<<"Sizes are:"<<arr[parent_a].size<<" "<<arr[parent_b].size<<endl;
    if(arr[parent_a].size>arr[parent_b].size)
    {
        arr[parent_b].parent=parent_a;
        arr[parent_a].size+=arr[parent_b].size;
    }
    else
    {
        // cout<<"Parent of"<<parent_a<<" is "<<parent_b<<endl;
        arr[parent_a].parent=parent_b;
        // cout<<parent_a<<endl;
        arr[parent_b].size+=arr[parent_a].size;
    }
}
main()
{
    int n;
    // cin>>n;
    n=7;
    initialise(n);
    vector<pair<int,int>>unions_to_be_done;
    unions_to_be_done.push_back(make_pair(1,2));
    unions_to_be_done.push_back(make_pair(2,3));
    unions_to_be_done.push_back(make_pair(4,5));
    unions_to_be_done.push_back(make_pair(6,7));
    unions_to_be_done.push_back(make_pair(5,6));
    unions_to_be_done.push_back(make_pair(3,7));

    for(pair<int,int>p:unions_to_be_done)
    {
        _union(p.first,p.second);
        // cout<<"Included the reln btwn"<<p.first<<" and "<<p.second<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<arr[i].parent+1<<" ";
        }
        cout<<endl;
    }
}
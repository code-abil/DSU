//Time Complexity: union,find:O((log*n)m) where log*n is mostly 5.
// log*n is very very slowly increasing function.
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data,rank,parent;
};
// Rank is an approximate of the depth of the tree.
// That's the reason ,why even after path compression(which may change the rank of a tree) we progress by
// applying the union_rank operation with the less accurate ranks of the tree.
struct node arr[1000];
void initialise(int n)
{
    for(int i=0;i<n;i++)
        arr[i].data=i,arr[i].rank=0,arr[i].parent=i;
    // Assuming data is in the range of 1 to n.
}
int find(int a)
{
    int copy_a=a;
    while(1)
    {
        if(arr[a].parent==a)
        {
            arr[copy_a].parent=a;   //Path compression(we store the parent of the disj set).
            return a;
        }
        a=arr[a].parent;
    }
}
void _union(int a,int b)
{
    a--;b--;
    int parent_a=find(a);
    int parent_b=find(b);
    if(parent_a==parent_b)
    {
        // Already a,b belongs to the same group.
        return ;
    }
    // cout<<"Ranks are "<<arr[parent_a].rank<<" "<<arr[parent_b].rank<<endl;
    if(arr[parent_a].rank>arr[parent_b].rank)
    {
        // cout<<"Parent of "<<parent_b<<" is "<<parent_a<<endl;
        arr[parent_b].parent=parent_a;
        arr[parent_a].rank=max(arr[parent_a].rank,1+arr[parent_b].rank);
    }
    else
    {
        // cout<<"Parent of "<<parent_a<<" is "<<parent_b<<endl;
        arr[parent_a].parent=parent_b;
        arr[parent_b].rank=max(arr[parent_b].rank,1+arr[parent_a].rank);
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

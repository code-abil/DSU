//Time Complexity: union:o(n*m),find:O(1)


#include<bits/stdc++.h>
using namespace std;
int parent[1000];
void initialise(int n)
{
    for(int i=0;i<n;i++)
        parent[i]=i;
}

void _union(int a,int b,int n)
{
    //Zero based indexing
    a--,b--;
    
    //If they already belong to the same group.
    if(parent[a]==parent[b])
        return;
    for(int i=0;i<n;i++)
    {
        if(parent[i]==parent[a])
        {
            parent[i]=parent[b];
        }
    }
}
// find() is simply the value present in the parent array itself.
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
        _union(p.first,p.second,n);
        cout<<"Included the reln btwn"<<p.first<<" and "<<p.second<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<parent[i]<<" ";
        }
        cout<<endl;
    }
}
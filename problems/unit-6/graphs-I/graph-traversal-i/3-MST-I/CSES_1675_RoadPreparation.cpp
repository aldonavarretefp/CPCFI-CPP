#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;

struct node {
	int parent;
	int rank;
};
struct Edge {
	long long src;
	long long dst;
	long long wt;
};

vector<node> dsuf;
vector<Edge> mst;
long long edgeCost = 0;
//FIND operation
int find(int v)
{
	if(dsuf[v].parent==-1)
		return v;
	return dsuf[v].parent=find(dsuf[v].parent);	//Path Compression
}

void union_op(int fromP,int toP)
{
	//fromP = find(fromP);
	//toP = find(toP);

	//UNION by RANK
	if(dsuf[fromP].rank > dsuf[toP].rank)	//fromP has higher rank
		dsuf[toP].parent = fromP;
	else if(dsuf[fromP].rank < dsuf[toP].rank)	//toP has higher rank
		dsuf[fromP].parent = toP;
	else
	{
		//Both have same rank and so anyone can be made as parent
		dsuf[fromP].parent = toP;
		dsuf[toP].rank +=1;		//Increase rank of parent
	}
}

bool comparator(Edge a,Edge b)
{
	return a.wt < b.wt;
}
/*
void printEdgeList(vector<Edge>& edge_List)
{
	for(auto p: edge_List)
		cout<<"src: "<<p.src<<"  dst: "<<p.dst<<"  wt: "<<p.wt<<"\n";
	cout<<"============================================================\n";
}
*/
void Kruskals(vector<Edge>& edge_List,int V,int E)
{
	//cout<<"edge_List before sort\n";
	//printEdgeList(edge_List);
	sort(edge_List.begin(),edge_List.end(),comparator);
	//cout<<"edge_List after sort\n";
	//printEdgeList(edge_List);

	int i=0,j=0;
	while(i<V-1 && j<E)
	{
		int fromP = find(edge_List[j].src);	//FIND absolute parent of subset
		int toP = find(edge_List[j].dst);
		
		if(fromP == toP){	
            ++j;	
            continue;	
        }

		//UNION operation
		union_op(fromP,toP);	//UNION of 2 sets
		mst.push_back(edge_List[j]);
        edgeCost += edge_List[j].wt;
		++i;
	}
}
//Display the formed MST
void printMST(vector<Edge>& mst)
{
	int cc=0;
	//If theres more than on cc it is impossible
	for(auto p: mst)
	{
		cout<<"src: "<<p.src<<"  dst: "<<p.dst<<"  wt: "<<p.wt<<"\n";
		cc++;
	}
	cout<<cc<<	"\n";
	cout<<cc<<" edges in MST\n";
	cout<<"MST formed is\n";
	cout<<edgeCost<<"\n";
	for(auto p: mst)
		cout<<"src: "<<p.src<<"  dst: "<<p.dst<<"  wt: "<<p.wt<<"\n";
    if (mst.size() == 0)
        cout << "No MST found\n";
    else
        cout<<edgeCost<<endl;
}

int solve()
{
	long long V,E;
	cin>>V>>E;

	dsuf.resize(V);	//Mark all vertices as separate subsets with only 1 element
	for(int i=0;i<V;++i)	//Mark all nodes as independent set
	{
		dsuf[i].parent=-1;
		dsuf[i].rank=0;
	}

	vector<Edge> edge_List;	//Adjacency list
	Edge temp;
	for(int i=0;i<E;++i)
	{
		int from,to,wt;
		cin>>from>>to>>wt;
		temp.src = from;
		temp.dst = to;
		temp.wt = wt;
		edge_List.push_back(temp);
	}

	Kruskals(edge_List,V,E);
	printMST(mst);
	
	return 0;
}

//TIME COMPLEXITY: O(ElogE + ElogV)
//ElogE for sorting E edges in edge_list
//ElogV for applying FIND & UNION operations on E edges having V vertices

void setIO(){
  string file = __FILE__;
  file = string(file.begin(),file.end()-3);
  string input_file = file + "in";
  string output_file = file + "out";
  freopen(input_file.c_str(), "r",stdin);
  freopen(output_file.c_str(),"w",stdout);
  
}

/********** Main()  function **********/
int main()
{
    
    if(getenv("CP_IO")){setIO();}
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T=1;
    for(int i = 0; i < T; i++)
        solve();
    return 0;
}
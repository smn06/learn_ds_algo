#include<iostream>
using namespace std;
#define max 1000
int arr[max][max]={{0}};
int front=-1,rear=-1,top=-1;
bool visited[max];
class G{
	public:
	void graph();
	void enq(int [],int);
	void deq(int []);
	void dfs(int,int);
	void bfs(int,int);
};
void G::graph()
{
	int n,e;
	cout<<"Enter the number of nodes and edges\n";
	cin>>n>>e;
	int arr[n][n]={{0}};
	int a,b;
		
	cout<<"Enter the nodes which are connected\n";
	for(int i=0;i<e;i++)
	{
		cin>>a>>b;
		arr[a][b]=arr[b][a]=1;
	}
	for(int i=1;i<=n;i++)
	{
		 cout<<i<<" ---> ";
		 for(int j=1;j<=n;j++)
		{
			  if(arr[i][j]==1)
			  cout<<" "<<j;
		    
		}
		  
		  cout<<endl;
	  }
}
void G::enq(int a[],int b)
{
	
	if(rear>=max-1){
	   cout<<"Queue is full"<<endl;
	   return;
   }
	 else
	   {
	    front=0;
	    rear++;
	    a[rear]=b;
	    
	   }
   }
 void G::deq(int a[])
 {
	 if(front>rear){
	  cout<<"Queue is empty"<<endl;
	  return;
       }
     else
     {
		front++;
		}
}
void G::bfs(int v,int n)
{
	for(int j=1;j<=n;j++){
	    visited[j]=false;}
	
	int que[100]={0};
	visited[v]=true;
	enq(que,v);
	
	while(front<=rear)
	{
		v=que[front];
		deq(que);
		cout<<v<<endl;		
		for(int i=1;i<=n;i++)
		{
			if(arr[v][i]==1 && visited[i]==false)
			{
				visited[i]=true;
				rear++;
				que[rear]=i;
				
			}
		}
	}
}

void G::dfs(int v,int n)
{  
	for(int j=1;j<=n;j++){
	    visited[j]=false;}
	
	int sta[100]={0},pop;
	top++;
	    sta[top]=v;	  
	    while(top>=0)
	    {
		  pop=sta[top];
		  top--;
		  if(visited[pop]==false)
		  {
		  cout<<pop;
		  visited[pop]=true;
	        } 
		  else{
		   continue;
	       }
		   for(int i=n;i>=1;i--)
		   {
		
			if(arr[pop][i]==1 && visited[i]==false)
			{
				top++;
				sta[top]=i;
			}
		}
	}
}
	 
		 

	

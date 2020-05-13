#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
using namespace std;

# define INF 0x3f3f3f3f 

typedef pair<int, int> iPair; 

int find_meetup_city(int **adj_matrix, int your_city, int friend_city,int n)
{
	//Using dijasstra's algorithm on first city
    int distA[n];
	
	for(int i = 0; i < n; i++)
    {
		distA[i] = INF;
    }
    distA[your_city]= 0;

	priority_queue<iPair, vector<iPair>, greater<iPair> > pq;
	pq.push(make_pair(0, your_city));
	
	
	while(!pq.empty())
	{
		int node = pq.top().second;
		pq.pop();
		for(int i = 0; i<n; i++)
		{
			int weight = adj_matrix[node][i];
			if((distA[i] > distA[node] + weight) && weight!=0)
			{
				distA[i] = distA[node] + weight;
				pq.push(make_pair(distA[i],i));
			} 
		}
	}

	//Using dijasstra's algorithm on second city
    int distB[n];
	
	for(int i = 0; i < n; i++)
    {
		distB[i] = INF;
    }
    distB[friend_city]= 0;

	priority_queue<iPair, vector<iPair>, greater<iPair> > pq1;
	pq1.push(make_pair(0, friend_city));
	
	
	while(!pq1.empty())
	{
		int node = pq1.top().second;
		pq1.pop();
		for(int i = 0; i<n; i++)
		{
			int weight = adj_matrix[node][i];
			if((distB[i] > distB[node] + weight) && weight!=0)
			{
				distB[i] = distB[node] + weight;
				pq1.push(make_pair(distB[i],i));
			} 
		}
	}
	
	//Finding optimum distance
	int time = INF;
	int ans=0;
	
	for (int i = 0; i < n; i++)
	{
		//cout<<"This is working"<<endl;
		if (i != your_city && i != friend_city)
		{
			if (time > max(distA[i], distB[i]) )
			{
				time = max(distA[i], distB[i]);
				ans = i;
				//cout<<ans;
			}
		}
	}
	return ans;
}

int main()
{
    int n;
    int pointA,pointB;
    int **Adjmatrix;
    cout<<"Enter the sixe of matrix"<<endl;
    cin>>n;
    
    Adjmatrix= new int*[n];     //Dynamically Creating a 2*2 Adj matrix;
	for(int i = 0; i<n; i++)
	{
		Adjmatrix[i] = new int[n];
	}

    cout<<"Enter the Adjacency Matrix"<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>Adjmatrix[i][j];
        }
    }
    cout<<"Enter the Two destinations"<<endl;
    cin>>pointA;
    cin>>pointB;
    cout<<"Optimum Meeting point is "<<find_meetup_city(Adjmatrix,pointA,pointB,n)<<endl;
    
    for(int i = 0; i<n; i++)
    {
		delete []Adjmatrix[i];
    }
	delete []Adjmatrix;
}
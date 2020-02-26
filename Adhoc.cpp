//Cpp program to implement the  adhoc mechanism.


#include <iostream>
#include <cstring>
using namespace std;

class Graph
{
	int dst, src;
	int path[100];
	int visited[100];
	int matrix[100][100];
	int n, ptr, flag;
	
  public:
  
  	Graph(int a)
  	{
  		n = a;
  	}
  	
  	void getData()
  	{
  		int i, j;
  		cout << "Enter graph detail in table form" << endl;
  		for(i = 0; i < n; i++)
  			for(j = 0; j < n;j++)
  				cin >> matrix[i][j];
  		
  		cout << "Enter source and destination router value" << endl;
  		cin >> src >> dst;
  	}
  	
  	void findpath()
  	{
  		if(src == dst)
  		{
  			cout << "Source and Destination can\'t be same" << endl;
  			return;
  		}
  		
  		if(src < 0 || src >= n || dst < 0 || dst >= n)
  		{
  			cout << "Error in source and destination input" << endl;
  			return;
  		}
  	
  		ptr = flag = 0;
  		for(int i = 0; i < n; i++)
  			visited[i] = 0;
  		
  		int j = src;
  		for(int i = 0; i < n; i++)
  		{
  			if(flag)
  				break;
  			find(j);
  			j = (j+1) % n;
  		}
	  	
	  	for(int i = 0; i < ptr; i++)
	  		cout << path[i] << " ";
	  	cout << endl;
  	}
  	
  	void find(int s)
  	{
  		if(matrix[s][dst] == 1)
  		{
  			path[ptr++] = s;
  			path[ptr++] = dst;
  			flag = 1;
  			return;
  		}
  	
  	
  		if(visited[s] != 1)
  		{
  			visited[s] = 1;
  			path[ptr++] = s;
  			
  			for(int i = 0; i < n; i++)
  			{
  				if(matrix[s][i] == 1 && visited[i] != 1)
  				{
  					if(i == dst)
  					{
  						flag = 1;
  						path[ptr++] = i;
  						return;
  					}
  					else
  					{
  						find(i);
  						if(flag)
  							return;
  						// ptr--;
  					}
  				}
  			}
  		}
  	}
};

int main()
{
	int n;
	cout << "Enter the number of routers: ";
	cin >> n;
	
	Graph g(n);
	g.getData();
	g.findpath();

	return 0;
}

// Cpp program to implement the multidimentional Routing mechanism.

#include <bits/stdc++.h>
using namespace std;

class Router
{
	int table[100][100],m,n;
	int visited[100],flag;
  public:
  	Router(int m)
  	{
  		this->m = m;
  	}
  	void getdata()
  	{
  		cout << "Enter the table\n";
  		for(int i = 0;i<m;i++)
  			for(int j = 0;j<m;j++)
  				cin >> table[i][j];
  			
  	}
  	void disp()
  	{
  		for(int i =0;i<m;i++)
  		{
  			for(int j = 0;j<m;j++)
  				cout << table[i][j] << " ";
  			cout << endl;
  		}
  	}
  	
  	void route(int s,int d)
  	{
  		for(int i=0;i<m;i++)
  			visited[i] = 0;
  		this->n = d;
  		visited[s]=0;
  		flag=0;
  		for(int i=0;i<m;i++)
  			visitneigbour(i);
  	}
  	void visitneigbour(int s)
  	{
  		if(visited[s]!=1)
  		{
  			cout << s << " ";
  			visited[s] = 1;
  			
  		for(int i = 0;i<m;i++)
  			if(flag && table[s][i] == 1)
  				if(i == this->n)
  				{
  					flag = 0;
  					cout << "Destination reached\n";
  				}
  				else{
  					visitneigbour(i);
  				}
  		}
  	}
  	
  	void getdst()
  	{
  		int temp[m],dn,sn;
  		cin >> dn >> sn;
  		for(int i = 0;i<dn;i++)
  		{
  			cin >> temp[i];
  			route(sn,temp[i]);
  			cout << "\n";
  		}
  	}
};

int main()
{
	int n;
	cin >> n;
	Router r(n);
	r.getdata();
	r.disp();
	r.getdst();
	return 0;
}

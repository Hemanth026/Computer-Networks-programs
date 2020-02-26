[7:01 pm, 27/11/2019] Hemanth🤓: 🙏🏻
[7:34 pm, 27/11/2019] Hemanth🤓: // flooding

#include <iostream>
using namespace std;

class Routers
{
	int m, table[100][100], data;
	int start;
	
  public:
  	Routers(int m)
  	{
  		this->m = m;
  	}
  	
  	void getData()
  	{
  		cin >> start;
  		for(int i = 0; i < m; i++)
  			for(int j = 0; j < m; j++)
  				cin >> table[i][j];
  	}
  	
  	void disp()
	{
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < m; j++)
				cout << table[i][j] << " ";
			cout << endl;
		}
	}
	
	void flood()
	{
		int s = this->start;
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < m; j++)
			{
				if(table[i][j])
					cout << "Recieved at " << j << " from " << s << endl;
				
				s = (s+1) % m;
			}
		}
	}
};

int main()
{
	int n;
	cin >> n;
	
	Routers r(n);
	r.getData();
	r.disp();
	r.flood();
	
	return 0;
}

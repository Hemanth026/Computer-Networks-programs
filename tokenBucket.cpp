//Cp program to implement token bucket mechanism.

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int tokenrate = 5;
	int tot = 1, i, n, temp;
	int clk = 0;
	
	cout << "Enter the total number of packets: ";
	cin >> n;
	
	int buffer[n];
	
	cout << "Enter each token size" << endl;
	for(i = 0; i < n; i++)
		cin >> buffer[i];
		
	i = 0;	
	while(n != i)
	{
		if(buffer[i] <= tot)
		{
			temp = buffer[i];
			i++;
			cout << "sent " << temp << " at clock " << clk << endl;
			
			tot -= temp;
			
			if(tot == 0)
				tot = 1;
		}
		
		clk++;
		tot *= tokenrate;
	}
	
	return 0;
}

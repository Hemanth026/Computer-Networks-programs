// Cpp program to implement arp and rarp mechanism.

#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int strpos(char* s, char* mainS)
{
	char* p = strstr(s, mainS);

	if(p)
	 	return p-s;
	else
		return -1;
}

class AddressTable
{
	char ip[100], mac[100];
  public:
  
  	void getARPcache()
  	{
  		system("arp -a>arptable.txt");
  	}
  	
  	void options()
  	{
  		int choice;
  		cout << "Enter 1 for ARP\nEnter 2 for RARP\n";
  		cin >> choice;
  		
  		switch(choice)
  		{
  			case 1: cout << "Enter the ip address: ";
  					cin >> ip;
  					ARP();
  					break;
  					
  			case 2: cout << "Enter the mac address: ";
  					cin >> mac;
  					RARP();
  					break;
  					
  			default: cout << "Invalid IP" << endl;
  		}
  	}
  	
  	void ARP()
  	{
  		char c, data[10000];
  		int pos=0;
  		
  		fstream fio("arptable.txt", ios::in);
  		
  		while(fio >> c)
  			data[pos++] = c;
 
  		data[pos] = '\0';
  		
  		if(strpos(data, ip) != -1)
  		{
  			char query[50] = "grep ";
  			strcat(query, ip);
  			strcat(query, " arptable.txt");
  			system(query);
  		}
  	}
  	
  	void RARP()
  	{
  		swap(ip, mac);
  		ARP();
  		swap(ip, mac);
  	}
 };
 
int main()
{
	AddressTable T;
	T.getARPcache();	
	T.options();
		
 	return 0;
 }

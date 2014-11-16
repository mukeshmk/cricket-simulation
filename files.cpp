#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class player
{
	private:
		char nm[30];
	public:
		void cpy_nm(char* str)
		{
			strcpy(nm,str);
		}
		void show_nm()
		{
			cout<<nm<<endl;
		}
};
int get_playernm(player *p)
{
	fstream file("playerinfo.txt",ios::in);
	if(!file)
	{
		cout<<"file not opened!!"<<endl;
		return -1;
	}
	char str[30],ch;
	int i;
	for(i=0;i<11;i++)
	{
		file>>str;
		p[i].cpy_nm(str);
	}
}
int main()
{
	player p[11];
	int i,ret=get_playernm(p);
	for(i=0;i<11;i++)
		p[i].show_nm();
	return 0;
}

#include<iostream>
#include<fstream>
#include<string.h>
#include<math.h>
#include<iomanip>
#include<stdlib>
using namespace std;
class bowling
{
	private:
		int bwl_pts;
		int balls;
		int runs;
		char bwl_typ[30];
		float eco;
		int wkts;
		float spd;
	public:
		bowling()
		{
			bwl_pts=0;
			runs=0;
			strcpy(bwl_typ,"");
			eco=0;
			balls=0;
			wkts=0;
			spd=0;
		}
		friend ifstream& operator >> (ifstream& in,bowling b);
		friend ofstream& operator << (ofstream& out,bowling b);
		void change_stats(int ball,int speed)
		{
			if(ball==-1)
				wkts++;
			runs+=ball;
			balls++;
			eco=(balls/wkts);
		}
		int ret_pts()
		{
			return bwl_pts;
		}
}
ifstream& operator >> (ifstream& in,bowling b)
{
	cout<<"enter bwl_pts: "<<endl;
	in>>b.bwl_pts;
	cout<<"enter bwl_typ: "<<endl;
	in>>b.bwl_typ;
	cout<<"enter economy: "<<endl;
	in>>b.eco;
	cout<<"enter wickets: "<<endl;
	in>>b.wkts;
	cout<<"enter bowling speed: "<<endl;
	in>>b.spd;
}
ofstream& operator << (ofstream& out,bowling b)
{
	out<<"bowling points is: "<<b.bwl_pts<<endl;
	out<<"bowling type is: "<<b.bwl_typ<<endl;
	out<<"no of balls bowled: "<<b.balls<<endl;
	out<<"runs given: "<<b.runs<<endl;
	out<<"bowling economy is: "<<b.eco<<endl;
	out<<"wickets taken: "<<b.wkts<<endl;
	out<<"bowling speed: "<<b.speed<<endl;
}
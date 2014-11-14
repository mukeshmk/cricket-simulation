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
class bat {
    //members:
	private:
		int bat_points;
		char bat_type[30];     
		int high_score;     
		float average;//str rate     
		int cent;     
		int half_cent;     
		int score;     
		int num_ball;     
	//functions:     
	public:         
		void bat()      //default constructor       
		{             
			bat_points=0;             
			high_score=0;             
			average=0.0;             
			cent=0;             
			half_cent=0;             
			score=0;             
			num_ball=0;             
			strcpy(bat_type,"");         
		}         
		friend istream& operator >> (istream& in,bat b); //operator overloading extraction         
		friend ostream& operator << (ostream& out,bat b);//operator overloading insertion         
		void change_stats(int scr)         
		{             
			num_ball++;             
			if(!scr=-1)             
				score+=scr;             
			average=score/num_ball;          
		}  
}; 
istream& operator >>(istream& in, bat b) 
{         
	cout<<"Enter batsman's points: "<<endl;         
	in>>b.bat_points;         
	cout<<"Enter batting type: "<<endl;         
	in>>b.bat_type;         
	cout<<"Enter batsman's high score: "<<endl;         
	in>>b.high_score;         
	cout<"Enter number of centuries and half-centuries: "<<endl;         
	in>>b.cent>>b.half_cent;  
} 
ostream& operator <<(ostream& out, bat b) 
{     
	out<<"Number of Balls: "<<b.num_ball<<endl;     
	out<<"Batsman's points: "<<b.bat_points<<endl;     
	out<<"Batting type: "<<b.bat_type<<endl;     
	out<<"High score: "<<b.high_score<<endl;     
	out<<"Centuries: "<<b.cent<<endl;     
	out<<"Half Centuries: "<<b.half_cent<<endl; 
}
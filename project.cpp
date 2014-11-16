#include<iostream>
#include<fstream>
#include<string.h>
#include<math.h>
#include<iomanip>
#include<stdlib.h>
#include<time.h>
using namespace std;

enum pairup{gg,gb,bg,bb};
int arr[4][10]={{-1,-1,-1,0,1,2,4,4,6,6},{-1,-1,1,2,2,4,4,6,6,6},{-1,-1,-1,0,0,1,2,2,4,4},{	-1,-1,0,0,1,1,1,2,2,2}}

class bowl
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
		bowl()
		{
			bwl_pts=0;
			runs=0;
			strcpy(bwl_typ,"");
			eco=0;
			balls=0;
			wkts=0;
			spd=0;
		}

		void get_bwl();
		void put_bwl();

		void bwl_cs(int ball,int speed)
		{
			if(ball==-1)
				wkts++;
			runs+=ball;
			balls++;
			eco=(balls/wkts);
		}
		int ret_bwlpts()
		{
			return bwl_pts;
		}
};

void bowl::get_bwl()
{
	cout<<"enter bwl_pts: "<<endl;
	cin>>b.bwl_pts;
	cout<<"enter bwl_typ: "<<endl;
	cin>>b.bwl_typ;
	cout<<"enter economy: "<<endl;
	cin>>b.eco;
	cout<<"enter wickets: "<<endl;
	cin>>b.wkts;
	cout<<"enter bowling speed: "<<endl;
	cin>>b.spd;
}

void bowl::put_bwl()
{
	cout<<"bowling points is: "<<b.bwl_pts<<endl;
	cout<<"bowling type is: "<<b.bwl_typ<<endl;
	cout<<"no of balls bowled: "<<b.balls<<endl;
	cout<<"runs given: "<<b.runs<<endl;
	cout<<"bowling economy is: "<<b.eco<<endl;
	cout<<"wickets taken: "<<b.wkts<<endl;
	cout<<"bowling speed: "<<b.spd<<endl;
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
		bat()      //default constructor       
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

		void get_bat();
		void put_bat();

		void bat_cs(int scr)         
		{             
			num_ball++;             
			if(!(scr==-1))             
				score+=scr;             
			average=score/num_ball;          
		}

		int ret_batpts()
		{
			return bat_points;
		}
}; 

void bat::get_bat()
{         
	cout<<"Enter batsman's points: "<<endl;         
	cin>>b.bat_points;         
	cout<<"Enter batting type: "<<endl;         
	cin>>b.bat_type;         
	cout<<"Enter batsman's high score: "<<endl;         
	cin>>b.high_score;         
	cout<<"Enter number of centuries and half-centuries: "<<endl;         
	cin>>b.cent>>b.half_cent;  
} 

void bat::put_bat()
{     
	cout<<"Number of Balls: "<<b.num_ball<<endl;     
	cout<<"Batsman's points: "<<b.bat_points<<endl;     
	cout<<"Batting type: "<<b.bat_type<<endl;     
	cout<<"High score: "<<b.high_score<<endl;     
	cout<<"Centuries: "<<b.cent<<endl;     
	cout<<"Half Centuries: "<<b.half_cent<<endl; 
}

class player:public bat,public bowl
{
	private:
		char nm[30];
		pairup p;
	public:
		player()
		{
			strcpy(nm,"");
			age=0;
		}
		
		friend istream& operator >>(istream& in, player p);
		friend ostream& operator <<(ostream& out,player p);
}
istream& operator >> (istream& in,player p)
{
	cout<<"enter batting data:"<<endl;
    get_bat();
	cout<<"enter bowling data:"<<endl;
	get_bwl();
}
ostream& operator <<(ostream& out,player p)
{
	cout<<"player name: "<<nm<<endl<<endl;
	cout<<"batting data:"<<endl;
	put_bat();
	cout<<"bowling data:"<<endl;
	put_bwl();
}

class team
{
	
}

int randomize()
{
	time_t t;
	srand((unsigned) time(&t));
	return(rand()%10);
}

int main()
{
	return 0;
}

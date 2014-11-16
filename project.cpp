#include<iostream>
#include<fstream>
#include<string.h>
#include<math.h>
#include<iomanip>
#include<stdlib.h>
#include<time.h>
using namespace std;

enum pairup{gg,gb,bg,bb};
int arr[4][10]={{-1,-1,-1,0,1,2,4,4,6,6},{-1,-1,1,2,2,4,4,6,6,6},{-1,-1,-1,0,0,1,2,2,4,4},{	-1,-1,0,0,1,1,1,2,2,2}};

class team;
class bowl
{
	private:	
		int bwl_pts;
		char bwl_typ[30];
		
		int balls;
		int runs;
		float eco;
		int wkts;
		float spd;
		friend class team;
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
	cin>>bwl_pts;
	cout<<"enter bwl_typ: "<<endl;
	cin>>bwl_typ;
	cout<<"enter economy: "<<endl;
	cin>>eco;
	cout<<"enter wickets: "<<endl;
	cin>>wkts;
	cout<<"enter bowling speed: "<<endl;
	cin>>spd;
}

void bowl::put_bwl()
{
	cout<<"bowling points is: "<<bwl_pts<<endl;
	cout<<"bowling type is: "<<bwl_typ<<endl;
	cout<<"no of balls bowled: "<<balls<<endl;
	cout<<"runs given: "<<runs<<endl;
	cout<<"bowling economy is: "<<eco<<endl;
	cout<<"wickets taken: "<<wkts<<endl;
	cout<<"bowling speed: "<<spd<<endl<<endl;
}

class bat {
    //members:
	private:
		int bat_points;
		char bat_type[30];     
		int cent;     
		int half_cent;     
		
		int high_score;     
		float average;//str rate     
		int score;     
		int num_ball;    
		friend class team;
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
	cin>>bat_points;         
	cout<<"Enter batting type: "<<endl;         
	cin>>bat_type;         
	cout<<"Enter batsman's high score: "<<endl;         
	cin>>high_score;         
	cout<<"Enter number of centuries and half-centuries: "<<endl;         
	cin>>cent>>half_cent;  
} 

void bat::put_bat()
{     
	cout<<"Number of Balls: "<<num_ball<<endl;     
	cout<<"Batsman's points: "<<bat_points<<endl;     
	cout<<"Batting type: "<<bat_type<<endl;     
	cout<<"High score: "<<high_score<<endl;     
	cout<<"Centuries: "<<cent<<endl;     
	cout<<"Half Centuries: "<<half_cent<<endl<<endl; 
}

class player:public bat,public bowl
{
	private:
		char nm[30];
		pairup p;
		friend class team;
	public:
		player()
		{
			strcpy(nm,"");
		}
		void cpy_nm(char* str)
		{
			strcpy(nm,str);
		}
		void get_player();
		void put_player();
};
void player::get_player()
{
	cout<<"enter player name:"<<endl;
	cin>>nm;
	cout<<"enter batting data:"<<endl;
    get_bat();
	cout<<"enter bowling data:"<<endl;
	get_bwl();
}
void player::put_player()
{
	cout<<"player name: "<<nm<<endl<<endl;
	cout<<"batting data:"<<endl<<endl;
	put_bat();
	cout<<"bowling data:"<<endl<<endl;
	put_bwl();
}

class team
{
	private:         
		char team_nm[30];         
		player p[11];
		friend class player;
	public:         
		team()//default constructor         
		{             
			strcpy(team_nm,"");         
		}         
		void input()         
		{             
			cout<<"Enter the team's name: "<<endl;             
			cin>>team_nm;         
		}         
		void output()         
		{             
			cout<<"The team's name: "<<team_nm<<endl<<endl;
			for(int i=0;i<11;i++)
				p[i].put_player();
		}
		void read_playerinfo();
};
void team::read_playerinfo()
{
	fstream file("playerinfo.txt",ios::in);
	if(!file)
	{
		cout<<"file not opened !!"<<endl;
		return ;
	}
	for(int i=0;i<11;i++)
	{
		file>>p[i].nm;
		file>>p[i].bat_points;
		file>>p[i].bat_type;
		file>>p[i].cent;
		file>>p[i].half_cent;
		file>>p[i].bwl_pts;
		file>>p[i].bwl_typ;
	}
}
int randomize()
{
	time_t t;
	srand((unsigned) time(&t));
	return(rand()%10);
}

int main()
{
	team t1;
	t1.input();
	t1.read_playerinfo();
	t1.output();
	return 0;
}

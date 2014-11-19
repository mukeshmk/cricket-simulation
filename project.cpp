#include<iostream>
#include<fstream>
#include<string.h>
#include<math.h>
#include<iomanip>
#include<stdlib.h>
#include<time.h>
using namespace std;

class team;
enum pairup{gg,gb,bg,bb};
int arr[4][10]={{-1,-1,-1,0,1,2,4,4,6,6},{-1,-1,1,2,2,4,4,6,6,6},{-1,-1,-1,0,0,1,2,2,4,4},{	-1,-1,0,0,1,1,1,2,2,2}};

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
			cout<<"z"<<endl;
			if(ball==-1)
			{
				cout<<"x"<<endl;
				wkts++;
			}
			else
			{
				cout<<"c"<<endl;
				runs+=ball;
			}
			cout<<"v"<<endl;
			balls++;
			cout<<"balls"<<endl;
			if(wkts!=0)
				eco=(balls/wkts);
			cout<<"eco"<<endl;
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
		static int tno;
		int teamno;
		char team_nm[30];
		int r;
		friend class player;
	public:         
		player p[11];
	
		team()//default constructor         
		{     
			r=0;
			strcpy(team_nm,"");
			tno++;
			teamno=tno;
		}
		char* retnm()
		{
			return team_nm;
		}
		void inc_run(int x)
		{
			r+=x;
		}
		int ret_run()
		{
			return r;
		}
		void read_playerinfo();
		void input()
		{             
			cout<<"Enter the team "<<teamno<<"'s name: "<<endl;             
			cin>>team_nm;
			read_playerinfo();
		}         
		void output()         
		{             
			cout<<"The team's name: "<<team_nm<<endl<<endl;
			for(int i=0;i<11;i++)
				p[i].put_player();
		}
};
int team::tno = 0;
void team::read_playerinfo()
{
	int i;
	player p1;
	fstream file("playerinfo.txt",ios::in);
	if(!file)
	{
		cout<<"file not opened !!"<<endl;
		return ;
	}
	if(teamno==1)
		for(i=0;i<11;i++)
		{
			file>>p[i].nm;
			file>>p[i].bat_points;
			file>>p[i].bat_type;
			file>>p[i].cent;
			file>>p[i].half_cent;
			file>>p[i].bwl_pts;
			file>>p[i].bwl_typ;
		}
	else if(teamno==2)
	{
		for(i=0;i<11;i++)
		{
			file>>p1.nm;
			file>>p1.bat_points;
			file>>p1.bat_type;
			file>>p1.cent;
			file>>p1.half_cent;
			file>>p1.bwl_pts;
			file>>p1.bwl_typ;
		}
		for(i=0;i<11;i++)
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
}
int randomize(int a=10)
{
	time_t t;
	srand((unsigned) time(&t));
	return(rand()%a);
}

void save_file(team &t1,team &t2)
{
	fstream file("matchdata.dat",ios::out);
	if(!file)
	{
		cout<<"file not opened !!"<<endl;
		return ;
	}
	file.write((char*)&t1,sizeof(team));
	file.write((char*)&t2,sizeof(team));
	file.close();
}

int cmp_player(player tm1, player tm2)
{
    int temp0=tm1.ret_batpts();
    int temp1=tm2.ret_bwlpts();
    if((temp0>7)&&(temp1>7))
        return 0;
    else if((temp0>7)&&(temp1<=7))
        return 1;
    else if((temp0<=7)&&(temp1>7))
        return 2;
    else if((temp0<=7)&&(temp1<=7))
        return 3;
    else
		return -1;
}

int run(int no)
{
	int runs[10],i;
	for(i=0;i<10;i++)
		runs[i]=arr[no][i];
	return runs[randomize()];
}

int cointoss(char* tmnm1, char* tmnm2)
{
	int i,ran;

	cout<<"the coin is being tossed"<<endl;

	ran=randomize(2);

	if(ran==0)
	{
		cout<<endl<<tmnm1<<" wins the \"TOSS\" and choose to bat"<<endl;
		return 0;
	}
	else
	{
		cout<<endl<<tmnm2<<" wins the \"TOSS\" and choose to bat"<<endl;
		return 1;
	}
}

int main()
{
	int tn,i,j,k;
	char c;
	team t[2];
	
	t[0].input();
	t[1].input();
	tn=cointoss(t[0].retnm(),t[1].retnm());

	int bt=0,bw=11,r,n;
	for(i=0;i<10;i++)
	{
		cout<<1<<endl;
		for(j=0;j<6;j++)
		{
			cout<<2<<endl;
			if(tn==0)
				n=cmp_player(t[0].p[bt],t[1].p[bt]);
			else
				n=cmp_player(t[1].p[bt],t[0].p[bt]);
			r=run(n);
			cout<<3<<endl;
			if(tn==0)
			{
				cout<<"a"<<endl;
				t[0].p[bt].bat_cs(r);
				cout<<"A"<<endl;
				t[1].p[bw].bwl_cs(r,100);
			}
			else
			{
				cout<<"b"<<endl;
				t[1].p[bt].bat_cs(r);
				cout<<"B"<<endl;
				t[0].p[bw].bwl_cs(r,100);
				cout<<"bB"<<endl;
			}
			cout<<4<<endl;
			if(r==-1)
			{
				cout<<"OUT !!!!!"<<endl;
				t[tn].p[bt].put_player();
				bt++;
			}
			else
				t[tn].inc_run(r);
			if(bt==12)
			{
				cout<<"ALL OUT !!!!!"<<endl;
				c=getchar();
				t[tn].output();
				break;
			}
		}
		cout<<"OVER UP !!"<<endl;
		if(tn==0)
			t[1].p[bw].put_player();
		else
			t[0].p[bw].put_player();
		bw--;
		if(i==5)
			bw=11;
	}

	save_file(t[0],t[1]);
	
	return 0;
}

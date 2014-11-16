#include<stdlib.h>
#include<iostream>
#include<time.h>
using namespace std;
int main()
{
	int i;
	time_t t;
	
	srand((unsigned) time(&t));
	
	cout<<"random no b/w 1-10 :"<<endl;
	for(i=0;i<10;i++)
		cout<<rand()%10<<endl;
	
	return 0;
}

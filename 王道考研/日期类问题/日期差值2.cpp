#include<stdio.h>
#include<cmath>
int isleap(int year)
{
	return year%4 == 0 && year % 100 !=0 ||  year% 400 ==0 ?1 : 0 ;
}
int dayOfMonth[13][2] = {
	0 , 0, 
	31 , 31 ,
	28 , 29 ,
	31 , 31 , 
	30 , 30 , 
	31 , 31 , 
	30 , 30 , 
	31 , 31 , 
	31 , 31 , 
	30 , 30 , 
	31 , 31 , 
	30 , 30 , 
	31 , 31 ,
} ; 

struct date
{
	int day ;
	int month ;
	int year;
	void nextDay()
	{
		day++;
		if ( day > dayOfMonth[month][isleap(year)]) 
		{
			day = 1 ;
			month++ ;
			if (month > 12)
			{	
				month = 1 ;
				year++ ;				
			}
			
		}
	}
};

int buf[5001][13][32] ;

int main()
{
	date tmp ;
	int cnt = 0 ;
	
	tmp.day = 1 ;
	tmp.month = 1  ;
	tmp.year = 0  ;
	
	while(tmp.year!= 5001){
		buf[tmp.year][tmp.month][tmp.day] = cnt ;
		tmp.nextDay() ;
		cnt++ ;
	}
	
	int d1 , m1 , y1 ;
	int d2 , m2 , y2 ;
	while(scanf("%4d%2d%2d" , &y1 , &m1 , &d1) != EOF)
	{
		scanf("%4d%2d%2d" , &y2 , &m2  ,&d2) ;
		printf("%d\n" , abs(buf[y2][m2][d2] - buf[y1][m1][d1]) + 1 ) ;
	}
	
	return  0 ;
}

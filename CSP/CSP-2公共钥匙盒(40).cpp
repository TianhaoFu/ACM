#include<cstdio> 
#include<iostream> 
#include<queue>
using namespace std ;
struct ope
{
	bool ret ; 
	int time ;
	int num ;
	ope(){}
	//	大的在前面 
	bool operator < ( const ope & e)const {
		if ( this->time !=  e.time) 
			return this->time > e.time ;
		else if (this->ret!= e.ret) 
			return !this->ret&&e.ret ;
		else   
			return this->num > e.num;
		}	
};
int main()
{
	int n , k ;
	int w ,  s , c ;
	int box[1001] ;
	priority_queue<ope> oper ;
	scanf("%d%d" , &n , &k) ;
	for ( int i =1  ; i <= n ; i ++ )
		box[i] = i ;
	for ( int i = 0 ; i < k ; i ++ )
	{
		scanf("%d%d%d" , &w  ,&s , &c) ;
		ope temp ;
		temp.ret = false ;
		temp.num = w ;
		temp.time = s ;
		oper.push(temp);
		temp.ret = true ;
		temp.num = w ;
		temp.time = s + c ;
		oper.push(temp);
	}
	for ( int i = 0 ; i < 2 * k ; i ++ )
	{
		ope temp = oper.top() ;
		oper.pop() ;
		if(temp.ret == 1)
		{
			int j = 1;
			while(box[j]!=0)
				j++ ;
			box[j] = temp.num; 
		}
		else
		{
			int j = 1;
			while(box[j] != temp.num)
				j++ ;
			box[j] = 0 ;
		}
//		printf("时刻：%d\n" , temp.time);
//		for ( int i = 1 ; i <= n ; i ++ )
//			printf("%d" , box[i]) ;
//		printf("\n") ;
	}
	
	for ( int i = 1 ; i <= n ; i ++ )
		printf("%d " , box[i]) ;
	
//	system("PAUSE");
	return  0 ;
}

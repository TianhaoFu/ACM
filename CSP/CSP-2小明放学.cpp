#include<iostream>
using namespace std ;
int r , y , g ;
int n ;
int a[100001][2] ;
int sum = 0 ;
int period ;
int tt ; 

//ֻ��20�� 

//��r1 30 ��g3 30  ��y2 3 
//��һ����� ������� 
//�ƵƼ������ 

void gengxin (int start , int t)
{
	for ( int i = start ; i < n ; i ++ )
	{
//		printf("�Ե�%d���ƽ����޸�\n" ,i) ; 
		if(a[i][0] == 0)
			continue ;
		
		tt = t%period ;
		
		if(a[i][0] == 1)
		{
			if(tt<=a[i][1])
				a[i][1] -= tt ;
			else if ( tt <= a[i][1]+g)
				{
//					printf("�ڵ�%d�ֺ�Ʊ��̵�\n",i);
					a[i][0] = 3;
					//��д��һ��=�� 
//					printf("+-+-+%d+-+-+=",a[1][0]);
					a[i][1] =g-(tt-a[i][1]) ;
				}
			else if( tt <=a[i][1] + g +y)
			{
				a[i][0] = 2 ;
				a[i][1] = y-(tt-a[i][1]-g);
			}
			else if( tt <= a[i][1 + g + y  +r])
			{
				a[i][1] = r - (tt-a[i][1] - g -y);
			}
		}
		//��r1 ��g3  ��y2 
		if(a[i][0]  == 2)
		{
			if(tt <= a[i][1])
				a[i][1] -= tt ;
			else if( tt <=a[i][1]  +r)
			{
				a[i][0] = 1 ;
				a[i][1] = r - (tt-a[i][1]);
			}
			else if (tt <=a[i][1]  +r +g)
			{
				a[i][0] = 3 ;
				a[i][1] = g - (tt-a[i][1]  -r);
			}
			else if( tt <= a[i][1] +r  +g + y)
			{
				a[i][1] = y - (tt-a[i][1] - t - g);
			}
		}
		//��r1 ��g3  ��y2 
		if(a[i][0] == 3)
		{
			if(tt <= a[i][1])
				a[i][1]  -= tt ;
			else if(tt <= a[i][1] + y)
			{
				a[i][0] = 2 ;
				a[i][1] = y - (tt-a[i][1]);
			}
			else if(tt <= a[i][1] + y +r)
			{
				a[i][0] = 1;
				a[i][1] = r - (tt-a[i][1] - y);
			}
			else if( tt <= a[i][1] + y + r +g)
			{
				a[i][1] = g - (tt-a[i][1] -y - r);
			}
		}
	}
}

int main() 
{
	
	scanf("%d%d%d" , &r , &y , &g) ;
	scanf("%d" , &n) ;
	
	period = r + y + g ;
	for (int i = 0 ; i < n ; i ++  )
	{
		scanf("%d%d" , &a[i][0] , &a[i][1]);
	}
	
	for (int  i =0  ; i < n ; i ++)
	{
//		printf("%d:\n" , i) ;
		if (a[i][0] == 0)
			{
				sum += a[i][1];
				gengxin( i ,a[i][1]);
			}
		else if(a[i][0] == 3)
			{
				sum += 0 ;
				continue;
			}
		else if(a[i][0] == 2)
		{
			sum += a[i][1] + r ;
			gengxin( i, r + a[i][1]);
		}
		else if(a[i][0] == 1)
			{
				sum += a[i][1];
				gengxin( i ,a[i][1]);
			}
//		printf("--%d--\n"  ,sum);
//		printf("��һ����ƣ�++%d+%d++\n",a[1][0] , a[1][1]) ;
//		printf("�ڶ����Ƶƣ�++%d+%d++\n",a[3][0] , a[3][1]) ;
	}
	
	printf("%d",sum);
	
	return 0 ;
}


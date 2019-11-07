#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std ;
int N ,  M  ;
vector< vector < int > > a ;
vector< int> k_;
int T=0 , k , P ;

void shuguo()
{
	for(int i = 0 ; i < N ; i ++ )//遍历N棵苹果树 
	{
		for( int j = 0 ; j < M ; j ++)//迭代M次
		{
//			cout << "dfsd" <<endl; 
			a[i][0] -= a[i][j];
//			cout << "dfsd" <<endl; 
			k_[i] += -a[i][j];
//			cout <<a[i][j];
		}
	}
	
	for( int i = 0 ; i < N ; i ++) 
	{
		T += a[i][0];
	}
	
	cout << T ; 
	
	int flag=-1 ,index ;
//	priority_queue<int> kk;
	for( int i = 0 ; i <  N ; i ++ )
	{
		if( k_[i]>flag)
		{
			index = i ;
			flag = k_[i];
		}
	}
	for( int i = 0 ; i < N ; i ++ )
	{
		if(flag == k_[i])
			{
				index = i ;
				break ;
			}
	}
	
	k = index ;
	P = k_[index];
	
}
int main()
{
	cin >> N >> M ; 
	int temp ;
	a.resize(N);
	k_.resize(N);
	for ( int i = 0  ; i < N ; i ++)
	{
//		a[i].resize(M+1);
//		cout << N << M ; 
		k_[i] = 0;
		for ( int j = 0  ; j <= M ; j ++ )
		{
			scanf("%d",&temp);
//			printf("----") ;
			a[i].push_back(temp);
			cout<<temp ; 
//			cout << a[i][j] ;
		}
		cout<<endl ;
	}
	shuguo();
	cout<<"----" ;
	cout<< T <<' '<< k <<' '<< P;
	return 0 ;
}


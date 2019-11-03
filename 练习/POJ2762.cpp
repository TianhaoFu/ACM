#include<cstdio>
#include<string>
#define _ 60002
#define o 10002
//��ĿҪ���ж�ͼ���Ƿ���������ɹ�������i��j����ͨ·����j��i����ͨ·
//�⼴���ж���ͼ�Ƿ�������ͨͼ 
//��һ�ַ�ʽ��Ϊ��ͼ�е�����ǿ��ͨ�����������㣬Ȼ���ж���ͼ�Ƿ���ͨ
//һ������ͨ�������޻�ͼ������ͼ�е����е㶼��һ������
//����ͨ�����������ж�ʵ�� �����ĳ��ɾ�����ʱ�����������Ϊ0�ĵ㣬
//��˵����������ֻ�����Ѿ���ɾ���ĵ㵽�
//Ҳ����˵�������㻥�಻�ɴ 
//��ôֻ���¼��ǰ���Ϊ0�ĸ�����������1��ʱ�򲻳���


//�ο��� 
//�������û�л�������ͼ�Ļ���
//��ôֻ�е����еĵ㶼��һ�����ϵ�ʱ��ͼ������ͨ�ġ��� 

//���õ�ǿ��ͨ��֧�����½�ͼ�ķ����ǣ�
//�½�һ���洢ͼ�Ŀռ䡣
//��ÿ��ǿ��ͨ��֧�ı����Ϊ��ͼ�н��ı�š�
//�ж�ԭ����ÿ���ߵ����˵��Ƿ�����ͬһǿ��ͨ��֧��
//��������������ͼ�м���һ����������ǿ��ͨ��֧��Ŷ�Ӧ���ıߡ��� 
using namespace std ;

void link( int , int  )  ;
void link2 (int  , int ) ;
void tarjan( int ) ;
bool judge () ;
void topsort(int ) ; 

int dfn[ o ] ;
int low[ o ] ;
int h[ 0 ] ;
int h2[ o ] ;
int id[ o ] ;
int od [ o ] ;
int stack[ o ] ;
int code [ o ] ;

int net[ _ ] ;
int g[ _ ] ;
int next2[ _ ] ;
int g2[ _ ] ;

int q , n , m  , t , t2 , top , cnt , index , sid ;
bool ins[ o ] ;
bool flag ;

int main()
{
	freopen( "2762.in" , "r"  ,stdin );
	freopen( "2762.out" , "w" , stdout) ;
	scanf("%d" , &q ) ;
	
	int aa , bb ;
	
	while(q--) 
	{
		memset( dfn , 0 , sizeof( dfn )) ;
		memeset( low , 0 , sizeof( low )) ;
		memset ( next , 0 , sizeof( next)) ;
		memset( h , 0 , sizeof( h )) ;
		memset( next2 , 0 , sizeof(next2)) ; 
		memset( id , 0 , sizeof( id)) ;
		memset( od , 0 , sizeof(od)) ;
		memset( code , 0 , sizeof( code )) ;
		
		t = 0 ; 
		t2 = 0 ;
		cnt = 0 ;
		scanf("%d%d" , &n , &m) ;
		
		for( int i = 1 ; i <= m ; i ++ )
		{
			scanf("%d%d" , &aa , &bb ) ;
			link( aa,  bb ) ; 
	    }

	    for( int i = 1 ; i <= n ;i ++ )
	    	if( !dfn[i])
	    		tarjan( i ) ;
	    
	    if ( judge( ) )
	    	printf("Yes\n") ;
	    else 
	    	printf("No\n") ;
	}
	
	return 0 ;
	
} 

void link( int aa , int bb )
{
	next[ ++t ] = h [aa] ;
	h[aa] = t ;
	g[ t ] = bb ;
}

void link2( int aa , int bb )
{
	next2 [ ++t2 ]  = h2[ aa ] ;
	h2 [ aa ] = t2 ; 
	g2[ t2 ] = bb ;
}

void tarjan( int i )
{
	int j ;
	
	dfn[i] = low[i] = ++index ;
	stack[ ++top ] = i ;
	ins[ i ] = true ;
	
	for( int k = h[ i ] ; k ; k = next[ k ])
	{
		j = g [ k ] ;
		
		if( !dfn[j])
		{
			tarjan( j ) ;
			if( low[ j ] < low[ i ])
				low[ i ] = low[ j ];
		}
		
		else if ( ins[ j ] && dfn[ j ] < low[ i ])
			low[ i ] = dfn[ j ];
	}
	
	if( low[ i ] == dfn[ i ])
	{
		cnt++ ;
		do
		{
			j = stack[ top-- ] ;
			code[ j ] = cnt ;
			ins[ j ] = false ;
		}
		
		while( i != j) ;
	}
}

bool judge( )
{
	int j ;
	
	flag = true ; 
	sid = 0;
	for( int i = 1 ; i<= n ;i ++ )
	{
		for( int k = h[ i ] ; k ; k = next [ k ])
		{
			j = [ k ] ;
			if( code[ i ] != code[ j ])
			{
				id[ code[ j ]]++ ;
				link2( code[ i ] , code[ j ]) ;
			}
		}
	}
	
	for( int i = 1 ; i <= cnt ; i++ )
		if( id[ i ] == 0)
			sid++ ;
			
	if( sid > 1) return 0 ;
	
	for( int i = 1 ; i <= cnt ; i++)
		if( id[ i ] == 0)
			topsort( i ) ;
	
	if( flag )
		return 1;  
		
	return  0 ;
}

void topsort( int i )
{
	int j ;
	sid-- ;
	id[ i ]  = -1 ;
	
	for( int k = h2[ i ] ; k ; k = next2[ k ])
	{
		j = g2[ k ] ;
		id[ j ]-- ;
		if( id[ j ] == 0)
			sid++ ;
	}
	
	if( sid > 1) 
		flag = false ;
		
	for( int k = h2[ i ] ; k ; k = next2[ k ])
	{
		j = g2[ k ] ;
		if( id[ j ] == 0)
			topsort( j );
	}
 } 

#include<cstdio>
#include<vector>
#include<algorithm>
//ϣ����С�������е����Ȩֵ�ı�Ȩ����������������С�ı�Ȩ
//��С������Ȩֵ�б�����С�ģ����и�С�ıߣ�������ǰ�ƣ�
//Ϊ�������ܱ�Ȩ��С����������б������ƣ���ʱ���ı߾ͱ��� 
//��˴��������С���������� 

//1.POJ 2395 Out of Hay
//�����ǽ���Сƿ����������Ҫ���������е�������С��
//��ʵ��С�����������߾���Ҫ���ֵ��
//�÷�֤�������ȼ�����С������ΪT1,����ΪE1,����һ�����߸�С��������ΪT2������ΪE2��
//���E2 < E1����T2�����еı�Ȩֵ��С��E1��E1��T1������������ͨ����A,B����T2��һ��������A,B������ͨ�����ıߣ������������Ͳ���ͨ�ˣ�����Щ�߶�С��E1���������滻E1����T1����Ȩֵ��С���� T1����С������ì�ܡ�
//�����С�����������ߵ�Ȩֵ������������������Ȩֵ����Сֵ��
//����˵��С��������KС�ı��������������� KС�ı�����С�ģ���֪����ô֤����

using namespace std ; 
struct Edge{
	int from ; 
	int to ; 
	int distance ;
};

int father[50005] ; 

bool  cmp(Edge e1 ,  Edge e2){
	return e1.distance < e2.distance ; 
}

int result = 0   ;

int main()
{
	void init(int number) ; 
	void unio(int from , int to , int distance) ;
	int vertextNumber , edgeNumber , root ;
	scanf("%d%d%d" , &vertextNumber , &edgeNumber , &root) ;
	vector<Edge> vec ;
	Edge temp ; 
	int from , to , distance ; 
	
	for (int i = 0 ; i < edgeNumber ; i ++ )
	{
		scanf("%d%d%d",&from , &to , &distance)  ;
		temp.from = from ; 
		temp.to = to ;
		temp.distance = distance ;
		vec.push_back(temp) ;
	 } 
	
	sort(vec.begin() , vec.end() , cmp) ; 
	init(veretxtNumber) ; 
	for(  int i = 0 ; i < vec.size() ; i ++) 
	 {
	 	temp = vec[i] ; 
	 	from = temp.from ; 
	 	to = temp.to ;
	 	distance = temp.distance ; 
	 	unio(from , to , distance) ;
	 }
	 
	printf("%d\n" , result) ;
	
	 return 0 ;
}

void init(int number)
{
	for( int i = 0 ;i <= numbre ; i ++ )
	{
		father[i] = i;
	}
}

int findFather(int x){
	int a = x ;
	while(x != father[x])
	{
		x = father[x] ; 
	}
	
	while(a != father[a])
	{
		int z = father[a] ;
		
		father[a] = x ;
		a = z ;
	}
	
	return x  ;
	
}

void unio ( int from , int to , itn distance)
{
	int fx = findFather(from ) ; 
	int fy = findFather(to ) ;
	if( fx != fy) 
	{
		fahter[fx]  =fy  ;
		result = distance ;
	 } 
}

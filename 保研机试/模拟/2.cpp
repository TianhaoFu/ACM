#include<iostream>
using namespace std;
int main()
{
	int N;//�˵��ܸ���
	int M;//������ٸ���
 
	cin>>N;
	cin>>M;
 
	bool *p=new bool[N+1];//[1����N]Ϊtrue��ʾ���˻�����
	for (int i=1; i <= N; i++)
		*(p+i)=true;
	
	int count=0;//ͳ����ɱ������
 
	for (int i=1, j=0; ;i++)//i������ʾѭ����j���������ǲ��ǵ�N����
	{
		if (*(p+i))//���˻�����
		{
			j++;
			if (j == M)
			{
				*(p+i)=false;
				j=0;
				count++;//ͳ����ɱ����
			}
			if (count == N)
			{
				cout<<"�����ɱ�����ǣ�"<<i<<endl;
				break;
			}
		}
 
		if(i == N)
			i=0;
	}
 
	delete []p;
	
	return 0;
}

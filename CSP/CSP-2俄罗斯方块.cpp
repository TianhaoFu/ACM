#include<bits/stdc++.h>
using namespace std ;
//�ؼ���ȷ���¼�����ĵ�һ��Ӧ��ͣ�ڳ�ʼ����ͼ�ĵڼ��С�
//�����ά����A�洢��ʼ����ͼ��B�洢�¼����飬
//num�洢�¼���������ڳ�ʼ����ͼ��һ�С�
//����һ������Ϊ10������Atemp��¼��ʼ����ͼÿһ�з������ڵ���С������������0��ʼ��ţ���Ӧ������кţ���
//��û�з��飬����Ϊ15��
//����һ������Ϊ4������Btemp��¼�¼�����ÿһ�з������ڵ����������������0��ʼ��ţ���Ӧ������кţ���
//minRow��¼�¼�����ĵ�һ��Ӧ��ͣ�ڳ�ʼ����ͼ��������///
//����Btemp��
//����ÿһ����Ϊ-1��Ԫ��Btemp[i]��0<=i<4����
//����minRow=min(minRow,Atemp[num+i-1]-Btemp[i]-1)��
//���õ���minRow��Ϊ�¼�����ĵ�һ��Ӧ��ͣ�ڳ�ʼ����ͼ������
//Ȼ���¼������minRow�д��ϵ���������ʼ����ͼ���ɡ�
int main()
{
    int a[15][10] , atemp[10] ;
    int b[4][4],btemp = {-1,-1,-1,-1} ;

    fill(atemp , atemp+10 , 15) ;

    for(int i = 0  ; i<15 ; i ++ )
    {
        scanf("%d" , &a[i][j]) ;
        if(a[i][j] == 1 && atemp[j])
            atemp [j] = i ;
    }
    for( int i = 0 ; i < 4 ; i ++ )
    {
        for( int j = 0 ; j <4 ; j ++)
        {
            scanf("%d" , &b[i][j]);
            if(b[i])[j] == 1)
            {
                    btemp[j] = i ;
            }
        }

    }

    int num  , minRow = 15 ;
    scanf("%d" , &num ) ;
    for(int i = 0 ;i < 4 ; i++)
    {
        if(btemp[i] > -1)
            minRow = min(minRow , atemp[num + i - 1] - btemp[i] - 1) ;
    }
    for(int i = 0 ; i < 4 && i+minRow <15; i ++ )
    {
        for( int j = 0 ; j <4 ; j ++)
        {
            if( i +minRow >= 0 )
                a[i+minRow][num-1+j] = b[i][j] == 1? 1 : a[i+minRow][num-1+j] ;
        }
    }

    for( int  i= 0 ; i < 15 ; i ++ )
    {
        for( int  j= 0 ;j <10 ; j ++
            printf("%d" , a[i][j]) ;
        printf("\n");
    }

    return 0 ;
}

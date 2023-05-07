#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
#define Infinity 999 
struct GraM
{
	char Senics[21][30];
	int Senics_Num,Way_Num;
	int matrix[21][21];
};

GraM Init_GraM()
{
	GraM  Y;
	strcpy(Y.Senics[0],"�����");strcpy(Y.Senics[1],"Ħ����");strcpy(Y.Senics[2],"·��1");strcpy(Y.Senics[3],"��ɽ��");
	strcpy(Y.Senics[4],"·��2");strcpy(Y.Senics[5],"������");strcpy(Y.Senics[6],"·��3");strcpy(Y.Senics[7],"��תľ��");
	strcpy(Y.Senics[8],"·��4");strcpy(Y.Senics[9],"������");strcpy(Y.Senics[10],"·��5");strcpy(Y.Senics[11],"�����½�");
	strcpy(Y.Senics[12],"·��6");strcpy(Y.Senics[13],"����Ĵ�");strcpy(Y.Senics[14],"·��7");strcpy(Y.Senics[15],"��ͯ��԰");
	strcpy(Y.Senics[16],"·��8");strcpy(Y.Senics[17],"����̽��");strcpy(Y.Senics[18],"·��9");strcpy(Y.Senics[19],"�羰��");
	strcpy(Y.Senics[20],"·��10");
	Y.Senics_Num=10;Y.Way_Num=21;
	for(int i=0;i<21;i++)
		for(int j=0;j<21;j++)
			Y.matrix[i][j]=Infinity;
	Y.matrix[0][2]=1;Y.matrix[2][0]=1;
	Y.matrix[1][2]=15;Y.matrix[2][1]=15;
	Y.matrix[2][4]=3;Y.matrix[4][2]=3;
	Y.matrix[3][4]=25;Y.matrix[4][3]=25;
	Y.matrix[4][6]=4;Y.matrix[6][4]=4;
	Y.matrix[5][6]=30;Y.matrix[6][5]=30;
	Y.matrix[6][8]=5;Y.matrix[8][6]=5;
	Y.matrix[7][8]=20;Y.matrix[8][7]=20;
	Y.matrix[8][10]=4;Y.matrix[10][8]=4;
	Y.matrix[9][10]=24;Y.matrix[10][9]=24;
	Y.matrix[10][12]=3;Y.matrix[12][10]=3;
	Y.matrix[11][12]=35;Y.matrix[12][11]=35;
	Y.matrix[12][14]=4;Y.matrix[14][12]=4;
	Y.matrix[13][14]=17;Y.matrix[14][13]=17;
	Y.matrix[14][16]=5;Y.matrix[16][14]=5;
	Y.matrix[15][16]=28;Y.matrix[16][15]=28;
	Y.matrix[16][18]=6;Y.matrix[18][16]=6;
	Y.matrix[17][18]=20;Y.matrix[18][17]=20;
	Y.matrix[18][20]=6;Y.matrix[20][18]=6;
	Y.matrix[19][20]=27;Y.matrix[20][19]=27;
	return Y;
}
int D[21][21];        
void Floyide(GraM *G) //������֮�����·�����       
{
	int i,j,k;
	for (i=0;i<21;i++)         //��ʼ��G
	{
		for (j=0;j<21;j++)
		{
			D[i][j]=G->matrix[i][j];
		}
	}
	for (k=0;k<21;k++)
	{
		for (i=0;i<21;i++)
		{
			for (j=0;j<21;j++)
			{
				if (D[i][j]>D[i][k]+D[k][j])
					D[i][j]=D[i][k]+D[k][j];
			}
		}
	}
}

void Waysort(int *a)//����ѡ��
{
	int b[10];
	for(int i=0;i<10;i++)
		b[i]=D[0][2*i+1];
	for(int i=0;i<10;i++)
	{
		a[i]=0;
		for(int j=1;j<10;j++)
		{ 
			if(b[a[i]]>b[j])
				a[i]=j;
		}
		b[a[i]]=Infinity;
	}
}
int Senicssort(int *a,int Play_Time)//����˳��ѡ��
{
	int n=0;
		for(int i=9;i>=0;i--)
		{
			int Time=Play_Time-D[0][2*a[i]+1]*2;
			for(int j=i-1;j>=0;j--)
				Time=Time-2*D[2*a[j]+1][2*a[j]+2];
			if(Time>0)
			{
				n=i;
				break;
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				if(a[j]<a[j-1])
				{
					int t=a[j];
					a[j]=a[j-1];
					a[j-1]=t;
				}
			}
			return n;
}
void Display(int n,int *a,GraM *G)
{
	cout<<"�����";
	for(int i=0;i<=n;i++)
	{
		cout<<"->"<<G->Senics[2*a[i]+1];
	}
	cout<<"->�����"<<endl;
}
int main()
{
	GraM G=Init_GraM();

	int Play_Time;
	cout<<"����������ʱ�䣨����)�磺39"<<endl;
	cin>>Play_Time;
	if(Play_Time<32)
		cout<<"ʱ�䲻��ԣ������������";
	else
	{
		Floyide(&G);
		int a[10];
		Waysort(a);
		int n=Senicssort(a,Play_Time);
		Display(n,a,&G);
	}
	system("pause");
	return 1;
}
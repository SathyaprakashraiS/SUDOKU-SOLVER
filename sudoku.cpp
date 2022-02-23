#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
int a[9][9] = {
   {3, 0, 6, 5, 0, 8, 4, 0, 0},
   {5, 2, 0, 0, 0, 0, 0, 0, 0},
   {0, 8, 7, 0, 0, 0, 0, 3, 1},
   {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
   {9, 0, 0, 8, 6, 3, 0, 0, 5},
   {0, 5, 0, 0, 9, 0, 6, 0, 0},
   {1, 3, 0, 0, 0, 0, 2, 5, 0},
   {0, 0, 0, 0, 0, 0, 0, 7, 4},
   {0, 0, 5, 2, 0, 6, 3, 0, 0}
};
using namespace std;
int search(int i,int j,int number)
{
	for(int k=0;k<9;k++)
	{
		if(k!=i)
		{
			if(a[k][j]==number)
			{
				return 0;
			}
		}
	}
	for(int k=0;k<9;k++)
	{
		if(k!=j)
		{
			if(a[i][k]==number)
			{
				return 0;
			}
		}
	}
	if(i<3 && j<3)
	{
		for(int k=0;k<3;k++)
		{
			for(int l=0;l<3;l++)
			{
				if(number==a[k][l])
				{
					return 0;
				}
			}
		}
	}
	if(i<3 && j<6 && j>=3)
	{
		for(int k=0;k<3;k++)
		{
			for(int l=3;l<6;l++)
			{
				if(number==a[k][l])
				{
					return 0;
				}
			}
		}
	}
	if(i<3 && j<9 && j>=6)
	{
		for(int k=0;k<3;k++)
		{
			for(int l=6;l<9;l++)
			{
				if(number==a[k][l])
				{
					return 0;
				}
			}
		}
	}
	if(i<6 && i>=3 && j<3)
	{
		for(int k=3;k<6;k++)
		{
			for(int l=0;l<3;l++)
			{
				if(number==a[k][l])
				{
					return 0;
				}
			}
		}
	}
	if(i<6 && i>=3 && j<6 && j>=3)
	{
		for(int k=3;k<6;k++)
		{
			for(int l=3;l<6;l++)
			{
				if(number==a[k][l])
				{
					return 0;
				}
			}
		}
	}
	if(i<6 && i>=3 && j<9 && j>=6)
	{
		for(int k=3;k<6;k++)
		{
			for(int l=6;l<9;l++)
			{
				if(number==a[k][l])
				{
					return 0;
				}
			}
		}
	}
	if(i<9 && i>=6 && j<3)
	{
		for(int k=6;k<9;k++)
		{
			for(int l=0;l<3;l++)
			{
				if(number==a[k][l])
				{
					return 0;
				}
			}
		}
	}
	if(i<9 && i>=6 && j<6 && j>=3)
	{
		for(int k=6;k<9;k++)
		{
			for(int l=3;l<6;l++)
			{
				if(number==a[k][l])
				{
					return 0;
				}
			}
		}
	}
	if(i<9 && i>=6 && j<9 && j>=6)
	{
		for(int k=6;k<9;k++)
		{
			for(int l=6;l<9;l++)
			{
				if(number==a[k][l])
				{
					return 0;
				}
			}
		}
	}
return 1;
}
int solve()
{
	int sf=0,number=1,placed=0;
	for(int i=0;i<9;i++)
	{
	for(int j=0;j<9;j++)
	{
		if(a[i][j]==0)
		{
		while(placed==0 && number>0 && number<10)
		{
			int kuttiflag;
			kuttiflag=search(i,j,number);
			if(kuttiflag==1)
			{
				a[i][j]=number;
				placed=1;
				int ans;
				ans=solve();
				if(ans==1)
				{
					placed=0;
					number++;
				}
				else
				{
					placed=1;
					return 0;
				}
			}
			else{
				number++;
			}
		};
		a[i][j]=0;
		return 1;
		}
	}
}
return 0;
}
int main()
{
system("cls");
int loop=0,q=0,pass=0;
cout<<"solving begins...\n";
solve();
cout<<"SOLUTION\n";
for(int u=0;u<9;u++)
	{
		for(int y=0;y<9;y++)
		{
			cout<<a[u][y]<<" ";
		}
		cout<<"\n";
	}
return 0;
}

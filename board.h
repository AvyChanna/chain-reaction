#ifndef __board
#define __board
#include<iostream>
#include<iomanip>
using namespace std;
class board
{
	private:
	
		int ***arr;
	
		int r;
		int c;

	public:

		int winner;
		int checktable()
		{
			return 0;
		}
		board(int row, int column)
		{
			int i,j;
			arr = new int**[row];
			for(i = 0; i < row; i++)
				arr[i] = new int*[column];
			for(i = 0; i < row; i++)
				for(j = 0; j < column; j++)
				{
					arr[i][j] = new int[2];
					arr[i][j][0] = -1;
					arr[i][j][1] = 0;
				}
			winner = -1;
			r = row;
			c = column;
		}
		int get(int x, int y)
		{
			return arr[x][y][0];
		}
		int turn(int x, int y, int player)
		{
			if(x >= r || c >= c)
				return 0;
			if(arr[x][y][0] != player && arr[x][y][0] == ((player+1)%2))
				return 0;
			arr[x][y][0]++;
			arr[x][y][1] = player;
			cout<<"------BoardChanged------"<<endl;
			printboard();
			return 1;
		}
		void printboard()
		{
			int i,j;
			for(i=0;i<r;i++)
			{
				for(j=0;j<c;j++)
					cout<<setw(2)<<arr[i][j][0]<<","<<arr[i][j][1]<<" ";
				cout<<endl;
			}
		}

};

#endif
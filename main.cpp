#include<iostream>
#include"board.h"
using namespace std;

int main()
{
	int r, c;
	cin>>r>>c;
	board b(r, c);
	b.printboard();
	int i,j;
	int player=1;
	while(b.winner == -1)
	{
		// if(b.checktable())
		// 	break;
		player = (player+1)%2;
		cin>>i>>j;
		cout<<"NextTurn"<<endl;
		while(!b.turn(i, j, player))
			cin>>i>>j;
	}
	b.printboard();
	cout<<b.winner<<" wins"<<endl;
	return 0;
}
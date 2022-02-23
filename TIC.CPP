#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
char square[10] = {'o','1','2','3','4','5','6','7','8','9'};
int ch, player=1;
int move(int);
int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])
	return 1;
    else if (square[4] == square[5] && square[5] == square[6])
	return 1;
    else if (square[7] == square[8] && square[8] == square[9])
	return 1;
    else if (square[1] == square[4] && square[4] == square[7])
	return 1;
    else if (square[2] == square[5] && square[5] == square[8])
	return 1;
    else if (square[3] == square[6] && square[6] == square[9])
	return 1;
    else if (square[1] == square[5] && square[5] == square[9])
	return 1;
    else if (square[3] == square[5] && square[5] == square[7])
	return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3'
	     && square[4] != '4' && square[5] != '5' && square[6] != '6'
	     && square[7] != '7' && square[8] != '8' && square[9] != '9')
	return 0;
    else
	return -1;
}
void board()
{
    clrscr();
    cout << "\n\n\tTic Tac Toe\n\n";
    cout << "Player 1 (X)  -  Player 2 (O)\n\n\n";
    cout << "     |     |     " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;
    cout << "     |     |     " << endl << endl;
}
int check_move(int choice)
{
	  if (choice == 1 && square[1] == '1')
	    return(1);
	  else if (choice == 2 && square[2] == '2')
	    return(1);
	  else if (choice == 3 && square[3] == '3')
	    return(1);
	  else if (choice == 4 && square[4] == '4')
	    return(1);
	  else if (choice == 5 && square[5] == '5')
	    return(1);
	  else if (choice == 6 && square[6] == '6')
	    return(1);
	  else if (choice == 7 && square[7] == '7')
	    return(1);
	  else if (choice == 8 && square[8] == '8')
	    return(1);
	  else if (choice == 9 && square[9] == '9')
	    return(1);
	  else
	    return(0);
}
int move(int player)
{
 int choice,i,ctr=0,n;
 int a[10],g='1';
 switch(ch)
 {
  case 1: cin>>choice;
	  i=check_move(choice);
	  if(i==0)
	  {
	   do
	   {
	    cout<<"\nInvalid Move Give new Move : ";
	    cin>>choice;
	    i=check_move(choice);
	   }while(i==0);
	  }
  break;
  case 2: if(player==1)
	  {
	    cin>>choice;
	    i=check_move(choice);
	    if(i==0)
	    {
	     do
	     {
	       cout<<"\nInvalid Move Give new Move : ";
	       cin>>choice;
	       i=check_move(choice);
	     }while(i==0);
	    }
	  }
	  else if(player==2)
	  {
	   randomize();
	   randomize();
	   for(int j=1; j<10; j++,g++)
	   {
	     if(square[j]==g)
	     {
	      a[ctr]=j;
	      ++ctr;
	     }
	   }
	   n=random(ctr);
	   choice=a[n];
	  }
  break;
 }
 return choice;
}
void game()
{
	int i,choice;
    char mark;
    do
    {
	board();
	player=(player%2)?1:2;
	if(ch==1)
	{
	  cout << "Player " << player << " enter a number :  ";
	}
	else if(ch==2)
	{
	  cout << "Player enter a number : ";
	}
	choice=move(player);
	mark=(player == 1) ? 'X' : 'O';
	square[choice]=mark;
	i=checkwin();
	++player;
    }while(i==-1);
    board();
    if(i==1)
	cout<<"==>\aPlayer "<<--player<<" win ";
    else
	cout<<"==>\aGame draw";
    getch();
}
void main()
{
 clrscr();
 char ans,p='1';
 cout<<"\n\n\n\t\t\tWelcome to the game";
 cout<<"\n\t\tPress any key to continue";
 getch();
 do
 {
   clrscr();
   cout<<"\n\t\tSelect Mode\n\t\t1.Play With other player\n\t\t2.Play with computer";
   cout<<"\n\n\tChoice : ";
   cin>>ch;
   game();
   cout<<"\n\tDo you Want to Play Again\?(Y/N)\n\tChoice : ";
   cin>>ans;
   if(ans=='y'||ans=='Y')
   {
    player=1;
    for(int x=1; x<10;p++,x++)
    square[x]=p;
   }
 }while(ans=='y'||ans=='Y');
}

/*********************************************
    FUNCTION TO RETURN GAME STATUS
    1 FOR GAME IS OVER WITH RESULT
    -1 FOR GAME IS IN PROGRESS
    O GAME IS OVER AND NO RESULT
**********************************************/



/*******************************************************************
     FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
********************************************************************/



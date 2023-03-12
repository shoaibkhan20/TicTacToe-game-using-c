#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

main()
{
	start:
	/* i use character array because everytime user give an integer box number  actually
	that will be the index of that number in array and i will it by that user ie X or O */
	char options[] = {'0','1','2','3','4','5','6','7','8','9'};
	int choice;
	char user = 'X',winner;
	refresh: // label for refresh everytime user select choice
	
	printf("[ Game By Shoaib Khan ]");  //start screen
	printf("\n======================\n\n");
	printf("         |       |      \n");
    printf("     %c   |   %c   |   %c   \n",options[1],options[2],options[3]);
    printf("         |       |      \n");
	printf("  ----------------------\n");
	printf("         |       |      \n");
	printf("     %c   |   %c   |   %c   \n",options[4],options[5],options[6]);
	printf("         |       |      \n");
	printf("  ----------------------\n");
	printf("         |       |      \n");
	printf("     %c   |   %c   |   %c   \n",options[7],options[8],options[9]);
	printf("         |       |        \n\n");
	
	
	/*  wrote conditions of the top because i want  the  compiler to check it everytime
	 after refresh the values  */
	 
	// checking the winner for player X
	if(options[1]=='X' && options[2]=='X' && options[3]=='X')
		winner = 'X';
	else if(options[4]=='X' && options[5]=='X' && options[6]=='X')
		winner = 'X';
	else if(options[7]=='X' && options[8]=='X' && options[9]=='X')
		winner = 'X';
	else if(options[1]=='X' && options[4]=='X' && options[7]=='X')
		winner = 'X';
	else if(options[2]=='X' && options[5]=='X' && options[8]=='X')
		winner = 'X';
	else if(options[3]=='X' && options[6]=='X' && options[9]=='X')
		winner = 'X';
	else if(options[1]=='X' && options[5]=='X' && options[9]=='X')
		winner = 'X';
	else if(options[3]=='X' && options[5]=='X' && options[7]=='X')
		winner = 'X';
	//==================================
	// checking the winner for player Y
	else if(options[1]=='O' && options[2]=='O' && options[3]=='O')
		winner = 'O';
	else if(options[4]=='O' && options[5]=='O' && options[6]=='O')
		winner = 'O';
	else if(options[7]=='O' && options[8]=='O' && options[9]=='O')
		winner = 'O';
	else if(options[1]=='O' && options[4]=='O' && options[7]=='O')
		winner = 'O';
	else if(options[2]=='O' && options[5]=='O' && options[8]=='O')
		winner = 'O';
	else if(options[3]=='O' && options[6]=='O' && options[9]=='O')
		winner = 'O';
	else if(options[1]=='O' && options[5]=='O' && options[9]=='O')
		winner = 'O';
	else if(options[3]=='O' && options[5]=='O' && options[7]=='O')
		winner = 'O';
		
	if(winner == 'X' || winner == 'O')
	{
		printf("\n( Player %c is a Winner )", winner);
		goto end;
	}
	   // checking the non selected boxes if found then leave condition for choose
	   // if all boxes selected and no one is selected as winner then 
	   // it will print that no one is winner and restart the game again
	   // if there will beatleat one unselected box then it will wait till all boxes filled
      if(options[1]=='1'||options[2]=='2'||options[3]=='3'||options[4]=='4'
         ||options[5]=='5'||options[6]=='6'||options[7]=='7'||options[8]=='8'
		 ||options[9]=='9')
         printf("");
    else {
       		system("cls");
       		printf("NO ONE IS WINNER TRY AGAIN \n\n");
       		goto start;
	   }
	//==================================
	
	// getting choice from user
	choose: printf("Its player ( %c ) turn \n\n=> choose option by entering box number :  ",user);
	scanf("%d",&choice);
	if(!(choice>0 && choice <= 9))
	{
		printf("\n-> only upper numbers choices allowed\n\n");
		goto choose;
	}
	//=========================
	// 
	if(user == 'X')
	{
		if(options[choice] == 'X'|| options[choice] == 'O')
		{
			printf(" Option not availible \n");
			goto choose;
		}
		else{
		options[choice] =user;
		// change user turn after x user turn
		user = 'O';
		//====================
		//clear screen
		system("cls");
		// back to top
		goto refresh;
	      }
	}
	if(user=='O')
	{
		if(options[choice] == 'X'|| options[choice] == 'X')
		{
			printf(" Option not availible \n");
			goto choose;
		}
		else{
		options[choice] =user;
		user = 'X';
		system("cls");
		goto refresh;
	      }
	}
	
	end:
	char r;
	printf("\n\n=> Do you want to try again ( y/n )  ");
	r=getche();
	if(r=='y'|| r=='Y')
	{
		/* if winner will be X or Y then it will show winner messege again and
		 again therefore i change the variabe data */
		winner = 'n';
		system("cls");
		goto start;
	}
	else{
		return 0;
	}

}

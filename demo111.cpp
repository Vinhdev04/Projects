#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <MMsystem.h>

char square[17] = {'o','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16'};
int checkWin();
void drawBoard();

int main(){
	system("color a");
	int player = 1, i ,choice;
	char mark; // X,O
	do {
		drawBoard();
		player = (player % 2) ? 1 : 2;
		printf("Player %d, enter the choice : ",player);
		scanf("%d",&choice);
		mark = (player == 1) ? 'X' : 'O';
		if(choice == 1 && square[1] == '1')
			square[1] = mark;
		else if(choice == 2 && square[2] == '2')
			square[2] = mark;
			else if(choice == 3 && square[3] == '3')
			square[3] = mark;
			else if(choice == 4 && square[4] == '4')
			square[4] = mark;
			else if(choice == 5 && square[5] == '5')
			square[5] = mark;
			else if(choice == 6 && square[6] == '6')
			square[6] = mark;
			else if(choice == 7 && square[7] == '7')
			square[7] = mark;
			else if(choice == 8 && square[8] == '8')
			square[8] = mark;
			else if(choice == 9 && square[9] == '9')
			square[9] = mark;
			else if(choice == 10 && square[10] == '10')
			square[10] = mark;
			else if(choice == 11 && square[11] == '11')
			square[11] = mark;
			else if(choice == 12 && square[12] == '12')
			square[12] = mark;
			else if(choice == 13 && square[13] == '13')
			square[13] = mark;
			else if(choice == 14 && square[14] == '14')
			square[14] = mark;
			else if(choice == 15 && square[15] == '15')
			square[15] = mark;
			else if(choice == 16 && square[16] == '16')
			square[16] = mark;
			else {
				printf("Invalid option !");
				player--;
				getch();
			}
			i = checkWin();
			player++;	
		
	}while(i == -1);
	
	drawBoard();
	if(i==1){
		printf("==>Player %d won",--player);
//		PlaySound(TEXT("C:\Users\vinhn\Music\\win.mp3"),NULL,SND_SYNC);
	}
	else {
		printf("==>Game draw");
	}
		getch();
		return 0;
}
int checkWin() {
	if (square[1] == square[2] && square[2] == square[3] && square[3] == square[4])
		return 1;
	else if (square[5] == square[6] && square[6] == square[7] && square[7] == square[8])
		return 1;
	else if (square[9] == square[10] && square[10] == square[11] && square[11] == square[12])
		return 1;
	else if (square[13] == square[14] && square[14] == square[15] && square[15] == square[16])
		return 1;
	else if (square[1] == square[5] && square[5] == square[9] && square[9] == square[13])
		return 1;
	else if (square[2] == square[6] && square[6] == square[10] && square[10] == square[14])
		return 1;
	else if (square[3] == square[7] && square[7] == square[11] && square[11] == square[15])
		return 1;
	else if (square[4] == square[8] && square[8] == square[12] && square[12] == square[16])
		return 1;
	else if (square[1] == square[6] && square[6] == square[11] && square[11] == square[16])
		return 1;
	else if (square[4] == square[7] && square[7] == square[10] && square[10] == square[13])
		return 1;
	else if (
		square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' &&
		square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' &&
		square[9] != '9' && square[10] != 'A' && square[11] != 'B' && square[12] != 'C' &&
		square[13] != 'D' && square[14] != 'E' && square[15] != 'F' && square[16] != 'G'
	)
		return 0;
	else
		return -1;
}

void drawBoard() {
    system("cls");
    printf("\n\n\t Tic Tac Toe \n\n");
    printf("Player1 (X) - Player2 (O) \n\n\n");
    printf("     |     |     |          \n");
    printf("  %c  |  %c  |  %c  |  %c  \n", square[1], square[2], square[3], square[4]);
    printf("_____|_____|_____|_____\n");
    printf("     |     |     |         \n");
    printf("  %c  |  %c  |  %c  |  %c  \n", square[5], square[6], square[7], square[8]);
    printf("_____|_____|_____|_____\n");
    printf("     |     |     |         \n");
    printf("  %c  |  %c  |  %c  |  %c  \n", square[9], square[10], square[11], square[12]);
    printf("_____|_____|_____|_____\n");
    printf("     |     |     |     \n");
    printf("  %c  |  %c  |  %c  |  %c  \n", square[13], square[14], square[15], square[16]);
    printf("_____|_____|_____|_____\n");
    printf("     |     |     |     \n");
}




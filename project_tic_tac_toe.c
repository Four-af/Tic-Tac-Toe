#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

char board[3][3];
const char PLAYER='X';
const char COMPUTER='O';


void restBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char );

int main()
{
    char winner=' ';//no winner //X-player wins O-computer wins
    restBoard();
    char choice;
    // printBoard();

    do
    {
    char winner=' ';
    restBoard();
    while (winner==' '&& checkFreeSpaces()!=0)
    {
        printBoard();

        playerMove();
        winner = checkWinner();
        if(winner != ' ' || checkFreeSpaces() == 0)//to see if game is over
        {
            break;
        }

        computerMove();
        winner = checkWinner();
        if(winner != ' ' || checkFreeSpaces() == 0)//to see if game is over
        {
            break;
        }
    }

    printBoard();
    printWinner(winner);

    printf("\nDo you want to play again?(y/n): ");
    getchar();
    scanf("%c",&choice);
    } while (choice== 'y'|| choice=='Y');
    
    printf("\nThanks for playing!\n");
    
    return 0;
}


void restBoard()
{
    for (int i = 0; i < 3; i++)//for each row
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j]=' ';//each element becomes empty
        }
    }
}

void printBoard()
{
    printf(" %c | %c | %c ",board[0][0],board[0][1],board[0][2]);
    printf( "\n---|---|---\n");
    printf(" %c | %c | %c ",board[1][0],board[1][1],board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ",board[2][0],board[2][1],board[2][2]);
    printf("\n");
}

int checkFreeSpaces()
{
    int freeSpaces=9;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != ' ')//if 2d board is occupied
            {
                freeSpaces--;
            }
        }
    }
    return freeSpaces;//if return value is 0 means game over no more spaces to move
}

void playerMove()
{
    int x,y;

    printf("Enter row no. (1-3): ");
    scanf("%d", &x);
    x--;//index 0
    printf("Enter column no. (1-3): ");
    scanf("%d", &y);
    y--;

   do
   {
    if (board[x][y] != ' ') //to see if coordinate is occupied
    {
        printf("Invalid move\n");
        playerMove();
        break;
    }
    else//SPOT OPEN
    {
        board[x][y]=PLAYER;
        break;
    }
   } while (board[x][y] != ' ');
   

    
}

void computerMove()
{
    //creating a seed based on current time
    srand(time(0));
    int x,y;

    if(checkFreeSpaces()>0)
    {
        do
        {
            x= rand() % 3;//generating random numbers
            y= rand() % 3;//no. btwn 0 to 2

        } while (board[x][y] != ' ');//generate till open space

        board[x][y] = COMPUTER;//fill the space
    }
    else
    {
        printWinner(' ');//draw...no winner
    }
}

char checkWinner()
{
    //check rows wise win
    for(int i=0; i<3; i++)
    {
        if(board[i][0]== board[i][1] && board[i][0] == board[i][2])//top left seeing rows
        {
            return board[i][0];
        }
    }
    //check columsss winss
    for(int i=0; i<3; i++)
    {
        if(board[0][i]== board[1][i] && board[0][i] == board[2][i])//top left seeing cols
        {
            return board[0][i];
        }
    }
    //check diagonal winss
    if(board[0][0]== board[1][1] && board[0][0] == board[2][2])//top left to bottom right
    {
        return board[0][0];
    }
    if(board[0][2]== board[1][1] && board[0][2] == board[2][0])//bottom left to top right 
    {
        return board[0][2];
    }

    return ' '; //no winner yet
}

void printWinner(char winner)
{
    if (winner == PLAYER)
    {
        printf("\nYOU WIN!");
    }
    else if (winner == COMPUTER)
    {
        printf("\nYOU LOSE!");
    }
    else
    {
        printf("\nGAME TIED!");
    }
    
}
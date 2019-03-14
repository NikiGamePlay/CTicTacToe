#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char board[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'}; // our "map"

void drawBoard();
int checkIfWon();

void clearScreen() // clears screen by spamming newlines
{
    int n;
    for (n = 0; n < 10; n++)
        printf("\n\n\n\n\n\n\n\n\n\n");
}

int main()
{
    int choice, player = 1, i;
    char mark;
    do
    {
        drawBoard();          // draw board 
        player = (player % 2) ? 1 : 2; // change player each run
        printf("Player %d, enter a number:  ", player);
        scanf("%d", &choice); // get choice

        char choiceChar = choice + '0'; // convert int to char

        if (player == 1)
            mark = 'X';
        else
            mark = 'O';

        if (choiceChar == board[choice]) // check if field is already occupied
        {
            board[choice] = mark;
        }
        else
        {
            char ch[10];
            printf("Invalid move!\n");
            player--;
            getchar();
            getchar(); // we're calling getchar twice, due to an issue with scanf
        }

        i = checkIfWon();
        player++;

    } while (i == -1);

    drawBoard();

    if (i == 1)
    {
        printf("Player %d won!\n", --player); // we need to substract 1 from player
    }
    else
    {
        printf("Game draw!\n");
    }
    getchar();
}

void drawBoard()
{
    clearScreen();
    printf("\n");
    printf("|%c|%c|%c|\n", board[1], board[2], board[3]);
    printf("\n");
    printf("|%c|%c|%c|\n", board[4], board[5], board[6]);
    printf("\n");
    printf("|%c|%c|%c|\n", board[7], board[8], board[9]);
    printf("\n");
}

int checkIfWon()
{
    if (board[1] == board[2] && board[2] == board[3])
        return 1;
    else if (board[4] == board[5] && board[5] == board[6])
        return 1;
    else if (board[7] == board[8] && board[8] == board[9])
        return 1;
    else if (board[1] == board[4] && board[4] == board[7])
        return 1;
    else if (board[2] == board[5] && board[5] == board[8])
        return 1;
    else if (board[3] == board[6] && board[6] == board[9])
        return 1;
    else if (board[1] == board[5] && board[5] == board[9])
        return 1;
    else if (board[3] == board[5] && board[5] == board[7])
        return 1;
    
    char arr[] = "X";
    int i;
    for (i = 1; i < 9; i++) // draw check
    {
        int field;
        arr[0] = board[i];
        field = atoi(arr);
        if (i != field){
            continue;
        }  
        else{
            break;
        }
    }
    if (i == 9)  // all of the values are different, draw
        return 0;
    return -1; // win check failed, still playing
}
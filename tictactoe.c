#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
char COMPUTER = 'X';
char PLAYER = 'O';
char player1;
char player2;

char board[3][3];

void reset_board();
void print_board();
void player_move();
int check_space();
void computer_move();
char check_winner();
void print_winner();
void vs_computer();
void multi_player();
void player_moves();
void print_winners();
void computer_first_move();
void player_first_move();
void help();

int main()
{
    char response;

    do
    {
        system("clear");
        printf("- single player\n- multiplayer\n- exit\n- help\n\n->");
        fflush(stdin);
        scanf(" %c",&response);

        response = tolower(response);
        system("clear");

        if(response=='s')
        {
            vs_computer();
        }

        else if(response == 'm')
        {
            multi_player();
        }
        else if( response == 'e' )
        {
            break;
        }
        else if(response == 'h')
        {
            help();
        }
        else
        {
            printf("Invalid input\n");
        }
    }while (response != 'e');

        printf("\n");
        printf("Thank you for playing\n\n");
}

void reset_board()
{
    for(int i = 0 ; i<3; i++)
    {
        for(int j = 0 ; j < 3 ; j++ )
        {
            board[i][j]=' ';
        }
    }
}

void print_board()
{
    printf("\n");
    printf("         ||         ||         \n");
    printf("    %c    ||    %c    ||    %c    \n",board[0][0],board[0][1],board[0][2]);
    printf("---------||---------||--------\n");

    printf("         ||         ||         \n");
    printf("    %c    ||    %c    ||    %c    \n",board[1][0],board[1][1],board[1][2]);
    printf("         ||         ||         \n");
    printf("---------||---------||--------\n");

    printf("         ||         ||         \n");
    printf("    %c    ||    %c    ||    %c    \n",board[2][0],board[2][1],board[2][2]);
}

void player_move()
{
        int row,col;

        printf("\n");

        printf("\t-YOUR MOVE-");
        printf("\n");
        do
        {
            printf("Enter row number : ");
            scanf("%d" , &row);
            row--;

            printf("Enter col number : ");
            scanf("%d", &col);
            col--;

        } while(board[row][col] != ' ');

        board[row][col]= PLAYER ;
        system("clear");
        print_board();

}

int check_space()
{
    int gap = 9;

    for(int i =0 ; i < 3 ; i++)
    {
        for( int j = 0 ; j < 3 ; j++)
        {
            if(board[i][j] != ' ')
            {
                gap--;
            }
        }
    }
    return gap;
}


void computer_move()
{
    srand(time(NULL));

        int row,col;


        do
        {
            row = rand() % 3;
            col = rand() % 3;

        } while(board[row][col] != ' ');

        system("clear");

        board[row][col]=COMPUTER;
        print_board();


}

char check_winner()
{
    char a = ' ';

    for(int i = 0 ; i < 3 ; i++ )
    {
        if(board[0][i]==board[1][i] && board[0][i]==board[2][i])
        {
            return board[0][i];
        }

        else if(board[i][0]==board[i][1] && board[i][0]==board[i][2])
        {
            return board[i][0];
        }
    }

    if(board[0][0]==board[1][1] && board[0][0]==board[2][2])
    {
        return board[0][0];
    }

    else if(board[0][2]==board[1][1] && board[0][2]==board[2][0])
    {
        return board[0][2];
    }
    else
    {
        return ' ';
    }
}

void print_winner()
{
    char winner = check_winner();

    if( winner == PLAYER )
    {
        printf("\n\n\tYou won!!\n\n");
    }
    else if (winner == COMPUTER)
    {
        printf("\n\n\tYou lost :( \n\n");
    }
    else
    {
        printf("\n\n\tIt's a tie.\n\n");
    }
}


void vs_computer()
{
    char response;
    srand(time(NULL));
    int i;

    do
    {

        printf("Choose your icon (X/Y) : ");
        scanf(" %c",&response);

        response = toupper(response);

        if(response == 'E')
        {
            return;
        }

    }while(response!='X' && response!='O');

    if(response=='X')
    {
        PLAYER = 'X';
        COMPUTER = 'O';
    }

    else if (response == 'O')
    {
        PLAYER = 'O';
        COMPUTER = 'X';
    }

    system("clear");

    do
    {
        i=rand()%2;
        reset_board();
        print_board();

        if(i==0)
        {
            player_first_move();
        }
        else
        {
            computer_first_move();
        }

        do
        {
            printf("Want to play again?(Y/N) - ");
            scanf(" %c",&response);
            response=toupper(response);

            if(response!='Y'&&response!='N')
            {
                printf("Invalid input\n");
            }

         } while(response!='Y'&&response!='N');

    }while(response == 'Y');
}

void multi_player()
{
    char response;

    do
    {
        printf("Enter player 1 symbol (X/Y) : ");
        scanf(" %c", &player1);
        player1 = toupper(player1);

        if(player1=='E')
        {
            return;
        }
        if( player1 == 'X')
        {
            player2 = 'O';
            break;
        }
        if(player1 == 'O')
        {
            player2 = 'X';
            break;
        }

        system("clear");
        printf("Invalid Input\n\n");

    } while(1);

    do
        {
            reset_board();

            do
            {
                player_moves();


            } while (check_winner()==' ' && check_space() > 0 );

            print_winners();
            printf("\n");
            printf("Want to play again?(Y/N) - ");
            scanf(" %c",&response);
            response = toupper(response);

        }while(response == 'Y');


}

void player_moves()
{
        static int x;

        if(check_space()==9)
        {
            x = rand()%2 +1;
        }

        int row,col;

        printf("\n");

        if(x%2 == 0)
        {

            if(check_winner()==' ' && check_space() != 0 )
            {
                printf("\t-PLAYER 1 TURN-");
                printf("\n");
                do
                {
                    print_board();

                    printf("\nEnter row number : ");
                    scanf("%d" , &row);
                    row--;

                    printf("Enter col number : ");
                    scanf("%d", &col);
                    col--;

                    system("clear");

                } while(board[row][col] != ' '&&check_winner() == ' ');

                board[row][col]=  player1 ;
                system("clear");
            }
            else if(check_winner()!=' ')
            {
                return;
            }
        }
        else
        {
            if(check_winner()==' ' && check_space() != 0 )
            {
                printf("\t-PLAYER 2 TURN-");
                printf("\n");

                do
                {
                    print_board();

                    printf("\nEnter row number : ");
                    scanf(" %d",&row);
                    row--;

                    printf("Enter col number : ");
                    scanf(" %d",&col);
                    col--;
                    system("clear");

                } while(board[row][col] != ' ');

                board[row][col]=  player2 ;
            }
            else if(check_winner()!=' ')
            {
                return;
            }
        }

        x++;

}


void print_winners()
{
    char winner = check_winner();

    if( winner == player1)
    {
        printf("\nPlayer 1 won!!\n");
    }
    else if (winner == player2)
    {
        printf("\nPlayer 2 won!! \n");
    }
    else
    {
        printf("\nIt's a tie.\n");
    }
}

void computer_first_move()
{
    system("clear");
    reset_board();
    print_board();

    while(1)
    {
        computer_move();
        if(check_winner() == 'X'||check_space()==0)
        {
            print_winner();
            return;
        }
        system("clear");
        print_board();
        player_move();

        if(check_winner() == 'O'||check_space()==0)
        {
            print_winner();
            return;
        }

    }

}

void player_first_move()
{
    system("clear");
    reset_board();
    print_board();

    while(1)
    {
        player_move();

        if(check_winner() == 'O'||check_space()==0)
        {
            print_winner();
            return;
        }

        computer_move();

        if(check_winner() == 'X'||check_space()==0)
        {
            print_winner();
            return;
        }

    }

}

void help()
{
    char response;
    int j=1;

    printf("1.The game is played on a grid that's 3 squares by 3 squares.\n");
    printf("2.Suppose you are X , your friend or the computer is O . Players take turns putting their marks in empty squares.\n");
    printf("3.The first player to get 3 of her marks in a row (up, down, across, or diagonally) is the winner.\n");
    printf("4.When all 9 squares are full, the game is over. If no player has 3 marks in a row, the game ends in a tie.\n\n");
    printf("Winning conditions -> \n");

    for(int i = 0 ; i < 3 ; i++,j++ )
    {
        printf("%d :\n",j);
        reset_board();
        board[0][i]=board[1][i]=board[2][i] = 'X';
        print_board();

        printf("\n");

    }

    for(int i = 0 ; i < 3 ; i++,j++)
    {
        printf("%d :\n",j);
        reset_board();
        board[i][0]=board[i][1]=board[i][2]='X';
        print_board();

        printf("\n");
    }

    j++;
    printf("%d :\n",j);
    reset_board();
    board[0][0]=board[1][1]=board[2][2]='X';
    print_board();

    printf("\n");

    j++;
    printf("%d :\n",j);
    reset_board();
    board[0][2]=board[1][1]=board[2][0]='X';
    print_board();

    printf("\n");

    while(1)
    {
        printf("Inpt \"H\"  ");
        scanf(" %c",&response);
        if(response=='e')
        {
            return;
        }
    }


}

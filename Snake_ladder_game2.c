#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int roll_dice();
int move_player(int,int);
void print_board(int,int,int,int);
int new_position1=0,new_position2=0;
void main()
{
    printf("--------------------------------------------------------------------------------\n");
    printf("                |:-) |:-) WELCOME TO SNAKE AND LADDER GAME |:-) |:-)            \n");
    printf("--------------------------------------------------------------------------------\n");
    int roll,player=1,loop=0;
    while(!loop)
    {
        if(player==1)
        {
            printf("Press enter key to roll a dice:");
            getchar();
            roll=roll_dice();
            new_position1=move_player(roll,player);
            print_board(new_position1,new_position2,player,player+1);
            if(new_position1==100)
            {
                printf("Player%d won\n\n",player);
                printf("HOPE YOU ENJOYED THE GAME |:-)\n");
                printf("THANK YOU |:-)\n");
                printf("--------------------------------------------------------------------------------\n");
                loop=1;
            }
            player=(player==1)?2:1;
        }
        else
        {
            printf("Press enter key to roll a dice:");
            getchar();
            roll=roll_dice();
            new_position2=move_player(roll,player);
            print_board(new_position2,new_position1,player,player-1);
            if(new_position2==100)
            {
                printf("Player%d won\n\n",player);
                printf("HOPE YOU ENJOYED THE GAME |:-)\n");
                printf("THANK YOU |:-)\n");
                printf("--------------------------------------------------------------------------------\n");
                loop=1;
            }
            player=(player==2)?1:2;
        }
    }
}
int roll_dice()
{
    int value;
    srand(time(NULL));
    value=rand()%6+1;
    return value;
}
int move_player(int dice_top,int current_player)
{
    if(current_player==1)
    {
        printf("%d comes for player %d\n",dice_top,current_player);
        if((new_position1+dice_top)>100)
        {
            return new_position1;
        }
        new_position1=new_position1+dice_top;
        if(new_position1==99)
        {
            new_position1=1;
        }
        if(new_position1==65)
        {
            new_position1=40;
        }
        if(new_position1==25)
        {
            new_position1=9;
        }
        if(new_position1==70)
        {
            new_position1=93;
        }
        if(new_position1==60)
        {
            new_position1=83;
        }
        if(new_position1==13)
        {
            new_position1=42;
        }
        return new_position1;
    }
    if(current_player==2)
    {
        printf("%d comes for player %d\n",dice_top,current_player);
        if((new_position2+dice_top)>100)
        {
            return new_position2;
        }
        new_position2=new_position2+dice_top;
        if(new_position2==99)
        {
            new_position2=1;
        }
        if(new_position2==65)
        {
            new_position2=40;
        }
        if(new_position2==25)
        {
            new_position2=9;
        }
        if(new_position2==70)
        {
            new_position2=93;
        }
        if(new_position2==60)
        {
            new_position2=83;
        }
        if(new_position2==13)
        {
            new_position2=42;
        }
        return new_position2;
    }
}
    
void print_board(int new_pos1,int new_pos2,int current_player1,int current_player2)
{
    int control=0,num_print=100;
    int snake_ladder[100],i;
    for(i=1;i<=100;i++)
    {
        snake_ladder[i]=i;
    }
    for(int i=1;i<=10;i++)
    {
        if(i==10)
        {
            for(int j=1;j<=10;j++)
            {
                if((snake_ladder[num_print]==new_pos1)&&(snake_ladder[num_print]==new_pos2)&&(new_pos1==new_pos2))
                    printf("#pb\t ");
                else if(snake_ladder[num_print]==new_pos1)
                    printf("#P%d\t ",current_player1);
                else if(snake_ladder[num_print]==new_pos2)
                    printf("#P%d\t ",current_player2);
                else
                    printf("%d\t ",num_print);
                num_print++;;
            }
            num_print-=11;
            printf("\n");
        }
        else
        {
            if(i%2==0)
            {
                for(int j=1;j<=10;j++)
                {
                    if((snake_ladder[num_print]==new_pos1)&&(snake_ladder[num_print]==new_pos2)&&(new_pos1==new_pos2))
                        printf("#pb\t");
                    else if(snake_ladder[num_print]==new_pos1)
                        printf("#P%d\t",current_player1);
                    else if(snake_ladder[num_print]==new_pos2)
                        printf("#P%d\t",current_player2);
                    else
                        printf("%d\t",num_print);
                    num_print++;;
                }
                num_print-=11;
                printf("\n");
            }
            else
            {
                for(int j=1;j<=10;j++)
                {
                    if((snake_ladder[num_print]==new_pos1)&&(snake_ladder[num_print]==new_pos2)&&(new_pos1==new_pos2))
                        printf("#pb\t");
                    else if(snake_ladder[num_print]==new_pos1)
                        printf("#P%d\t",current_player1);
                    else if(snake_ladder[num_print]==new_pos2)
                        printf("#P%d\t",current_player2);
                    else
                        printf("%d\t",num_print);
                    num_print--;
                }
                num_print-=9;
                printf("\n");
            }
        }
        
     }
}
#include<conio.h>
#include<stdio.h>
#include<windows.h>
#include<time.h>
void gotoxy(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

struct snake
{
    int x;
    int y;
};
typedef struct snake snake;



int main()
{

gotoxy(32,3);
printf("%c INTRUCTIONS %c\n\n",15,15);

printf("\t\t     %c Press the arrow keys to take a term.\n\n\n",26);

printf("\t\t\t\t      up\n \t\t\t\t      %c\n\n",30);
printf("\t\t\t      Left %c     %c Right\n\n",17,16);
printf("\t\t\t\t      %c \n \t\t\t\t    Down",31);
printf("\n\n\n\t\t     %c Press SPACE bar to pause the game.",26);
printf("\n\n\n\t\t      I hope you like this, Thank You...");
printf("\n\n\n\t\t\t\t\t\t\t  %c Vaitul Bhayani",1);

getch();



/*****************Functions*********************/
register   int x=20,y=10;
register int i=1,l=3,life=3;
int speed=135,level=1,xl,yl,score;
char dir;
snake snk[1794];
void printsnk()
{
    for(i=1;i<=l;i++)
    {
        gotoxy(snk[i].x,snk[i].y);
        if(i==1)
            printf("%c",2);
        else if(i==l)
            printf("%c",4);
        else
            printf("%c",4);
    }
}
void generateT()
{
        //Generating target
    srand(time(0));
    x=rand()%76+2;
    y=rand()%19+4;
    l++;
}
void lifeOver(void)
{
    life--;
        if(life<0)
        {
            system("cls");
            gotoxy(33,8);
            printf("GAME OVER !!! \n\n \t\t\t\t  \n\n\n \t\t\t\t   Thanks.. \n\n\n\n\n \t\t\t    (Press any key to exit)");
            getch();
            printf("\n\n\n");
            exit(0);
        }
        l=3;
        snk[1].x=33;
        snk[1].y=11;
}

/**************************************/

   for(i=1;i<=l;i++)
    {
        gotoxy(x+i,y);
        snk[i].x=x+i;
        snk[i].y=y;
        printf("%c",176);
    }
    while(1){
    system("cls");

    score = (l-3)*2;

    gotoxy(5,1);
    printf("THE SNAKE GAME \t\t\t\t\tSCORE : %d   LIFE : %d ",score,life);

    gotoxy(10,24);
    printf("\t\t\t\t\t       A GAME BY VAITUL BHAYANI");

    if(snk[1].x==78 || snk[1].x==1 || snk[1].y==3 || snk[1].y==23)
        lifeOver();
    for(i=3;i<=l;i++)
    {
        if(snk[1].x==snk[i].x && snk[1].y==snk[i].y)
        {
            lifeOver();
            break;
        }
    }

    //drawing lines ,borders
    gotoxy(1,3);
    for(i=1;i<=78;i++)  //AB 1 to 78
        printf("%c",196);

    gotoxy(1,23);
    for(i=1;i<=78;i++)  //CD 1 to 78
        printf("%c",196);

    gotoxy(0,4);
    for(i=3;i<=21;i++)       //AC & BD 4 to 21
        printf(" %c\t\t\t\t\t\t\t\t\t      %c\n",179,179);

    gotoxy(1,3);
    printf("%c",218);
    gotoxy(78,3);
    printf("%c",191);
    gotoxy(78,23);
    printf("%c",217);
    gotoxy(1,23);
    printf("%c",192);


    if(snk[1].x==x && snk[1].y==y)
        generateT();
    gotoxy(x,y);
    printf("%c",4);

    printsnk();

    if(kbhit())
    {
        switch(getch())
        {
            case 72:  //UP
                if(dir!='d'){
                dir='u';
                for(i=l;i>1;i--)
                    snk[i]=snk[i-1];
               // snk[1].x=x;
                snk[1].y=snk[1].y-1;
                }
                printsnk();
                break;

            case 80:  //DOWN
                if(dir!='u'){
                dir='d';
                for(i=l;i>1;i--)
                    snk[i]=snk[i-1];
               // snk[1].x=x;
                snk[1].y=snk[1].y+1;
                }
                printsnk();
                break;

            case 75:  //LEFT
            if(dir!='r'){
                dir='l';
                for(i=l;i>1;i--)
                    snk[i]=snk[i-1];
               // snk[1].x=x;
                snk[1].x=snk[1].x-1;
            }
                printsnk();
                break;

            case 77:  //RIGHT
                if(dir!='l'){
                dir='r';
                for(i=l;i>1;i--)
                    snk[i]=snk[i-1];
               // snk[1].x=x;
                snk[1].x=snk[1].x+1;
                }
                printsnk();
                break;
            case 32:
                gotoxy(32,20);
                printf("Game Paused.");
                getch();
        }
    }
    else
    {
        Sleep(speed);
        switch(dir)
        {
            case 'u':
                for(i=l;i>1;i--)
                    snk[i]=snk[i-1];
               // snk[1].x=x;
                snk[1].y=snk[1].y-1;
                printsnk();
            break;

            case 'd':
                 for(i=l;i>1;i--)
                    snk[i]=snk[i-1];
               // snk[1].x=x;
                snk[1].y=snk[1].y+1;
                printsnk();
            break;

            case 'l':
                for(i=l;i>1;i--)
                    snk[i]=snk[i-1];
               // snk[1].x=x;
                snk[1].x=snk[1].x-1;
                printsnk();
            break;

            case 'r':
                for(i=l;i>1;i--)
                    snk[i]=snk[i-1];
               // snk[1].x=x;
                snk[1].x=snk[1].x+1;
                printsnk();
            break;

        }
    }
    }
}

#include<conio.h>
#include<stdio.h>
int l=4,i,score=0,life=3,tarX,tarY;
struct snkpos
{
	int x;
	int y;
};
struct snkpos snkpos[1500];
void start();
void ptsnk()
{
	for(i=l-1;i>=0;i--)
	{
		gotoxy(snkpos[i].x,snkpos[i].y);
		if(i==0)
		  printf("%c",2);
		else
		  printf("%c",4);
	}
}
void interchange()
{
	gotoxy(snkpos[l-1].x,snkpos[l-1].y);
	printf(" ");
	for(i=l-1;i>0;i--)
	{
		snkpos[i] = snkpos[i-1];
	}
	gotoxy(snkpos[0].x,snkpos[0].y);
}
void ptFrame()
{
    int x=2, y=2, w=75, h=22;
    gotoxy(1,1);
    printf("  %c The Snake Game \t\t\t\t  %c Score : %.3d   %c Life : %d",5,2,score,3,life);
    gotoxy(x+0,y+0);
    printf("%c",218);//top left corner
    for(i=1;i<=h;i++)
    {
	gotoxy(x+0,y+i);
	printf("%c",179);// |
    }
    gotoxy(x+0,y+1+h);
    printf("%c",192);//bottom left corner
    gotoxy(x+1,y+0);

    for(i=1;i<=1+w;i++)
	printf("%c",196);// -

    printf("%c",191);//top right corner

    for(i=1;i<=h;i++)
    {
	gotoxy(x+2+w,y+i);
	printf("%c",179);// |
    }

    gotoxy(x+1,y+1+h);
    for(i=1;i<=1+w;i++)
	printf("%c",196);// -
    printf("%c",217);//bottom right corner
}
void animatedWord(int x,int y,char  tmp[],int F,int speed)
{
    gotoxy(x,y);
    for(i=0;tmp[i]!='\0';i++)
    {
	delay(speed);
	if(F)
	    printf("%c", tmp[i]);
	else
	    printf(" ");
    }
}
void welcome()
{
	char arr[20];
	for(i=0;i<=23;i++)
	  arr[i]=176;
	animatedWord(29,10," Vaitul Bhayani Presents ",1,20);
	animatedWord(34,12,"The Snake Game",1,20);delay(500);
	gotoxy(37,18);printf("Loading..");
	animatedWord(29,20,arr,1,100);delay(1000);

	gotoxy(29,10);printf("                        ");
	gotoxy(29,12);printf("                        ");
	gotoxy(28,18);printf("                         ");
	gotoxy(28,20);printf("                         ");
	ptFrame();
	animatedWord(28,12,"Game Starts In 3 Seconds ",1,20);delay(800);
	animatedWord(28,12,"Game Starts In 2 Seconds ",1,20);delay(800);
	animatedWord(28,12,"Game Starts In 1 Seconds ",1,20);delay(800);
	animatedWord(28,12,"Game Starts In 0 Seconds ",1,20);delay(100);
	gotoxy(28,12);printf("                        ");delay(0);
	start();
}
void generate()
{
	srand(time(0));
	tarX=rand()%75+3;
	tarY=rand()%22+3;
}
int flag=0;
void check()
{
	if(life!=-1)
	{
		if(tarX==snkpos[0].x&&tarY==snkpos[0].y)
		{
			l++;
			score = score + 5;
			ptFrame();
			generate();
		}
		if( snkpos[0].y<=2 || snkpos[0].y>=25 || snkpos[0].x<=2 || snkpos[0].x>=79)
		{
			flag=1;
		}
		else
		{
		      for(i=l-1;i>0;i--)
			{
				if(snkpos[i].x==snkpos[0].x && snkpos[i].y==snkpos[0].y)
				{
					flag=1;
					break;
				}
			}
		}
		if(flag==1)
		{
			flag=0;
			life--;
			l = 4;
			gotoxy(38,12);
			printf("OOPS !!!");
			delay(1500);
			clrscr();
			start();
		}
	}
	else
	{
		life=0;
		clrscr();
		ptFrame();
		animatedWord(30,12,"Game Over, Score : ",1,100);printf("%d",score);
		getch();
		exit();
	}
}
void start()
{
	int ch;
	char dir='r';
	ptFrame();
	generate();
	for(i=l-1;i>=0;i--)
	{
		snkpos[i].x=10-i;
		snkpos[i].y=10;
	}
	ptsnk();
	while(1)
	{

		gotoxy(tarX,tarY);
		printf("%c",3);
		if(kbhit())
		{
			ch = getch();
			if(!((dir=='u'&&ch==80) || (dir=='d'&&ch==72) || (dir=='l'&&ch==77) || (dir=='r'&&ch==75)))
			switch(ch)
			{
				case 72: //up
				  interchange();
				  snkpos[0].y--;
				  dir = 'u';
				  break;
				case 80: //down
				  interchange();
				  snkpos[0].y++;
				  dir = 'd';
				  break;
				case 75: //left
				  interchange();
				  snkpos[0].x--;
				  dir = 'l';
				  break;
				case 77: //right
				  interchange();
				  snkpos[0].x++;
				  dir = 'r';
				  break;
				case 27:
				  clrscr();
				  exit(0);
				case 32:
				  gotoxy(38,12);
				  printf("PAUSED");
				  getch();
				  gotoxy(38,12);
				  printf("      ");
			}
		}
		else
		{
			switch(dir)
			{
				case 'u': //up
				  interchange();
				  snkpos[0].y--;
				  break;
				case 'd': //down
				  interchange();
				  snkpos[0].y++;
				  break;
				case 'l': //left
				  interchange();
				  snkpos[0].x--;
				  break;
				case 'r': //right
				  interchange();
				  snkpos[0].x++;
				  break;
			}
			if(dir=='u' || dir=='d')
				delay(180);
			else
				delay(150);
		}
		ptsnk();
		check();
	}
}
void main()
{
	clrscr();
	welcome();
	getch();
}
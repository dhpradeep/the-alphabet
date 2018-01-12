 #include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include "rectangle.h"
int xco=50, yco=10;
int score;
char name[20];
int highscore=0;
struct player
{
	char name[20];
	int score;
}p;

FILE *fp1;

//user define function
void welcome(void); //for welcome page
void new_game(void); //for gaming platform
void charbox(int,int,int); //for print character within box
void displayscore(int,char[20]);//final score print
void main_menu(void); //for menu page
void instruction(void); // for instruction page
void about_us(void); //about us
void end(void); //exit program with ending message
void rect(int,int,int,int); //for rectangle 


int main()
{
 fullscreen ();  //for start program with fullscreen 
 welcome(); //welcome function call
 return 0;

}

//menu page
void main_menu()
{
	do{
	system("cls");
	int num;
   rect(xco,xco+80,yco,yco+20);
   gotoxy(65+xco,2+yco);	printf("%s",__DATE__);
   gotoxy(35+xco,8+yco); 	printf("---------");
   gotoxy(35+xco,9+yco); 	printf("MAIN MENU");
   gotoxy(35+xco,10+yco);   printf("---------");
   gotoxy(35+xco,11+yco);	printf("1. NEW GAME\n");
   gotoxy(35+xco,12+yco);   printf("2. INSTRUCTION\n");
   gotoxy(35+xco,13+yco);   printf("3. ABOUT US\n");
   gotoxy(35+xco,14+yco);   printf("4. EXIT");

  	num = getch();

   switch(num-48)
   {
    case 1:
    system("cls");
    rect(xco-5,xco+80,yco-2,yco+20);
    gotoxy(65+xco,2+yco);	printf("%s",__DATE__);
  	gotoxy(20+xco,7+yco);	printf("Enter your name:\t");
  		//scanf("%s",name);
      gets(name);
    	new_game();
      break;
    case 2:
    	instruction();  //function call
     	 break;
    case 3:
    	about_us();    //function call
    	break;
    case 4:
    	end();
    	break;
    }
    }while(1);
}

//for game platform
void new_game()
{
	if((fp1=fopen("ever.soft","r"))==NULL)
	{
		highscore=0;
		fclose(fp1);
		fp1=fopen("ever.soft","w");
		fclose(fp1);
	}
	else
	{
		while(fread(&p,sizeof(p),1,fp1)==1)
		{
			if(p.score>highscore)
			highscore=p.score;
		}
	}
	int life=4; 
	score=0;
	next:
	do
	{
		int i; int ch=rand()%(/*112*/90+1-65)+65;
        int hspace=rand()%(75+1-1)+1;
      //int speed=rand()%(10)+1;

	for(i=3;i<26;i++)
   	{  if(kbhit())
      	{
         	if(getch()==ch+32)
            	{
                  score++;
                  goto next;
               }
         }
          system("cls");
        
         charbox(hspace,i,ch);

        // gotoxy(hspace,i); printf("%c",ch);
         gotoxy(1+xco,1+yco); 	 printf("%s",name);
         gotoxy(20+xco,1+yco);   printf("SCORE = %d",score);
         gotoxy(42+xco,1+yco);
         				switch(life)
                     {
                     	case 4: printf("LIFE = %c %c %c",3,3,3); break;
                        case 3: printf("LIFE = %c %c",3,3);break;
                        case 2: printf("LIFE = %c",3); break;
                        case 1: printf("LIFE =\n");break;
                     }
         gotoxy(65+xco,1+yco); printf("HIGH SCORE = %d",highscore);
        	gotoxy(xco+1,2+yco);

         printf("-------------------------------------------------------------------------------");
         	gotoxy(xco,27+yco);

         printf("________________________________________________________________________________");
         
      	Sleep(700-score*10);
   	}
      life--;

		if (life==3)
      Beep(900,700);
      else if(life==2)
      Beep(900,700);
      else if (life==1)
      Beep(900,700);
      else if(life==0)
      Beep(900,700);

      if(life==0)
      {	
      	strcpy(p.name,name);
      	p.score=score;
      	fp1=fopen("ever.soft","a+");
      	fwrite(&p,sizeof(p),1,fp1);
      	fclose(fp1);
      	displayscore(score,name);
      }else goto next;
   }while(0);
}

//for about us page
void instruction()
{/*
	do{
	   system("cls");
	    int i,j;
		for (i=20;i>10;i--)
		{
			Sleep(700);
			gotoxy(10,i);
			printf("                                                                                                    ");
			gotoxy(30+xco,i-10);
			printf(" The Alphabet                                                                                        ");
			gotoxy(3+xco,i-9);
			printf("Info & Customer Care http:://www.eversoft.com.np                                                      ");
			gotoxy(3+xco,i-8);
			printf("  1.Player should type the same character in keyboard which falls on game interface.                  ");
			gotoxy(3+xco,i-7);
			printf("                                                                                                      ");
			gotoxy(3+xco,i-6);
			printf("   2.This game only save single word so user should entered single word.                               ");
			gotoxy(3+xco,i-5);
			printf("                                                                                                      ");
			printf(" 	3.Every time you enter correct word the score will increase.                                      "); 
			}
         getch();
         main_menu();
         */
         
         
         	do{
	   system("cls");
	    int i,j;
		for (i=20;i>10;i--)
		{
			Sleep(700);
			gotoxy(10,i);
			printf("                                               ");
			gotoxy(30+xco,i-10);
			printf(" The Alphabet                                   ");
			gotoxy(3+xco,i-9);
			printf("Info & Customer Care http:://www.eversoft.com.np ");
			gotoxy(3+xco,i-8);
			printf(" 1.Player should type the same character in keyboard which falls on game interface.             ");
			gotoxy(3+xco,i-7);
			printf("                                                                                              ");
			gotoxy(3+xco,i-6);
			printf("                                                                                     ");
			gotoxy(3+xco,i-5);
			printf(" 2.This game only save single word so user should entered single word.                   ");
			gotoxy(3+xco,i-4);
			printf("                                                                                ");
			gotoxy(3+xco,i-3);
			printf("                                                                                   ");
			gotoxy(3+xco,i-2);
			printf(" 3.Every time you enter correct word the score will increase.                     ");
			gotoxy(3+xco,i-1);
			printf("                                                                          ");
			gotoxy(3+xco,i-0);
			printf("                                                                              ");
			gotoxy(3+xco,i+1);
			printf("                                                                                   ");
			gotoxy(3+xco,i+2);
			printf("                                                       ");
			gotoxy(3+xco,i+3);
			printf("                                                       ");
			gotoxy(3+xco,i+4);
			printf("                                                        ");
			}
         getch();
         main_menu();
    }while(1);
}

 //for making character and border
void charbox(int x, int y, int c)
{
	drawrectangle(x+xco,y+yco,5,3,178);

   gotoxy(x+2+xco,y+1+yco); printf("%c",c);

}

//ending message and page
void displayscore(int sc,char name[20])
{
	
	char ch;
	do{
   	system("cls");
   	rect(xco,xco+80,yco-2,yco+27);
   	if(sc>highscore)
	{gotoxy(xco+10,yco+2); printf("congrats %s ! You beat the High Score.",name);}
	else{
	printf("");	
	}
   gotoxy(11+xco,11+yco); printf("GAME OVER. BETTER LUCK NEXT TIME %c",1);
   gotoxy(18+xco,12+yco); printf("YOUR SCORE => %d",sc);
   Sleep(500);
   gotoxy(11+xco,13+yco); printf("Do you want to play again(y/n)?");

   ch=getch();
   if(ch=='Y'||ch=='y')
   {
    Sleep(300);
   	new_game();
   }
   else if(ch=='N'||ch=='n')
   {
    main_menu();
   }else{
    continue;
   }
   }while(ch!=27);
}




//for instruction page
void about_us()
{
	do{
	   system("cls");
	    int i,j;
		for (i=20;i>10;i--)
		{
			Sleep(700);
			gotoxy(10,i);
			printf("                                               ");
			gotoxy(30+xco,i-10);
			printf(" The Alphabet                                   ");
			gotoxy(3+xco,i-9);
			printf("Info & Customer Care http:://www.eversoft.com.np ");
			gotoxy(3+xco,i-8);
			printf("      eversoft.nepal@gmail.com                   ");
			gotoxy(3+xco,i-7);
			printf("                                             ");
			gotoxy(3+xco,i-6);
			printf(" >>> PROGRAMMER AND CODER <<< ");
			gotoxy(3+xco,i-5);
			printf(" Oscar,pravhu,pradip,pradeep                 ");
			gotoxy(3+xco,i-4);
			printf("                                              ");
			gotoxy(3+xco,i-3);
			printf(" >>> GAME DESIGNER AND DOCUMENATION <<<  ");
			gotoxy(3+xco,i-2);
			printf(" \t \t EVERSOFT GROUP                       ");
			gotoxy(3+xco,i-1);
			printf("                                               ");
			gotoxy(3+xco,i-0);
			printf(" Inspired by Mr. PRADEEP KARKI Sir");
			gotoxy(3+xco,i+1);
			printf("Powered by LA GRANDEE Int College & POKHARA UNIVERSITY ");
			gotoxy(3+xco,i+2);
			printf("                                                       ");
			gotoxy(3+xco,i+3);
			printf("    THANK YOU all of you for being the part of this :)");
			gotoxy(3+xco,i+4);
			printf("                                                        ");
			}
         getch();
         main_menu();
    }while(1);
}

//exit page
void end()
{
	int i;
	system("cls");
  	char ever[]="THANK YOU FOR USING THIS PROGRAM!!!!";
    for(i=0;i<strlen(ever);i++)
	{
  	gotoxy(15+i+xco,8+yco); printf("%c",ever[i]);
   }
	for(i=0;i<strlen(ever)/2;i++)
	{
  	  Sleep(100*2); gotoxy(15+i*2+xco,9+yco); printf("%c",3);
	}
   Sleep(1000);
	exit(0);
}


//welcome page
void welcome()
{
	system("cls");
	//for 3 number line
	Sleep(130);gotoxy(5+xco,3+yco); printf(" ________");gotoxy(14+xco,3+yco); printf(" _ ");

//for 4 number line					
Sleep(130);gotoxy(5+xco,4+yco);printf("|___  ___|");gotoxy(15+xco,4+yco); printf(" |   ");

//for 5 number line					
Sleep(130);gotoxy(7+xco,5+yco); printf(" | |   ");gotoxy(13+xco,5+yco); printf(" | |   ");gotoxy(17+xco,5+yco); printf("____");gotoxy(24+xco,5+yco);printf("____");

//for 6 number line				 
Sleep(130);   
gotoxy(7+xco,6+yco);  printf(" | |   ");	
gotoxy(13+xco,6+yco); printf(" |    ");	
gotoxy(17+xco,6+yco); printf("___ \x5c");
gotoxy(23+xco,6+yco); printf("/");
gotoxy(28+xco,6+yco); printf("\x5c");
gotoxy(24+xco,6+yco); printf(" __");

//for 7 number line 
Sleep(130);gotoxy(7+xco,7+yco); printf(" | |   ");gotoxy(13+xco,7+yco); printf(" | |   ");gotoxy(20+xco,7+yco); printf("| |");gotoxy(23+xco,7+yco);printf("  ___/"); 

//for 8 number line 
Sleep(130);gotoxy(7+xco,8+yco); printf(" |_|   ");gotoxy(13+xco,8+yco); printf(" |_|   ");gotoxy(20+xco,8+yco); printf("|_|");gotoxy(23+xco,8+yco);printf("\x5c ___|");

//11 number line
Sleep(130);gotoxy(28+xco,11+yco); printf("_    ");gotoxy(37+xco,11+yco); printf("      _");gotoxy(57+xco,11+yco); printf("_");

//for 12 number line
Sleep(130);
gotoxy(8+xco,12+yco); printf("___");
gotoxy(16+xco,12+yco); printf("_");
gotoxy(19+xco,12+yco); printf("_____");
gotoxy(27+xco,12+yco); printf("| | ");
gotoxy(37+xco,12+yco); printf("     | |");
gotoxy(56+xco,12+yco); printf("| |__");

//for 13 number line
Sleep(130);
gotoxy(7+xco,13+yco); printf("/ _ \x5c"); 
gotoxy(15+xco,13+yco); printf("| |");
gotoxy(18+xco,13+yco); printf("|  __  \x5c");
gotoxy(27+xco,13+yco); printf("| |___ ");
gotoxy(37+xco,13+yco); printf(" __,_| |___");
gotoxy(50+xco,13+yco); printf("___");
gotoxy(56+xco,13+yco); printf("| ___|");

//for 14 number line
Sleep(130);
gotoxy(6+xco,14+yco); printf("/ /_\x5c \x5c");
gotoxy(15+xco,14+yco); printf("| |");
gotoxy(18+xco,14+yco); printf("| |__| |");
gotoxy(27+xco,14+yco); printf("|  __  \x5c ");
gotoxy(36+xco,14+yco); printf("/ __  |     \x5c ");
gotoxy(49+xco,14+yco); printf("/ __ \x5c");
gotoxy(56+xco,14+yco); printf("| |");

//for 15 number line
Sleep(130);
gotoxy(5+xco,15+yco); printf("/ /   \x5c \x5c");
gotoxy(15+xco,15+yco); printf("| |");
gotoxy(18+xco,15+yco); printf("|  ____/");
gotoxy(27+xco,15+yco); printf("| |   | |");
gotoxy(37+xco,15+yco); printf("(_ | | |)  |");
gotoxy(49+xco,15+yco); printf("  ___/");
gotoxy(56+xco,15+yco); printf("| |____");
gotoxy(15+xco,16+yco); printf("|_|");

//for 16 number line
Sleep(130);
gotoxy(4+xco,16+yco); printf("/_/     \x5c_\x5c");
gotoxy(18+xco,16+yco); printf("|_|");
gotoxy(27+xco,16+yco); printf("|_|   |_|");
gotoxy(36+xco,16+yco); printf("\x5c___,_| ____/ ");
gotoxy(49+xco,16+yco); printf("\x5c____|");
gotoxy(56+xco,16+yco); printf("\x5c_____| ");
 
 int i;
 char designer[]="Developed By EVERSOFT...";
 for(i=0;i<strlen(designer);i++)
 {Sleep(100); gotoxy(57+i+xco,25+yco); printf("%c",designer[i]);}Sleep(2000);
   main_menu();
}


void rect(int x1,int x2,int y1,int y2)
{
	int i,j;
	for (i=x1+1,j=0;i<x2;i++)
	{
		gotoxy(x1+1+j,y1);printf("_");
		j++;
	}
	for (i=y1+1,j=0;i<=y2;i++)
	{
		gotoxy(x1,y1+1+j);printf("|");
		j++;
	}
	for (i=x1+1,j=0;i<x2;i++)
	{
		gotoxy(x1+1+j,y2);printf("_");
		j++;
	}
	for (i=y1+1,j=0;i<=y2;i++)
	{
		gotoxy(x2,y1+1+j);printf("|");
		j++;
	}		
}

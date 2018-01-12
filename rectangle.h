#include <stdio.h>
#include <conio.h>
#include <windows.h>
//Global Variable:
COORD coordinate={0,0};
//Making a gotoxy function:
void gotoxy(int x,int y)
{
    coordinate.X=x;
    coordinate.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinate);
}

void drawrectangle(int x,int y,int l,int b,int c)
{
 char ltc,h,rtc,v,lbc,rbc;
 switch(c)
 {
 	case 0:
   	ltc = 218; h=196; rtc= 191;
      v = 179;
      lbc = 192; rbc = 217;
      break;
   case 1:
   	ltc = 201; h = 205; rtc = 187;
      v = 186;
      lbc = 200; rbc = 188;
      break;
 	default:
   ltc = h = lbc = rtc = v = rbc = c;
   }
   //rectangle start from here
   gotoxy(x,y); printf("%c",ltc); //print character at the top left
   int i;
   for (i=1; i<=l-2; i++)
   {
   	gotoxy(x+i,y); printf("%c",h);
   }
   gotoxy(x+i,y); printf("%c",rtc); //top right
   for (i=1; i<=b-2; i++)
   {
   	gotoxy(x,y+i); printf("%c",v); //vertical ine
      gotoxy(x+l-1,y+i); printf("%c",v);
   }
   gotoxy(x,y+b-1); printf("%c",lbc); //left bottom
   for(i=1; i<=l-2; i++)
   {
   	gotoxy(x+i,y+b-1); printf("%c",h);
   }
   gotoxy(x+l-1, y+b-1); printf("%c",rbc);
   gotoxy(x+1,y+1);
}

void fullscreen(void);
void gotoxy(int,int);

//Making a full screen console:
void fullscreen()
{
keybd_event(VK_MENU,0x38,0,0);
keybd_event(VK_RETURN,0x1c,0,0);
keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}






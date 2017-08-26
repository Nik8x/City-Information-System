//next is menu generator

int menu(int x , int y ,int max)
{
char T;
int j=3;
gotoxy(x-2,y);
cout<<"=>";
while(1)
{
display_time(1,3);
fflush(stdin);
T=getch();
switch(T)
{
case 87:
case 119:
case UP:
if(j==1)
{
gotoxy(10,20);
cout<<"Cannot go up  \n\n\t press any key";
getch();
}
else
{
gotoxy(x-2,y) ;
cout<<"  ";
y-=1;
j--;
gotoxy(x-2,y);
cout<<"=>";
}
break;
case 115:
case 83:
case down:
if(j==max)
{
gotoxy(10,20);
cout<<"Cannot go down\n\n\t press any key";
getch();
}
else
{
gotoxy(x-2,y) ;
cout<<"  ";
y+=1;
gotoxy(x-2,y);
cout<<"=>";
j++;
}
break;
case 97:
case 65:
case 75:
case Esc  :
return (0);
case 68:
case 100:
case 77:
case Enter:
return j;
}
}
}

//timer
time1 :: timer(int a,int b)
{
   time_t timer;
   struct tm *tblock;

   /* gets time of day */
   timer = time(NULL);

   /* converts date/time to a structure */
   tblock = localtime(&timer);
   gotoxy(a,b);
   cprintf("%s", asctime(tblock));

   return 0;
}


void display_time(int a,int b)
{
time1 tim;
tim.timer(a,b);
}

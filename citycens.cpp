/***************************************************************************
****************************************************************************
		    City Information System
****************************************************************************
****************************************************************************/
 #include "FUNC1.H"
long y;
int hi;
class informations
{
char sub[20],information[500];
long int d;
public:
void getinformation();
void putinformation();
int search();
void newinformation();
};


void informations :: getinformation()
{
cout<<"\n\tEnter CITY PIN No.: ";
cin>>d;
cout<<"\n\tEnter any city for the information : ";
gets(sub);
cout<<"\n\nPress any key to start typing the information.\nPress ENTER key when you have finished typing.\n\n";
getch();
clrscr();
gets(information);
}

void informations :: putinformation()
{
display_time(1,3);
cout<<"\n\tPIN : "<<d<<endl;
cout<<"\tCity : "<<sub<<endl<<endl;
cout<<"\t\tDetailed information of the CITY is : \n\n"<<"\t"<<information<<endl;
}

void informations :: newinformation()
{
ofstream san("information.sv",ios::out|ios::ate|ios::binary);
informations n;
n.getinformation();
y=n.d;
san.write((char*)&n, sizeof(n));
san.close();
}


int informations :: search()
{
informations n;
int a,b=0;
char c[20];
ifstream san("information.sv",ios::in|ios::binary);
san.seekg(0);
a=sizeof(n);
cout<<"\tEnter the city name: ";
gets(c);
while(san)
{
san.read((char*)&n, sizeof(n));
if(strcmpi(n.sub,c)==0)
{
clrscr();
gotoxy(15,23);
cout<<"Program by NIKET.";
y=n.d;
gotoxy(1,1);
n.putinformation();
san.close();
return (1);
}
else
{
b++;
san.seekg(a*b);
}
}
cout<<"\tDetails of this information are not available.\n";
y=3;
san.close();
return (0);
}
inline void refresh();
inline void onexit();
class temp
{
   protected:
     static int counter;
     struct person
       {
         int hno;
         float person_no;
         char name[40];
         char gender;
         char address[20];
       };
   public:
};
int temp ::  counter;
class person_Details : private temp
{
int recsize ;
person pho;
FILE *fp,*ft;
public:
friend void operator <<(ostream & nout ,person &p);
friend istream & operator >>(istream & nin ,person &p);
void modify_records() ;
void display_records();
void delete_records();
void add_records();
person_Details();
void options();
void search_records();
};

void person_Details :: add_records()
{
refresh();
ofstream file("person.dat",ios :: nocreate | ios :: ate | ios :: binary );
cin>>pho;
cout<<pho;
cout<<"\n\n  Is this the correct details(Y/N)?: ";
getch();
file.seekp(0,ios :: end);
file.write ((char *) &pho, sizeof(pho));
fclose(fp);
}

void person_Details :: search_records()
{
ifstream file("person.dat", ios :: out | ios :: nocreate | ios :: binary );
file.seekg(0,ios :: beg);
int count=0;
refresh();
cout<<"  Enter the House no:";
int temp_hno;
cin>>temp_hno;
while(file.read((char *) &pho.hno,2))
{
if(temp_hno == pho.hno)
{
cout<<"\n Record Found\n";
file.read((char *)&pho.person_no,4);
file.read((char *)&pho.name,44);
file.read((char *)&pho.gender,46);
file.read((char *)&pho.address,66);
cout<<"\n========================================================================\n";
cout<<pho;
count++;
file.close();
break;
}
file.seekg(44,ios :: cur);
if(file.eof())
break;
}
if(count==0)
cout<<"\n NO Record Found\n";
getch();
}
void person_Details :: options()
{
FILE *ft,*f2;
char a,as[10],asd[10];
int T,pre=0;
do
{
refresh()   ;
gotoxy(20,10);
cout<<"Press Enter To Create a REPORT ";
T=menu(20,10,3);
switch(T)
{
case 3:
ifstream file("person.dat", ios :: nocreate,ios::binary);
f2=fopen("PERSON.TXT","w");

fprintf(f2,"NAME                     HOUSE NO   PERSON ID  GENDER  ADDRESS");
fprintf(f2,"\n---------------------------------------------------\n");
while(file.read((char *)&pho,sizeof(pho)) && !file.eof())
{
fprintf(f2,"%-30s%6d   %-10.0f%c%-10s\n\n",pho.name,pho.hno,pho.person_no,pho.gender,pho.address);
}
gotoxy(20,30);
cout<<"File has been created name PERSON.TXT";
fclose(f2);
file.close();

break;
case 0:
pre=1;
getch();
break;
}
}while(pre==0);
}


void operator <<(ostream & nout ,person &p)
{
char str[100];
sprintf(str,"%-30s%6d%  -10.0f%6c %6s",p.name,p.hno,p.person_no,p.gender,p.address);
strcat(str,"\n");
nout<<str;
}

void person_Details :: delete_records()
{
int uchoise;
ifstream file;
refresh();
gotoxy ( 30, 10 ) ;
printf ( "Delete complete Deatils of Person " ) ;
gotoxy ( 30, 11 ) ;
printf ( "Delete record by record " ) ;
gotoxy ( 30, 14 ) ;
printf ( "Your choice " ) ;
fflush ( stdin ) ;
uchoise = menu(30,10,2) ;
gotoxy(20,18);
if(uchoise==1)
{
cout<<"\nAre u sure to delete  Y/N";
if(toupper(getch())=='Y')
{
//if sure to delete them all
cout<<"\nDeleting Records...... ";
for(int i=0;i<50;i++)                 //fake looping just for display purpose
{
cout<<".";
delay(30);
}
remove ("person.dat");
fp=fopen("person.dat","w");
fclose(fp);
}
}
else
{
do
{
cout<<endl<<"  Enter HOUSE NO. to delete: " ;
int temp_hno;
int count=0;
cin>>temp_hno;

ofstream temp;
temp.open ( "TEMP.DAT", ios :: binary | ios :: trunc  ) ;        // opens a temp file
file.open( "person.dat",ios :: binary | ios :: nocreate) ;       // opens the data base
file.seekg(0, ios :: beg );                                     // goes to the begning of the file

while ( file.read ( (char *)&pho, sizeof(pho) ) && !file.eof() )
{
if ( pho.hno!=temp_hno )
temp.write ( (char *)&pho, sizeof(pho) ) ;
else
count++;
}

temp.close (  ) ;
file.close (  ) ;
remove ( "person.DAT" ) ;
rename ( "TEMP.DAT", "person.DAT" ) ;

if(count==0)
cout<<"\n SORRY!!!! NO PERSON DELETED \n";
if(count!=0)
cout<<"\n RECORD OF PERSON DELETED\n";
printf ( " Delete another Record (Y/N):" ) ;
fflush ( stdin ) ;
}while(toupper(getch())=='Y');
}
}

void person_Details :: display_records()
{
ifstream file;
refresh();
file.open("person.dat",ios :: nocreate ,ios :: binary);
fseek(fp,0,SEEK_SET);
printf("%-30s%-7s","NAME","HOUSE NO.");
cout<<" PERSON ID"<<" Gender" <<" Address";
printf("\n--------------------------------------------------------------------");
while ( file.read ((char *)&pho, recsize) )
{
if(file.eof())
{
file.close();
break;
}
cout<<endl<<endl<<pho;
}
getch();
}

void person_Details :: modify_records()
{
refresh();                                           //clears the screen
int temp_hno,count=0;                          //storing the temp room no & count to conform found or not
fp=fopen("person.dat","rb+");
do
{
cout<<" Enter the House no to be modified :";
cin>>temp_hno;
rewind ( fp ) ;
while ( fread ( &pho, recsize, 1, fp ) == 1 )
{
if ( pho.hno == temp_hno )
{
cin>>pho;
fseek ( fp, - recsize, SEEK_CUR ) ;
fwrite ( &pho, recsize, 1, fp ) ;
cout<<"\n Record modified Succesfully....";
for(int i=0;i<50;i++)                 //fake looping just for display purpose
{
cout<<".";
delay(30);
}
count++;
break;
}
}
if(count==0)                          //if we cant find the record it shows the an error
cout<<"\nCannot find the record ";
printf ( "\n Modify another Record (Y/N): " ) ;
fflush ( stdin ) ;
}while(toupper(getch())=='Y');  	//for user to find weater he wants to continue
fclose(fp);
}

istream & operator >>(istream & nin ,person &p)
{
strcpy(p.name," ");
p.hno=0;
p.person_no=0;
cout<<" Enter the person no: ";
nin>>p.person_no;
cout<<" Enter the House no: ";
nin>>p.hno;
cout<<" Enter the Gender: ";
nin>>p.gender;
cout<<" Enter the address: ";
nin>>p.address;
cout<<" Do u want to Enter name of the Person(Y/N):\n";
if(toupper(getch())=='Y')
{
cout<<" Enter the name of Person: ";
nin>>p.name;
}
return (nin);
}


person_Details :: person_Details()
{
int forexit=0,a;
recsize = sizeof(pho);
fp=fopen("person.dat","rb+");
if(fp == 0)
{
fp=fopen("person.dat","wb+");
if(fp == 0)
{
refresh();
cout<<" Cannot Open the file \npress any key to halt ";
onexit();
}
}
while(forexit==0)
{
refresh();
{
ifstream temp_file("person.dat", ios :: out | ios :: nocreate | ios :: binary );
temp_file.seekg(0,ios :: end);
gotoxy(20,25);
counter=temp_file.tellg()/sizeof(pho);
cout<<"POPULATION OF CITY AT PRESENT= "<<temp_file.tellg()/sizeof(pho);
temp_file.close();
}
gotoxy(1,1);
cout<<"************************** PRESS Esc TO GOTO MAIN MENU *************************";
display_time(1,3);
gotoxy(20,6);
cout<<"Add Records ";
gotoxy(20,7);
cout<<"List Records ";
gotoxy(20,8);
cout<<"Modify Records";
gotoxy(20,9);
cout<<"Search Records";
gotoxy(20,10);
cout<<"Delete Records";
gotoxy(20,11);
cout<<"PRINT Report";
gotoxy(30,20);
a=menu(20,8,6);
switch(a)
{
case 0:
forexit=1;
break;
case 1:
add_records();
break;
case 2:
display_records();
break;
case 3:
modify_records();
break;
case 4:
search_records();
break;
case 5:
delete_records();
break;
case 6:
options();
break;
}
}
fclose(fp);
}

inline void onexit()
{
refresh();
gotoxy(1,2);
cprintf("\n\n\t\tThis program is made by ");
cout<<endl<<endl;
cprintf("                 NIKET CHOUDHARY ROLL NO. 30");
cout<<endl<<endl;
cprintf("                 THANK U FOR USING THE PROGRAM ");
cout<<endl<<endl;
cprintf("                 This PROGRAM IS MADE FOR SUBJECT Comp. Sc.  ON DATE 24/11/2008");
cout<<endl<<endl;
cprintf("                 This is the end of program\n\npress any key to EXIT....");
getch();
exit(0);
}

void refresh()
{
clrscr();
textcolor(WHITE);
textbackground(RED);
cprintf("********************************************************************************");
cprintf("   *********************** CITY INFORMATION SYSTEM **************************");
gotoxy(1,3);
textcolor(RED);
textbackground(GREEN);
cprintf(" ");
cout<<endl;
}

void main()
{
int a;
informations nt;
refresh();
clrscr();
char pass[10],user[10];
refresh();
gotoxy(20,8);
for(int j=0;j<41;j++)
printf("-");

for(j=9;j<=14;j++)
{	gotoxy(20,j);		printf("|");	}

for(j=9;j<=14;j++)
{	gotoxy(60,j);		printf("|");	}

gotoxy(20,15);
for(j=0;j<41;j++)
printf("-");


gotoxy(28,11);
cout<<"User-name:";
gotoxy(29,13);
cout<<"Password:";
gotoxy(39,11);
cin>>user;
gotoxy(39,13);
int f=0;
for (f=0;f<100;f++)
{
pass[f]=getch();
cout<<"*";
if (pass[f]=='\r') break;
sound(1600);
delay(100);
nosound();
}
if (pass[f]=='\r') pass[f]='\0';else pass[100]='\0';

if(strcmp(pass,"niket")!=0 || strcmp(user,"niket")!=0)
{
cout<<"\n WRONG PASSWORD ";
getch();
onexit();
}
cout<<"\n\n\n   Wait while I load...." ;
for(int i=0;i<50;i++){cout<<".";sound(50); delay(50); nosound();  }
while(1)
{
refresh();
gotoxy(5,30);
cout<<"************************** PRESS Esc TO EXIT *****************************";
display_time(1,3);
gotoxy(20,10);
cout<<"CITY INFORMATION";
gotoxy(20,11);
cout<<"POPULATION INFORMATION";
gotoxy(20,12);
cout<<"OTHER DETAILS ";
gotoxy(20,25);
cprintf("Use up And DOWN Arrow key");
a=menu(20,11,4);
switch(a)
{
case 2:
sav:
	clrscr();
	gotoxy(24,23);
	cout<<"Program by xxxxx.";
	gotoxy(1,1);
	hi=13;
	cout<<"OPTIONS\n1.New information\n2.Open an existing information\n3.Return to main menu\n";
	cout<<"\nEnter a choice : ";
	cin>>i;
	switch(i)
	{
	case 1: nt.newinformation();
		break;

	case 2: int i=nt.search();
		getch();
		if(i==0)
		goto sav;
		else
		break;

	case 3: onexit();
	default: clrscr();
		 goto sav;

	}
	break;

case 3:
person_Details obj;
break;
case 4:
refresh();
char line[80];
strcpy(line,"THIS IS A SIMPLE PROGRAM For CITY INFORMATION CITY. ");
for(int linr=0;linr<80;linr++)
{
cout<<line[linr];
delay(50);
if(line[linr]=='\0')
break;
}
cout<<endl;
strcpy(line,"IT Contains All the information Related to City Persons.");
for(linr=0;linr<80;linr++)
{
cout<<line[linr];
delay(50);
if(line[linr]=='\0')
break;
}
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t St. Aloysius Senior Secondary School,Sadar,Jabalpur ";
getch();
break;
case 0:
onexit();
}
}
}

#include<stdio.h>
#include<iostream>
#include<fstream>
#include<graphics.h>
#include<windows.h>
#include<conio.h>
#include<unistd.h>
#include<cctype>
#include<cmath>
using namespace std;
#define size 50
int a,k;
char ch;

void playMusic(char name[],char img[]);

void image(char a[])     //image function
{

    PlaySound(TEXT("015"),NULL,SND_ASYNC);
    initwindow(400,600,"KARL IMAGE MODE");
    readimagefile(a,0,0,400,600);
    delay(1000);
    closegraph();
}


void DOT(int i)                          //   Dott //
{  int m ,k;
    for(m=0;m<i;m++)
    {
        for(k=9;k>=0;--k)
        {
        cout<<".";
        delay(150);
        }
        for(k=9;k>=0;--k)
        cout<<"\b \b";

    }
        for(k=9;k>=0;--k)
        cout<<"\b \b";
}

void DOTT(int i)                          //   Dott //
{  int m ,k;
    for(m=0;m<i;m++)
    {
        for(k=9;k>=0;--k)
        {
        cout<<".";
        delay(150);
        }
        for(k=9;k>=0;--k)
        cout<<"\b \b";

    }
}

void time_wait(int i)                          //time_wait()//
{   int k;
    for(k=i;k>=0;--k)
        {
        cout<<k;
        delay(750);
        cout<<"\b \b";                         //backspace here
        }

}


int password()                  //DEVELOPER CHANDAN//         //LOGIN MODE//
{
    char a,user[50],pass[20];
    int b;
    int p_s=0,i=0;
    system("refresh");
    PlaySound(TEXT("login mode"),NULL,SND_ASYNC);

    START1:system("cls");
    cout<<"\n\t\t\t\t*********** KARL LOGIN MODE *************";
    cout<<"\nKARL_USERNAME : ";
    gets(user);
    strupr(user);
    if(strcmp(user,"CHANDAN@KARL.IN")==0)                                //USERNAME SETTINGS                 CHANDAN@KARL.IN//
  {
       START:
      if(p_s==3)
     {   system("cls");
        cout<<"\nYOU HAVE EXCEEDED THE LIMIT.........."<<"\n TRY AGAIN LATER_________________";
        PlaySound(TEXT("cwpad"),NULL,SND_ASYNC);
        cout<<"\nEXITING ";
        DOT(2);
        exit(0);

     }
    cout<<"\nKARL_PASSWORD:";                           //PASSWORD SETTINGS//
    PlaySound(TEXT("eyp"),NULL,SND_ASYNC);
    for(;;)
    {    a =_getch();
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0' && a<='9'))
       {
           pass[i]=a;
           i++;
           cout<<"*";
        }
    if(a=='\b' && i>=1)
    {
        cout<<"\b \b";
          i--;
    }
    if(a=='\r')
       {
        pass[i]='\0';
        break;
       }
}
if(i<=6)
{   cout<<"\nKARL_: Password must contain atleast '6' char.'s \n";
    Beep(523,500);
    PlaySound(TEXT("pmc6c"),NULL,SND_ASYNC);
    i=0;
    system("pause");
    goto START;
}
if(strcmp(pass,"chandan1234")==0)                         //PASSWORD SETTINGS                                    chandan1234//
{   cout<<"\nKARL_:  ACCESS GRANTED..........";
      PlaySound(TEXT("ag"),NULL,0);
return 1;
}
else
    { ++p_s;
      i=0;
      Beep(650,1000);
      cout<<"\n'WRONG PASSWORD' \nACCESS DENIED.............\n";
      PlaySound(TEXT("wpad"),NULL,SND_ASYNC);
      cout<<"KARL_:"<< 3-p_s <<"_ATTEMPTS REMAINING \n";
      PlaySound(TEXT("gar"),NULL,SND_ASYNC);
      cout<<"\nKARL_: TRY AGAIN IN "; time_wait(3);
      goto START;
    }
}

else
{
   cout<<"Invalid USERNAME\n";
   system("pause");
   goto START1;
}

}

void KARL_READING()                                                  //READING FUNCTION

{


    int op,k,i=0;
   char F_name[50];
   char a,b[10];
   ifstream F_in;
   READING:
    system("cls");
   cout<<"\t\t\t\t\t\tKARL READING MODE -\"CHANDAN SHARMA\" \n";
   cout<<"\n\t\t\tPlease provide Extension after file name e.g .txt  , .dat etc";
   cout<<"\n\nEnter File:";
        gets(F_name);
       if(access(F_name,F_OK)==-1)
    {
        cout<<"\nSTATUS:";
        perror(ERROR);
        cout<<endl;
        cout<<"KARL:TRY AGAIN IN ";
        time_wait(5);
    goto READING;
    }
     F_in.open(F_name);
    system("cls");
cout<<"\t\t\t\t\t\tKARL READING MODE -\"CHANDAN SHARMA\" \n\n";
while(!F_in.eof())
{
    a=F_in.get();
    cout<<a;
}
F_in.close();
cout<<"\n\nKARL:ANOTHER FILE/STORY PRESS 1::";
cin>>op;
if(op=='1')
       goto READING;
else
    return;
}


void Play_Sound(int a);

int KARL_MUSIC()                                                        //MUSIC PLAYER
{
    ifstream F_in;
    int k,b,i=0;
    char F_PLAYLIST[50];
    MUSIC : system("CLS");
            cout<<"\n\a\t\t\t\t\t   .............KARL MUSIC PLAYER................";
            cout<<"\nKARL_Enter PlayList:";
    gets(F_PLAYLIST);

     if(access(F_PLAYLIST,F_OK)==-1)
     {
    cout<<"\nSTATUS:";
    perror(ERROR);
    cout<<endl;
    cout<<"KARL_TRY AGAIN IN ";
    for(k=9;k>=1;--k)
    {
    cout<<k;
    delay(600);
    cout<<"\b \b";

    }
     goto MUSIC;
    }
    LIST:system("cls");

    cout<<"\n\a\t\t\t\t\t  .............KARL MUSIC PLAYER................\n\n";
    cout<<"CURRENT PLAYLIST::"<<F_PLAYLIST<<"\n";

    F_in.open(F_PLAYLIST);
    while(!F_in.eof())
    {
        ch=F_in.get();
        cout<<ch;
    }

    F_in.close();

    cout<<"\n\n\tKARL_ENTER MUSIC:";
    cin>>a;
    closegraph();
    if(a==1010)
     goto MUSIC;

    Play_Sound(a);

    if(a!=0)
    goto LIST;

    cout<<"\n\tKARL:EXITING MUSIC PLAYER";
    DOTT(3);
    return 0;
}


void playMusic(char name[],char img[] ){

        PlaySound(TEXT(name),NULL,SND_ASYNC);
        initwindow(300,300,name);
        readimagefile(img,0,0,300,300);

}


void Play_Sound(int a)

{

switch(a)
{

case 0: return;
/*
case 1: playMusic("song","image.jpg");
break;
case 2:playMusic("Brown Munda","2.jpg");
break;
case 3:playMusic("song","image.jpg");
break;
case 4:playMusic("song","image.jpg");
break;

case 5:playMusic("song","image.jpg");
break;
*/
default : cout<<"\nSorry MUSIC is not available............\n";
          system("pause");
}
}




void KARL_NOTEPAD()                        //NOTEPAD FUNCTION//
 {
    int op=0,i=0;
   char A[100000],F_name[50];
   char a;
   ofstream F_out;
   ifstream F_in;
   NOTE:
         system("cls");
         cout<<"\t\t\t\t\t\tKARL NOTEPAD - \"CHANDAN SHARMA\"\n";
         cout<<"\n\t\t\tPlease provide Extension after file name e.g .txt  , .dat etc";
         cout<<"\n\nKARL: Use ESCAPE KEY TO SAVE FILE....";
         cout<<"\nKARL:_Enter File:";

         gets(F_name);

         if(strcmp(strupr(F_name),"EXIT")==0||strcmp(strupr(F_name),"OUT")==0)
          {  cout<<"\nKARL :Exiting"; DOT(3);
              return;
          }
         cout<<"KARL: 1.CREATE (REmove old data)  2.APPEND/MERGE (include old Data in  Begg.)\n";
         op = getche();
         system("cls");
         if(op=='1')
         F_out.open(F_name);
         else if (op=='2')
         F_out.open(F_name,ios::app|ios::out);

   else {
             cout<<endl
             <<"KARL:No Such Command Found"
             <<"\nKARL:Processing";DOT(1);
             cout<<endl;
             goto NOTE;

        }
 cout<<"\t\t\t\t\t\tKARL NOTEPAD \"CHANDAN SHARMA\" \n";
   for(;;)
    {       a= _getch();

   if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0' && a<='9')||a==32||a==33)
        {
           A[i]=a;
           i++;
           cout<<a;
        }
   if(a=='\b' && i>=1)
       {
        cout<<"\b \b";
          i--;
       }
   if((a>32 && a<48) ||(a>57 && a<65) || (a>90 && a<97))
       {

           A[i]=a;
           i++;
           cout<<a;
       }

   if(a=='\r')
      {
        A[i]='\n';
        cout<<"\n";
        i++;
      }

   if(a==27)
        {

        A[i]='\0';
        system("cls");
        cout<<"\n\t KARL: Creating File:"<<F_name<<"\n\n"<<"\tWait It is Saving";
        DOTT(1);
        cout<<"SAVED";
        cout<<"\nKARL_: File "<<F_name<<" sAVEd to desktop/KARL";
        cout<<"\nKARL:ENTER TO OUT.....\n";
        YO:
        a=_getch();
        if(a=='\r')
        break;
        else

        {
             cout<<"\nKARL:Wrong Button Pressed try Again";
              goto YO;
        }

       }
    }

        F_out<<A;
        cout<<A;
}

int check()                                                   //Authentication check//
{     int op=0;
      int P_check;
       start: system("cls");
       cout<<"\n\t\t\t\t\t\t WELCOME  TO MY WORLD "
       <<"\n*****************************************"
       <<"********************************************"
       <<"***********************************\n";
        PlaySound(TEXT("01"),0,SND_ASYNC);
        cout<<"\nYOU NEED TO PROVIDE AUTHANTICATION TO ACCESS KARL"
             <<"\n\n1.AUTHANTICATE \t 2.COME ON LATER\n"
              <<"KARL:";
           op=_getch();

           if(op=='2')
           {
               cout<<"\nKARL:EXITING";
               DOT(3);
               exit(0);
           }

           else if(op=='1')
           {
               cout<<"KARL:TAKING YOU TO LOGIN PAGE WAIT";
               DOT(2);
                P_check=password();
            }
           else {
               cout<<"\nWrong Choice(Enter to cont.)...........\n";
                 system("pause");
                goto start;
           }
if(P_check==2)

{
    Beep(523,1000);
    cout<<"\nKARL : UNAUTHUARIZED USER";
    cout<<"\nKARL:EXITING"; DOT(3);
    exit(0);
    cout<<"\n";
}

}

void F_EXPLORE()                              //CMD LIST
{   int i=0;
    char a,b[120];
    ifstream cmd;
    cout<<"Enter File To find: ";
    gets(b);
    strupr(b);
    if(strcmp(b,"CMD_LIST")==0||strcmp(b,"C_L")==0||strcmp(b,"ALL COMMAND")==0||strcmp(b,"COMMAND ALL")==0)
    strcpy(b,"cmd.txt");

    if( access(b,F_OK)==-1 )
    {
      perror("FILE REMOVED");
      cout<<"\nKARL:ENTER TO GO BACK..";
      DOTT(3);
     for(;;)
    {
      a = _getch();
      if(a=='\r')
      return;
      cout<<"\nKARL: WRONG KEY PRESSED";
      DOTT(2);

    }
    }

    cmd.open(b);
    cout<<"\n";
    while(!cmd.eof())
 {
      a=cmd.get();
      cout<<a;
 }
 cout<<"\nKARL:ENTER TO EXIT....";
 for(;;)
{
 a=_getch();
 if(a=='\r')
 return;
 cout<<"\nKARL: WRONG BUTTON PRESSED..";
 DOTT(2);
 cout<<endl;
}
}

int j=1;
main()

{   int i=0;
    char cmd[100],k[50],N[30];
   check();
 RENAME: system("cls");
 cout<<"\n \t \t \t ***************************WELCOME TO KARL***************************";
 cout<<"\n\nKARL:How would You Like to Called:";
     gets(N);
     strupr(N);

     cout<<"\nKARL:You Entered "<<N<<". Do You want to ReName it : Yes/Enter... \nEnter : ";
     gets(k);
     strupr(k);
     if(strcmp(k,"YES")==0)
     {   cout<<"\nLoadind"; DOT(2);
          goto RENAME;

    }
 system("cls");
 cout<<"\n \t \t \t***********************************WELCOME TO KARL************************************\n\n";
 cout<<"\nKARL:SAY SAOMETHING ??";
PlaySound(TEXT("015"),NULL,SND_ASYNC);
for(;;)
{

cout<<"\n"<<N<<":";
gets(cmd);
strupr(cmd);
if(strcmp("EXIT",cmd)==0||strcmp("0",cmd)==0)
exit(0);

else if(strcmp("VIEW ",cmd)==0||strcmp("FIND SOMETHING",cmd)==0||strcmp("WATCH",cmd)==0||strcmp("ACCESS FILE",cmd)==0)
F_EXPLORE();

else if(strcmp("MUSIC PLAYER",cmd)==0||strcmp("OPEN MUSIC PLAYER",cmd)==0||strcmp("KARL PLAYER",cmd)==0||strcmp("K_PLAY",cmd)==0||strcmp("PLAY MUSIC",cmd)==0)
KARL_MUSIC();

else if(strcmp("I WANT TO READ",cmd)==0||strcmp("READING MODE",cmd)==0||strcmp("STORY MODE",cmd)==0)
KARL_READING();

else if(strcmp("KARL NOTEPAD",cmd)==0||strcmp("OPEN NOTEPAD",cmd)==0||strcmp("TEXT WRITER",cmd)==0||strcmp("WRITE TEXT",cmd)==0||strcmp("WRITE",cmd)==0)
KARL_NOTEPAD();

else if(strcmp("CLEAR",cmd)==0||strcmp("CLRSCR",cmd)==0||strcmp("CLEAR SCREEN",cmd)==0||strcmp("CLEAR ALL",cmd)==0)

{
    system("cls");
cout<<"\nKARL:SCREEN CLEARED AS YOU WISHED,"<<N<<" .DO MORE CHATS...";
}//chatting LIBRARY//
else if(strcmp("WHAT ARE YOU DOING?",cmd)==0||strcmp("WHAT ARE YOU DOING",cmd)==0||strcmp("KARL WHAT ARE YOU DOING?",cmd)==0||strcmp("KARL WHAT ARE YOU DOING",cmd)==0||strcmp("WHT R U DOING",cmd)==0||strcmp("WHT R U DOiN",cmd)==0)

    {   PlaySound(TEXT("1"),NULL,SND_ASYNC);
        cout<<"\nKARL: I'M ASSISTING YOU "<<N<<" HOPE YOU ENJOYING ME..";

    }

else if(strcmp("HOW ARE YOU KARL?",cmd)==0||strcmp("HOW ARE YOU",cmd)==0||strcmp("HOW ARE YOU?",cmd)==0||strcmp("HOW ARE YOU KARL",cmd)==0||strcmp("KARL HW R U",cmd)==0||strcmp("HW R U?",cmd)==0||strcmp("HW R U KARL",cmd)==0)
    {cout<<"\nKARL:I'M FINE! THANKS FOR ASKING ME "<<N<<" !"<<" HOW ARE YOU?";
      PlaySound(TEXT("2"),NULL,SND_ASYNC);}

else if(strcmp("I AM FINE THANKS",cmd)==0||strcmp("I AM ALSO FINE!",cmd)==0||strcmp("I'M ALSO FNE",cmd)==0||strcmp("I'M ALSO FINE",cmd)==0||strcmp("I'M ALSO FINE KARL",cmd)==0||strcmp("IM ALSO FINE!",cmd)==0||strcmp("M ALSO FINE",cmd)==0)
     {cout<<"\nKARL: OHH! THATS GREAT.. "<<N;
     PlaySound(TEXT("3"),NULL,SND_ASYNC);
     }


else if(strcmp("SAY SOMETHING ABOUT YOU?",cmd)==0||strcmp("TELL ME ABOUT YOU?",cmd)==0||strcmp("SAY SOMETHING ABOUT YOU",cmd)==0||strcmp("TELL ME SOMWTHING ABOUT YOU",cmd)==0)
  {
      cout<<"\nKARL:HELLO,I AM KARL,THE ROBOT. I CANNOT DO THINGS LIKE HUMAN BUT I CAN ASSIST THEM EASILY..";
       PlaySound(TEXT("4"),NULL,SND_ASYNC);
  }

else if(strcmp("WOULD YOU LIKE TO TALK WITH ME?",cmd)==0||strcmp("WOULD YOU LIKE TO CHAT?",cmd)==0||strcmp("TALK WITH ME?",cmd)==0)
  {cout<<"\nKARL:YES,I WOULD LIKE TOO. "<<N<<",SAY SOMETHING?";
  PlaySound(TEXT("5"),NULL,SND_ASYNC);}

else if(strcmp("BYE",cmd)==0||strcmp("SHUTDOWN",cmd)==0||strcmp("CLOSE",cmd)==0)
  {cout<<"KARL__TERMINATING ITSELF,PROCESSING";DOTT(3);exit(0);}


else if(strcmp("WHO ARE YOU?",cmd)==0||strcmp("WHO ARE YOU",cmd)==0)
  {cout<<"\nKARL:I AM KARL,YOUR PERSONEL ASSISTANCE!";

  PlaySound(TEXT("6"),NULL,SND_ASYNC);
  }

else if(strcmp("PLAY A SONG FOR ME",cmd)==0)
{
cout<<"\nKARL:OK SIR WHY NOT "<<N<<"\nKARL:PLAYING THE SONG IT WILL CHANGE AFTER COMPLETIOn.\n";

Play_Sound(j);

}
else if(strcmp("CHANGE SONG",cmd)==0||strcmp("CHANGE IT",cmd)==0||strcmp("CHANGE THIS",cmd)==0||strcmp("NEXT",cmd)==0)
{  closegraph();
    j=j+1;
  cout<<"\nKARL:oK,"<<N<<" CHANgING It:";
  Play_Sound(j);
}
else if(strcmp("STOP MUSIC",cmd)==0||strcmp("STOP IT",cmd)==0)
{
    Play_Sound(0);
}
else if(strcmp("HAHA",cmd)==0||strcmp("LAUGH",cmd)==0)
{
    PlaySound(TEXT("15"),0,SND_ASYNC);
}

else if(strcmp(cmd,"HII")==0||strcmp("HELP ME",cmd)==0||strcmp("HELLO",cmd)==0)
{
PlaySound(TEXT("8"),NULL,SND_ASYNC);
cout<<"\nKARL: HELLO "<<N<<",HOW MAY I HELP YOU...";

}
else if(strcmp("KARL YOU ARE DOG",cmd)==0||strcmp("FUCK YOU",cmd)==0||strcmp("FUCK OFF",cmd)==0||strcmp("STUPID",cmd)==0)
    cout<<"\nKARL:MIND YOU LANGUAGE "<<N<<" LISTEN YOU CAN'T DO THAT I AM A ROBOT NOT A HUMAN..";


else if(strcmp("WHO IS YOUR DEVELOPER",cmd)==0||strcmp("WHO IS CHANDAN SHARMA",cmd)==0||strcmp("WHO IS CHANDAN",cmd)==0)
{

cout<<"KARL: CHANDAN SHARMA IS MY DEVELOPER.HE MADE ME AND NAMED ME KARL.......";
PlaySound(TEXT("12"),NULL,SND_ASYNC);
}

else if(strcmp("OPEN IMAGES",cmd)==0||strcmp("IMAGES",cmd)==0||strcmp("KARL IMAGES",cmd)==0)
{  char a[size];
sound:cout<<"Enter image name:";
  gets(a);
  image(a);
cout<<"Do you want to see more:Press 1 else any key(use .jpg):";
int b;
b=_getch();
if(b==1)
    goto sound;
}
else if(strcmp("RESTART MY PC",cmd)==0||strcmp("RESTART",cmd)==0||strcmp("SHUTDOWN PC",cmd)==0)
{
    if(strcmp("SHUTDOWN PC",cmd)==0)

    system("c:\\windows\\system32\\shutdown /s/t30");
else
system("c:\\windows\\system32\\shutdown /r/t30");
}
else
{
 PlaySound(TEXT("11"),NULL,SND_ASYNC);
 cout<<"\nKARL: I'M NOT PROGRAMMED FOR THIS..";
}

}

return 0;

}





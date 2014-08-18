#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<graphics.h>
#include<dos.h>
using namespace std;
  int a[100][100],x=3,y=3,p1,p2,p3,p4,k,ex=0;    char tit[10],tat[10],gam[20],d[50],g[50],pam[50];
void head()                /* To print the Title of the game */
{       int gdriver = DETECT, gmode, errorcode;

/* initialize graphics mode */
initgraph(&gdriver, &gmode, "");

	int i,j;
	settextstyle(0,0,1);
	setcolor(YELLOW);


	for(i=0;i<=100;i++)
	{
		outtextxy(random(700),random(450),".");
	}
	for(i=0,j=500;i<=200;i+=5,j-=5)
	{
		settextstyle(4,0,7);
		setcolor(RED);
		outtextxy(i,150,tit);
		outtextxy(j,150,tat);
		setcolor(0);
		sound(200+j*10);
		delay(100);
		outtextxy(i,150,tit);
		outtextxy(j,150,tat);
	}
	setcolor(10);
	settextstyle(4,0,7);
	nosound();
	outtextxy(j-70,150,gam);
	settextstyle(1,0,2);
	for(i=340,j=340;i<=440;i+=5,j-=5)
	{
		outtextxy(i,210,"@");
		outtextxy(j,210,"@");
		delay(200);
	}
	setcolor(1);
	outtextxy(10,450,"GAURAV ");
	outtextxy(500,450,"PARAS");
	settextstyle(0,0,1);
	setcolor(BLUE);
	for(i=0;i<=100;i++)
		outtextxy(random(700),random(450),".");
	getch();
	cleardevice();
	settextstyle(0,0,1);
	setbkcolor(0);
	closegraph();
 }

int mai()
{
      while (!kbhit())
     return 0;
}
void in(char &a)
{
if(a==1)
a='!';
if(a==2)
a='@';
if(a==3)
a='#';
if(a==4)
a='$';
if(a==5)
a='%';
if(a==6)
a='^';
if(a==7)
a='&';
if(a==8)
a='*';
if(a==9)
a='+';
if(a==0)
a='?';
}
int ch00()
{
int c=0,b=0,f=0;
for(int i=0;i<x;i++)
{b=0;c=0;
for(int j=0;j<y;j++)
{
b=b+a[i][j];
c=c+a[j][i];
}
if(((b==15)&&(c==15))||((b==65)&&(c==65))||((b==175)&&(c==175)))
continue;
else
{
f=1;
break;
}
}
if(f==0)
return 0;
else
return 1;
}

void check(int b,int c)
{
for(int i=0;i<x;i++)
{for(int j=0;j<y;j++)
{
if(a[i][j]==b)
{p1=i;p2=j;}
if(a[i][j]==c)
{p3=i;p4=j;}}}
a[p3][p4]=b;
a[p1][p2]=c;}

int ch11(int b,int c)
{int d=0;
for(int i=1;i<=(x*y);i++)
{
if((b==i)||(c==i))
d++;
}
if(d==2)
return d;
else
return 0;
}

void disc()
{cout<<endl<<endl<<endl<<endl;
for(int i=0;i<x;i++)
{cout<<endl<<endl<<"          ";
for(int j=0;j<y;j++)
{
if(a[i][j]<10)
cout<<"     ";
else
cout<<"    ";
cout<<a[i][j];}
}
cout<<endl<<endl;
}

int m[3][3];
int cou=0;
void ch()
{void ch1(),ch2(),ch3();
if(cou==1)
ch1();
else
{
if(cou==2)
ch2();
else if(cou==3)
ch3();}}
void dis()
{closegraph();
for( int i=0;i<3;i++)
{cout<<endl<<endl;
for(int j=0;j<3;j++)
{   if(m[i][j]==35)
cout<<"        "<<"*";
else
{if(m[i][j]==42)
cout<<"        "<<"0";
else
cout<<"        "<<m[i][j];}}cout<<endl<<"\n";
}
}

int tem[3][3];
void ch0()
{for(int i=0;i<3;i++)
{
for(int j=0;j<3;j++)
{
 tem[i][j]=m[i][j];}}}
void ch1()
{
for(int i=0;i<3;i++)
{
for(int j=0,l=2;j<3;j++,l--)
{
tem[i][l]=m[i][j];}} }
void ch2()
{for(int i=0,k=2;i<3;i++,k--)
{for(int j=0,l=2;j<3;j++,l--)
{
tem[k][l]=m[i][j];}} }
void ch3(){
for(int i=0,k=2;i<3;i++,k--)
{
for(int j=0;j<3;j++)
{
tem[k][j]=m[i][j];}}}

void ch02()
{ for(int i=0;i<3;i++)
{
for(int j=0;j<3;j++)
{m[i][j]=tem[i][j];}}}
void ch12()
{for(int i=0;i<3;i++)
{for(int j=0,l=2;j<3;j++,l--)
{m[i][l]=tem[i][j];}} }
void ch22()
{for(int i=0,k=2;i<3;i++,k--)
{for(int j=0,l=2;j<3;j++,l--)
 {
m[k][l]=tem[i][j];}} }
void ch32()
{
for(int i=0,k=2;i<3;i++,k--)
{
for(int j=0;j<3;j++)
{
m[k][j]=tem[i][j];}}}

	  int mu=0;
void disp()
{ closegraph();   if(cou==4)
{if(mu%2==0)
{ch02();}
for(int i=0;i<3;i++)
{cout<<endl<<endl;
for(int j=0;j<3;j++)
{  if(m[i][j]==35)
cout<<"        "<<"*";
else
{if(m[i][j]==42)
cout<<"        "<<"0";
else
cout<<"        "<<m[i][j];}}cout<<endl<<"\n";}
mu++; ch0();
}
if(cou==1)
{
ch12();
for(int i=0;i<3;i++)
{cout<<endl<<endl;
for(int j=0;j<3;j++)
{cout<<"        "<<m[i][j];}cout<<endl<<"\n";}
ch1();
}
if(cou==2)
{ch22();
for(int i=0;i<3;i++)
{cout<<endl<<endl;
for(int j=0;j<3;j++)
{cout<<"        "<<m[i][j];}cout<<endl<<"\n";}
ch2();
}
if(cou==3)
{ch32();
for(int i=0;i<3;i++)
{cout<<endl<<endl;
for(int j=0;j<3;j++)
{cout<<"        "<<m[i][j];}cout<<endl<<"\n";}
ch3();   }
}
void input(char pam[50])
{
int o,p,q;
cout<<"     "<<pam<<":enter your choice";
a77:
cin>>o;
--o;
p=o/3;
q=o%3;
if((m[p][q]=='#')||(m[p][q]=='*'))
{
cout<<endl<<"     wrong choice";
cout<<endl<<"     enter new choice";
goto a77;
}
else
m[p][q]='#';      ch();
clrscr();
disp();
}        int an=0;





void main()
{void medium(int);
clrscr(); ppgg:
 int gdriver = DETECT, gmode, errorcode;

/* initialize graphics mode */
initgraph(&gdriver, &gmode, "");

			for(int i=0;i<50;i++)
			{
			for(int j=0;j<10;j++)
				{
				delay(5);clrscr();
				cout<<endl<<endl<<"         YOU HAVE ENTER PARAS'S WORLD";

				}

		       cleardevice();
		       int h;int an=0;
		       settextstyle(4,0,4);setcolor(1);
		       outtextxy(100,100," Which Game You Wanna Play ");
		       outtextxy(100,150,"1: 0 & * ");
		       outtextxy(100,200,"2:Magic Box");
		       outtextxy(100,250,"3:Casino Royals");
		       outtextxy(100,300,"4:Exit ");
		       cout<<endl<<endl;
		       outtextxy(150,350,"enter choice:- ");

		       cin>>h;              closegraph();
		       if(h==1)
				{  strcpy(::tit,"0   * ");
				strcpy(::tat," & ");  strcpy(::gam,"0 & *");
				head();      gp:
				int gdriver = DETECT, gmode, errorcode;

/* initialize graphics mode */
initgraph(&gdriver, &gmode, "");


				cleardevice();
				int k;                  settextstyle(6,0,4);setcolor(RED);
				outtextxy(100,100,"Enter your choice");
				outtextxy(100,150,"1:One player");
				outtextxy(100,200,"2:Two player");
				outtextxy(100,250,"3:Exit");
				outtextxy(100,320,"Enter choice(1/2):- ");
				cin>>k;       closegraph();
				if(k==1)
					{      char pam[50];     				int gdriver = DETECT, gmode, errorcode;

/* initialize graphics mode */
initgraph(&gdriver, &gmode, "");

					cleardevice();   setcolor(BLUE); settextstyle(5,0,4);
					     outtextxy(0,0,"enter your name");
					     gets(pam);cleardevice();
					int l;           setcolor(BLUE); settextstyle(5,0,4);
					outtextxy(100,100,"Enter choice");
					outtextxy(100,150,"1:Easy");
					outtextxy(100,200,"2:Medium");
					outtextxy(100,250,"3:Hard");
					outtextxy(100,300,"enter choice(1/2/3):- ");
					cin>>l;    cleardevice(); closegraph();
					if(l==1)
						{
						 int n=1;
						for(int i=0;i<3;i++)
						{
						for(int j=0;j<3;j++)
						{
						m[i][j]=n;
						n++;
						}}

						for(int cc=1;cc<9;cc++)
							{clrscr();
							dis();
							if(cc%2==0)
								{
							input(pam);
									for(int r=0;r<3;r++)
								{
								if(((m[0][r]=='#')&&(m[1][r]=='#')&&(m[2][r]=='#'))||((m[r][r]=='#')&&(m[r+1][r+1])&&(m[r+2][r+2]=='#'))||((m[r][0]=='#')&&(m[r][1]=='#')&&(m[r][2]=='#'))||((m[0][2]=='#')&&(m[1][1]=='#')&&(m[2][0]=='#')))
									{       clrscr();dis();   ++an;
									cout<<endl<<"    "<<pam<< " wins";
									getch();goto gp;
									}
								}
								}
							else
								{

								aaa:
								int r,p,q;
							       randomize();
							r=random(9);  --r;
								p=r/3;
								q=r%3;
								if((m[p][q]=='#')||(m[p][q]=='*'))
									{
									goto aaa;
									}

								else
								{clrscr();
								m[p][q]='*';dis();}
									for(r=0;r<3;r++)
								{
								if(((m[0][r]=='*')&&(m[1][r]=='*')&&(m[2][r]=='*'))||((m[r][r]=='*')&&(m[r+1][r+1]=='*')&&(m[r+2][r+2]=='*'))||((m[r][0]=='*')&&(m[r][1]=='*')&&(m[r][2]=='*'))||((m[0][2]=='*')&&(m[1][1]=='*')&&(m[2][0]=='*')))
									{       clrscr();dis();++an;
									cout<<endl<<"computer  wins";
									getch();goto gp;
									}

								}
								}  }
							if(an==0)
							{clrscr();dis();
							cout<<"Match draw";
							getch();
							goto gp;}
						}

					if(l==2)
						{int s=0;
						clrscr();
						int n=1;
						for(i=0;i<3;i++)
							{
							for(int j=0;j<3;j++)
								{
								m[i][j]=n;
								n++;
								}
							}
						for(int dd=0;dd<9;dd++)
							{
							clrscr();
						      dis();
							if(dd%2==0)
								{
								input(pam);
									for(int r=0;r<3;r++)
								{
								if(((m[0][r]=='#')&&(m[1][r]=='#')&&(m[2][r]=='#'))||((m[r][r]=='#')&&(m[r+1][r+1]=='#')&&(m[r+2][r+2]=='#'))||((m[r][0]=='#')&&(m[r][1]=='#')&&(m[r][2]=='#')))
									{       clrscr();dis();++an;
									cout<<endl<<"    "<<pam<<"  wins";
									getch();
									goto gp;
									}
								}
								}

							else
								{
								int p,q,r,o;
								if(dd==1)
									{
									if((m[0][0]=='#')||(m[0][2]=='#')||(m[2][0]=='#')||(m[2][2]=='#'))
									s=1;
									if((m[0][1]=='#')||(m[1][0]=='#')||(m[1][2]=='#')||(m[2][1]=='#'))
									s=2;
									if(m[1][1]=='#')
									s=3;
									}
								if((s==2)||(s==3))
									{
									aaaaa:
									int r;
									randomize();
									r=random(9);  --r;
									p=r/3;
									q=r%3;
									if((m[p][q]=='#')||(m[p][q]=='*'))
										{
										goto aaaaa;
										}
									else
									{m[p][q]='*';clrscr();dis();}
										for(r=0;r<3;r++)
								{
								if(((m[0][r]=='*')&&(m[1][r]=='*')&&(m[2][r]=='*'))||((m[r][r]=='*')&&(m[r+1][r+1]=='*')&&(m[r+2][r+2]=='*'))||((m[r][0]=='*')&&(m[r][1]=='*')&&(m[r][2]=='*')))
									{               clrscr();dis(); ++an;
									cout<<endl<<"computer  wins";
									getch();goto gp;
									}

								}       }

								if(s==1)
									{medium(r);goto gp;

								}

								}

							}
						if(an==0)
								    {clrscr();dis();
								    cout<<"Match draw";
								    getch();goto gp;
								    }

						}
					if(l==3)
						{
						clrscr();
						int n=1;
						for(i=0;i<3;i++)
							{
							for(int j=0;j<3;j++)
								{
								m[i][j]=n;
								n++;
								}
							cout<<endl;
							}
						for(int as=0;as<9;as++)
							{clrscr();
							dis();
							if(as%2==0)
								{
								if(as==0)
								m[0][0]='#';
								if(as==2)
									{
									if((m[0][1]=='*')||(m[1][2]=='*'))
									m[2][0]='#';
									if((m[1][0]=='*')||(m[2][1]=='*'))
									m[0][2]='#';
									if(m[2][2]=='*')
									m[0][2]='#';
									if(m[0][2]=='*')
									m[2][2]='#';
									if(m[2][0]=='*')
									m[2][2]='#';
									if(m[1][1]=='*')
									m[0][1]='#';
									}
								if(as==4)
									{
									if((m[0][1]=='*')&&(m[2][0]=='#')&&(m[1][0]=='*'))
									m[2][2]='#';
									if((m[0][1]=='*')&&(m[2][0]=='#')&&(m[1][0]!='*'))
									{
									m[1][0]='#';        clrscr();dis();
									cout<<endl<<"computer has won1";
									getch();goto gp;}
									if((m[1][0]=='*')&&(m[0][2]=='#')&&(m[0][1]=='*'))
									m[2][2]='#';
									if((m[1][0]=='*')&&(m[0][2]=='#')&&(m[0][1]!='*'))
									{
									m[0][1]='#';                      clrscr();dis();
									cout<<endl<<"computer has won2";
									getch();goto gp;}
									if((m[2][0]=='*')&&(m[2][2]=='#')&&(m[1][1]=='*'))
									m[0][2]='#';
									if((m[2][0]=='*')&&(m[2][2]=='#')&&(m[1][1]!='*'))
									{
									m[1][1]='#';                clrscr();dis();
									cout<<endl<<"computer has won3";
									getch();goto gp;}
									if((m[0][2]=='*')&&(m[2][2]=='#')&&(m[1][1]=='*'))
									m[2][0]='#';
									if((m[2][0]=='*')&&(m[2][2]=='#')&&(m[1][1]!='*'))
									{
									m[1][1]='#';      clrscr();dis();
									cout<<endl<<"computer has won4";
									getch();goto gp;}
									if((m[1][1]=='*')&&(m[0][1]=='#')&&(m[0][2]=='*'))
									m[2][0]='#';
									if((m[1][1]=='*')&&(m[0][1]=='#')&&(m[0][2]!='*'))
									{
									m[0][2]='#';   clrscr();dis();
									cout<<endl<<"computer has won5";
									getch();goto gp;}
									if((m[2][2]=='*')&&(m[0][2]=='#')&&(m[0][1]=='*'))
									m[2][0]='#';
									if((m[2][2]=='*')&&(m[0][2]=='#')&&(m[0][1]!='*'))
									{
									m[0][1]='#';                      clrscr();dis();
									cout<<endl<<"computer has won6";getch();goto gp;}
									if((m[1][2]=='*')&&(m[2][0]=='#')&&(m[1][0]=='*'))
									m[1][1]='#';
									if((m[0][1]=='*')&&(m[2][0]=='#')&&(m[1][0]!='*')&&(m[2][2]!='*'))
									{
									m[1][0]='#';         clrscr();dis();
									cout<<endl<<"computer has won7";
									getch();goto gp;}
									if((m[2][1]=='*')&&(m[0][2]=='#')&&(m[0][1]=='*'))
									m[1][1]='#';
									if((m[1][0]=='*')&&(m[0][2]=='#')&&(m[0][1]!='*'))
									{
									m[0][1]='#';   clrscr();dis();
									cout<<endl<<"computer has won8";getch();goto gp;}
									}
								if(as==6)
									{
									 if((m[0][1]=='*')&&(m[1][0]=='*')&&(m[1][1]=='*')&&(m[2][0]=='#')&&(m[2][2]=='#'))
									 {m[2][1]='#';  clrscr();dis();
									 cout<<endl<<"computer has won";getch();goto gp;}
									 if((m[0][1]=='*')&&(m[1][0]=='*')&&(m[2][1]=='*')&&(m[2][0]=='#')&&(m[2][2]=='#'))
									 {m[1][1]='#';   clrscr();dis();
									 cout<<endl<<"computer has won";
									 getch();goto gp;}
									 if((m[0][1]=='*')&&(m[1][0]=='*')&&(m[2][1]!='*')&&(m[1][1]!='*')&&(m[2][0]=='#')&&(m[2][2]=='#'))
									 {m[1][1]='#';   clrscr();dis();
									 cout<<endl<<"computer has won";getch();goto gp;}

									 if((m[1][0]=='*')&&(m[0][1]=='*')&&(m[1][1]=='*')&&(m[0][2]=='#')&&(m[2][2]=='#'))
									 {m[1][2]='#';   clrscr();dis();
									 cout<<endl<<"computer has  won      ";getch();goto gp;}
									 if((m[1][0]=='*')&&(m[0][1]=='*')&&(m[1][2]=='*')&&(m[0][2]=='#')&&(m[2][2]=='#'))
									 {m[1][1]='#';     clrscr();dis();
									 cout<<endl<<"computer has won         ";getch();goto gp;}
									 if((m[1][0]=='*')&&(m[0][1]=='*')&&(m[1][2]!='*')&&(m[1][1]!='*')&&(m[0][2]=='#')&&(m[2][2]=='#'))
									 {m[1][1]='#';          clrscr();dis();
									 cout<<endl<<"computer has won ";getch();clrscr();goto gp;}

									 if((m[1][2]=='*')&&(m[1][0]=='*')&&(m[2][0]=='#')&&(m[1][1]=='#')&&(m[0][2]=='*'))
									 {m[2][2]='#';            clrscr();dis();
									 cout<<endl<<"computer 11    ";getch();goto gp;}
									 if((m[1][2]=='*')&&(m[1][0]=='*')&&(m[2][0]=='#')&&(m[1][1]=='#')&&(m[2][2]=='*'))
									 {m[0][2]='#';                      clrscr();dis();
									 cout<<endl<<"compurte12";getch();goto gp;}
									 if((m[1][2]=='*')&&(m[1][0]=='*')&&(m[2][0]=='#')&&(m[1][1]=='#')&&(m[2][2]!='*')&&(m[0][2]!='*'))
									 {m[2][2]='#';                        clrscr();dis();
									 cout<<endl<<"computer:l13";getch();goto gp;}

									 if((m[2][1]=='*')&&(m[0][1]=='*')&&(m[0][2]=='#')&&(m[1][1]=='#')&&(m[2][2]=='*'))
									 {m[2][0]='#';                          clrscr();dis();
									 cout<<endl<<"computer;1  14";getch();goto gp;}
									 if((m[2][1]=='*')&&(m[0][1]=='*')&&(m[0][2]=='#')&&(m[1][1]=='#')&&(m[2][0]=='*'))
									 {m[2][2]='#';                                clrscr();dis();
									 cout<<endl<<"computer has won 15 ";getch();goto gp;}
									 if((m[2][1]=='*')&&(m[0][1]=='*')&&(m[0][2]=='#')&&(m[1][1]=='#')&&(m[2][0]!='*')&&(m[2][2]!='*'))
									 {m[2][0]='#';      clrscr();dis();
									 cout<<endl<<"computer16";getch();
									 goto gp; }

									 if((m[2][0]=='*')&&(m[1][1]=='*')&&(m[0][1]=='*')&&(m[0][2]=='#')&&(m[2][2]=='#'))
									 {m[1][2]='#';                      clrscr();dis();
									 cout<<endl<<"computer17";getch();goto gp;}
									 if((m[2][0]=='*')&&(m[1][1]=='*')&&(m[1][2]=='*')&&(m[0][2]=='#')&&(m[2][2]=='#'))
									 {m[0][1]='#';        clrscr();dis();
									 cout<<endl<<"computer has won 18";getch();goto gp;}
									 if((m[2][0]=='*')&&(m[1][1]=='*')&&(m[0][1]!='*')&&(m[1][2]!='*')&&(m[2][2]=='#')&&(m[0][2]=='#'))
									 {m[1][2]='#';  clrscr();dis();
									 cout<<"computer had won";getch();goto gp;}

									 if((m[0][2]=='*')&&(m[2][2]=='#')&&(m[1][1]=='*')&&(m[2][0]=='#')&&(m[1][0]=='*'))
									 {m[2][1]='#';  clrscr();dis();
									 cout<<"computer has won";getch();goto gp;}
									 if((m[0][2]=='*')&&(m[2][2]=='#')&&(m[1][1]=='*')&&(m[2][0]=='#')&&(m[2][1]=='*'))
									 {m[1][0]='#';   clrscr();dis();
									 cout<<"computer has won";getch();goto gp;}
									 if((m[0][2]=='*')&&(m[2][2]=='#')&&(m[1][1]=='*')&&(m[2][0]=='#')&&(m[2][1]!='*')&&(m[1][0]!='*'))
									 {m[1][0]='#';   clrscr();dis();
									 cout<<"computer has won";getch();goto gp;}

									 if((m[2][2]=='*')&&(m[0][2]=='#')&&(m[0][1]=='*')&&(m[2][0]=='#')&&(m[1][0]=='*'))
									 {m[1][1]='#';   clrscr();dis();
									 cout<<"computer has won";getch();goto gp;}
									 if((m[2][2]=='*')&&(m[0][2]=='#')&&(m[0][1]=='*')&&(m[2][0]=='#')&&(m[1][0]!='*')&&(m[1][1]!='*'))
									 {m[1][1]='#';   clrscr();dis();
									 cout<<"computer has won";getch();goto gp;}
									 if((m[2][2]=='*')&&(m[0][2]=='#')&&(m[0][1]=='*')&&(m[2][0]=='#')&&(m[1][1]=='*'))
									 {m[1][0]='#';   clrscr();dis();
									 cout<<"computer has won";getch();goto gp;}
									 if((m[1][1]=='*')&&(m[0][2]=='*')&&(m[0][1]=='#')&&(m[2][0]=='#')&&(m[1][0]!='*'))
									 {m[1][0]='#';      clrscr();dis();
									 cout<<"computer has won";getch();goto gp;}
									 if((m[1][1]=='*')&&(m[0][2]=='*')&&(m[0][1]=='#')&&(m[2][0]=='#')&&(m[1][0]=='*'))
									 m[1][2]='#';

									}

								if(as==8)
									{
									if(m[2][1]==8)
									{m[2][1]='#';    clrscr();dis();
									cout<<endl<<"match draw";getch();goto gp;
									}
									if(m[2][2]==9)
									{m[2][2]='#';   clrscr();dis();
									cout<<endl<<"match draw ";getch();goto gp;}
									}
								}
							else
								{
								int o,p,q;
								cout<<pam<<":enter your choice";
								aabb:
								cin>>o;
								o--;
								p=o/3;
								q=o%3;
								if((m[p][q]=='#')||(m[p][q]=='*'))
									{
									cout<<endl<<"wrong choice";
									cout<<endl<<"enter new choice";
									goto aabb;
									}
								else
								m[p][q]='*';
								}

							 }

						}
					  }
				   if(k==2)
					{
					int tm;int mmm,w,kk=0,gg=0,va=0,yy=0;     char d[50],g[50];
					clrscr(); int gdriver = DETECT, gmode, errorcode;

/* initialize graphics mode */
initgraph(&gdriver, &gmode, "");
settextstyle(3,0,3);setcolor(4);
outtextxy(20,20,"player 1 enter your name");
gets(d);
outtextxy(50,50,"player 2 enter your name");
gets(g);                                              cleardevice();
						settextstyle(3,0,3);setcolor(4);
					outtextxy(100,100,"1:Single Match");
					outtextxy(100,150,"2:Tournament");
					outtextxy(100,200,"Enter choice t(1/2):-");
					cin>>tm;
						if(tm==2)
						{
						if(va==0)
							{
							outtextxy(100,300,"    tell us the no. of match(3/5/7):-");
							cin>>mmm; va++;
							}     closegraph();
						for(yy;yy<mmm;yy++)
							{  clrscr();
							if(yy==0)
							{
							cout<<endl<<endl<<"                  First match";
							cout<<endl<<endl<<"            "<<d<<"'s score = "<<kk;
							cout<<endl<<endl<<"            "<<g<<"'s score = "<<gg;

							}
							if(yy==1)
							{
							cout<<endl<<endl<<"                 Second match";
							cout<<endl<<endl<<"            "<<d<<"'s score = "<<kk;
							cout<<endl<<endl<<"            "<<g<<"'s score = "<<gg;
													}
							if(yy==2)
							{
							cout<<endl<<endl<<"                 Third match";
								cout<<endl<<endl<<"            "<<d<<"'s score = "<<kk;
							cout<<endl<<endl<<"            "<<g<<"'s score = "<<gg;
													}
							if(yy==3)
							{
							cout<<endl<<endl<<"                 Fourth match";
								cout<<endl<<endl<<"            "<<d<<"'s score = "<<kk;
							cout<<endl<<endl<<"            "<<g<<"'s score = "<<gg;
												}
							if(yy==4)
							{
							cout<<endl<<endl<<"                 Fifth match";
								cout<<endl<<endl<<"            "<<d<<"'s score = "<<kk;
							cout<<endl<<endl<<"            "<<g<<"'s score = "<<gg;
													}

							if(yy==5)
							{
							cout<<endl<<endl<<"                 Sixth match";
								cout<<endl<<endl<<"            "<<d<<"'s score = "<<kk;
							cout<<endl<<endl<<"            "<<g<<"'s score = "<<gg;

							}

							if(yy==6)
							{
							cout<<endl<<endl<<"                 Seventh match";
								cout<<endl<<endl<<"            "<<d<<"'s score = "<<kk;
							cout<<endl<<endl<<"            "<<g<<"'s score = "<<gg;

							}

							getch();
						       goto pg;
							pg1:
							pg2:
							}
						if(gg==kk)
					     {       	cout<<endl<<endl<<"            "<<d<<"'s score = "<<kk;
							cout<<endl<<endl<<"            "<<g<<"'s score = "<<gg;


						cout<<endl<<endl<<endl<<endl<<"      Tournament draw";
						}
						else
							{
							if(gg>kk)
							{ 	cout<<endl<<endl<<"            "<<d<<"'s score = "<<kk;
							cout<<endl<<endl<<"            "<<g<<"'s score = "<<gg;


							cout<<endl<<endl<<endl<<"            "<<g<<" wins the tournament";
							cout<<endl<<endl<<"            CONGRATULATIONS";
							 }
							else
						       {  	cout<<endl<<endl<<"            "<<d<<"'s score = "<<kk;
							cout<<endl<<endl<<"            "<<g<<"'s score = "<<gg;


							cout<<endl<<endl<<endl<<"            "<<d<<" wins the tournament";
							 cout<<endl<<endl<<"            CONGRATULATIONS";
							 }
							 } getch();
							 goto gp;
						 }

					if(tm==1)
						{
						pg:
						clrscr();
						int n,o,p,q,r,s,t,u,v;char w;
						aaaaaa:
						clrscr();n=1;
						for(int x=0;x<3;x++)
							{
							for(int y=0;y<3;y++)
								{
								m[x][y]=n;n++;
								}
							}
						for(int z=0;z<9;z++)
							{clrscr();
							dis();
							if(z%2==0)
								{
								p=0;q=0;
								aaaaaaa:
								cout<<endl<<d<<": enter choice ";
								cin>>o;--o;
								p=o/3;q=o%3;
								if((m[p][q]!='#')&&(m[p][q]!='*'))
									{
									m[p][q]='#';clrscr();dis();
									}
								else
									{
									cout<<endl<<"enter other choice";
									goto aaaaaaa;
									}
								for(int r=0;r<3;r++)
									{
									if(((m[0][r]=='#')&&(m[1][r]=='#')&&(m[2][r]=='#'))||((m[r][r]=='#')&&(m[r+1][r+1]=='#')&&(m[r+2][r+2]=='#'))||((m[r][0]=='#')&&(m[r][1]=='#')&&(m[r][2]=='#'))||((m[0][2]=='#')&&(m[1][1]=='#')&&(m[2][0]=='#')))
										{
										++an;clrscr();dis();++kk;
										cout<<endl<<endl<<"       "<<d<<" wins";getch();clrscr();
										if(tm==1)
										goto aaaaaaaa;
										else
										goto pg1;
										}
									}
								}
							else
								{
								p=0;q=0;
								aaaaaaaaa:
								cout<<endl<<g<<" enter choice ";
								cin>>o;--o;
								p=o/3;q=o%3;
								if((m[p][q]!='*')&&(m[p][q]!='#'))
									{
									m[p][q]='*';clrscr();dis();
									}
								else
									{
									cout<<endl<<endl<<"enter other choice ";
									goto aaaaaaaaa;
									}
								for(r=0;r<3;r++)
									{
									if(((m[0][r]=='*')&&(m[1][r]=='*')&&(m[2][r]=='*'))||((m[r][r]=='*')&&(m[r+1][r+1]=='*')&&(m[r+2][r+2]=='*'))||((m[r][0]=='*')&&(m[r][1]=='*')&&(m[r][2]=='*'))||((m[0][2]=='*')&&(m[1][1]=='*')&&(m[2][0]=='*')))
										{
										       ++an;   clrscr();dis(); ++gg;
										cout<<endl<<endl<<"       "<<g<<" wins";getch();        clrscr();
										if(tm==1)
										goto aaaaaaaa;
										else
										goto pg2;
										}
									}

								}
									  }
						if(z==9)
							{
							clrscr();dis();
							cout<<endl<<endl<<"Match draw";
							getch();goto gp;
							}
					  }
					  aaaaaaaa:
					 abcd:
					  goto gp;

				     }    if(k==3)
				     goto ppgg;  }
			if(h==2)
				{
				 clrscr();int f;
int n,che,chec,e;int b,c;       strcpy(tit,"M G C ");
strcpy(tat," A I ");
strcpy(gam,"MAGIC");
head();
abcdt:    mag:
int gdriver = DETECT, gmode, errorcode;

/* initialize graphics mode */
initgraph(&gdriver, &gmode, "");
settextstyle(2,0,6);setcolor(6);
outtextxy(100,100,"TIME TO PLAY  ");
outtextxy(100,150,"1:START GAME");
outtextxy(100,200,"2:INSTRUCTIONS");
outtextxy(100,250,"3:EXIT");
outtextxy(100,300,"ENTER CHOICE:-");
cin>>e;   closegraph();
if(e==1)
{abc:n=1;
for(int i=0;i<x;i++)
{
for(int j=0;j<y;j++)
{
a[i][j]=n;
n++;
}
}
if(x==3)
f=20;
if(x==5)
f=50;
if(x==7)
f=80;

for(k=f;k>0;k--)
{clrscr();disc();
cout<<endl<<endl<<"              NUMBER OF MOVES LEFT =  "<<k;
aat:
cout<<endl<<endl<<"              Enter  Position  U  wanna Interchange";
cin>>b;
cin>>c;
chec=ch11(b,c);
if(chec==0)
{cout<<endl<<endl<<"              WRONG INTERCHANGE  ";goto aat;}
check(b,c);
che=ch00();
if(che==0)
{cout<<endl<<endl<<"              U won";getch();
 cout<<endl<<endl<<"              U HAVE ENTER NEXT LEVEL :";
x=x+2;y=y+2;goto abc;}
clrscr();
disc();}
}

if(e==2)
{clrscr();    int gdriver = DETECT, gmode, errorcode;

/* initialize graphics mode */
initgraph(&gdriver, &gmode, "");
char ch;
	cleardevice();
	settextstyle(1,0,1);
	setcolor(CYAN);
	rectangle(30,50,600,450);
	setfillstyle(LTSLASH_FILL,CYAN);
	floodfill(40,40,CYAN);
	textattr(7+BLINK);
	setcolor(GREEN);
	outtextxy(60,70,"1:Player has to arrange the grid in such a way that  ");
outtextxy(62,120,"the sum of all the rows and column are equal.");
outtextxy(60,170,"2:Player can change the places by writing no after space.");
outtextxy(60,220,"3:For the folowing grids the sum must be:-");
outtextxy(80,270,"3*3 = 15");
outtextxy(80,320,"5*5 = 65");
outtextxy(80,370,"7*7 = 175");
outtextxy(60,420,"4:As you win you can go to next harder level.");

	while(1)
	{
		ch=getch();
		if(ch==13)
		break;
	}
	cleardevice();
	textattr(07);
	setcolor(3);
      closegraph();
clrscr();
goto abcdt;
}

if(e==3)
goto ppgg;
if(k==0)
{cout<<endl<<endl<<"              U R A BIG LOOSER GO TO MOUNTAIN";
getch();goto mag;
}
}
    if(h==3)
    {   closegraph();      int gdriver = DETECT, gmode, errorcode;

/* initialize graphics mode */
initgraph(&gdriver, &gmode, "");
		 settextstyle(4,0,5);setcolor(7);
outtextxy(50,100,"TIME TO PLAY CASINO");getch();

     long mo=100,s,ss,sss=0,f,B=0;
     char a,b,c; ss=sss;
     char y,nn;
cleardevice();
strcpy(tit,"C S N ");
strcpy(tat," A I O");
strcpy(gam,"CASINO");

head();
at:
  closegraph();
  cas:
   gdriver = DETECT, gmode, errorcode;

/* initialize graphics mode */
initgraph(&gdriver, &gmode, "");	settextstyle(7,0,4);setcolor(9);
outtextxy(100,100,"CASINO ROYALS ");
outtextxy(100,150,"1:Play");
outtextxy(100,200,"2:Help");
outtextxy(100,250,"3:Exit");
outtextxy(100,300,"  t(1/2/3)");
cin>>f; cleardevice(); closegraph();
if(f==1)
{     bb:
			cout<<endl<<endl<<endl<<endl<<endl;
aatt:
for(int i=0;i<100,i>=0;i++)
{
randomize();

for(int j=0;j<30,j>=0;j++)
{                 clrscr();
int d;
cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
cout<<"                                       "<<"CASINO"<<endl<<endl;
cout<<"                                                          "<<"Money";
cout<<endl<<endl;
d=mai();
if(d!= 0)
goto aaat;
else
{
a=random(9);
	       in(a);
	       }
aaat:
cout<<"               "<<a;
d=mai();
if(d!= 0)
goto aaaat;
else
{
b=random(9);
in(b);
	   }
aaaat:
cout<<"               "<<b;
d=mai();
if(d!= 0)
goto aaaaat;
else
{
c=random(9);
in(c);
	   }
aaaaat:
cout<<"               "<<c;
delay(200);
d=mai();
if(d!=0)
{
i=i-9;
      j=j-5;
}
}
}
    getch();
       s=mo;
if((a==b)&&(a==c))
mo=mo+20;
if((a==b)&&(a=='$'))
mo=mo+50;
if((a==c)&&(a=='$'))
mo=mo+30;
if((b==c)&&(b=='$'))
mo=mo+30;
if(a=='$')
mo=mo+10;
if((a==b)&&(b==c)&&(a=='$'))
mo=mo+100;
if((a==b)&&(a==c))
mo=mo+50;
if((a==b))
mo=mo+20;
if((a==c))
mo=mo+15;
if(b==c)
mo=mo+15;
if(a=='?')
mo=mo+5;
if(mo==s)
mo=mo-ss;
else
mo=mo+ss;
cout<<"          Rs."<<mo;
cout<<endl<<endl;
if(mo<=0)
{
cout<<endl<<endl<<"                       You lost";
cout<<endl<<endl<<"                       Get lost and have some money";
if(B==0)
{
cout<<endl<<endl<<"                       Want a chance to pay amount"<<endl;
cout<<endl<<"                       t(y/n):-";
cin>>nn;
if(nn=='y')
{
B++;
goto bb;
}
else
cout<<endl<<endl<<"                        Pay amount or go to jail";
getch();
goto cas;
}

}
else
{
cout<<endl<<endl<<"                              wanna bet again";
cout<<endl<<endl<<"                                t(y/n) :- ";
cin>>y;
if(y=='n')
{                    mo=mo-100;
cout<<endl<<endl<<"                              "<<"Your black moneys = Rs."<<mo<<endl;
if(mo<0)
{
if(B==0)
{
cout<<endl<<endl<<"                              "<<"want a chance to pay amount"<<endl;
cin>>nn;
if(nn=='y')
{
B++;
goto bb;
}
else
{cout<<endl<<endl<<"                             "<<"Pay amount or go to jail";
getch();goto cas;}
}
else
{cout<<endl<<endl<<"                             "<<"Pay amout or go to jail";
getch();goto cas;}
}
else
{
cout<<endl<<endl<<"                              "<<"Enjoy your money";
cout<<endl<<endl<<"                                   "<<"BYE";
goto cas;
}
getch();
goto cas;
}
else
{
cout<<endl<<endl<<endl<<endl;
cout<<"                              "<<"Enter bet money";
cout<<endl<<endl<<"                                Rs. ";
cin>>ss;
goto aatt;
}
 }
getch();
}
if(f==2)
{
clrscr();
int gdriver = DETECT, gmode, errorcode;

/* initialize graphics mode */
initgraph(&gdriver, &gmode, "");
char ch;
	cleardevice();
	settextstyle(1,0,1);
	setcolor(CYAN);
	rectangle(30,50,600,450);
	setfillstyle(LTSLASH_FILL,8);
	floodfill(40,40,CYAN);
	textattr(7+BLINK);
	setcolor(GREEN);
	outtextxy(50,60,"Instructions:-");
outtextxy(50,80,"1:You got Rs.100 from casino.");
outtextxy(50,100,"2:If you want to bet you can.");
outtextxy(50,120,"3:If you get any of combination your money increases  ");
outtextxy(50,140,"  as given with your bet money.");
outtextxy(50,160,"4:If you don't get any of combination your money get  ");
outtextxy(50,180,"  reduce by your bet money.");
outtextxy(80,200,"   $     $     $     =100");
outtextxy(80,220,"   $     $           =50");
outtextxy(80,240,"   $           $     =30");
outtextxy(80,260,"         $     $     =30");
outtextxy(80,280,"   $                 =10");
outtextxy(50,300,"5:Some special bonus.");
outtextxy(50,320,"6:If you quit your won money is reduced by given money.");
outtextxy(50,340,"7:And you get your won money");
outtextxy(50,360,"8:If your money is less than 0.You have to pay the amout.");
outtextxy(50,380,"9:You got one chance to pay. If you loose you have  ");
outtextxy(50,400,"  to pay that money also.");
outtextxy(50,420,"10:If you win you have to get/pay the reduced money .");

	while(1)
	{
		ch=getch();
		if(ch==13)
		break;
	}
	cleardevice();
	textattr(07);
	setcolor(3);
closegraph();
goto at;
}
if(f==3)
goto ppgg;
getch();
    }  if(h==4)
      exit(0);
}
closegraph();	}
void wins()
{
for(int r=0;r<3;r++)
{
if(((tem[0][r]=='*')&&(tem[1][r]=='*')&&(tem[2][r]=='*'))||((tem[r][r]=='*')&&(tem[r+1][r+1]=='*')&&(tem[r+2][r+2]=='*'))||((tem[r][0]=='*')&&(tem[r][1]=='*')&&(tem[r][2]=='*'))||((tem[0][2]=='*')&&(tem[1][1]=='*')&&(tem[2][0]=='*')))
{        ++an;clrscr();disp();
cout<<endl<<"       Computer  wins";
getch();
ex=1;
}
}
for( r=0;r<3;r++)
{
if(((tem[0][r]=='#')&&(tem[1][r]=='#')&&(tem[2][r]=='#'))||((tem[r][r]=='#')&&(tem[r+1][r+1]=='#')&&(tem[r+2][r+2]=='#'))||((tem[r][0]=='#')&&(tem[r][1]=='#')&&(tem[r][2]=='#'))||((tem[0][2]=='#')&&(tem[1][1]=='#')&&(tem[2][0]=='#')))
{              ++an;clrscr();disp();
cout<<endl<<"      "<<pam<<" wins";
getch();
ex=1;
}
}
if(an==0)
{
cout<<"        Match draw";
getch();
ex=1;
}
}



void medium(int r)
{int co=0;
if(co==0)
{   if(m[0][0]=='#')
{ch0();cou=4;}
if(m[0][2]=='#')
{ch1();cou=1;}
if(m[2][2]=='#')
{ch2();cou=2;}
if(m[2][0]=='#')
{ch3();cou=3;}
co++;}
      int an=0;
									if(tem[0][0]=='#')
									{tem[1][1]='*';
									clrscr();
									disp();        input(::pam);
											if(tem[0][1]=='#')
									 {
										 tem[0][2]='*';
										    clrscr();
										    disp();
										  input(::pam);
									    if(tem[2][0]=='#')
										    {
										    tem[1][0]='*';
										    clrscr();
										    disp();
										    input(pam);
											if(tem[1][2]=='#')
												{
												 tem[2][2]='*';
												 clrscr();
												 disp();
											       input(pam);
												  }
												  else
												  tem[1][2]='*';
												  clrscr();
												  disp();
											  }
											  else
											  tem[2][0]='*';
											  clrscr();
											  disp();

											wins();
											if(ex==1)
											goto pppggg;


								}         }
								if(tem[0][2]=='#')
								{
								tem[0][1]='*';
								clrscr();
								disp();
								    input(pam);
								   if(tem[2][1]=='#')
								   {
								   tem[1][0]='*';
								   clrscr();
								   disp();
								    input(pam);
								   if(tem[1][2]=='#')
								   {
								   tem[2][2]='*';
								   clrscr();
								   disp();
								    input(pam);
								   }
								   else
								   tem[1][2]='*';
								   clrscr();
								   disp();
								   }
								   else
								   tem[2][1]='*';
								   clrscr();
								   disp();
									wins();
									if(ex==1)
											goto pppggg;

								}
								if(tem[1][0]=='#')
								{

								tem[2][0]='*';
								clrscr();
								disp();
								  input(pam);
									if(tem[0][2]=='#')
									{
									tem[0][1]='*';
									clrscr();
									disp();
									input(pam);
								   if(tem[2][1]=='#')
								   {tem[2][2]='*';
								   clrscr();
								   disp();
								  input(pam);  }
								   else
								   tem[2][1]='*';
								   clrscr();
								   disp();
								   }
								   else
								   tem[0][2]='*';
								   clrscr();
								  disp();
									wins();
									if(ex==1)
											goto pppggg;

								}
								if(tem[1][2]=='#')
								{

								tem[2][1]='*';
								clrscr();
								disp();
							input(pam);
								if(tem[0][1]=='#')
								{
								 tem[0][2]='*';
								 clrscr();
								 disp();
								 input(pam);
								 if(tem[2][0]=='#')
								 {
								 tem[1][0]='*';
								 clrscr();
								 disp();
								 input(pam);
								  }
								 else
								 tem[2][0]='*';
								 clrscr();
								 disp();
								 }
								 else
								 tem[0][1]='*';
								 clrscr();
									disp();
									wins();
									if(ex==1)
											goto pppggg;

								}
								if(tem[2][0]=='#')
								{

								tem[1][0]='*';
								clrscr();
								disp();
								input(pam);
								  if(tem[1][2]=='#')
								  {
								  tem[0][1]='*';
								  clrscr();
								  disp();
								  input(pam);
								if(tem[2][1]=='#')
								{
								tem[2][2]='*';
								clrscr();
								disp();
								input(pam);
								}
								else
								tem[2][1]='*';

							clrscr();
							disp();
								}
								tem[1][2]='*';

								clrscr();
								disp();
						wins();
						if(ex==1)
											goto pppggg;

								}
								if(tem[2][1]=='#')
								{

								tem[1][0]='*';
								clrscr();
								disp();
								input(pam);
								if(tem[1][2]=='#')
								{
								tem[0][2]='*';
								clrscr();
								disp();
								input(pam);
								if(tem[2][0]=='#')
								{
								tem[2][2]='*';
								clrscr();
								disp();
								input(pam);
								}
								else
								tem[2][0]='*';
								 clrscr();
								 disp();
								}
								else
								tem[1][2]='*';
								clrscr();
								disp();
								wins();
								if(ex==1)
											goto pppggg;

								}
								if(tem[2][2]=='#')
								{

								tem[2][1]='*';
								clrscr();
								disp();
								input(pam);
								if(tem[0][1]=='#')
								{
								tem[0][2]='*';
								clrscr();
								disp();
								input(pam);
								if(tem[2][0]=='#')
								 {
								 tem[1][0]='*';
								 clrscr();
								 disp();
								 input(pam);
								    }
								    else
								    tem[2][0]='*';
								    clrscr();
								    disp();
								    }
								    else
								    tem[0][1]='*';

								    clrscr();
								    disp();
								    wins();
								    if(ex==1)goto pppggg;
								 }
							       pppggg:	}

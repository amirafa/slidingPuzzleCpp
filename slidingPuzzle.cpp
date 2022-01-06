/* Yaser Mohammady */ 
/* JURCHIN */
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;
class game{
private:
	int a[3][3];
	int satr;
	int seton;
public:
	game();
	int check(int a[3][3],int,int);
	void setrnd();
	void swap(char);
	void print();
	int checkf();
	void start();
	};
game::game(){
	setrnd();
	}
int game::checkf(){
	for(int i=0,k=1;i<3;i++)
		for(int j=0;j<3;j++,k++)
			if(a[i][j]!=k)
				return 0;
	return 1;
	}
int game::check(int a[3][3],int i,int j){
	int n=0,m=0;
	for(m=0;m<3;m++)
		for(n=0;n<3;n++){
			if(n==j && m==i)
				return 0;
			if(a[i][j]==a[m][n])
				return 1;
			}
	return 0;
	}
void game::setrnd(){
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++){
			a[i][j]=rand()%(9)+1;
			while(check(a,i,j)==1)
				a[i][j]=rand()%(9)+1;
			}
	}
void game::swap(char c){
	int sr=satr;
	int st=seton;
	if(c=='w')
		if(satr<2)
			satr++;
	if(c=='s')
		if(satr>0)
			satr--;
	if(c=='d')
		if(seton>0)
			seton--;
	if(c=='a')
		if(seton<2)
			seton++;
	int d=a[sr][st];
	a[sr][st]=a[satr][seton];
	a[satr][seton]=d;
	}
void gotoxy(int x,int y)
{
    COORD pos;
    HANDLE hConsole = GetStdHandle ( STD_OUTPUT_HANDLE );
 
    if (INVALID_HANDLE_VALUE != hConsole)
    {
        pos.X = x;
        pos.Y = y;
 
        SetConsoleCursorPosition( hConsole, pos );
    }
}
void game::print(){
	for(int i=1;i<=13;i+=4)
		for(int j=1;j<=7;j++){
			gotoxy(33+i,j+9);
			cout<<"|";
			}
	for(int i=1;i<=7;i+=2)
		for(int j=1;j<=9;j+=4){
			gotoxy(33+j,i+9);
			cout<<"+---+";
			}
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++){
			if(a[j][i]==9){
				gotoxy(33+4*i+3,2*(j+1)+9);
				cout<<" ";
				satr=j;
				seton=i;
				}
			else {
				gotoxy(33+4*i+3,2*(j+1)+9);
				cout<<a[j][i];
				}
			}
	}
void game::start(){
	system("cls");
	char c;
	while(1){
	print();
	c=getch();
	swap(c);
	if(c=='q')
		return;
	if(c=='r')
		setrnd();
	if(checkf()==1){
		print();
		gotoxy(5,2);
		cout<<"YOU WIN";
		getch();
		return;
		}
	}
}
int main(){
game a;
a.start();
}
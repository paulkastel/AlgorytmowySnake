#include<Windows.h> //smieszna biblioteka Windows do kolorkow 
#include<iostream>
#include"global_ruch.h"
using namespace std;

//prawo
void right(int &size, char** &tab, int &x, int &y, int &licznik, int &ruch, bool &mr)
{
	bool tmp2 = false, tmp1 = false;
	ruch = 0;
	while(true)	//zeby nie konczyl ruchu po jednym kroku
	{
		//sprawdzam czy nie mam przeszkody, albo sciany przed soba
		if(tab[x][y+1] != 'X' && tab[x][y+1] != '#' && y+1<size )
		{
			tab[x][y] = '#';
			tab[x][y+1] = 'A';
			y++;			//zmieniam pozycje bohatera
			licznik++;		//zwiekszam glowny licznik
			ruch++;			//zwiekszam licznik aktualnego ruchu
		}
		else
		{	
			cout<<"\n\nGOIN' RIGHT by "<<ruch;
			poka_tab(size, tab);	//pokazuje ile przeszdlem
			cout<<"\nI CANNOT GO MORE!";

			if(x==size-1)	//sprawdzam czy nie mam ponizej sciany
				tmp1 = true;		//mam
			if(tmp1 == false)		//jesli nie mam to 
			{
				//sprawdzam czy nie mam tam przeszkody
				if(tab[x+1][y] !='X' && tab[x+1][y] !='#')
				{	
					cout<<"\nI TRY GO DOWN... "; //ide w dol
					down(size,tab, x, y, licznik, ruch, mr);
					break;
				}
			}
			if(x<=1)		//sprawdzam czy nie mam nad soba sciany
				tmp2 = true;		//mam
			if(tmp2 == false)		//jesli nie mam to
			{
				//sprawdzam czy nie ma tam przeszkody
				if(tab[x-1][y] !='X' && tab[x-1][y] !='#')
				{
					cout<<"\nI TRY GO UP!... ";	//ide w gore
					up(size,tab, x, y, licznik, ruch, mr);
					break;
				}
			}
			cout<<"\nDEAD END!! END OF TRIP!";
			mr = false;		//blokada! - brak mozliwosci ruchu
			break;			//wyjscie z while(true)
		}
	}
}

//dol
void down(int &size, char** &tab, int &x, int &y, int &licznik, int &ruch, bool &mr)
{	
	bool tmp2 = false, tmp1 = false;
	ruch=0;	
	while(true)
	{
		bool zmiana=false;
		if(x+1<size)
		{
			zmiana = false;
			if(tab[x+1][y]!= 'X' && tab[x+1][y]!= '#')
			{
				zmiana = true;
				tab[x][y] = '#';
				tab[x+1][y] = 'A';
				x++;
				licznik++;
				ruch++;
			}
		}
		if(zmiana == false)
		{
			cout<<"\n\nGOIN' DOWN by "<<ruch;
			poka_tab(size, tab);
			cout<<"\nI CANNOT GO MORE!";
			if(y<=1)
				tmp1 = true;

			if(tmp1 == false)
			{
				if(tab[x][y-1] != 'X' && tab[x][y-1] != '#')
				{cout<<"\nI TRY GO LEFT... ";
				left(size,tab, x, y, licznik, ruch, mr);
				break;
				}
			}
			if(y==size-1)
				tmp2 = true;

			if(tmp2 == false)
			{
				if(tab[x][y+1] != 'X' && tab[x][y+1] != '#')
				{
					cout<<"\nI TRY GO RIGHT... ";
					right(size,tab, x, y, licznik, ruch, mr);
					break;
				}
			}
			cout<<"\nDEAD END!! END OF TRIP!";
			mr = false;
			break;
		}
	}
}

//lewo
void left(int &size, char** &tab, int &x, int &y, int &licznik, int &ruch, bool &mr)
{
	bool tmp2=false, tmp1=false;
	ruch=0;
	while(true)
	{
		if(tab[x][y-1] != 'X' && tab[x][y-1] != '#' && y-1>=0)
		{
			tab[x][y] = '#';
			tab[x][y-1] = 'A';
			y--;
			licznik++;
			ruch++;
		}
		else
		{
			cout<<"\n\nGOIN' LEFT by "<<ruch;
			poka_tab(size, tab);
			cout<<"\nI CANNOT GO MORE!";
			if(x<=1)
				tmp2 = true;
			if(tmp2 == false)
			{
				if(tab[x-1][y] !='X' && tab[x-1][y] !='#')
				{
					cout<<"\nI TRY GO UP... ";
					up(size,tab, x, y, licznik, ruch, mr);
					break;
				}
			}
			if(x==size-1)
				tmp1 = true;
			if(tmp1 == false)
			{
				if(tab[x+1][y] !='X' && tab[x+1][y] !='#')
				{
					cout<<"\nI TRY GO DOWN... ";
					down(size,tab, x, y, licznik, ruch, mr);
					break;
				}
			}
			cout<<"\nDEAD END!! END OF TRIP!";
			mr = false;
			break;
		}
	}
}

//gora
void up(int &size, char** &tab, int &x, int &y, int &licznik, int &ruch, bool &mr)
{
	bool tmp1 = false;
	ruch=0;				//zerowanie licznika dla nowego ruchu
	while(true)			//zeby sie ruszal w gore do oporu
	{
		//nie kazda przeszkoda ma pozycje sciany wiec
		//cos tam nie dzialalalo przy odejmowaniu 
		//i robila sie nieskoczona petla- flagi to rozwiazaly sprawe
		//podobnie przy ruchu w dol
		bool zmiana=false;
		if(x-1>=0)
		{
			zmiana = false;
			if(tab[x-1][y] != 'X' && tab[x-1][y] != '#')
			{
				zmiana=true; //potwierdzam to ze ruszylem sie do gory
				tab[x-1][y] = 'A';
				tab[x][y]= '#';
				x--;		//zmiana pozycji w gore
				licznik++;
				ruch++;
			}
		}
		//jesli nie ruszyl sie do gory tzn ze trafil na przeszkode
		if(zmiana ==false)	
		{
			cout<<"\n\nGOIN' UP by "<<ruch;
			poka_tab(size, tab);
			cout<<"\nI CANNOT GO MORE!";
			if(y==size-1)		//nie mam sciany na prawo?
				tmp1 = true;	//masz
			if(tmp1 == false)	//jesli nie sciana
			{					//to moze przeszkoda?
				if(tab[x][y+1] != 'X' && tab[x][y+1] != '#')
				{
					cout<<"\nI TRY GO RIGHT... ";	//czysto, idz
					right(size,tab, x, y, licznik, ruch, mr);
					break;
				}
			}
			if(tab[x][y-1] != 'X' && tab[x][y-1] != '#')
			{
				cout<<"\nI TRY GO LEFT... ";
				left(size,tab, x, y, licznik, ruch, mr);
				break;
			}
			cout<<"\nDEAD END!! END OF TRIP!";
			mr = false; //blokada. nie da sie w gore, nie da sie w prawo/lewo
			break;
		}
	}
}

//wswietlanie tablicy
void poka_tab(int size, char **tab)
{
	//do ustawienia kolorkow
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	cout<<"\n/";
	for(int i=0; i<size; i++)
		cout<<"-";
	cout<<"\\\n";
	for(int i=0; i<size; i++)
	{
		cout<<"|";
		for(int j=0; j<size; j++)
		{
			if(tab[i][j] == '#')
			{	
				SetConsoleTextAttribute( hOut, 11);		//cyan
				cout<<tab[i][j];
			}
			else if(tab[i][j] == 'A')
			{
				SetConsoleTextAttribute( hOut, 10);		//neongreen
				cout<<tab[i][j];
			}
			else if(tab[i][j] == 'X')
			{
				SetConsoleTextAttribute( hOut, 19 );	//lightbluewithdark
				cout<<tab[i][j];
			}
			else
				cout<<tab[i][j];
			SetConsoleTextAttribute( hOut, 7);			//console grey
		}
		cout<<"|\n";
	}
	cout<<"\\";
	for(int i=0; i<size; i++)
		cout<<"-";
	cout<<"/";
}

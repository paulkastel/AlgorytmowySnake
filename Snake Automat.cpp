#include<time.h>
#include<iostream>
#include"global_ruch.h" //zalaczenie globalnych funkcji ruchu do pliku
using namespace std;

/*-----------------------------------------------------
Jest to cos w rodzaju snake'a automata.
Waz sam zawsze porusza sie zgodznie z kierunkami zegara
i zostawia za soba hasztagi. Skreca po zderzeniu ze sciana lub X.
Uzytkownik moze wybrac wielkosc planszy i gestosc przeszkod.

Mozna by sprobowac dodac: mozliwosc kierowania wezem i
zapisywanie szczegolowych wynikow do pliku...
-----------------------------------------------------*/

//Funkcja tworzy plansze z przeszkodami w losowych miejscach
//Uzytkownik wybiera jak gesto maja stac przeszkody
//& - wskaznik do pracy na tych KONKRETNYCH zmiennych
void tworz_plansze(int size, char **tab, int x, int y)
{	
	//Blokada zeby nie wpisywac liter oraz zeby nie losowac liczb ujemnych
	int gest=0;
	cout<<"Wybierz gestosc przeszkod (1 - duzo | n - malo ): ";
	while(!(cin>>gest) || gest<=0 )
	{
		cout<<"Musisz podac LICZBE od 1 do n! ";
		cin.clear();
		cin.sync();
	}
	if(gest == 1)
		gest = 2;

	//Wypelnianie macierzy trescia
	for(int i=0; i<size; i++)
	{
		for(int j=0; j<size; j++)
		{
			int los = rand() % gest;
			if (los == 1)
				tab[i][j] = 'X';
			else
				tab[i][j] = ' ';
		}
	}
	//Ustawienie figurki na pozycji startowej bohatera
	tab[x][y] = 'A';
}

//==========================================================
int main()
{	
	srand(time(0));
	//Blokowanie przed wpisywaniem zlych wartosci i glupot
	cout<<"Podaj rozmiar tablicy: ";
	int size=-1;
	while(!(cin>>size) || size<=0)
	{
		cout<<"Musisz podac LICZBE wieksza od 0! ";
		cin.clear();
		cin.sync();
	}

	//Tworzenie macierzy dynamicznej o wymiarach uzytkowika
	char **tab= new char*[size];
	for(int i=0; i<size; i++)
		tab[i] = new char[size];

	int y=rand() % size;	//Losowa pozycja bohatera
	int x=rand() % size;

	//liczniki ruchow - mr sprawdza czy jest mozliwe wykonanie ruchu
	int licznik = 0, ruch=0;
	bool mr = true;

	tworz_plansze(size, tab, x, y);
	cout<<"//------------------------------//\n";
	cout<<"ZACZYNAMY Z POZYCJI:";
	cout<<"\tX: "<<x+1<<"\tY: "<<y<<endl;
	cout<<"//------------------------------//";	

	//-----Funkcje z pliku global do poruszania bohaterem------
	//W przypadku kiedy nie moge sie ruszc za pierwszym razem	XX
	// sprawdzam czy moze da sie isc w inna strone --->			 AX
	if(mr == true)	//warunek do sprawdzania czy moge siê ruszyc X
		right(size, tab, x, y, licznik, ruch, mr);
	if(mr == true)
		down(size, tab, x, y, licznik, ruch, mr);
	if(mr == true)
		left(size, tab, x, y, licznik, ruch, mr);
	if(mr == true)
		up(size, tab, x, y, licznik, ruch, mr);


	cout<<"\nYOU MADE: "<<licznik<<" MOVES! NICE!";
	cout<<endl<<endl;
	system("pause");
}

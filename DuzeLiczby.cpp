// DuzeLiczby.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.


#include <iostream>
#include <string>
using namespace std;

bool naz(int tab1[], int tab2[], int d);	//sprawdzenie ktora liczba jest wieksza


int main()
{
	int t;

	cin >> t;
	while (t--)
	{
		string c;
		char znak;

		int liczba1[256], liczba2[256],wynik[256];
		
		for (int i = 0; i < 256; i++)	//zerowanie tablic
		{
			liczba1[i] = 0;
			liczba2[i] = 0;
			wynik[i] = 0;
		}

		cin >> c;
		int dlstring = c.length();
		int i = 0;
		int dl1 = 0, dl2 = 0;	//dlugosc pierwszej i drugiej liczby

		while (c[i] > 47 && c[i] < 58)	//wczytanie pierwszej liczby
		{
			liczba1[dl1] = c[i]-48;
			i++;
			dl1++;
		}

		znak = c[i];	//wczytanie znaku dzialania
		i++;

		while (c[i] > 47 && c[i] < 58)		//wczytanie drugiej liczby
		{
			liczba2[dl2] = c[i]-48;
			i++;
			dl2++;
		}

		int a;	
		for (int i = 0; i < dl1 / 2; i++)	//odwrocenie miejsc w tabeli
		{
			a = liczba1[i];
			liczba1[i] = liczba1[dl1 - 1 - i];
			liczba1[dl1 - 1 - i] = a;
		}
		for (int i = 0; i < dl2 / 2; i++)
		{
			a = liczba2[i];
			liczba2[i] = liczba2[dl2 - 1 - i];
			liczba2[dl2 - 1 - i] = a;
		}
		
		
		int dl=dl1;		//max dlugosc wyniku
		if (dl2 > dl1)
			dl = dl2;

		if(znak == '+')
		{
			a = 0;	
			for (int i = 0; i < dl; i++)
			{
				a += liczba1[i] + liczba2[i];
				wynik[i] = a % 10;
				a /= 10;
			}
			while (a)
			{
				wynik[dl] = a % 10;
				a /= 10;
				dl++;

			}
		}

		else if (znak == '-')
		{	
			if (naz(liczba1, liczba2, dl)) //gdy wynik odejmowania jest ujemny
			{
				for (int i = 0; i < dl; i++)
				{
					if (liczba1[i] > liczba2[i])
					{
						liczba2[i + 1] -= 1;
						liczba2[i] += 10;
					}
					wynik[i] = liczba2[i] - liczba1[i];
				}
				cout << "-";
			}
			else							//gdy wynik odejmowania jest dodatni
				for (int i = 0; i < dl; i++)
				{
					if (liczba2[i] > liczba1[i])
					{
						liczba1[i + 1] -= 1;
						liczba1[i] += 10;
					}
					wynik[i] = liczba1[i] - liczba2[i];
				}
		}

		else if (znak == '*')
		{ 
			a = 0;
			for (int i = 0; i < dl1; i++)
			{
				for (int j = 0; j < dl2; j++)
				{
					a = liczba1[i] * liczba2[j] + wynik[j + i];
					wynik[j+i] =  a % 10;				
					a /= 10;
					dl = j+i;
					while (a)
					{
						dl++;
						a += wynik[dl];
						wynik[dl] = a % 10;
						a =  a / 10;
					}
				}
			}
			dl++;
		}

		else if (znak == '/')
		{
			string r;
			int licz = 0;
			if (naz(liczba1, liczba2, dl))
				cout << 0;
			else if (dl2 < 19)
			{
				long long dzielnik = 0;
				for (int i = 0; i < dl2; i++)
					dzielnik += liczba2[i] * pow(10, i);
				int j = 0;
				long long z = liczba1[dl1-j-1];
				while (z < dzielnik)
					z = z * 10 + liczba1[dl1-++j-1];
				i = 0;
				while (dl1 > j)
				{
					r += (z / dzielnik)  + '0';
					z = (z % dzielnik) * 10 + liczba1[dl1-++j-1];
					i++;
				}
				cout << r;
			}
			else
			{	
				do {
					licz++;
					for (int i = 0; i < dl; i++)
						{
						if (liczba2[i] > liczba1[i])
						{
							liczba1[i + 1] -= 1;
							liczba1[i] += 10;
						}
						liczba1[i] = liczba1[i] - liczba2[i];
					}
				} while (!naz(liczba1, liczba2, dl));
			}
				wynik[0] = licz;
		}

		bool b = 0;
		for (int i = dl - 1; i >= 0; i--)
		{	
			if (wynik[i] == 0 && b == false);
			
			else
			{
				cout << wynik[i];
				b = true; //pierwsza cyfra znaczaca 
			}
		}
		if (b == false && znak != '/')
			cout << 0 << endl;
		else
			cout << endl;
	}
	return 0;
}

bool naz(int tab1[], int tab2[], int d)		//sprawdzenie ktora liczba jest wieksza
{
	for (int i = d - 1; i >= 0; i--)
	{
		if (tab2[i] > tab1[i])
			return true;
		else if (tab2[i] < tab1[i])
			return false;
	}
	return false;
}



// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln

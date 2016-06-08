#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <locale>
#include <windows.h>
#include "MMSystem.h"

#define MAXWORDSIZE 500

using namespace std;

bool password(); 
void musice();
int menu();
void rus(), eng(), fr(), bel(), german(), it(), poli();
void music();
void musice(), musicword(), request(), valied(), data(), found(), bye();
void Entrez(), Tous(), Ces();
void Geben(), Alle(), Diese();
void Inserire(), Tutte(), Queste();
void Ruenter(), Ruvse(), Runet();

void rusenter();
void design();

int match_template(const char *src, const char *tpl)
{
	for (; *src == *tpl || *tpl == '_'; src++, tpl++) 
	{
		if (*src == '\0')
			return 1;
	}
	
	return 0;
}

int main()
{
	
	SetConsoleCP(1251);
  	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "RUS");
	
	system("color 2");

	//Трек/Track
	/*PlaySound(TEXT("music.wav"), NULL, SND_SYNC);*/
	
	if(password())
	cout << "" /*"\t\t\t\t\t\tSign allowed.\n\n"*/;		
	else{
		system("color 4");
		cout << "\t\t\t\t\t\tAccess denied.\n\n\a\a";
		cin.get();
		return 0;
		}
			
	system("color 2");

	int choice;
	do{						
//		music();
		design();
		choice = menu();	//Получаем команду 
        					//выбранную пользователем	
		switch(choice)
		{
			case 1: 
			{
				rus();
				break;	
			}
			case 2:
			{
				eng();
				break;				
			}
			case 3:
			{
				fr();
				break;	
			}
			case 4:
			{
				german();
				break;
			}
			case 5:
			{
				it();
				break;
			}
			case 6:
			{
				rusenter();
				bye();
				return 0;	
			}	
			default:
			system("cls");
			system("color 4");
			design();
			cout << "\n\t\t\t\tВведите корректные данные: \n\a\a\a"
				 << "\n\t\t\t\tEnter the correct data: \n\n\a\a\a";
			cout << "\t\t\t\t//////////////////////////////////////////////////";	 
				
			data();	 
				 cin.get();
				 cin.get();
			cout << '\n';	 
		} 
	system("color 2");
	}while(choice != 0);
	
	system("pause"); 
	return 0;
}
	
	//Функция возвращает команду, выбранную пользователем
	int menu()
	{
		int choice;

		cout << "\t\t\t\t\t\t1. РУССКИЙ СЛОВАРЬ\n" 
			 << "\t\t\t\t\t\t2. ENGLISH DICTIONARY\n" 
		 	 << "\t\t\t\t\t\t3. FRENCH DICTIONNAIRE\n"
			 << "\t\t\t\t\t\t4. DEUTSCH WORTERBUCH\n" 
			 << "\t\t\t\t\t\t5. ITALIANO DIZIONARIO\n"
			 << "\t\t\t\t\t\t6. EXIT||ВЫХОД\n"; 
		cout << "\t\t\t\t==================================================" << endl;
		cout << "\t\t\t\t\t\tYour choice?\n" 
			 << "\t\t\t\t\t\tВаш выбор: ";	cin >> choice;
		cout << "\n\t\t\t\t//////////////////////////////////////////////////";
		cin.get();
		cin.get();
		
		return choice;
	}

void musice()
{
	PlaySound(TEXT("Music_Files/Enter.wav"), NULL, SND_SYNC);
}

void valied()
{
	PlaySound(TEXT("Music_Files/valied.wav"), NULL, SND_SYNC);
}
void musicword()
{
	PlaySound(TEXT("Music_Files/musicword.wav"), NULL, SND_SYNC);
}

void request()
{
	PlaySound(TEXT("Music_Files/request.wav"), NULL, SND_SYNC);
}

void data()
{
	PlaySound(TEXT("Music_Files/data.wav"), NULL, SND_SYNC);
}

void found()
{
	PlaySound(TEXT("Music_Files/found.wav"), NULL, SND_SYNC);
}

void rusenter()
{
	PlaySound(TEXT("Music_Files/rusenter.wav"), NULL, SND_SYNC);	
}

void bye()
{
	PlaySound(TEXT("Music_Files/bye.wav"), NULL, SND_SYNC);
}

void Entrez()
{
	PlaySound(TEXT("Music_Files/Entrez.wav"), NULL, SND_SYNC);	
}

void Tous()
{
	PlaySound(TEXT("Music_Files/Tous.wav"), NULL, SND_SYNC);	
}

void Ces()
{
	PlaySound(TEXT("Music_Files/Ces.wav"), NULL, SND_SYNC);	
}

void Geben()
{
	PlaySound(TEXT("Music_Files/Geben.wav"), NULL, SND_SYNC);	
}

void Alle()
{
	PlaySound(TEXT("Music_Files/Alle.wav"), NULL, SND_SYNC);	
}

void Diese()
{
	PlaySound(TEXT("Music_Files/Diese.wav"), NULL, SND_SYNC);	
}

void Inserire()
{
	PlaySound(TEXT("Music_Files/Inserire.wav"), NULL, SND_SYNC);	
}

void Tutte()
{
	PlaySound(TEXT("Music_Files/Tutte.wav"), NULL, SND_SYNC);	
}

void Queste()
{
	PlaySound(TEXT("Music_Files/Queste.wav"), NULL, SND_SYNC);	
}

void Ruenter()
{
	PlaySound(TEXT("Music_Files/Ruenter.wav"), NULL, SND_SYNC);	
}

void Ruvse()
{
	PlaySound(TEXT("Music_Files/Ruvse.wav"), NULL, SND_SYNC);	
}

void Runet()
{
	PlaySound(TEXT("Music_Files/Runet.wav"), NULL, SND_SYNC);	
}

//Функция пароля
bool password()
{	
	char s[80];
	
	cout << "\n\n\n\n\n\n\t\t\t\t\t\tEnter password: ";
	musice();

	/*cout << "\t\t\t\t\t\t";*/ gets(s);
	
	if(strcmp(s, "0797"))	//Строки различны
	{
		system("color 4");
		cout << "\t\t\t\t\t\tThe password is not valid.\n\a\a";	
		valied();
		return false;
	}
	//Сравниваемые строки совпадают
	return true;
}

void design()
{
	system("cls");
	
	cout << "\n\n";
	cout << "\t\t\t\t//////////////////////////////////////////////////\n";
	cout << "\t\t\t\t/////   Drawing on letters of create words   /////\n";
	cout << "\t\t\t\t//////////////////////////////////////////////////\n";
	//cout << "\n\n";
}

//Функция для русскоязычного варианта
void rus()
{
	system("cls");
	
//	music();
	char buf[MAXWORDSIZE];
	char word[MAXWORDSIZE];
	size_t tsize;
	FILE *fp;
	
	cout << "\n\n";
	cout << "\t\t\t\t//////////////////////////////////////////////////";
	cout << "\n\n\t\t\t\tВведите слово (Неизвестные буквы обозначайте знаком _): ";
		Ruenter();
	cout << "\t\t\t\t\t\t\t\t\t"; cin >> word;
	
	tsize = strlen(word);
	fp = fopen("rus.txt", "r");
	cout << "\t\t\t\tВсе возможные слова с вашим запросом : " << word;
	cout << "\n";
	cout << " " << endl;
	
	int r=0;
	while (fscanf(fp, "%s", buf) > 0) 
	{
		if (strlen(buf) != tsize)
		continue;

		if (match_template(buf, word))
		{
			cout << "\t\t\t\t\t\t"; puts(buf);
				r = 1;
		}
	}
		Ruvse();
		
		if (r==0)
		{
			cout << "\t\t\t\t\tЭти слова не встречаются в файле" << endl;
			Runet();
		}
	
		cout << "\n\n\n";
		cout << "\t\t\t\t//////////////////////////////////////////////////\n";
		
		fclose(fp);	
		cin.get();
		cin.get();

		system("cls");
}

//Функция для англоязычного варианта
void eng()
{
	system("cls");
	
	char buf[MAXWORDSIZE];
	char word[MAXWORDSIZE];
	size_t tsize;
	FILE *fp;
	
	cout << "\n\n";
	cout << "\t\t\t\t//////////////////////////////////////////////////";
	cout << "\n\n\t\t\t\tEnter word (Unidentified letters indicating the sign _): ";
		musicword();
		
	cout << "\t\t\t\t\t\t\t\t\t"; cin >> word; 
	tsize = strlen(word);
	fp = fopen("en.txt", "r");
	cout << "\t\t\t\tAll possible words with your request :" << word;
	cout << "\n";
	cout << " " << endl;
	int r=0;
	while (fscanf(fp, "%s", buf) > 0) 
	{
		if (strlen(buf) != tsize)
		continue;
    
		if (match_template(buf, word))
		{
			cout << "\t\t\t\t\t\t"; puts(buf);
			r = 1;
		}
	}
		request();
	
	if (r==0)
		{
			cout << "\t\t\t\t\tThese words are not found in the file" << endl;
			found();
		}
	
	cout << "\n\n\n";
	cout << "\t\t\t\t//////////////////////////////////////////////////\n";
	
	fclose(fp);		
	cin.get();
	cin.get();
	system("cls");	
}

//Функция для французского варианта
void fr()
{
	system("cls");
	
	char buf[MAXWORDSIZE];
	char word[MAXWORDSIZE];
	size_t tsize;
	FILE *fp;
	
	cout << "\n\n";
	cout << "\t\t\t\t//////////////////////////////////////////////////";
	cout << "\n\n\t\t\t\tEntrez le mot (inconnu lettres indiquant le signe _): ";
		Entrez();
	cout << "\t\t\t\t\t\t\t\t\t"; cin >> word;
	
	tsize = strlen(word);
	fp = fopen("fr.txt", "r");
	cout << "\t\t\t\tTous les mots possibles avec votre demande :" << word;
	cout << "\n";
	cout << " " << endl;
	
	int r=0;
	while (fscanf(fp, "%s", buf) > 0) 
	{
		if (strlen(buf) != tsize)
		continue;
    
		if (match_template(buf, word))
		{
			cout << "\t\t\t\t\t\t"; puts(buf);
			r = 1;
		}
	}
		Tous();
	
	if (r==0)
		{
			cout << "\t\t\t\t\tCes mots ne figurent pas dans le fichier" << endl;
			Ces();
		}
		
	cout << "\n\n\n";
	cout << "\t\t\t\t//////////////////////////////////////////////////\n";
			
	fclose(fp);		
	cin.get();
	cin.get();
	system("cls");	
}

//Функция для немецкого варианта
void german()
{
	system("cls");
	
	char buf[MAXWORDSIZE];
	char word[MAXWORDSIZE];
	size_t tsize;
	FILE *fp;
	
	cout << "\n\n";
	cout << "\t\t\t\t//////////////////////////////////////////////////";
	cout << "\n\n\t\t\t\tGeben Sie das Wort (unbekannt Buchstaben, welche die Zeichen _): ";
		Geben();
	cout << "\t\t\t\t\t\t\t\t\t"; cin >> word;
	
	tsize = strlen(word);
	fp = fopen("dot.txt", "r");
	cout << "\t\t\t\tAlle moglichen Worter mit Ihrer Anfrage : " << word;
	cout << "\n";
	cout << " " << endl;
	
	int r=0;
	while (fscanf(fp, "%s", buf) > 0) 
	{
		if (strlen(buf) != tsize)
		continue;

		if (match_template(buf, word))
		{
			cout << "\t\t\t\t\t\t"; puts(buf);
			r = 1;
		}
	}
		Alle();
		
		if (r==0)
		{
			cout << "\t\t\t\t\tDiese Worter werden in der Datei nicht gefunden" << endl;
			Diese();
		}
		
		cout << "\n\n\n";
		cout << "\t\t\t\t//////////////////////////////////////////////////\n";
		
		fclose(fp);	
		cin.get();
		cin.get();
		system("cls");
}

//Функция для итальянского варианта
void it()
{
	system("cls");
	
	char buf[MAXWORDSIZE];
	char word[MAXWORDSIZE];
	size_t tsize;
	FILE *fp;
	
	cout << "\n\n";
	cout << "\t\t\t\t//////////////////////////////////////////////////";
	cout << "\n\n\t\t\t\tInserire la parola (sconosciuto lettere che indicano il segno _): ";
		Inserire();
	cout << "\t\t\t\t\t\t\t\t\t"; cin >> word; /*code blocs*/
	
	tsize = strlen(word);
	fp = fopen("it.txt", "r");
	cout << "\t\t\t\tTutte le parole possibili con la vostra richiesta : " << word;
	cout << "\n";
	cout << " " << endl;
	
	int r=0;
	while (fscanf(fp, "%s", buf) > 0) 
	{
		if (strlen(buf) != tsize)
		continue;

		if (match_template(buf, word))
		{
			cout << "\t\t\t\t\t\t"; puts(buf);
			r = 1;
		}
	}
		Tutte();
	
	if (r==0)
	{
		cout << "\t\t\t\t\tQueste parole non si trovano nel file" << endl;
			Queste();
	}
	
	cout << "\n\n\n";
	cout << "\t\t\t\t//////////////////////////////////////////////////\n";
		
	fclose(fp);	
	cin.get();
	cin.get();
	system("cls");
}


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
		music();
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
				bel();
				break;
			}
			case 5:
			{
				german();
				break;
			}
			case 6:
			{
				it();
				break;
			}
			case 7:
			{
				rusenter();
				bye();
				return 0;	
			}	
			default:
			system("cls");
			system("color 4");
			design();;
			cout << "\n\t\t\t\tВведите корректные данные: \n\a\a\a"
				 << "\n\t\t\t\tEnter the correct data: \n\n\a\a\a";
			cout << "\t\t\t\t//////////////////////////////////////////////////";	 
			data();	 
				 cin.get();
				 cin.get();
			cout << '\n';	 
		} 
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
			 << "\t\t\t\t\t\t4. БЕЛАРУСКI СЛОУНIК\n"
			 << "\t\t\t\t\t\t5. DEUTSCH WORTERBUCH\n" 
			 << "\t\t\t\t\t\t6. ITALIANO DIZIONARIO\n"
			 << "\t\t\t\t\t\t7. EXIT||ВЫХОД\n"; 
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
	PlaySound(TEXT("Enter.wav"), NULL, SND_SYNC);
}

void valied()
{
	PlaySound(TEXT("valied.wav"), NULL, SND_SYNC);
}
void musicword()
{
	PlaySound(TEXT("musicword.wav"), NULL, SND_SYNC);
}

void request()
{
	PlaySound(TEXT("request.wav"), NULL, SND_SYNC);
}

void data()
{
	PlaySound(TEXT("data.wav"), NULL, SND_SYNC);
}

void found()
{
	PlaySound(TEXT("found.wav"), NULL, SND_SYNC);
}

void rusenter()
{
	PlaySound(TEXT("rusenter.wav"), NULL, SND_SYNC);	
}

void bye()
{
	PlaySound(TEXT("bye.wav"), NULL, SND_SYNC);
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

//Функция начальной мелодии
void music()
{
	char soundfile[] = "D:\Music.wav";
	cout << PlaySound((LPCSTR) soundfile, NULL, SND_FILENAME | SND_ASYNC);
}

//Функция дизайна
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
	
	music();
	char buf[MAXWORDSIZE];
	char word[MAXWORDSIZE];
	size_t tsize;
	FILE *fp;
	
	cout << "\n\n";
	cout << "\t\t\t\t//////////////////////////////////////////////////";
	cout << "\n\n\t\t\t\tВведите слово (Неизвесные буквы обозначайте знаком _): ";
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
	
		if (r==0)
		{
			cout << "\t\t\t\t\tЭти слова не встречаются в файле" << endl;
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
		musicword();
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

//Функция для белоруского варианта
void bel()
{
	system("cls");
	
	char buf[MAXWORDSIZE];
	char word[MAXWORDSIZE];
	size_t tsize;
	FILE *fp;
	
	cout << "\n\n";
	cout << "\t\t\t\t//////////////////////////////////////////////////";
	cout << "\n\n\t\t\t\tУвядзiце словы (Невядомыя літары вызначайце знакам _): ";
		musicword();
	cout << "\t\t\t\t\t\t\t\t\t"; cin >> word;
	
	tsize = strlen(word);
	fp = fopen("bel.txt", "r");
	cout << "\t\t\t\tУсе магчымыя словы з вашым запытам : " << word;
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
		musicword();
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
		musicword();
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


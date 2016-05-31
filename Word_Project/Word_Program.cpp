#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <locale>
#include <windows.h>
#include "MMSystem.h"

#define MAXWORDSIZE 50

using namespace std;

bool password(); 
int menu();
void rus(), eng();
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

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
  	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "RUS");
	
	system("color 2");

	//Трек/Track
	/*PlaySound(TEXT("music.wav"), NULL, SND_SYNC);
	system("pause");
	return 0;*/
	
	char soundfile[] = "D:\music.wav";
	cout << PlaySound((LPCSTR) soundfile, NULL, SND_FILENAME | SND_ASYNC);
	
	if(password())
	cout << " " /*"\t\t\t\t\t\tSign allowed.\n\n"*/;		
	else{
		system("color 4");
		cout << "\t\t\t\t\t\tAccess denied.\n\n\a\a";
		cin.get();
		return 0;
		}
			
	system("color 2");
	
	//char soundfile[] = "D:\Lolita.wav";
	//cout << PlaySound((LPCSTR) soundfile, NULL, SND_FILENAME | SND_ASYNC);

	int choice;
	do{						
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
				cout << "\n\n\n\n\n\n";
				return 0;
			}
		default:
			system("cls");
			system("color 4");
			design();
			cout << "\n\t\t\t\tВведите корректные данные: \n\a\a\a"
				 << "\n\t\t\t\tEnter the correct data: \n\n\a\a\a";
			cout << "\t\t\t\t//////////////////////////////////////////////////";	 
				 cin.get();
				 cin.get();
			system("color 2");	 
		} 
	}while(choice != 0);
	
	system("pause"); 
	return 0;
}
	
	//Функция возвращает команду, выбранную пользователем
	int menu()
	{
		int choice;

		cout << "\t\t\t\t\t\t1. РУССКИЙ\n" 
			 << "\t\t\t\t\t\t2. ENGLISH\n" 
		 	 << "\t\t\t\t\t\t3. EXIT||ВЫХОД\n"; 
		cout << "\t\t\t\t==================================================" << endl;
		cout << "\t\t\t\t\t\tYour choice?\n" 
			 << "\t\t\t\t\t\tВаш выбор: ";	cin >> choice;
		cout << "\n\t\t\t\t//////////////////////////////////////////////////";
		cin.get();
		cin.get();
		return choice;
	}

//Функция пароля
bool password()
{
	char s[80];
	
	cout << "\n\n\n\n\n\n\t\t\t\t\t\tEnter password: ";
	/*cout << "\t\t\t\t\t\t";*/ gets(s);
	
	if(strcmp(s, "0797"))	//Строки различны
	{
		system("color 4");
		cout << "\t\t\t\t\t\tThe password is not valid.\n\a\a";	
		return false;
	}
	//Сравниваемые строки совпадают
	return true;
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
	
	char buf[MAXWORDSIZE];
	char word[MAXWORDSIZE];
	size_t tsize;
	FILE *fp;
	
	cout << "\n\n";
	cout << "\t\t\t\t//////////////////////////////////////////////////";
	cout << "\n\n\t\t\t\tВведите слово (Неизвесные буквы обозначайте знаком _): ";
	//scanf("%s\t\t\t", &word);
	cout << "\t\t\t\t\t\t\t\t\t"; cin >> word;
	
	tsize = strlen(word);
	fp = fopen("rus.txt", "r");
	cout << "\t\t\t\tВсе возможные слова с вашим запрсом : " << word;
	cout << "\n";
	cout << " " << endl;
	
	while (fscanf(fp, "%s", buf) > 0) 
	{
		if (strlen(buf) != tsize)
		continue;

		if (match_template(buf, word))
		{
			cout << "\t\t\t\t\t\t"; puts(buf);
		}
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
	cout << "\t\t\t\t\t\t\t\t\t"; cin >> word;
	
	tsize = strlen(word);
	fp = fopen("en.txt", "r");
	cout << "\t\t\t\tAll possible words with your request :" << word;
	cout << "\n";
	cout << " " << endl;
	
	while (fscanf(fp, "%s", buf) > 0) 
	{
		if (strlen(buf) != tsize)
		continue;
    
		if (match_template(buf, word))
		{
			cout << "\t\t\t\t\t\t"; puts(buf);
		}
	}
	
	cout << "\n\n\n";
	cout << "\t\t\t\t//////////////////////////////////////////////////\n";
	
	fclose(fp);		
	cin.get();
	cin.get();
	system("cls");	
}


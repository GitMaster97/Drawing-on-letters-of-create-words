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
int menu();
void rus(), eng(), fr(), bel(), german(), it(), poli();
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

	//PlaySound(TEXT("Music.wav"), NULL, SND_SYNC);

	//����/Track
	/*PlaySound(TEXT("music.wav"), NULL, SND_SYNC);
	system("pause");
	return 0;*/
	
	char soundfile[] = "D:\Music.wav";
	cout << PlaySound((LPCSTR) soundfile, NULL, SND_FILENAME | SND_ASYNC);
	
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
		design();
		choice = menu();	//�������� ������� 
        					//��������� �������������	
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
				return 0;	
			}	
			default:
			system("cls");
			system("color 4");
			design();
			cout << "\n\t\t\t\t������� ���������� ������: \n\a\a\a"
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
	
	//������� ���������� �������, ��������� �������������
	int menu()
	{
		int choice;

		cout << "\t\t\t\t\t\t1. ������� �������\n" 
			 << "\t\t\t\t\t\t2. ENGLISH DICTIONARY\n" 
		 	 << "\t\t\t\t\t\t3. FRENCH DICTIONNAIRE\n"
			 << "\t\t\t\t\t\t4. ��������� �������\n"
			 << "\t\t\t\t\t\t5. DEUTSCH WORTERBUCH\n" 
			 << "\t\t\t\t\t\t6. ITALIANO DIZIONARIO\n"
			 << "\t\t\t\t\t\t7. EXIT||�����\n"; 
		cout << "\t\t\t\t==================================================" << endl;
		cout << "\t\t\t\t\t\tYour choice?\n" 
			 << "\t\t\t\t\t\t��� �����: ";	cin >> choice;
		cout << "\n\t\t\t\t//////////////////////////////////////////////////";
		cin.get();
		cin.get();
		return choice;
	}

//������� ������
bool password()
{
	char s[80];
	
	cout << "\n\n\n\n\n\n\t\t\t\t\t\tEnter password: ";
	/*cout << "\t\t\t\t\t\t";*/ gets(s);
	
	if(strcmp(s, "0797"))	//������ ��������
	{
		system("color 4");
		cout << "\t\t\t\t\t\tThe password is not valid.\n\a\a";	
		return false;
	}
	//������������ ������ ���������
	return true;
}

//������� �������
void design()
{
	system("cls");
	
	cout << "\n\n";
	cout << "\t\t\t\t//////////////////////////////////////////////////\n";
	cout << "\t\t\t\t/////   Drawing on letters of create words   /////\n";
	cout << "\t\t\t\t//////////////////////////////////////////////////\n";
	//cout << "\n\n";
}

//������� ��� �������������� ��������
void rus()
{
	system("cls");
	
	char buf[MAXWORDSIZE];
	char word[MAXWORDSIZE];
	size_t tsize;
	FILE *fp;
	
	cout << "\n\n";
	cout << "\t\t\t\t//////////////////////////////////////////////////";
	cout << "\n\n\t\t\t\t������� ����� (���������� ����� ����������� ������ _): ";
	cout << "\t\t\t\t\t\t\t\t\t"; cin >> word;
	
	tsize = strlen(word);
	fp = fopen("rus.txt", "r");
	cout << "\t\t\t\t��� ��������� ����� � ����� �������� : " << word;
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

//������� ��� ������������� ��������
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

//������� ��� ������������ ��������
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
	cout << "\t\t\t\t\t\t\t\t\t"; cin >> word;
	
	tsize = strlen(word);
	fp = fopen("fr.txt", "r");
	cout << "\t\t\t\tTous les mots possibles avec votre demande :" << word;
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

//������� ��� ����������� ��������
void bel()
{
	system("cls");
	
	char buf[MAXWORDSIZE];
	char word[MAXWORDSIZE];
	size_t tsize;
	FILE *fp;
	
	cout << "\n\n";
	cout << "\t\t\t\t//////////////////////////////////////////////////";
	cout << "\n\n\t\t\t\t�����i�� ����� (��������� ����� ���������� ������ _): ";
	cout << "\t\t\t\t\t\t\t\t\t"; cin >> word;
	
	tsize = strlen(word);
	fp = fopen("bel.txt", "r");
	cout << "\t\t\t\t��� �������� ����� � ����� ������� : " << word;
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

//������� ��� ��������� ��������
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
	cout << "\t\t\t\t\t\t\t\t\t"; cin >> word;
	
	tsize = strlen(word);
	fp = fopen("dot.txt", "r");
	cout << "\t\t\t\tAlle moglichen Worter mit Ihrer Anfrage : " << word;
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

//������� ��� ������������ ��������
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
	cout << "\t\t\t\t\t\t\t\t\t"; cin >> word;
	
	tsize = strlen(word);
	fp = fopen("it.txt", "r");
	cout << "\t\t\t\tTutte le parole possibili con la vostra richiesta : " << word;
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


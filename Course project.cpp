#include <iostream>
#include <cstdlib>
#include <fstream>
#include <conio.h>
#include <windows.h>
using namespace std;
 
char bufRus[256];
 
char* Rus(const char* text) 
{
      CharToOem(text, bufRus);
      return bufRus;
}
int Search(char *str, char *slovo)
    {
        char *buf = new char[20];
        strlwr(str);
        strlwr(slovo);
        char ch = slovo[0];
        int count = 0;
        
		for(int i = 0; str[i] != 0; i++)
        {
            if(str[i] == ch)
            {
                for(int j = 0, z = i; j <= strlen(slovo); z++, j++)
                {
                    buf[j] = str[z];
                    if(buf[j] ==' ')
					{
						buf[j] = 0;
                    	buf[j + 1] = 0;
                	}
				}
                if(strcmp(slovo, buf) == 0)
				{	
					count++;
           		}
			}
        }
        delete[]buf;
        return count;
    }

int main(void)
{
    SetConsoleCP(1251);
  	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "RUS");
    
    char fname[128];
    char *str = new char[1024];
    ifstream infile;
    cout << "//////////////////////////////////////////////\n";
	cout << "///   Drawing on letters of create words   ///\n";
	cout << "//////////////////////////////////////////////\n";
	cout << " " << endl;
	cout << Rus("Enter the file name: \n");
		cin.getline(fname, 127);
    infile.open(fname, ios :: in);
    
	if(!infile)
    {
        cout << Rus("I can not open the file");
        
		delete[]str;
        
		return 1;
    }
    
	do{
    char *slovo = new char[20];
    cout << "**********************************************\n";
	cout << Rus("\tEnter the word: >>> ");
			cin.getline(slovo, 19);
    
	int countStr = 0;
    int countSl = 0;
    
    	cout << "Number of row(s) in which this word occurs: \n";
	while(!infile.eof())
    {
        infile.getline(str, 1023);
        countStr++;
        countSl += Search(str, slovo);
		if(Search(str, slovo))
        {
            cout << " --> \t" << countStr << " \n";
        }
    }
    infile.clear();
    
	if(countSl)
    {
        cout << Rus("It occurs in these rows ") << countSl;
        cout << Rus(" time.") << endl;
    }
    else
    	{
        	cout << Rus("This word is not found") << endl;
        	cout << "**********************************************\n";
    	}
    
    }while(false);
    
	delete[]str;
    
	return 0;
}

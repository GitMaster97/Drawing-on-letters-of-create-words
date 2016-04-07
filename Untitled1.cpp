#include <fstream>
#include <iostream>
#include <cstdlib>
#include <windows.h>
using namespace std;

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
  	SetConsoleOutputCP(1251);
  	setlocale(LC_ALL, "Russian");
  	
  	char string[300];
  	char string2[300];
  	int buff; 
  	
	cout << "¬ведите буквы: \n";
  	gets(string);
  	//cout << "\n";
  	
  	for(int i = 0; string[i] ; i++)
  	{
  		cout << string[i];
	}
	
	/*ofstream fout("reverse.txt"); 
    //fout << " "; 
    fout.close(); */
    
	ifstream fin("reverse.txt");
 		fin >> string2; 
    cout << "\n"<< string2 << endl;
  	
	system("pause");
  	return 0;
}



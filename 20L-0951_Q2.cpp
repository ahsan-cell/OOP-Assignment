#include<iostream>
using namespace std;

int strsize(char* str);// additional function
void StringConcatenate(char*& str1, char* str2);
void CompressString(char*& str);
char* ReverseSentence(char* str);
void pluralWords(char** s, int wordcount);
void menu();

int main()
{
	menu();
}

int strsize(char* str)
{
	int n = 0;
	for (int i = 0; str[i] != '\0'; i++)
		n++;
	return n;
}

void StringConcatenate(char*& str1, char* str2)
{
	char* conc = new char[strsize(str1)+strsize(str2)+1];
	int i = 0;
	for (; str1[i] != '\0'; i++)
		conc[i] = str1[i];
	for (int j = 0; str2[j] != '\0'; j++)
	{
		conc[i] = str2[j];
		i++;
	}
	conc[i] = '\0';
	delete[]str1;
	str1 = conc;
	conc = nullptr;
}

void CompressString(char* &str)
{
	int n = 1;
	
	for (int i = 1; str[i] != '\0'; i++)
	{
		int check = 1;
		for (int j = 0; j<i && check ==1; j++)
		{
			
			if (str[i] == str[j])
				check = 0;
		}
		if (check == 1)
			n++;
	}
	n++;
	
	char* str2 = new char[n];
	str2[0] = str[0];
	int j = 1;
	for (int i = 1; str[i] != '\0'; i++)
	{
		int check = 1;
		for (int k = 0; k < j; k++)
		{
			if (str[i] == str2[k])
			{
				check = 0;
			}
		}
		if (check == 1)
		{
			str2[j] = str[i];
			j++;
		}
			
	}
	str2[n - 1] = '\0';
	delete[]str;
	str = str2;
	str2 = nullptr;
}

char* ReverseSentence(char* str)
{
	int n = strsize(str);

	char* reversed = new char[n+1];
	for (int i = 0; str[i] != '\0'; i++)
	{
		reversed[n - i-1] = str[i];
	}
	reversed[n] = '\0';
	
	return reversed;
}

void pluralWords(char** s, int wordcount)
{
	char vowels[5] = { 'a','e','i','o','u' };
	for (int i = 0; i < wordcount; i++)
	{
		int done = 0;
		int size = strsize(s[i]);
		// appending es at the end
		if ((s[i][size-1]=='h' && (s[i][size-2]=='c' || s[i][size - 2] == 's'))   || (s[i][size - 1] == 'x') || (s[i][size - 3] == 'a' && s[i][size - 2] == 't' && s[i][size - 1] == 'o'))
		{
			char* plural = new char[size + 2];
			int k = 0;
			for (; s[i][k] != '\0'; k++)
				plural[k] = s[i][k];
			plural[k] = 'e';
			plural[k+1] = 's';
			plural[k+2] = '\0';

			delete[]s[i];
			s[i] = plural;
			plural = nullptr;
			done = 1;
		}
		// appending es (analysis --> analyses )
		else if (s[i][size - 1] == 's' && s[i][size - 2] == 'i')
		{
			s[i][size - 2] = '#';
			s[i][size - 1] = '#';
			char* plural = new char[size + 1];
			int k = 0;
			for (; s[i][k]; k++)
				plural[k] = s[i][k];
			plural[k] = 'e';
			plural[k + 1] = 's';
			plural[k + 2] = '\0';
			
			delete[]s[i];
			s[i] = plural;
			plural = nullptr;
			done = 1;
		}
		//If last letter is ‘s’ or ‘z’ and second last letter is not a vowel
		else if (s[i][size - 1] == 's' || s[i][size - 1] == 'z')
		{
			int check2 = 0;
			for (int j = 0; j < 3; j++)
			{
				if (s[i][size - 2] != vowels[j])
					check2 = 1;
			}
			if (check2 == 1)
			{
				char* plural = new char[size + 2];
				int k = 0;
				for (; s[i][k] != '\0'; k++)
					plural[k] = s[i][k];
				plural[k] = 'e';
				plural[k + 1] = 's';
				plural[k + 2] = '\0';

				delete[]s[i];
				s[i] = plural;
				plural = nullptr;
				done = 1;
			}
		}
		
		//append ‘zes’
        else if (s[i][size - 1] == 'z')
		{
			int check2 = 0;
			for (int j = 0; j < 3; j++)
			{
				if (s[i][size - 2] == vowels[j])
					check2 = 1;
			}
			if (check2 == 1)
			{
				char* plural = new char[size + 3];
				int k = 0;
				for (; s[i][k] != '\0'; k++)
					plural[k] = s[i][k];
				plural[k] = 'z';
				plural[k + 1] = 'e';
				plural[k + 2] = 's';
				plural[k + 3] = '\0';
				
				delete[]s[i];
				s[i] = plural;
				plural = nullptr;
				done = 1;
			}

		}
		//append ‘ses’
		else if (s[i][size - 1] == 's')
		{
			int check2 = 0;
			for (int j = 0; j < 3; j++)
			{
				if (s[i][size - 2] == vowels[j])
					check2 = 1;
			}
			if (check2 == 1)
			{
				char* plural = new char[size + 3];
				int k = 0;
				for (; s[i][k] != '\0'; k++)
					plural[k] = s[i][k];
				plural[k] = 's';
				plural[k + 1] = 'e';
				plural[k + 2] = 's';
				plural[k + 3] = '\0';

				delete[]s[i];
				s[i] = plural;
				plural = nullptr;
				done = 1;
			}
			
		}
		//append 's'
		else if (s[i][size - 1] == 'f' && s[i][size - 2] == 'f')
		{
			char* plural = new char[size + 1];
			int k = 0;
			for (; s[i][k] != '\0'; k++)
				plural[k] = s[i][k];
			plural[k] = 's';
			plural[k + 1] = '\0';
			

			delete[]s[i];
			s[i] = plural;
			plural = nullptr;
			done = 1;
		}
		//If the noun ends with ‘f’ or ‘fe’
		else if (s[i][size - 1] == 'f' || ((s[i][size - 2] == 'f') && (s[i][size - 1] == 'e')))
		{
			char* plural = new char[size + 2];
			int k = size - 1;
			while (s[i][k] != 'f')
			{
				k--;
			}
			int k2 = 0;
			for (; k2 < k; k2++)
				plural[k2] = s[i][k2];
			plural[k2] = 'v';
			plural[k2 + 1] = 'e';
			plural[k2 + 2] = 's';
			plural[k2 + 3] = '\0';

			delete[]s[i];
			s[i] = plural;
			plural = nullptr;
			done = 1;

		}
		//If the singular noun ends in ‘on’, then ‘‘on’’ is changed to ‘a’.
		else if (s[i][size - 1] == 'n' && s[i][size - 2] == 'o')
		{
			char* plural = new char[size-1];
			s[i][size - 1] = '#';
			s[i][size - 2] = '#';
			int k = 0;
			for (; s[i][k] != '#'; k++)
				plural[k] = s[i][k];
			plural[k] = 'a';
			plural[k + 1] = '\0';

			delete[]s[i];
			s[i] = plural;
			plural = nullptr;
			done = 1;
						
		}
		//If the singular noun ends in ‘us’
	    if (s[i][size - 1] == 's' && s[i][size - 2] == 'u')
		{
			char* plural = new char[size - 1];
			s[i][size - 1] = '#';
			s[i][size - 2] = '#';
			int k = 0;
			for (; s[i][k] != '#'; k++)
				plural[k] = s[i][k];
			plural[k] = 'i';
			plural[k + 1] = '\0';

			delete[]s[i];
			s[i] = plural;
			plural = nullptr;
			done = 1;

		}
		//appending 's' or 'ies'
		else if (s[i][size - 1] == 'y')
		{
			int check2 = 0;
			for (int j = 0; j < 3; j++)
			{
				if (s[i][size - 2] == vowels[j])
					check2 = 1;
			}
			if (check2 == 1)
			{
				char* plural = new char[size + 1];
				int k = 0;
				for (; s[i][k] != '\0'; k++)
					plural[k] = s[i][k];
				plural[k] = 's';
				plural[k + 1] = '\0';

				delete[]s[i];
				s[i] = plural;
				plural = nullptr;
				done = 1;
			}
			else
			{
				char* plural = new char[size + 2];
				s[i][size - 1] = '#';
				int k = 0;
				for (; s[i][k] != '#'; k++)
					plural[k] = s[i][k];
				plural[k] = 'i';
				plural[k + 1] = 'e';
				plural[k + 2] = 's';
				plural[k + 3] = '\0';

				delete[]s[i];
				s[i] = plural;
				plural = nullptr;
				done = 1;
			}

		}
		//for all other cases
		else if(done==0)
		{
			char* plural = new char[size + 1];
			int k = 0;
			for (; s[i][k] != '\0'; k++)
				plural[k] = s[i][k];
			plural[k] = 's';
			plural[k + 1] = '\0';

			delete[]s[i];
			s[i] = plural;
			plural = nullptr;
		}
	}
}

void menu()
{
	int choice = -1;
	while (choice != 0)
	{
		cout << "0.Exit" << endl;
		cout << "1.Concatenate two strings" << endl;
		cout << "2.Compress a string" << endl;
		cout << "3.Reverse String" << endl;
		cout << "4.Give plurals of an array of singular words" << endl;
		cin >> choice;
		cout << "---------------------------------------------" << endl;
		if (choice == 1)
		{
			char* str1 = new char[20];
			char str2[20];
			cout << "Enter first string: ";
			cin.ignore();
			cin.getline(str1, 20);
			cout << "Enter second string: ";
			cin.getline(str2, 20);

			StringConcatenate(str1, str2);
			cout << str1<<endl;
			cout << "---------------------------------------------" << endl;
			delete[] str1;
			str1 = nullptr;
		}
		else if (choice == 2)
		{
			char* str = new char[20];
			cout << "Enter a string: ";
			cin.ignore();
			cin.getline(str, 20);

			CompressString(str);
			cout << str<<endl;
			cout << "---------------------------------------------" << endl;
			delete[]str;
			str = nullptr;
		}
		else if (choice == 3)
		{
			char* str = new char[20];
			cout << "Enter a string: ";
			cin.ignore();
			cin.getline(str, 20);
			char* reverse = nullptr;

			reverse=ReverseSentence(str);
			cout << reverse<<endl;
			cout << "---------------------------------------------" << endl;
			delete[]str;
			str = nullptr;
			delete[]reverse;
			reverse = nullptr;
		}
		else if (choice == 4)
		{
			int wordcount = 0;
			cout << "Enter the words you want to enter: " << endl;
			cin >> wordcount;
			char** word = new char* [wordcount];
			for (int i = 0; i < wordcount; i++)
				word[i] = new char[20];
			cout << "Enter the words:-" << endl;
			cin.ignore();
			for (int i = 0; i < wordcount; i++)
			{
				cin.getline(word[i], 20);
			}
			pluralWords(word, wordcount);
			cout << endl;
			for (int i = 0; i < wordcount; i++)
				cout << word[i] << endl;
		}
		else if (choice != 0)
			cout << "Invalid input"<<endl;
	}
}
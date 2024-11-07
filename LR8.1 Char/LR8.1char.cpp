#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;


int CountLet(char* str, char cr)
{
	int k = 0; 
	size_t pos = 0;
	char* t;
	while (t = strchr(str + pos, cr)) {
		if (str[pos] == cr)
			k++;
		pos++;
	}
	return k;
}
char* Change(char* str)
{
	size_t len = strlen(str);

	char* t = new char[len];
	char* p;
	size_t pos1 = 0,
		pos2 = 0;
	*t = 0;

	while (p = strchr(str + pos1, 'w')) {
		if (str[p - str + 1] == 'h'
			&&
			str[p - str + 2] == 'i'
			&&
			str[p - str + 3] == 'l'
			&&
			str[p - str + 4] == 'e') {
			pos2 = p - str + 5;
			strncat_s(t,len, str + pos1, pos2 - pos1 - 5);
			strcat_s(t,len, "**");
			pos1 = pos2;
		}
		else {
			pos2 = p - str + 1;
			strncat_s(t,len, str + pos1, pos2 - pos1);
			pos1 = pos2;
		}
	}
	strcat_s(t,len, str + pos1);
	strcpy_s(str, len, t);

	return t;
}
int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);

	cout << "String contained " << CountLet(str, 'w') << " \'w\'" << endl;
	cout << "String contained " << CountLet(str, 'h') << " \'h\'" << endl;
	cout << "String contained " << CountLet(str, 'i') << " \'i\'" << endl;
	cout << "String contained " << CountLet(str, 'l') << " \'l\'" << endl;
	cout << "String contained " << CountLet(str, 'e') << " \'e\'" << endl;
	
	char* modstr = new char[151];
	modstr = Change(str);
	
	cout << "Modified string: " << modstr << endl;

	delete[] modstr;
	return 0;
}
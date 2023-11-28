#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int FindChar(char* str)
{
    if (strlen(str) < 3)
        return 0;
    int k = 0;
    for (int i = 1; i < strlen(str); i++) {
        if (str[i] == 'B' || str[i] == 'A' || str[i] == 'S' || str[i] == 'I' || str[i] == 'C')
            k++;
    }
    return k;
}
char* Change(char* str)
{
    size_t len = strlen(str);
    if (len < 5)
        return str;

    char* tmp = new char[len * 2 + 1];
    char* t = tmp;
    tmp[0] = '\0';
    size_t i = 0;

    while (i < len)
    {

        if (strncmp(str + i, "BASIC", 5) == 0)
        {
            strcat(t, "DELPHI");
            t += 6;
            i += 5;
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';
        }
    }


    while (i < len)
    {
        *t++ = str[i++];
        *t = '\0';
    }

    *t = '\0';

    strcpy(str, tmp);

    return tmp;
}
int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    cout << "Number of chars BASIC:    " << FindChar(str) << endl;
    char* dest = new char[151];

    dest = Change(str);
    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;
    return 0;
}
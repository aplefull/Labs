//Удалить слова, содержащие чётное кол-во символов.
#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int n = 0;
	char a[100];
	
	gets_s(a);

	strcat_s(a, " ");

	for (int i = 0; i < strlen(a); i++)
	{
		if (a[i] != ' ')
		{
			n++;
		}

		else
		{
			if ( (n) % 2 == 0 && n != 0)
			{
				for (; n > 0; n--)
				{
					for (int j = i - 1; j < strlen(a); j++)
					{
						a[j] = a[j + 1];
					}

					i--;
				}
			}

			n = 0;
		}
	}

	puts(a);
    return 0;
}
//Удалить слова, содержащие чётное кол-во символов.
#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int n = 0, size;
	char a[100];
	
	gets_s(a);

	strcat_s(a, " ");

	for (int i = 0; i < strlen(a); i++){

		if (a[i] != ' '){
			n++;
		}

		else{

			if ( (n) % 2 == 0 && n != 0){
				i -= n;
				size = strlen(a);
				for (int j = i; j < size - n + 1; j++){
						a[j] = a[j + n];
				}
			}
			n = 0;
		}
	}
	puts(a);
    return 0;
}
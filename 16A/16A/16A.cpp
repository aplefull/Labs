#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

using namespace std;

struct tstk
{
	double inf;
	tstk *a;
};

tstk *AddStack(tstk *sp, double inf)
{
	tstk *spt = new tstk;
	spt->inf = inf;
	spt->a = sp;
	return spt;
}

tstk *ReadStack(tstk *sp, double &inf)
{
	tstk *spt = sp;
	inf = sp->inf;
	sp = sp->a;
	delete spt;
	return sp;
}

double masz[122];
char str[100], strp[100];

int priority(char ch)
{
	switch (ch)
	{
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	case '^': return 3;
	default: return -1;
	}
}

void AddPostFix(char *strin, char *strout)
{
	tstk *sp = NULL;
	int n = 0;
	char ch;
	double inf;

	for (unsigned int i = 0; i < strlen(strin); i++)
	{
		ch = strin[i];
		if (ch >= 'A') { strout[n++] = ch; continue; }
		if (sp == NULL || ch == '(') { sp = AddStack(sp, ch); continue; }
		if (ch == ')')
		{
			while (sp->inf != '(')
			{
				sp = ReadStack(sp, inf);
				strout[n++] = (char)inf;
			}
			sp = ReadStack(sp, inf);
			continue;
		}

		int pr = priority(ch);

		while (sp != NULL && priority((char)sp->inf) >= pr)
		{
			sp = ReadStack(sp, inf);
			strout[n++] = (char)inf;
		}
		sp = AddStack(sp, ch);
	}
	while (sp != NULL)
	{
		sp = ReadStack(sp, inf);
		strout[n++] = (char)inf;
	}
	strout[n++] = '\0';
}

double rasAV(char *str, double *mz)
{
	tstk *sp = NULL;
	char ch;
	double inf, inf1, inf2;
	for (unsigned int i = 0; i < strlen(str); i++)
	{
		ch = str[i];
		if (ch >= 'A') { sp = AddStack(sp, mz[int(ch)]); continue; }
		sp = ReadStack(sp, inf2);
		sp = ReadStack(sp, inf1);

		switch (ch)
		{
		case '+': sp = AddStack(sp, inf1 + inf2); break;
		case '-': sp = AddStack(sp, inf1 - inf2); break;
		case '*': sp = AddStack(sp, inf1 * inf2); break;
		case '/': sp = AddStack(sp, inf1 / inf2); break;
		case '^': sp = AddStack(sp, pow(inf1, inf2)); break;
		}
	}
	sp = ReadStack(sp, inf);
	return inf;
}

int main()
{
	cout << "Vvedite a" << endl; cin >> masz[int('a')];
	cout << "Vvedite b" << endl; cin >> masz[int('b')];
	cout << " Vvedite viragenie (a, b, c, d, f) " << endl;
	cin >> str;
	AddPostFix(str, strp);
	cout << endl << strp;
	double s = rasAV(strp, masz);
	cout << endl << " Result = " << s << endl;
	return 0;
}


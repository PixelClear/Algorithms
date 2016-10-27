#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<string.h>

#define MAXLINE 5000

/*
Purpose of the programe is to demonstrate the ease 
we get while handling array of strings and we can 
easily sort them using array of pointers and as 
we can see array holds address of first character. 
*/
char* lineptr[MAXLINE];

int readlines(char* lineptr[], int nlines);
void writelines(char* lineptr[],int nlines);
int getline(char*, int);

void qsort(char* lineptr[], int left, int right);

int main()
{
	int nlines =0;

	if((nlines = readlines(lineptr,MAXLINE)) >=0)
	{
		shell_sort(lineptr,nlines);
		writelines(lineptr, nlines);
	}
	return 0;
}

int getline(char s[], int lim)
{
	int c;
	int i = 0;

	while(--lim > 0 && (c = getchar())!= EOF && c != '\n')s[i++] = c;
	if(c == '\n')
		s[i++] = '\n';
	s[i] = '\0';

	return i;
}

int readlines(char* lineptr[], int maxlines)
{
	int len , nlines;
	char* p, line[MAXLINE];

	nlines = 0;
	while((len = getline(line,MAXLINE)) > 0)
	{
		if(nlines > maxlines || (p =(char*) malloc(len)) == NULL)
			return -1;
		else
		{
			line[len-1] = '\0';
			strcpy(p,line);
			lineptr[nlines++] = p;
		}
	}

	return nlines;
}

void writelines(char* lineptr[], int nlines)
{
	int i =0;
	for(i = 0;i< nlines;i++)
		printf("%s\n",lineptr[i]);
}

void shell_sort(char* v[], int n)
{
	int gap = 0;
	int i = 0;
	int j = 0;

	for(gap = n/2; gap > 0; gap/=2)
	{
		for(i = gap ; i < n; i++)
		{
			for(j = i-gap; j >= 0 && strcmp(v[j], v[j+gap]) < 0 ; j-=gap)
			{
				char* temp;
				temp = v[j];
				v[j] = v[j+gap];
				v[j+gap] = temp;
			}
		}
	}

}

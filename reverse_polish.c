#include<stdio.h>
#include <ctype.h>

#define MAXLINE 100
#define NUMBER '0'
#define BUFSIZE 100


double atof(char s[]);
int getline(char s[], int lim);
char buff[BUFSIZE];
int bufp = 0;


int getch(void)
{
	return (bufp > 0) ? buff[--bufp] : getchar();
}

void ungetch(int c)
{
	if(bufp >= BUFSIZE)
		printf("Error in ungetch()\n");
	else
		buff[bufp++] = c;
}

int getops(char s[])
{
	int c;
	int i = 0;

	while((s[0] = c = getchar()) == ' ' || c == '\t');
	s[1]='\0';
	if(!isdigit(c) && c != '.')
		return c;

	i=0;
	if(isdigit(c))
		while(isdigit(s[++i] = c = getch()));
	if(c == '.')
	    while(isdigit(s[++i] = c = getch()));

	s[i] = '\0';
	if(c != EOF)
		ungetch(c);

	return NUMBER;
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

double atof(char s[])
{
  int i = 0;
  int sign = 0;
  double val = 0.0;
  double pow = 0.0;

  for(i = 0; i < isspace(s[i]); i++);
  sign = (s[i] == '-') ? -1 : 1;
  if(s[i] == '+' || s[i] == '-')
      i++;

  for(val = 0.0 ; isdigit(s[i]);i++)
	  val = 10.0 * val + s[i] -'0';
  if(s[i] == '.')
	  i++;
  for(pow = 1.0 ; isdigit(s[i]); i++)
  {
	  val = 10.0 * val + s[i] - '0';
	  pow = pow * 10.0;
  }

  return sign*(val/pow);
}

#define STACKLIMIT 100
int sp = 0;
double stack[STACKLIMIT];

void push(double val)
{
	if(sp < STACKLIMIT)
		stack[sp++] = val;
	else 
		printf("Stack full error\n");
}

double pop()
{
	if(sp > 0)
		return stack[--sp];
	else
	{
		printf("Stack empty error!\n");
		return 0.0;
	}
}

int main()
{
	char s[MAXLINE];
	int type;
	double op2;

	while((type = getops(s)) != EOF)
	{
		switch(type)
		{
		case NUMBER :
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '*':
			push(pop() * pop());
			break;
		case '/':
			op2 = pop();
			if(op2 != 0.0)
				push(pop()/op2);
			else 
				printf("Divide by zero error !!\n");
			break;

		case '\n':
			   printf("\tResult = %.8g\n",pop());
			break;

		}
	}
	

	return 0;
}

void reverse(char s[])
{
	int i =0;
	int j =0;
	char c = 0;

	for (i = 0, j =strlen(s)-1 ; i < j ; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}


void _itoa(int n , char s[])
{
	int num = 0;
	int i = 0;
	int sign = 0;

	if(n < 0)
	{
		n = -n;
		sign = -1;
	}
	
	while(n>0)
	{
		num = n%10;
		s[i++] = num;
		n/=10;
	}

	if(sign == -1)
		s[i++] = '-';

	s[i] = '\0';

	reverse(s);
}


int _atoi(char c[])
{
	int n = 0;
	int i = 0;
	int sign = 0;

	for(i = 0;c[i] == ' ';i++);

	sign = (c[i] == '-') ? -1 : 1;
	
	if(c[i] == '-' || c[i] == '+')
		i++;          

	for( ; c[i] != '\0' ; i++)
		n = n* 10 + (c[i] - '0');

	return (sign*n);
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


int main()
{
	char c[] = "-128";

	printf("Number: %d", _atoi(c));

	return 0;
}

void strcat(char *s, char *t)
{
	while(*s++!='\0');
    while(*s++=*t++);
	*s='\0';
}

int strend_1(char *s , char *t)
{
	char *bs = s;
	char *bt = t;

	while(*s != '\0')
		s++;

	while(*t != '\0')
	{
		s--;
		t++;
	}

	for(t=bt ; *s == *t; s++,t++)
	{
		if(*t == '\0' && *s == '\0')
			return 1;
	}
	return 0;
}

int strend_2(char *s , char *t)
{
	char *bs = s;
	char *bt = t;

	while(*s != '\0')
		s++;
	while(*t != '\0')
		t++;

	for(; *s == *t ; s--,t--)
	{
		if(t == bt || s == bs)
			break;
	}

	if(*s == *t && t == bt && *s != '\0')
		return 1;

	return 0;
}

int strlen(char *s)
{
	char *bs =s;
	while(*s != '\0')
		s++;

	return s-bs;
}

int strend_3(char *s , char *t)
{
	char *bs = s;
	int len = strlen(s) - strlen(t);

	s+=len;

	while(*s == *t)
	{
		if(*s == '\0' || *t == '\0')
			break;
		s++;
		t++;

	}	
	if(*s == '\0' && *t == '\0')
		return 1;

return 0;

}


void strncpy(char* s, char* t, int n)
{
	while(*s != '\0')
	      s++;
	while(n > 0 || *t != '\0')
	{
		*s = *t;
		s++;
		t++;
		n--;
	}
  *s = '\0';
}

int strncmp(char *s, char *t, int n )
{
	for(;*s == *t; s++,t++)
	{
		if(*s == '\0' || *t == '\0' || --n <=0)
			break;
	}

	return *s - *t;
}

int strcmp(char *s, char *t)
{
	for(;*s == *t;s++,t++)
	{
		if(*s == '\0' || *t == '\0')
			break;
	}

	if(*s == '\0' && *t == '\0')
		return 0 ;
	else 
		*s-*t;
}

int strncmp(char *s, char *t, int n )
{
	for(; n > 0; s++,t++,n--)
	{
		if(*s!=*t)
			return *s-*t;
	}

	if(*t == '\0')
		return 0;
}

int main()
{

return 0;
}

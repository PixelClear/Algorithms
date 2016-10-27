#include <stdio.h>
#include<limits.h>
/*Needed for float ranges*/
#include<float.h>
#include<string.h>

int main()
{
    int i =0;
    int n = 0;
    char s[]="0x01A";
    int hex_digit = 0;
    int len = 0;

    while(s[i] != 'x')// || s[i] !='X')
         i++;
	/* i is pointing to x we want to make it to point to next char*/
    i++;
	
    for(;s[i] != '\0';i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
          hex_digit = s[i] - '0';
        else if(s[i] >= 'a' && s[i] <= 'f')
          hex_digit = (s[i] -'a') + 10;
        else if(s[i] >= 'A' && s[i] <= 'F')
          hex_digit = (s[i] -'A') + 10;
          
          n = n * 16 + hex_digit;
    }
    
    printf("(%s)16: (%d)10\n",s,n);
    return 0;
}

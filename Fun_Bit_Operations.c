/*Some points to remember while working with bits
1. & to unset bits 
2. | to set bits 
3. us ~0 to built mask to eliminate or add bits we want
4. work with 8 bits data 
5. operands with bit operators must be integral type else result is undef
6. right shift of signed quantity will fill emptied slots with sign bits(arithmatic shift)
   on some machine else with 0 (logical shift) on other machines
7. right shifting unsigned quantity will fill zeros in empty slots
8.Right shift by 1 is divide by 2 and other is multiply by 2*/

#include <stdio.h>
unsigned int setbits(unsigned int x,unsigned int p,unsigned int n,unsigned int y)
{
	return (x & ~(~(~ 0 << n) << (p+1-n))) | ((y & ~(~0 << n)) << (p+1-n));
}

//First expression brings 0 to n th position and then we & it with x 
//So now nth bits of X are 0 then we or them with modified y.

/*----------------------------------2.7----------------------------*/

void invert(unsigned int x,unsigned int p,unsigned int n)
{
  return (x^ (~(~0 << n) << (p+1-n)));
}
/*we create mask with 111 at position p and xoring will give proper results*/

/*----------------------------------2.8----------------------------*/
#include <stdio.h>
#include<limits.h>
/*Needed for float ranges*/
#include<float.h>
#include<string.h>

int word_length()
{
	int i = 0;
	unsigned int num = ~0;

	for(i=0; (num = num >> 1) > 0;i++);

	return i;
}

unsigned rightrot(unsigned x, int n)
{

	int rbit;

	while(n-- > 0)
	{
		/*This statement brings rightmost bit to leftmost position*/
		rbit = (x & 1) << (word_length()-1);
		x = x >> 1;
		x = x | rbit;
	}

	return x;
}

/*----------------------------------2.9----------------------------*/
/*Count number bits set to 1*/
#include <stdio.h>
#include<limits.h>
/*Needed for float ranges*/
#include<float.h>
#include<string.h>

int bit_count(unsigned int v)
{
	int i =0;

	for(i = 0 ; v > 0 ; v >>= 1)
		if(v & 01)
			i++;

	return i;
}


int main()
{
	printf("%d\n",bit_count(7));
	return 0;
}

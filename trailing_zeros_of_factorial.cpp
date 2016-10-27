#include <iostream>
/* Issues faced 

1.What if factorial is <1
2.What should be size of data type for factorial
3.how to convert integer to string
4.How to find trailing zeros ( I have used ascii value trick )
*/
using namespace std;

int get_length(int i)
{
	int count = 0;
	while( i != 0)
	{
		i=i/10;
		count++;
	}
	return count;
}

long long int factorial(long long int n)
{
		
	if(n < 1)
		return 1;
	else
	return n*factorial(n-1);
}

// Function to return trailing 0s in factorial of n
unsigned long long int findTrailingZeros(unsigned long long int n)
{
    // Initialize result
    unsigned long long int count = 0;
 
    // Keep dividing n by powers of 5 and update count
    for (unsigned int i=5; n/i>=1; i *= 5)
          count += n/i;
 
    return count;
}

int get_trail_zeros(const char* number)
{
	int length =strlen(number);
	int zeros = 0;

	for(int i = length-1; i>=0; i--)
	{
		if('0'-number[i] == 0)
			zeros++;
		else 
			break;
	}

	return zeros;

}

int main()
{
	long long int n;

	cout << "Enter the number";
	cin >> n;

	long long int fact = factorial(n);
	int length = get_length(fact);
	char* number = (char*) malloc(sizeof(char)*length);

	sprintf(number, "%lli", fact);

	int trailing_zero = findTrailingZeros(n);
	cout << endl << "factorial : " << fact;
	cout << endl << "trail zeros" << endl;
	cout << trailing_zero;

	int k;

	cin >> k;
	return 0;

}

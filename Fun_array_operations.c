/* when locally you say int *p = &s;
s is on stack and p hold its adress.
So pointer not compulsory hold memory from malloc.
It is plan variable capable to hold adress.

Also when char[] pass to function internally it is converted
to char * so you can modify it in function.
Dont confuse it with char a[] a is const pointer.
when passed to function its not const pointer any more.

Following is some array fun.

*/
void print_a(int (*a)[4])
{
	for(int i = 0; i < 4; i++)
	{
		printf("%d\n",(*a)[i]);
	}
	//This statement will now point to next 1D array in our original 2D array
	a++;
	for(int i = 0; i < 8; i++)
	{
		printf("%d\n",(*a)[i]);
	}
}

int main()
{
	int a[4]={1,2,3,4};
	            

	print_a(&a);
	return 0;
}

void print_a(int (*a)[4])
{
	for(int i = 0; i < 8; i++)
	{
		printf("%d\n",(*a)[i]);
	}
}

int main()
{
	int **a;
	int cols = 4;
	int rows = 3;
	int i = 0;
	int j = 0;
	int (*point)[4][3];

	//Allocating array dynamically
	a=(int**) malloc(sizeof(int*) * rows);
	
	if(a != NULL)
	{
		for( i = 0; i < rows ;i++)
		{
			*(a+i) = (int*) malloc(sizeof(int) * cols);
		}
	}

	for( i = 0; i < rows; i++)
	{
		for(j = 0;j<cols;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	//Accessing the array as 1D array 
	//a[3][2] a[3*cols+2]
	for( i = 0; i < rows; i++)
	{
		for(j = 0;j<cols;j++)
		{
			printf("%d",a[3*cols+j]);
			printf("%d",*(a+(3*cols)+j));
		}
	}

	//Access 2d array using pointer to array 
	point = (int (*)[4][3])&a;
	for( i = 0; i < rows; i++)
	{
		for(j = 0;j<cols;j++)
		{
			printf("%d",(*point)[i][j]);
		}
	}

	//Freeing the dynamically allocated 2D array 
	for( i = 0 ; i <rows ;i++)
	{
		free(a[i]);
	}
free(a);
	return 0;
}

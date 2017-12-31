#include <stdio.h>
#include <stdlib.h>

int length(char* s)
{
    int i = 0;
    while(*s++) i++;
    return i;
}

int lengthPtr(char* s)
{
    char* bs = s;
    while(*s != '\0') s++;
    return s-bs;
}

void cat(char* s, char* t)
{
  while(*s++);
  s--;
  while(*s++ = *t++);
  *s ='\0';
}

void ncpy(char* s, char *t , int n)
{
  while(*s != '\0') s++;
  s--;
  while(n > 0)
  {
      if(*t == '\0')
          break;

      *s = *t;
      s++;
      t++;
      n--;
  }

  *s = '\0';
}

int ncmp(char* s, char* t, int n)
{
    while(*s == *t)
    {
        if(*s == '\0' || *t == '\0' || n-- >=0)
            break;
        s++;
        t++;
    }

     return *s-*t;
}

int cmp(char* s, char* t)
{
  while(*s == *t)
  {
      if(*s == '\0' || *t == '\0')
          break;
      s++;
      t++;
  }

  if(*s == '\0' && *t == '\0')
     return 0;
  else
     return *s-*t;
}

void reallocStrategy()
{
    int *oldpointer = (int* )malloc(100);

/* ... */

    int *newpointer =(int *) realloc(oldpointer, 1000);
    if (newpointer == NULL) {
        /* problems!!!!                                 */
        /* tell the user to stop playing DOOM and retry */
        /* or free(oldpointer) and abort, or whatever   */
    } else {
        /* everything ok                                                                 */
        /* `newpointer` now points to a new memory block with the contents of oldpointer */
        /* `oldpointer` points to an invalid address                                     */
        oldpointer = newpointer;
        /* oldpointer points to the correct address                                */
        /* the contents at oldpointer have been copied while realloc did its thing */
        /* if the new size is smaller than the old size, some data was lost        */
    }

}

void rev1(char* s)
{
  char temp;
  int len = length(s);
  len--;
  int i = 0;
  int j = len;

  while(j < i)
  {
      temp = s[j];
      s[j] = s[i];
      s[i] = temp;
      i++;
      j--;
  }
}

void rightShift(char *s, int n)
{
  int len = length(s);
  char * shifted = (char*) malloc(sizeof(char) * len);

  for(int i = 0 ; i < len; i++)
  {
      int idx = (i + n)%len;
      shifted[idx] = s[i];
  }

  delete shifted;
}

int main()
{
    int len = length("Paritosh");
    printf("%d\n", len);

    len = lengthPtr("Paritosh");
    printf("%d\n", len);

    char s[123] = "Paritosh";
    cat(s, "Kulkarni");
    printf("%s\n", s);

    char s1[123] = "Paritosh";
    ncpy(s1, "Kulkarni",3);
    printf("%s\n", s1);

    int ret = cmp(s,s1);
    printf("%d\n", ret);

    char* p = "Paritosh";
    //rev1(p);
    //rightShift(p, 3);
    leftShift(p, 3);
    printf("%s", p);

    return 0;
}


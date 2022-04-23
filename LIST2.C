#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "LIST2.H"
 

void GetStr( char *Str, int MaxLen )
{
  int i = 0;
  char ch;

  while ((ch = getchar()) != '\n')
  {
    if(Str != NULL && i < MaxLen - 1)
      Str[i++] = ch;
  }
    if(Str != NULL && i < MaxLen)
      Str[i] = 0;
}
/*case 1*/
int ListAddToFront( LIST **T, char *val )
{
  LIST *next = NULL;
  
  while(*T != NULL)
  {
	next = *T;
	T = &(*T)->Prev;
  }
  *T = (LIST*) malloc(sizeof(LIST));
  if (T == NULL)
	  return 0;

  (*T)->Prev = NULL;
  (*T)->Next = next;
  strncpy((*T)->Str, val, MAX - 1);
  return 1;
}
/*case 2*/
int ListDelFromFront( LIST **T, char *Old )
{
  LIST *next = NULL;
  if (*T == NULL)
    return 0;

  if ((*T)->Prev == NULL && (*T)->Next != NULL)
    *T = (*T)->Next;

  while ((*T)->Prev != NULL)
  {
    next = *T;
    T = &(*T)->Prev;
  }

  if (Old != NULL)
    strncpy(Old, (*T)->Str, MAX - 1);

  if (next != NULL)
    next->Prev = NULL;
  else
    *T = NULL;
  free(*T);
  return 1;
} 
/*case 3*/
int ListAddToBack( LIST **pList,  char *val )
{
  LIST *next = NULL;
  
  while(*pList != NULL)
  {
	next = *pList;
	pList = &(*pList)->Next;
  }
  *pList = (LIST*) malloc(sizeof(LIST));
  if (pList == NULL)
	  return 0;

  (*pList)->Next = NULL;
  (*pList)->Prev = next;
  strncpy((*pList)->Str, val, MAX - 1);
  return 1;
}
/*case 4*/
int ListDelFromEnd( LIST **T, char *Old )
{
  LIST *prev;

  if (*T == NULL)
    return 0;

  if ((*T)->Next == NULL && (*T)->Prev != NULL)
    *T = (*T)->Prev;

  if ((*T)->Prev != NULL)
    prev = (*T)->Prev;
  else
    prev = NULL;

  while ((*T)->Next != NULL)
  {
    prev = *T;
    T = &(*T)->Next;
  }

  if (Old != NULL)
    strncpy(Old, (*T)->Str, MAX - 1);

  if (prev != NULL)
    prev->Next = NULL; 
  else
    *T = NULL;

  free(*T);
  
  return 1;
} 
/*case 5*/
void ShiftPrev( LIST **L )
{
	if (*L != NULL && (*L)->Prev != NULL)
		*L = (*L)->Prev;
} 

/*case 6*/
void ShiftNext( LIST **L )
{
if (*L != NULL && (*L)->Next != NULL)
*L = (*L)->Next;
} 

/*case 7*/
int ListAddToArbitrary( LIST **T, char *val )
{
  LIST *next = NULL, *old = NULL;

  if (*T == NULL)
  {
    if ((*T = malloc(sizeof(LIST))) == NULL)
      return 0;

    (*T)->Prev = NULL;
    (*T)->Next = next;
    strncpy((*T)->Str, val, MAX - 1);

    return 1;
  }

  if ((*T)->Prev != NULL)
  {
    old = (*T)->Prev;
    next = *T;

    if ((*T = malloc(sizeof(LIST))) == NULL)
      return 0;

    (*T)->Prev = next->Prev;
    (*T)->Next = next;
    strncpy((*T)->Str, val, MAX - 1);

    next->Prev = *T; 
    old->Next = *T;
  }
  else if ((*T)->Prev == NULL)
  {
    next = *T;

    if ((*T = malloc(sizeof(LIST))) == NULL)
      return 0;

    (*T)->Next = next;
    (*T)->Prev = NULL;
    strncpy((*T)->Str, val, MAX - 1);

    next->Prev = *T;
  }
  return 1;
}
/*case 8*/

int ListDelFromArbitrary( LIST **T, char *Old )
{
  LIST *next = NULL;
               
  if (*T == NULL)
    return 0;

  if (Old != NULL)
    strncpy(Old, (*T)->Str, MAX - 1);

  if ((*T)->Prev != NULL && (*T)->Next != NULL)
  {
    (*T)->Prev->Next = (*T)->Next;
    (*T)->Next->Prev = (*T)->Prev;
    next = (*T)->Next;
  }
  else if ((*T)->Next != NULL)
  {
    (*T)->Next->Prev = NULL;
    next = (*T)->Next;
  }
  else if ((*T)->Prev != NULL)
  {
    (*T)->Prev->Next = NULL;
    next = (*T)->Prev;
  }

  free(*T);
  *T = next;

  return 1;
} 
/*case 9*/
int ClearList( LIST **T )
{
  if (*T == NULL)
    return 0;

  while (*T != NULL && (*T)->Prev != NULL)
    *T = (*T)->Prev;
  while (*T != NULL)
  {
    LIST *old = *T;

    *T = (*T)->Next;
    free(old);
  }

  return 1;
} /* End of 'ClearList' function */

/*display func*/
void ListDisplay( LIST *T )
{
	if (T == NULL)
		printf("<Empty list>\n");
	else
	{
		LIST *save = T;
		while (T->Prev != NULL)
			T = T->Prev;
		while (T != NULL)
		 {
			 printf("%s%s", T->Str, T == save ? "(*)" : "");
			 printf((T = T->Next) != NULL ? "\n" : ",");
		 }
	}
 
}

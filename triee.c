#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "Trie.h"


//Функция создания узлов и выделения памяти для них
Trie *trieNodeCr(char ch);
int fileSize(char *name);
 
Trie *trieCreate(Trie **head)
{
  *head = trieNodeCr('\0');
}

Trie *trieNodeCr(char ch)
{
  Trie *node = NULL;
  node = (Trie *)malloc(sizeof(Trie));
     
  if(node == NULL)
  {
    return node;
  }

  node->ch = ch;
  node->value = 0;
  node->next = NULL;
  node->child = NULL;
  node->parent= NULL;
  node->prev= NULL;
 return node;
}
 
Trie *trieAdd(Trie **head, char *ch)
{
  Trie *node = NULL;
 
	if(*head == NULL)
	{
		/* NULL is more clear to understand */
		return NULL; 
	}

	if((*head)->child == NULL)
	{
	/*Первая строка*/
		for(node = *head; *ch; node = node->child)
		{
			node->child = trieNodeCr(*ch);
			node->child->value++;
			node->child->parent = node;
			ch++;
		}
		return node;
	}

	node = (*head)->child;

	while((*ch) != '\0')
	{
		if((*ch) == node->ch)
		{
			ch++;
			node->value++;
			if (!node->child) {
				break;
			}
			node = node->child;
		}
		else
			break;
	}
 
	if(!(*ch))
	{
		return node;
	}

	while(node->next)
	{
		if(*ch == node->next->ch)
		{
			ch++;
			node->next->value++;
			trieAdd(&(node->next), ch);
			return node;
		}
		node = node->next;
	}

	if(*ch)
	{
		node->next = trieNodeCr(*ch);
		node->next->parent = node->parent;
		node->next->prev = node;
	}

	ch++;

  for(node = node->next; *ch; node = node->child)
  {
    node->child = trieNodeCr(*ch);
    if ( node->ch != '\0')
    {
      node->value++;
    }
    node->child->parent = node;
    ch++;
  }
  node->value++;
  node->child = trieNodeCr('\0');
  node->child->parent = node;
  return node;
}
 
Trie *trieDestroy( Trie* head )
{
  Trie *node = head;
  Trie *tmp = head;
 
  while(node)
  {
    while(node->child)
    node = node->child;
    //Есть оба соседних узла
    if( node->prev && node->next)
    {
      tmp = node;
      node->next->prev = node->prev;
      node->prev->next = node->next;
      free(tmp);
    }
    //Есть левый узел
    else if(node->prev && !(node->next))
    {
      tmp = node;
      node->prev->next = NULL;
      free(tmp);
    }
    //Есть правый узел
    else if(!(node->prev) && node->next)
    {
      tmp = node;
      node->parent->child = node->next;
      node->next->prev = NULL;
      node = node->next;
      free(tmp);
    }
    else
    {
      //Нет дочерних узлов
      tmp = node;
      if(node->parent == NULL)
      {
        /*Корень*/
        free(tmp);
        return node;
      }
      node = node->parent;
      node->child = NULL;
      free(tmp);
    }
  }
}

void triePrint(Trie *head){

  int level = 0;
  return trie_print( head, level);
}

void trie_print(Trie *head, int level)
{
  Trie *node = head;
  int i;
  for (; node != NULL; node = node->next)
  {
    for (i = 0; i < level; i++)
      printf(" ");
      printf("%c (%d)\n", node->ch, node->value);
      if (node->child != NULL)
      {
        trie_print(node->child, level + 1);
      }
  }
  return;
}

int fileSize(char *name)
{
  FILE *fp;
  int size;
  struct stat buff;
  if ((fp=fopen(name, "r")) == NULL) {
    printf("Cannot open file.\n");
    exit (1);
  }
// заполнение структуры типа stat 
  fstat (fileno (fp), &buff);
  size = buff.st_size;
  fclose (fp);
  return size;
}

Trie *trieCreateByFile(Trie **head, char *name)
{
  FILE *fp;
  Trie *node = *head;
  char *arr  = NULL;
  int  buffSize = 0;

  trieCreate(head);
  if ((fp=fopen(name, "r")) == NULL) {
    printf("Cannot open file.\n");
    exit(-1);
  }

	arr = malloc((buffSize =fileSize(name)));
	if (!arr) {
	  fclose(fp);
	  exit(-1);
	}

  while(fscanf(fp, "%s", arr) != EOF)
  {
  // create subtree 
    trieAdd(head, arr);
  }
  free(arr);
  fclose (fp);

  return *head;
}

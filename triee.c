#include <stdio.h>
#include <stdlib.h>
#include "trie.h"


//Функция создания узлов и выделения памяти для них
Trie *TrieNodeCr(char ch);
 
Trie *TrieCreate(Trie **head)
{
  *head = TrieNodeCr('\0');
}

Trie *TrieNodeCr(char ch)
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
 
Trie *TrieAdd(Trie **head, char *ch)
{
  Trie *node = NULL;
 
  if(*head == NULL)
  {
    return node;
  }
  node = (*head)->child;

  if(node == NULL)
  {
  /*Первая строка*/
  for(node = *head; *ch; node = node->child)
  {
    node->child = TrieNodeCr(*ch);
    if ( node->ch != NULL)
    {
      node->value++;
    }
    node->child->parent = node;
    ch++;
  }
  node->value++;
  node->child = TrieNodeCr('\0');
  node->child->parent = node;
  return node;
  }

  while(*ch != '\0')
  {
    if(*ch == node->ch)
      {
      ch++;
      node->value++;
      node = node->child;
    }
  else
  break;
  }
 
  while(node->next)
  {
    if(*ch == node->next->ch)
    {
      ch++;
      TrieAdd(&(node->next), ch);
      return node;
    }
    node = node->next;
  }
 
  if(*ch)
  {
    node->next = TrieNodeCr(*ch);
  }
 
  node->next->parent = node->parent;
  node->next->prev = node;
 
  if(!(*ch))
  {
    return node;
  }

  ch++;
 
  for(node = node->next; *ch; node = node->child)
  {
    node->child = TrieNodeCr(*ch);
    if ( node->ch != NULL)
    {
      node->value++;
    }
    node->child->parent = node;
    ch++;
  }
  node->value++;
  node->child = TrieNodeCr('\0');
  node->child->parent = node;
  return node;
}
 
Trie *TrieDestroy( Trie* head )
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

void TriePrint(Trie *head){

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
      printf("%c (%d) \n", node->ch, node->value);
      if (node->child != NULL)
      {
        trie_print(node->child, level + 1);
      }
  }
  return;
}
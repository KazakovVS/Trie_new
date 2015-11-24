#include <stdio.h>
#include <stdlib.h>

typedef struct trieNode {
  char   ch;
  int    value;
  struct trieNode *next;
  struct trieNode *prev;
  struct trieNode *child;
  struct trieNode *parent;
} Trie;
 
//Функция создания корня дерева
Trie *TrieCreate(Trie **head);
//Функция добавления строк в дерево
Trie *TrieAdd(Trie **head, char *ch);
//Функция удаления дерева
Trie *TrieDestroy( Trie* head );
//Функция печати дерева
void TriePrint(Trie *head);
void trie_print(Trie *head, int level);

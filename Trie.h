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
Trie *trieCreate(Trie **head);
//Функция добавления строк в дерево
Trie *trieAdd(Trie **head, char *ch);
//Функция удаления дерева
Trie *trieDestroy( Trie *head );
//Создание дерева на основе файла
Trie *trieCreateByFile(Trie **head);
//Функция печати дерева
void triePrint(Trie *head);
void trie_print(Trie *head, int level);
int fileSize(char *name);
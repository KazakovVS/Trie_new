#include <stdio.h>
#include <stdlib.h>
#include "trie.h"

int main()
{
    Trie *head;

    
    printf("Trie Example\n");
     
    /*Create a trie*/
    TrieCreate(&head);
     
    TrieAdd(&head, "andrew");
    TrieAdd(&head, "andrewa");
    TrieAdd(&head, "tina");
    TrieAdd(&head, "tinad");
    TrieAdd(&head, "tinada");
    TrieAdd(&head, "tinadaasd");
    TriePrint(head);
 
    /*Destroy the trie*/
    TrieDestroy(head);
 //       TriePrint(head);
}
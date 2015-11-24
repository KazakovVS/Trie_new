#include <stdio.h>
#include <stdlib.h>
#include "trie.h"


int main()
{   
    Trie *head;
    head = trieCreateByFile(&head);
    triePrint(head);
    trieDestroy(head);
    /*Trie *head;
     
    //Create a trie
    trieCreate(&head);
     
    trieAdd(&head, "andrew");
    trieAdd(&head, "andrewa");
    trieAdd(&head, "tina");
    trieAdd(&head, "tinad");
    trieAdd(&head, "tinada");
    trieAdd(&head, "tinadaasd");
    triePrint(head);
 
    //Destroy the trie
    trieDestroy(head);*/
       // TriePrint(head);
}
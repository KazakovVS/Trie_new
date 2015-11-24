#include <stdio.h>
#include <stdlib.h>
#include "trie.h"


int main()
{   
    Trie *head;
    int s = fileSize("test.txt");
    char arr[s][s];
    printf("%d\n", s );
    trieCreateByFile(&head, "test.txt");
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
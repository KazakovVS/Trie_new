#include <stdio.h>
#include <stdlib.h>
#include "Trie.h"


int main()
{   
    Trie *head;
    trieCreateByFile(&head, "test.txt");
      /*trieCreate(&head);
        trieAdd(&head, "asdf");
    trieAdd(&head, "asdfg");
    trieAdd(&head, "asdfgh");
    */
    triePrint(head);
    trieDestroy(head);
    /*Trie *head;
     
    //Create a trie
    trieCreate(&head);

    trieAdd(&head, "asdf");
    trieAdd(&head, "asdfg");
    trieAdd(&head, "asdfgh");
    trieAdd(&head, "tinad");
    trieAdd(&head, "tinada");
    trieAdd(&head, "tinadaasd");
    triePrint(head);
 
    //Destroy the trie
    trieDestroy(head);*/
       // TriePrint(head);
}

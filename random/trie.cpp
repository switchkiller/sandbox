#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
#define ALPHABET_SIZE (26)
#define CHAR_TO_INDEX(c) (int(c) - 65)

typedef struct trie_node trie_node_t;

struct trie_node{
  int value;
  trie_node_t *children[ALPHABET_SIZE];
};

typedef struct trie trie_t;

struct trie{
  trie_node_t *root;
  int count;
};

trie_node_t *getNode(void){
  trie_node_t *pNode = NULL;
  pNode = (trie_node_t *) malloc(sizeof(trie_node_t));
  if (pNode){
    int i;
    pNode->value = 0;
    for (i = 0; i < ALPHABET_SIZE; i++)
      pNode->children[i] = NULL;
  }
  return pNode;
}

void initialize(trie_t *pTrie){
  pTrie->root = getNode();
  pTrie->count = 0;
}

void insert(trie_t *pTrie, char key[]){
  int level;
  int length = strlen(key);
  int index;
  trie_node_t *pCrawl;

  pTrie->count++;
  pCrawl = pTrie->root;

  for (level = 0; level < length; level++){
    index = CHAR_TO_INDEX(key[level]);
    if (!pCrawl->children[index])
      pCrawl->children[index] = getNode();
    pCrawl = pCrawl->children[index];
  }
  pCrawl->value = pTrie->count;
}

int search(trie *pTrie, const char key[]){
  int level;
  int length = strlen(key);
  int index;
  trie_node_t *pCrawl;

  pCrawl = pTrie->root;

  for(level = 0; level < length; level++){
    index = CHAR_TO_INDEX(key[level]);

    if (!pCrawl->children[index])
      return 0;
    pCrawl = pCrawl->children[index];
  }

  return (0 != pCrawl && pCrawl->value);
}

int leafNode(trie_node_t *pNode){
  return (pNode->value != 0);
}

int isItFree(trie_node_t *pNode){
  int i;
  for (i = 0; i < ALPHABET_SIZE; i++)
    if (pNode->children[i])
      return 0;
  return 1;
}

bool deleleUtil(trie_node_t *pNode, char key[], int level, int len){
  if (pNode){
    if (level == len){ //Base.
      if (pNode->value){
        pNode->value = 0;
        if (isItFree(pNode))
          return true;
        return false;
      }
    }
    else{ //Recursion.
       int index = CHAR_TO_INDEX(key[level]);
       if (deleleUtil(pNode->children[index], key, level+1, len)){
         free (pNode->children[index]);
         return (!leafNode(pNode) && isItFree(pNode));
       }
    }
  }
  return false;
}

void deleteKey(trie_t *pTrie, char key[]){
  int len = strlen(key);
  if (len > 0){
    deleleUtil(pTrie->root, key, 0, len);
  }
}
int main(){
  char keys[][8] = {"the", "there", "a", "answer", "any", "by", "bye", "their"};
  trie_t trie;
  char output[][32] = {"Not present in trie", "Present in trie"};
  initialize(&trie);

  // Construct trie
  for(int i = 0; i < ARRAY_SIZE(keys); i++)
  {
      insert(&trie, keys[i]);
  }

    // Search for different keys
  printf("%s --- %s\n", "the", output[search(&trie, "the")] );
  printf("%s --- %s\n", "these", output[search(&trie, "these")] );
  printf("%s --- %s\n", "their", output[search(&trie, "their")] );
  printf("%s --- %s\n", "thaw", output[search(&trie, "thaw")] );
  printf("%s --- %s\n", "there", output[search(&trie, "there")] );
  printf("%s --- %s\n", "a", output[search(&trie, "a")] );
  deleteKey(&trie, keys[1]);
  deleteKey(&trie, keys[2]);
  printf("%s --- %s\n", "a", output[search(&trie, "a")] ); //TODO: error... 'a' not deleting
  printf("%s --- %s\n", "there", output[search(&trie, "there")] );
  //printf("%s --- %s\n", "answer", output[search(&trie, "answer")] );
  return 0;
}

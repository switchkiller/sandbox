// Implement reverse DNS lookup cache
// Method: Using trie

#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<cstdio>
#define MAX 50
#define CHARS 11

int getIndex(char c) { return (c == '.') ? 10 : (c - 48); }
char getCharFromIndex(int i){ return (i == 10) ? '.' : (48 + i); }

typedef struct trieNode trienode;
struct trieNode{
  bool isLeaf;
  char *URL;
  trienode *child[CHARS];
};

trienode *newTrieNode(void){
  trienode *newNode = new trieNode;
  newNode->isLeaf = false;
  newNode->URL = NULL;
  for (int i = 0; i < CHARS; i++)
    newNode->child[i] = NULL;
  return newNode;
}

void insert(trienode *root, char *ipAdd, char *URL){
  int len = strlen(ipAdd);
  trienode *pCrawl = root;
  for (int level = 0; level < len; level++){
    int index = getIndex(ipAdd[level]);
    if (!pCrawl->child[index])
      pCrawl->child[index] = newTrieNode();
    pCrawl = pCrawl->child[index];
  }
  pCrawl->isLeaf = true;
  pCrawl->URL = new char[strlen(URL) + 1];
  strcpy(pCrawl->URL, URL);
}

char *searchDNSCache(trienode *root, char *ipAdd){
  trienode *pCrawl = root;
  int len = strlen(ipAdd);
  for (int level = 0; level < len; level++){
    int index = getIndex(ipAdd[level]);
    if (!pCrawl->child[index])
      return NULL;
    pCrawl = pCrawl->child[index];
  }
  if (pCrawl != NULL && pCrawl->isLeaf)
    return pCrawl->URL;
  return NULL;
}

//Driver.
int main(){
  char ipAdd[][MAX] = {"74.125.200.106", "127.0.0.1"};
  char URL[][50] = {"www.google.com", "www.switchkiller.com"};
  int n = sizeof(ipAdd)/sizeof(ipAdd[0]);
  trienode *root = newTrieNode();
  for (int i = 0; i < n; i++)
    insert(root, ipAdd[i], URL[i]);
  char ip[] = "127.0.0.1";
  char *res_url = searchDNSCache(root, ip);
  if (res_url != NULL)
    printf("Reverse DNS look up resolved in cache:\n%s --> %s", ip, res_url);
  else
    printf("Reverse DNS look up not resolved in cache \n" );
  return 0;
}

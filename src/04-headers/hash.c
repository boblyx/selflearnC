/**
 * Hash function
 */

unsigned int hash(char* key, int cap){

  unsigned long hash = 5381;
  int c;

  while((c= *key++)){
    /* hash * 33 + c */
    hash = ((hash << 5)+ hash) + c; 
  }

  return hash % cap;
}

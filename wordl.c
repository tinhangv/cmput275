#include <stdio.h>
#include <string.h>
const char * const GREEN = "\x1b[32m";
const char * const YELLOW = "\x1b[33m";
const char * const WHITE = "\x1b[0m";
const char * current = "\x1b[0m";

void setColour(const char *colour) {
  if (current == colour) return;
  printf("%s", colour);
  //printf("*");
  current = colour;
}

// void printArray(int arr[], unsigned int len) {
//   for (unsigned int i = 0; i < len; ++i) {
//     printf("%d", arr[i]);
//   }
//   printf("\n");
// }

int main(int argc, char *argv[]){
  //store word from command line arg
  const char *word = argv[1];
  const int len = strlen(word);
  int wordLetters[26] = {0};
  for (int k=0; k<len; ++k){++wordLetters[(int)word[k]-97];} 

  //printArray(wordLetters,26);
  
  //6 guesses
  for (int i=0; i<6; ++i){
    char curWord[len];
    int curWordLetters[26] = {0};
    int greens = 0;
    printf("Enter guess: ");
    scanf("%s", curWord);
    
    //count green letters
    for(int j=0; j<len; ++j){
      char c = curWord[j];
      if(c==word[j])++curWordLetters[(int)c-97];
    }

    for(int j=0; j<len; ++j){
      char c = curWord[j];
      //determine letter colour 
      if(c==word[j]){ //green
        setColour(GREEN);
        ++greens;
      }else if(curWordLetters[(int)c-97] < wordLetters[(int)c-97]){ //yellow
        setColour(YELLOW);
        ++curWordLetters[(int)c-97];
      }else {setColour(WHITE);}//white
      //print letter
      printf("%c",c);
    }
    
    printf("\n");
    setColour(WHITE);
    if(greens == len){
        printf("Finished in %d guesses\n",i+1);
        return 0;
    }
  }
  printf("Failed to guess the word: %s\n", word);
  return 0;

}
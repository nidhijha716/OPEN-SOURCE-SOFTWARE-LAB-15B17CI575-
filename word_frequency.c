#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

void toLowerCase(char *str)
{
  for (int i = 0; str[i]; i++)
  {
    str[i] = tolower(str[i]);
  }
}

int findWord(char *word, char words[][MAX_WORD_LENGTH], int wordCounts[], int size)
{
  for (int i = 0; i < size; i++)
  {
    if (strcmp(words[i], word) == 0)
    {
      return i;
    }
  }
  return -1;
}

void addWord(char *word, char words[][MAX_WORD_LENGTH], int wordCounts[], int *size)
{
  int index = findWord(word, words, wordCounts, *size);
  if (index == -1)
  {
    strcpy(words[*size], word);
    wordCounts[*size] = 1;
    (*size)++;
  }
  else
  {
    wordCounts[index]++;
  }
}

int main()
{
  char paragraph[1000];
  char words[MAX_WORDS][MAX_WORD_LENGTH];
  int wordCounts[MAX_WORDS] = {0};
  int wordCount = 0;

  printf("Enter a paragraph: ");
  fgets(paragraph, sizeof(paragraph), stdin);

  char *token = strtok(paragraph, " ,.-\n");
  while (token != NULL)
  {
    toLowerCase(token);
    addWord(token, words, wordCounts, &wordCount);
    token = strtok(NULL, " ,.-\n");
  }

  printf("Word Frequencies:\n");
  for (int i = 0; i < wordCount; i++)
  {
    printf("%s: %d\n", words[i], wordCounts[i]);
  }

  return 0;
}

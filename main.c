// Program to use the dictionary lookup function

#include <stdio.h>
#include <stdbool.h>

// Define Structures
struct entry {
  char word[15];
  char definition[50];
};

// Declare Functions
bool areEqual (const char [], const char []);
int lookup (const struct entry [], const char [], const int);


int main(void) {

  const struct entry dictionary[100] = {
    { "aardvarK", "a burrowing african mammal" },
    { "abyss", "a bottomless pit" },
    { "acumen", "mentally sharp; keen" },
    { "addle", "to become confused" },
    { "aerie", "a high nest" },
    { "affix", "to append; attach" },
    { "agar", "a jelly made from seaweed" },
    { "ahoy", "a nautical call of greeting" },
    { "aigrette", "an ornamental cluster of feathers" },
    { "ajar", "partially opened" }
  };

  char word [10];
  int entries = 10;
  int entry;

  printf ("Enter word: ");
  scanf ("%9s", word);
  entry = lookup (dictionary, word, entries);

  if (entry != -1)
    printf ("%s\n", dictionary[entry].definition);
  else
    printf ("Sorry, the word %s is not in my dictionary.\n", word);
  
  return 0;
}


// Define Functions
bool areEqual (const char str1[], const char str2[]) {
  int i = 0;
  bool equal;

  while (str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0') {
    i++;
  }

  if (str1 [i] == '\0' && str2 [i] == '\0')
    equal = true;
  else
    equal = false;

  return equal;
}

int lookup (const struct entry dictionary[], const char search[], const int entries) {
  int i;

  for (i = 0; i < entries; i++) {
    if (areEqual (search, dictionary[i].word))
      return i;
  }

  return -1;
}
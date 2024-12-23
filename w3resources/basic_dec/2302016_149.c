#include<stdio.h>
#include <string.h>
typedef struct {
    int page;
    char word[50];
} Entry ;

int main() {
    Entry temp, list[1000];
    int count = 0;

    printf("Input pairs of a word and a page_no number:\n");
    while (scanf("%s %d", list[count].word, &list[count].page) != EOF) count++;

    for (int i = 0; i < count; i++) {
	for (int j = count - 1; j > 0; j--) {
	    temp = list[j]; 
	    int cmp = strcmp(list[j].word, list[j - 1].word);
	    if (cmp < 0) {
		list[j] = list[j - 1];
		list[j - 1] = temp;
	    }
	    else if (!cmp) {
		if (list[j].page < list[j - 1].page) {
		    list[j] = list[j - 1];
		    list[j - 1] = temp;
		}
	    }
	}
    }

    printf("\nWord and page_no number in alphabetical order:\n");
    for (int i = 0; i < count; i++) {
	if (!i) printf("\n%10s: %2d", list[i].word, list[i].page);
	else if (!strcmp(list[i].word, list[i - 1].word)) printf(" %2d", list[i].page);
	else  printf("\n%10s: %2d", list[i].word, list[i].page);
    }

    return 0;
}


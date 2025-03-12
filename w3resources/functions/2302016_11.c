#include <stdio.h>  
#include <string.h> 

int is_anagram(char *str1, char *str2);
int main()
{
    char str1[100], str2[100];
    printf(" Input the  first String : ");
    fgets(str1, sizeof str1, stdin);
    printf(" Input the  second String : ");
    fgets(str2, sizeof str2, stdin);

    int flag = is_anagram(str1, str2);

    str1[strlen(str1)-1] = '\0';
    str2[strlen(str2)-1] = '\0';
    printf(" `%s` and `%s` %s Anagram.\n\n",str1,str2, flag ? "are" : "are not");
    return 0;
}
 
int is_anagram(char *str1, char *str2)
{
    if(strlen(str1) != strlen(str2)) return 0;

    int str1_char_ctr[256] = {0}, str2_char_ctr[256] = {0}, ctr;

    for(ctr = 0; str1[ctr] != '\0'; ctr++) str1_char_ctr[str1[ctr]]++;
    for(ctr = 0; str2[ctr] != '\0'; ctr++) str2_char_ctr[str2[ctr]]++;

    for(ctr = 0; ctr < 256; ctr++)
    {
        if(str1_char_ctr[ctr] != str2_char_ctr[ctr]) return 0;
    }
    return 1;
}


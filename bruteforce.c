/*
	Bruteforce C - A simple recursive bruteforce algorithm in C
	Developed by Chris Samarinas
	For more projects visit: https://github.com/greekdev
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bruteforce(unsigned long long int length, unsigned long long int loop, unsigned long long int *steps, char pass[], char *chars, char *found, int *stop);

void main(){
    int i, stop = 0;
    unsigned long long int steps = 0;
    char check[4], pass[1025], symbols[1025], *chars, *found, charsize = 0;
    printf("   ________________________________________\n");
    printf("  | Bruteforce password cracking algorithm |\n");
    printf("   ----------------------------------------\n");
    printf("    Developed by Chris Samarinas\n\n\n");
    printf("   Give pass to find: ");
    gets(pass);
    printf("   Does the password contain letters? (y/n): ");
    scanf("%c",&check[0]);
    printf("   Does the password contain capitals? (y/n): ");
    fflush(stdin);
    scanf("%c",&check[1]);
    printf("   Does the password contain numbers? (y/n): ");
    fflush(stdin);
    scanf("%c",&check[2]);
    printf("   Does the password contain symbols? (y/n): ");
    fflush(stdin);
    scanf("%c",&check[3]);
    chars = (char *)malloc(sizeof(char));
    strcpy(chars,"");
    if(check[0]=='y'||check[0]=='Y'){
        charsize+=26;
        chars = (char *)realloc(chars,charsize*sizeof(char));
        strcat(chars,"etaoinshrdlcumwfgypbvkjxqz");
    }
    if(check[1]=='y'||check[1]=='Y'){
        charsize+=26;
        chars = (char *)realloc(chars,charsize*sizeof(char));
        strcat(chars,"ETAOINSHRDLCUMWFGYPBVKJXQZ");
    }
    if(check[2]=='y'||check[2]=='Y'){
        charsize+=10;
        chars = (char *)realloc(chars,charsize*sizeof(char));
        strcat(chars,"0123456789");
    }
    if(check[3]=='y'||check[3]=='Y'){
        printf("   Contain ALL common symbols? (will slow down the algorithm) (y/n): ");
        fflush(stdin);
        scanf("%c",&check[3]);
        if(check[3]=='y'||check[3]=='Y'){
            strcpy(symbols,"~!@#$%^&*()_+ []{};:'\",<.>/?");
        }else{
            printf("   Type the symbols you want: ");
            gets(symbols);
        }
        charsize+=strlen(symbols);
        chars = (char *)realloc(chars,charsize*sizeof(char));
        strcat(chars,symbols);
    }
    found = (char *)malloc((strlen(pass)+1)*sizeof(char));
    bruteforce(strlen(pass), 0, &steps, pass, chars, found, &stop);
    printf("\n   Found after %d combinations.\n\n",steps);
    system("pause");
}

void bruteforce(unsigned long long int length, unsigned long long int loop, unsigned long long int *steps, char pass[], char *chars, char *found, int *stop){
    int i;
    for(i=0;i<strlen(chars);i++){
        found[loop] = chars[i];
        if(length==1){
            (*steps)++;
            found[loop+1] = '\0';
            printf("   %s\n",found);
            if(strcmp(found,pass)==0){
                *stop = 1;
                return;
            }
        }else{
            bruteforce(length-1, loop+1, steps, pass, chars, found, stop);
            if(*stop==1) return;
        }
    }
}

#include <stdio.h>
#include <string.h>
#include "txtfind.h"

#define LINE 256
#define WORD 30

//gets a line from stdin and puts it in s.
// returns the number of chars that been readed. returns -1 if reached EOF(end of file.)
int getLine(char s[]) {
    
    char *sPt = s;
    int count = 0;
   
    do {
        *sPt++ = getchar();
        count++;
    } while (*(sPt-1) != EOF && *(sPt-1) != '\n'); //break the loop when reached EOF or a line break
    
    if (*(sPt-1) == EOF && count ==1) 
    return -1;//return -1 because reached EOF. 
    *(sPt-1) = '\0';
   
    return --count; //we return --count because when reached either EOF or '\n' we add one extra.
}

//gets a line from stdin and puts it in s.
// returns the number of chars that been readed. returns -1 if reached EOF(end of file.)
int getWord(char w[]) {
    
    char *wPt = w;
    int count = 0;
   
    do {
        *wPt++ = getchar();
        count++;
    } while (*(wPt-1) != EOF && *(wPt-1) != '\n' &&  *(wPt-1) != '\t' && *(wPt-1) != ' '); //This loop will break when reached EOF, space, tab, or line break
    if (*(wPt-1) == EOF && count == 1) 
    return -1; 
    *(wPt-1) = '\0';
    return --count; //we return --count because when reached either EOF, '\n', '\t', ' 'we add one extra.
}

//returns 1 if str2 is a substring of str1.
// returns  0 in other case.
int subString( char * str1, char * str2) {
    if (strstr(str1, str2) == NULL) {
        return 0;
    }
    return 1;
}

//returns 1 if you can get string t by removing n chars from string s. 
//returns 0 if not.
int similar (char *s, char *t, int n) {
    int sLen = strlen(s);
    int tLen = strlen(t);
    
    if (tLen != sLen-n) 
    return 0; 
    
    char *sPt = s;
    char *tPt = t;
    int misses = 0;
   
    while((misses <= n) && (*sPt != '\0' || *tPt != '\0')) { 
        if (*sPt != '\0' && *tPt != '\0') { 
            if (*tPt == *sPt) {
                tPt++;
                sPt++;
            } else {
                sPt++;
                misses++;
            }
        } else if (*tPt == '\0' ) { //we can still remove chars using s pointer incase that t pointer reached the end of the string
            sPt++;                  
            misses++;
        }
    }
    if (misses != n) return 0;
    else return 1;
}
//prints the lines that str appears in.(from stdin) 
void printLines(char * str) {
    
    char line[LINE];
    char *linePt = line;
    
    while(getLine(linePt) != -1) {
        if (subString(linePt, str) == 1) 
        printf("%s\n", linePt);
    }
}

//prints the words that are similar to str (from stdin).
void printSimilarWords(char * str) {
   
    char word[WORD];
    char *wordPt = word;
   
    while(getWord(wordPt) != -1) {
        if (subString(wordPt, str) == 1) {
            printf("%s\n", wordPt);
        } else if (similar(wordPt, str, 1) == 1) {
            printf("%s\n", wordPt);
        }
    }
}

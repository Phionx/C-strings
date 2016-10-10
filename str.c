/*
Shantanu Jha
Systems pd4
HW01
2016-10-03
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int strlen2(char *s);
char* strcpy2(char *dest, char *src);
char* strncpy2(char *dest, char *src, int n);
char* strcat2(char *dest, char *src);
char* strncat2(char *dest, char *src, int n);
int strcmp2(char *s1, char *s2);


int strlen2(char *s)
{ 
	int len = 0; while(*(s + len)) len++; return len;
}

char* strcpy2( char *dest, char *src ){
  int n = 0;
  while(src[n] != 0){
    dest[n] = src[n];
    n++;
  }
  return dest;
}

char* strncpy2( char *dest, char *src, int n){
  int i;
  for(i=0; i < n; i++) dest[i] = src[i];
  return dest;
}

char* strcat2( char *dest, char *src ){
	int i = 0;
	int lenDest = strlen2(dest);
  while(src[i] != 0){
    dest[i + lenDest] = src[i];
    i++;
  }
  dest[strlen2(src) + lenDest] = 0;
  return dest;
}


char * strncat2( char *dest, char *src, int n){
  int i = 0;
  int lenDest = strlen2(dest);
  for(i = 0; i < n; i++){
    dest[i + lenDest] = src[i];
  }
  dest[strlen2(src) + lenDest] = 0;
  return dest;
}

int strcmp2(char *s1, char *s2){
	while(*s1 && *s2){
		if(*s1 - *s2) return *s1 - *s2;
		s1++; 
		s2++;
	}
	return *s1 - *s2;
}


char* strchr2(char *s, char c){
	int i = 0;
	int len = strlen2(s);
	char *ans = &s[0];
	for(;i<len;i++){
		if (s[i]==c) return ans;
			ans++;
		}
	return 0;
}


char* strstr2(char *s1, char *s2){
	while(*s1){
		char *temp = s1;
		char *tempSub = s2;
		while(*s1 && *tempSub && *s1 == *tempSub){
			s1++;
			tempSub++;
		}
		if(!*tempSub) return temp;
		s1 = temp + 1;
	}
	return 0;
}




int main() {
    char s1[] = "a123456";
    char s2[50] = "";
    char s3[10] = "c";

    printf("Initial state of strings:\ns1 = \"%s\", length = %d\ns2 = \"%s\", length = %d\ns3 = \"%s\". length = %d\n", s1, strlen2(s1), s2, strlen2(s2), s3, strlen2(s3));

    strcpy(s2, s1);
    printf("\nstrcpy: Copy s1 to s2: s2 = \"%s\", length = %d\n", s2, strlen2(s2));
	strncpy(s2, s1, 4);
    printf("strncpy: Copy(n=4) s1 to s2: s2 = \"%s\", length = %d\n", s2, strlen2(s2));

    printf("\nstrcat: Cat \"+\" to s3: s3 = \"%s\", length = %d\n", strcat2(s3, "+"), strlen2(s3));
    printf("strncat: Cat(n=1) \"++++\" to s3: s3 = \"%s\", length = %d\n", strncat2(s3, "++++", 1), strlen2(s3));
	printf("s1 = \"%s\", length = %d\n\n", s1, strlen2(s1));

	printf("\nstrcmp: compare \"0123\" to \"0123 4\": %d", strcmp2("0123", "01234"));
	printf("\nstrcmp: compare \"0123\" to \"0123\\0 4\": %d", strcmp2("0123", "0123\0 4"));
	printf("\nstrcmp: compare \"0124\" to \"01234\": %d\n", strcmp2("0124", "01234"));
	//printf("\nstrncmp: compare(n=7) \"0123\" to \"01234\": %d", strncmp2("0123", "01234", 7));
	//printf("\nstrncmp: compare(n=2) \"0113\" to \"01224\": %d", strncmp2("0113", "01224", 2));
	//printf("\nstrncmp: compare(n=3) \"0123\" to \"01234\": %d\n", strncmp2("0123", "01234", 3));


	printf("\nstrchr: Looking for \'2\' in \"1234\": %s\n", strchr2("1234", '2'));
	printf("\nstrstr: Looking for \'23\' in \"1234\": %s\n", strstr2("1234", "23"));
		
	return 0;
}




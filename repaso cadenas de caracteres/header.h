#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<locale.h>

#define     A_MAYUSCULA(x)  ((x)>='a'&&(x)<='z')?(x-' '):(x)
#define     A_MINUSCULA(x)  ((x)>='A'&&(x)<='Z')?(x+' '):(x)

char *str_cpy(char *,const char*);
size_t str_len(const char*);
char *str_cat(char*,const char*);
int str_cmp(const char*,const char*);
int str_icmp(const char*,const char*);
char *str_ncpy(char*,const char*,int);
char *str_ncat(char*,const char*,int);
char *str_chr(const char*,int c);
char *str_rchr(const char*,int c);
char *str_str(const char*,const char*);
char *str_upr(char*);
char *str_lwr(char*);

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
void main(void) 
{ 
 char *s=(char *)calloc(sizeof(char),20000); 
 char *t=(char *)calloc(sizeof(char),20000); 
 char key[32][20]={"auto","break","case","char","const","continue","default" 
		    ,"do","double","else","enum","extern","float","for","goto" 
		    ,"if","int","long","register","return","short","signed", 
		    "sizeof","static","struct","switch","typedef","union" 
		    ,"unsigned","void","volatile","while"}; 
 int i,j,k=0,c; 
  char f[20],ch; 
  FILE *fp; 
 //clrscr(); 
 printf("enter a file: "); 
 scanf("%s",f); 
 fp=fopen(f,"r"); 
 if(fp==NULL) 
    printf("file cannot be opened"); 
 else 
 { 
  while((ch=fgetc(fp))!=EOF) 
  { 
    *(s+k)=ch; 
    k++; 
  } 
   *(s+k)='\0'; 
 } 
 printf("%s\n",s); 
 printf("------------------------------------------------------\n"); 
 i=0; 
 x:while(*(s+i)!='\0') 
 { 
   j=0;c=0; 
   if(*(s+i)=='#') 
   { 
     i++; 
     while(*(s+i)!='\n') 
     { 
       printf("%c",*(s+i)); 
       i++; 
     } 
     printf("is a pre processor directive\n"); 
     i++; 
   } 
   else if(isalpha(*(s+i))||*(s+i)=='_') 
   { 
     *(t+j)=*(s+i); 
    i++;     j++; 
    while((*(s+i)=='_'||isdigit(*(s+i))||isalpha(*(s+i)))&&*(s+i)!='\0') 
   { 
     *(t+j)=*(s+i); 
     i++;j++; 
    } 
    *(t+j)='\0'; 
   for(k=0;k<32;k++) 
   if(strcmp(t,key[k])==0) 
   { 
    c=1; 
    break; 
    } 
    if(c==1) 
     printf("%s is a keyword\n",t); 
   else 
   { 
    if(*(s+i)=='(') 
    { 
       printf("%s is a method\n",t); 
       goto x; 
    } 
    else 
    printf("%s is an identifier\n",t); 
   } 
   } 
   else if(*(s+i)=='"') 
   { 
      printf("\""); 
      i++; 
      while(*(s+i)!='"') 
      { 
        printf("%c",*(s+i)); 
        i++; 
      } 
      printf("\" is an argument \n"); 
      i++; 
   } 
   else if((*(s+i)=='/'&&*(s+i+1)=='/')||(*(s+i)=='/'&&*(s+i+1)=='*')) 
   { 
     i++; 
     if(*(s+i)=='/') 
     { 
       i++; 
       while(*(s+i)!='\n') 
{
	printf("%c",*(s+i));
       i++; 
}
      } 
     else if(*(s+i)=='*') 
     { 
       i++; 
       while(*(s+i)!='*'&&*(s+i+1)!='/') 
	{
	
          printf("%c",*(s+i));

	  i++;
	} 
        i=i+2; 
      } 
	printf("is a comment line\n");
   } 
   else if(*(s+i)=='['||*(s+i)==']'||*(s+i)=='('||*(s+i)==')'||*(s+i)=='{'||*(s+i)=='}') 
   { 
     printf("%c is a special symbol\n",*(s+i)); 
     i++; 
   } 
   else if(isdigit(*(s+i))) 
   { 
      if(isdigit(*(s+i))||*(s+i)=='.') 
      { 
      printf("%c",*(s+i)); 
       i++; 
      while(isdigit(*(s+i))||*(s+i)=='.') 
      { 
	    printf("%c",*(s+i)); 
	    i++; 
      } 
      printf(" is a number\n"); 
      } 
      else if(isalpha(*(s+i))) 
     { 
	while(isalpha(*(s+i))||*(s+i)=='_') 
       { 
	 printf("%c",*(s+i)); 
	 i++; 
       } 
	 printf(" is an invalid token\n"); 
      } 
    } 
   else if(*(s+i)=='='||*(s+i)=='+'||*(s+i)=='-'||*(s+i)=='*'||*(s+i)=='/'||*(s+i)=='%'||*(s+i)=='<'||*(s+i)=='>'||*(s+i)=='&'||*(s+i)=='|') 
   { 
     printf("%c is an operator\n",*(s+i)); 
      i++; 
    } 
   else if(*(s+i)==';') 
   { 
      printf("%c is terminator\n",*(s+i)); 
     i++; 
    } 
    else 
     i++; 
  } 
  fclose(fp); 
 }


#include <stdio.h>
#include <string.h> /* memset() */
#define NEWLINE "\n"   /* New Line Alternative */
#define MAX 12  /* Maximun File Name length */

int main(int argc, char* argv[]){

/* Trace Valid argument(s) */
if(argc!=3){
    fprintf(stderr,"Error: Invalid Argument(s)%s",NEWLINE);
    return 1;}
signed key; /* key to encrypt */
char pFileName[MAX]; /* Plain Text File Name */
char eFileName[MAX]; /* Encrypted Text File Name */

FILE* pText; /* Plain Text */
FILE* eText; /* Encrypted Text */

/* NULL Point to Memomry */
pText=NULL; 
eText=NULL; 

/* Fill memory with a constant  byte */
memset(pFileName,0,MAX);
memset(eFileName,0,MAX);


/* Extract Name and Copy to memory  */
snprintf(pFileName,MAX,"%s",argv[1]) ;
snprintf(eFileName,MAX,"%s",argv[2]);

/* Open Files ... */

pText=fopen(pFileName,"r");
eText=fopen(eFileName,"w");

/* Handle File Opening Error(s) */

if((pText==NULL) && (eText==NULL)){
   fprintf(stderr,"Error:Couldn't Open '%s' & '%s' file(s).%s",pFileName,eFileName,NEWLINE);
   return 2;}
if(pText==NULL){
   fprintf(stderr,"Error:Couldn't Open '%s' file%s",pFileName,NEWLINE);
   return 3;}
if(eText==NULL){
   fprintf(stderr,"Error:Couldn't Open '%s' file%s",eFileName,NEWLINE);
   return 4;}
/* Read Next Character */
signed c; /* signed ASCII code  */
key=12; /* key to encrypt */
/* EOF=-1 */
while((c=fgetc(pText)) && (c!=EOF)){
   c=(c^key); /* Encrypt Character */
   fputc(c,eText); /* Write Next Character */}
fprintf(stdout,"Successfully Ciphered.%s",NEWLINE);




/*Close Files ...*/
fclose(pText);
fclose(eText);


return 0;}

#include <stdio.h>
#include <string.h> /* memset() */
#define NEWLINE "\n"   /* New Line Alternative */
#define MAX 12  /* Maximun File Name length */

int main(int argc, char* argv[]){

/* Trace Valid argument(s) */
if(argc!=3){
    fprintf(stderr,"Error: Invalid Argument(s)%s",NEWLINE);
    return 1;}
signed key; /* key to decrypt */
char eFileName[MAX]; /* Plain Text File Name */
char dFileName[MAX]; /* Decrypted Text File Name */

FILE* eText; /* Encrypt Text */
FILE* dText; /* Decrypted Text */

/* NULL Point to Memomry */
eText=NULL; 
dText=NULL; 

/* Fill memory with a constant  byte */
memset(eFileName,0,MAX);
memset(dFileName,0,MAX);


/* Extract Name and Copy to memory  */
snprintf(eFileName,MAX,"%s",argv[1]) ;
snprintf(dFileName,MAX,"%s",argv[2]);

/* Open Files ... */

eText=fopen(eFileName,"r");
dText=fopen(dFileName,"w");

/* Handle File Opening Error(s) */

if((eText==NULL) && (dText==NULL)){
   fprintf(stderr,"Error:Couldn't Open '%s' & '%s' file(s).%s",eFileName,dFileName,NEWLINE);
   return 2;}
if(eText==NULL){
   fprintf(stderr,"Error:Couldn't Open '%s' file%s",eFileName,NEWLINE);
   return 3;}
if(dText==NULL){
   fprintf(stderr,"Error:Couldn't Open '%s' file%s",dFileName,NEWLINE);
   return 4;}
/* Read Next Character */
signed c; /* signed ASCII code  */
key=12; /* key to decrypt */
/* EOF=-1 */
while((c=fgetc(eText)) && (c!=EOF)){
   c=(c^key); /* decrypt Character */
   fputc(c,dText); /* Write Next Character */}
fprintf(stdout,"Successfully unCiphered.%s",NEWLINE);




/*Close Files ...*/
fclose(eText);
fclose(dText);


return 0;}

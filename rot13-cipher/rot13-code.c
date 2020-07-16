#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int rot13b(int c, int basis){
  c = (((c-basis)+13)%26)+basis;
  return c;
}

int rot13(int c){
  if('a' <= c && c <= 'z'){
    return rot13b(c,'a');
  } else if ('A' <= c && c <= 'Z') {
    return rot13b(c, 'A');
  } else {
    return c;
  }
}

int main(int argc,char *argv[])
{
    FILE *fp;
    int i;
    char string[30];
    fp = fopen(argv[1],"r");
    while(fgets(string,30,fp)){
        for(i=0;i<strlen(string);i++){
            string[i]=rot13(string[i]);
        }
        printf("%s", string);
    }
    fclose(fp);
    fp = fopen("out.txt","w");
    fprintf(fp,string);
    fclose(fp);
    return 0;
}

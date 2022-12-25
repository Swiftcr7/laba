#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char lower(char a){
    if (a>='A' && a<='Z'){
        char b=a+32;
        return b;


    }else{
        return a;
    }
}
char * itcoa(char c) {
  int i=c;  
  char * res = (char*)malloc(15*sizeof(char));
  sprintf(res, "%d", i);
  return res;
}
int letter(char a){
    if ((a>='a' && a<='z') || (a>='A' && a<='Z')){
        return 1;
    }else{
        return 0;
    }
}
char* concat(const char *s1, const char *s2){
    char *result = (char*)malloc(strlen(s1) + strlen(s2) + 1); 
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}
int mydigit(char ch){
    if (ch>='0' && ch<='9'){
        return 1;
    }else{
        return 0;
    }
}
int main(int argc, char* argv[]){
    if (argc!=3 && argc!=4){
        printf("invalid number of arguments");
        return 0;
    }
    char symbol;
    char postscript[4]="out_";
    FILE *inpt=fopen(argv[1], "r+");
    FILE *otp;
    int isymbl;
    if (inpt==NULL){
        printf("the file could not be opened");
        return 0;
    }
    if (strcmp(argv[2],"-nd")==0 || strcmp(argv[2],"/nd")==0 || strcmp(argv[2],"-ni")==0 || strcmp(argv[2],"/ni")==0 || strcmp(argv[2],"-ns")==0 || strcmp(argv[2],"/ns")==0 || strcmp(argv[2],"-na")==0 || strcmp(argv[2],"/na")==0 || strcmp(argv[2],"-nf")==0 || strcmp(argv[2],"/nf")==0){
        if (argc==3){
             otp=fopen(concat(postscript,argv[1]), "w");
             if (otp==NULL){
                printf("the file could not be opened");
                return 0;
             }
        }else{
            printf("invalid number of arguments");
            return 0;
        }
    } else if (strcmp(argv[2],"-d")==0 || strcmp(argv[2],"/d")==0 || strcmp(argv[2],"-i")==0 || strcmp(argv[2],"/i")==0 || strcmp(argv[2],"-s")==0 || strcmp(argv[2],"/s")==0 || strcmp(argv[2],"-a")==0 || strcmp(argv[2],"/a")==0 || strcmp(argv[2],"-f")==0 || strcmp(argv[2],"/f")==0){
        if (argc==4){
            otp=fopen(argv[3], "w");
            if (otp==NULL){
                printf("the file could not be opened");
                return 0;
             }
        }else{
            printf("invalid number of arguments");
            return 0;
        }
    }else{
        printf("incorrect flag format");
    }
    if (strcmp(argv[2],"-d")==0 || strcmp(argv[2],"/d")==0 || strcmp(argv[2],"-nd")==0 || strcmp(argv[2],"/nd")==0){
        while ((symbol=fgetc(inpt))!=EOF){
            if (mydigit(symbol)){
                continue;
            }
            fputc(symbol, otp);
        }
    }
    if (strcmp(argv[2], "-i")==0 || strcmp(argv[2], "/i")==0 || strcmp(argv[2], "-ni")==0 || strcmp(argv[2], "/ni")==0){
        int sum=0;
        while((symbol=fgetc(inpt))!=EOF){
            if (symbol=='\n'){
                fprintf(otp, "%d\n", sum);
                sum=0;
            }else{
                if(letter(symbol)==1) {
                    sum+=1;
                }
            }
        }
        fprintf(otp, "%d\n", sum);
    }
    if (strcmp(argv[2], "-s")==0 || strcmp(argv[2], "/s")==0 || strcmp(argv[2], "-ns")==0 || strcmp(argv[2], "/ns")==0){
        int sum=0;
        while((symbol=fgetc(inpt))!=EOF){
            if (symbol=='\n'){
                fprintf(otp, "%d\n", sum);
                sum=0;
            }else if (mydigit(symbol)==0 && letter(symbol)==0 && symbol!=' '){
                sum+=1;
            }
        }
        fprintf(otp, "%d\n", sum);
    }
    if (strcmp(argv[2], "-a")==0 || strcmp(argv[2], "/a")==0 || strcmp(argv[2], "-na")==0 || strcmp(argv[2], "/na")==0){
        while((symbol=fgetc(inpt))!=EOF){
            if (mydigit(symbol)==0 && symbol!='\n'){
                fprintf(otp,"%s", itcoa(symbol));
            }else{
                fputc(symbol, otp);
            }
        }
    }
    if (strcmp(argv[2], "-f")==0 || strcmp(argv[2], "/f")==0 || strcmp(argv[2], "-nf")==0 || strcmp(argv[2], "/nf")==0){
        int kol=1;
        int s=0;
        while((symbol=fgetc(inpt))!=EOF){
            if (kol%2!=0 && symbol!=' ' && symbol!='\n'){
                if (letter(symbol)==1){
                    fputc(lower(symbol), otp);

                }else{
                    fputc(symbol, otp);
                }
            }else if(kol%6==0 && symbol!=' ' && symbol!='\n'){
                fprintf(otp,"%s", itcoa(symbol));
            }else{
                fputc(symbol, otp);
            }
            if (symbol==' ' || symbol=='\n'){
                if (s==0){
                    kol+=1;
                    s=s+1;
                }
            }
            if (s==1 && symbol!=' ' && symbol!='\n'){
                s=s-1;
            }
        }
        
    }

    printf("data recorded");
    fclose(inpt);
    fclose(otp);
}


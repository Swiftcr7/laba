#include <stdio.h>
#include <string.h>
#include <malloc.h>
int main(int argc, char *argv[]){
    if (argc==1){
        printf("invalid number of arguments");
        return 0;
    }
    FILE *otp=fopen("test1.txt", "a");
    if (otp==NULL){
        printf("the file could not be opened");
        return 0;
    }
    char symbol;
    

    if (strcmp(argv[1],"-arg")==0){
        if (argc<3){
            printf("invalid number of arguments");
            return 0;
        }
        for (int i=2; i<argc; i++){
            FILE *inpt=fopen(argv[i], "r");
            if (inpt==NULL){
                printf("the file could not be opened");
                return 0;
            }
            while ((symbol=fgetc(inpt))!=EOF){
                fputc(symbol, otp);

            }
            fclose(inpt);


        }
        printf("data recorded");
        return 0;
    }
    if(strcmp(argv[1],"-cin")==0){
        if (argc!=2){
            printf("invalid number of arguments");
            return 0;
        }
        char c;
        int len=4, count=0;
        char *str=NULL;
        char *str1=NULL;
        str = (char*)malloc(len * sizeof(char));
        int n;
        scanf("%d\n", &n);
        for (int i=0; i<n; i++){
            while((c = getchar()) != '\n') {
                str[count] = c;
                count++;
                if (count==len-1){
                    len *= 2;
                    str1 = (char*)realloc(str, len * sizeof(char));
                    if (str1==NULL){
                        printf("problem with memory");
                        return 0;
                    }else{
                        str=str1;
                    }
                }
            }
            str[count] = 0;
            printf("%s", str);
            FILE *inpt=fopen(str, "r");
            char symbol;
            while ((symbol=fgetc(inpt))!=EOF){
                fputc(symbol, otp);
            }
            fclose(inpt);
            count=0;
            len=4;
            free(str);
            str = (char*)malloc(len * sizeof(char));
        }
    }
    if (strcmp(argv[1], "-fi")==0){
        if (argc!=3){
            printf("invalid number of arguments");
            return 0;

        }
        FILE *inpt1=fopen(argv[2], "r");
        if (inpt1==NULL){
            printf("the file could not be opened");
            return 0;
        }
        char *str=NULL;
        char symbol;
        int count=0, len=4;
        str = (char*)malloc(len * sizeof(char));
        if (str==NULL){
            printf("problem with memory");
            return 0;
        }
        char* str1=NULL;
        while((symbol=fgetc(inpt1))!=EOF){
            if( symbol != ' ') {
                str[count] = symbol;
                count++;
                if (count==len-1){
                    len *= 2;
                    str1 = (char*)realloc(str, len * sizeof(char));
                    if (str1==NULL){
                        printf("problem with memory");
                        free(str);
                        return 1;
                    }else{
                        str=str1;
                    }
                }
            }else{
                str[count] = 0;
                FILE *inpt=fopen(str, "r");
                if (inpt==NULL){
                    printf("the file could not be opened");
                    return 0;
                }
                char s;
                while ((s=fgetc(inpt))!=EOF){
                    fputc(s, otp);
                }
                fclose(inpt);
                count=0;
                len=4;
                free(str);
                str = (char*)malloc(len * sizeof(char));

            }
            

        }
        str[count] = 0;
        FILE *inpt=fopen(str, "r");
        if (inpt==NULL){
            printf("the file could not be opened");
            return 0;
        }
        char s;
        while ((s=fgetc(inpt))!=EOF){
                fputc(s, otp);
        }
        fclose(inpt);
        count=0;
        len=4;
        free(str);
        str = (char*)malloc(len * sizeof(char));
    }
    printf("data recorded");
    return 0;
}
    


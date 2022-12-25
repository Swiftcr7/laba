#include <stdio.h>
#include <malloc.h>
#include <string.h>
int translate(char* str, int base){
    int num=0;
    int len=strlen(str);
    for (int i=0; i<len; i++){
        if(str[i]<='9' && str[i]>='0'){
            num=num*base+str[i]-48;

        }else if (str[i]>='a' && str[i]<='z'){
            num=num*base+str[i]-87;
        }else if (str[i]>='A' && str[i]<='Z'){
            num=num*base+str[i]-55;
        }
    }
    return num;
}
int maxdegree(char* str){
    int maxd=0, flg=0;
    for(int i=0; i<strlen(str); i++){
        if (str[i]<='9' && str[i]>='0' && flg==0){
            if (str[i]-48>maxd){
                maxd=str[i]-48;
            }
        }else if (str[i]>='a' && str[i]<='z'){
            if (maxd<str[i]-87){
                maxd=str[i]-87;
                flg++;
            }
        }else if (str[i]>='A' && str[i]<='Z'){
            if (maxd<str[i]-55){
                maxd=str[i]-55;
                flg++;
            }
        }else{
            return 0;
        }
    }
    return maxd+1;
}
int main(){
    FILE *inpt=fopen("test.txt", "r");
    FILE *otp=fopen("test1.txt", "w");
    char *str=NULL;
    char *str1=NULL;
    int len=4, count=0;
    str = (char*)malloc(len * sizeof(char));
    if (str==NULL){
        printf("problem with memory");
        return 0;
    }
    if (inpt==NULL || otp==NULL){
        printf("the file could not be opened");
        return 0;
    }
    char symbol;
    while((symbol=fgetc(inpt))!=EOF){
        if (symbol==' ' || symbol=='\n' || symbol=='\t'){
            if(count!=0){
                str[count]=0;
                fprintf(otp, "%s ", str);
                if (maxdegree(str)==0){
                    printf("Wrong data");
                    return 0;
                }
                fprintf(otp, "%d ", maxdegree(str));
                fprintf(otp, "%d\n", translate(str, maxdegree(str)));
                count=0;
                len=4;
                free(str);
                str = (char*)malloc(len * sizeof(char));
                if (str==NULL){
                    printf("problem ith memory");
                    return 0;
                }


            }
        }else{
            str[count] = symbol;
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
    }
    free(str1);
    printf("data recorded");
    fclose(otp);
    fclose(inpt);
    return 0;
}
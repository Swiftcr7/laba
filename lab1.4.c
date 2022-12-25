#include <stdio.h>
#include <malloc.h>
#include <string.h>
int main(){
   char *str1=NULL;
   char *str2=NULL;
   char *str3=NULL;
   char symbol;
   FILE *f=fopen("test.txt", "r");
   FILE *f1=fopen("test2.txt", "w");
    if (f==NULL || f1==NULL){
        printf("the file could not be opened");
        return 0;
    }
    int count1=0, count2=0, count3=0, len1=4, len2=4, len3=4, flg1=0, flg2=0, flg3=0, flg4=0;
    str1 = (char*)malloc(len1 * sizeof(char));
    if (str1==NULL){
        printf("problems ith memory");
        return 0;
    }
    str2 = (char*)malloc(len2 * sizeof(char));
    if (str2==NULL){
        printf("problems ith memory");
        return 0;
    }
    str3 = (char*)malloc(len3 * sizeof(char));
    if (str3==NULL){
        printf("problems with memory");
        return 0;
    }
    char *str4=NULL;
    while((symbol = fgetc(f))!=EOF){
        if (symbol != '\n'){
            if (symbol!=' ' && flg1==0){
                str1[count1] = symbol;
                count1++;
                if (count1==len1-1){
                    len1 *= 2;
                    str4 = (char*)realloc(str1, len1 * sizeof(char));
                    if (str4==NULL){
                        printf("problems with memory");
                        return 0;
                    }else{
                        str1=str4;
                    }
                }
        
            }else{
                flg1+=1;
            }
            if (symbol!=' ' && flg1!=0 && flg2==0){
                str2[count2] = symbol;
                count2++;
                if (count2==len2-1){
                    len2 *= 2;
                    str4 = (char*)realloc(str2, len2 * sizeof(char));
                    if (str4==NULL){
                        printf("problems with memory");
                        return 0;
                    }else{
                        str2=str4;
                    }
                }
        
            }else{
                if (flg1!=1 && flg1!=0){
                    flg2+=1;

                }
                
            }
            if (symbol!=' ' && flg1!=0 && flg2!=0 && flg3==0){
                str3[count3] = symbol;
                flg4+=1;
                count3++;
                if (count3==len3-1){
                    len3 *= 2;
                    str4 = (char*)realloc(str3, len3 * sizeof(char));
                    if (str4==NULL){
                        printf("problems with memory");
                        return 0;
                    }else{
                        str3=str4;
                    }
                }
        
            }else{
                if (flg1!=0 && flg1!=1 && flg2!=0 && flg2!=1){
                    flg3+=1;

                }
                
            }
             if(flg4!=0 && flg3==2){
                 printf("incorrect number of columns1");
                 return 0;
            }
                
            
        }else{
            if (flg1==0 || flg2==0 || flg4==0){
                printf("incorrect number of columns2");
                return 0;
            }
            str1[count1]=0;
            str2[count2]=0;
            str3[count3]=0;
            for(int i=0; i<strlen(str3); i++){
                fputc(str3[i], f1);
            }
            fputc(' ', f1);
            for(int i=0; i<strlen(str1); i++){
                fputc(str1[i], f1);
            }
            fputc(' ', f1);
            for(int i=0; i<strlen(str2); i++){
                fputc(str2[i], f1);
            }
            fputc('\n', f1);
            free(str1);
            free(str2);
            free(str3);
            str1=NULL;
            str2=NULL;
            str3=NULL;
            count1=0, count2=0, count3=0, len1=4, len2=4, len3=4, flg1=0, flg2=0, flg3=0, flg4=0;
            str1 = (char*)malloc(len1 * sizeof(char));
            if (str1==NULL){
                printf("problem with memory");
                return 0;
            }
            str2 = (char*)malloc(len2 * sizeof(char));
            if (str2==NULL){
                printf("problem with memory");
                return 0;
            }
            str3 = (char*)malloc(len3 * sizeof(char));
            if (str3==NULL){
                printf("problem with memory");
                return 0;
            }
        }
        
    }
    free(str1);
    free(str2);
    free(str3);
    fclose(f);
    fclose(f1);
    printf("the file is overfilled");
    remove("test.txt");
    rename("test2.txt", "test.txt");
}
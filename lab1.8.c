#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <malloc.h>
#include <stdlib.h>
int sumersmaler(int *arr, int len, int ind, int *count){
    if (ind<=0 || ind>len){
        (*count)=1;
        return 0;
    }
    int sum=arr[0];
    arr[0]=arr[ind-1];
    arr[ind-1]=sum;
    sum=0;
    for (int i=1; i<len; i++){
        if (arr[i]<arr[0]){
            if (arr[0]>INT_MAX-arr[i] && arr[i]>0){
                (*count)=2;
                return 0;
            }
            if (arr[0]<INT_MIN+(-1)*arr[i] && arr[i]<0){
                (*count)=2;
                return 0;
            }
            sum=sum+arr[i];
        }
    }
    return sum;
}
int sumer(int *arr, int len, int ind, int *count){
    if (ind<=0 || ind>len){
        (*count)=1;
        return 0;
    }
    if (ind==1){
        return 0;
    }
    for (int i=1; i<ind-1; i++){
        if (arr[0]>INT_MAX-arr[i] && arr[i]>0){
            (*count)=2;
            return 0;
        }
        if (arr[0]<INT_MIN+(-1)*arr[i] && arr[i]<0){
            (*count)=2;
            return 0;
        }
        arr[0]=arr[0]+arr[i];
    }
    return arr[0];
}
int farelement(int *arr, int len, int ind, int *count){
    if (ind<=0 || ind>len){
        (*count)=1;
        return 0;
    }
    for (int i=1; i<len; i++){
        if (abs(arr[0]-arr[ind-1])<abs(arr[ind-1]-arr[i])){
            arr[0]=arr[i];
        }
    }
    return arr[0];
}
int* chet(int *arr, int *otparr, int len, int *count1){
    for (int i=0; i<len; i++){
        if (arr[i]&00000001){
            continue;
        }else{
            otparr[*count1]=arr[i];
            (*count1)+=1;
        }
    }
    return otparr;
}
int* nechet(int *arr, int *otparr, int len, int* count){
    for (int i=0; i<len; i=i+2){
        otparr[*count]=arr[i];
        (*count)+=1;
    }
    return otparr;
}
int myatoi(char string[], int* flg1){
    int size=strlen(string);
    int n=0;
    int count1=0;
    if (string[0]=='-'){
        for(int i=1; i<size; i++){
            if (string[i]>='0'&& string[i]<='9'){
                if (n>INT_MAX/10){
                    (*flg1)+=1;
                    return 0;
                }
                n=10*n+(string[i]-'0');
            }else{
                (*flg1)+=1;
                return 0;
            }
        }return -1*n;
    }else{
        for(int i=0; i<size; i++){
            if (string[i]>='0'&& string[i]<='9'){
                if (n>INT_MAX/10){
                    (*flg1)+=1;
                    return 0;
                }
                n=10*n+(string[i]-'0');
            }else{
                (*flg1)+=1;
                return 0;
            }
        }return n;
    }
}
int main(int argc, char* argv[]){
    int arr[128];
    int count1=0;
    int otparr[128];
    char *str=NULL;
    char *str1=NULL;
    FILE *inpt=fopen("test.txt", "r");
    if (inpt==NULL){
       printf("the file could not be opened");
       return -1;
    }
    char symbol;
    int len=4, count=0, countarr=0;
    str=(char*)malloc(len*sizeof(char));
    if (str==NULL){
        fclose(inpt);
        printf("problem with memory");
        return -1;
    }
    int flg=0;
    int flg1=0;
    while((symbol=fgetc(inpt))!=EOF){
        if (symbol==' ' || symbol=='\n'){
            flg+=1;
            if(flg!=0){
                str[count]=0;
                len=4;
                count=0;
                arr[countarr]=myatoi(str, &flg1);
                if(flg1){
                    free(str);
                    fclose(inpt);
                    printf("not a number entered or is the number too big");
                    return -1;
                }
                countarr+=1;
                if (countarr>128){
                    free(str);
                    fclose(inpt);
                    printf("the size of the array exceeds the maximum possible");
                    return -1;
                }
                free(str);
                str=(char*)malloc(len*sizeof(char));
                //
                flg=0;
                }
        }else{
            str[count] = symbol;
            count++;
            if (count==len-1){
                len *= 2;
                str1 = (char*)realloc(str, len * sizeof(char));
                if (str1==NULL){
                    free(str);
                    fclose(inpt);
                    printf("problems with memory");
                    return -1;
                }else{
                    str=str1;
                }
            }
        }
    }
    str[count]=0;
    arr[countarr]=myatoi(str, &flg1);
    if(flg1){
        free(str);
        fclose(inpt);
        printf("not a number entered or is the number too big");
        return -1;
    }
    countarr+=1;
    if (countarr>128){
        free(str);
        fclose(inpt);
        printf("the size of the array exceeds the maximum possible");
        return -1;
    }
    free(str);
    fclose(inpt);
    char flag;
    int *otparr1;
    scanf("%c", &flag);
    if (flag=='a'){
        otparr1=nechet(arr, otparr, countarr, &count1);
        for (int i=0; i<count1; i++){
            printf("%d ", otparr1[i]);
        }
    }
    if (flag=='b'){
        otparr1=chet(arr, otparr, countarr, &count1);
        for (int i=0; i<count1; i++){
            printf("%d ", otparr1[i]);
        }
    }
    if (flag=='c'){
        printf("enter the index of the current item ");
        int num;
        scanf("%d", &num);
        num=farelement(arr, countarr,num, &count1);
        if (count1==0){
            printf("%d", num);
            return 0;
        }
        printf("the index is not included in the array");
        return -1;
    }
    if (flag=='d'){
        printf("enter the index of the current item ");
        int num;
        scanf("%d", &num);
        num=sumer(arr, countarr,num, &count1);
        if (count1==1){
            printf("the index is not included in the array");
            return -1;
        }else if (count1==2){
            printf("the sum is greater than the maximum integer");
            return -1;
        }else{
            printf("%d", num);
        }
    }
    if (flag=='e'){
        printf("enter the index of the current item ");
        int num;
        scanf("%d", &num);
        num=sumersmaler(arr, countarr,num, &count1);
        if (count1==1){
            printf("the index is not included in the array");
            return -1;
        }else if (count1==2){
            printf("the sum is greater than the maximum integer");
            return -1;
        }else{
            printf("%d", num);
        }
    }
}
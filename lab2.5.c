#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct borders{
    int max;
    int min;
};
void replace_max_on_min (int* a, int *b){
    int flg;
    flg=(*a);
    *a=*b;
    *b=flg;

}
struct borders maxmin(int* arr, int len){
    int flg, flg1;
    struct borders a;
    flg=arr[0];
    flg1=arr[1];
    a.max=0;
    a.min=1;
    if (arr[0]<arr[1]){
        a.max=1;
        a.min=0;
        arr[0]=arr[1];
        arr[1]=flg;
    }
    for (int i=2; i<len; i++){
        if (arr[i]>arr[0]){
            arr[0]=arr[i];
            a.max=i;
        }else if (arr[1]>arr[i]){
            arr[1]=arr[i];
            a.min=i;
        }

    }
    arr[0]=flg;
    arr[1]=flg1;
    return a;

}
int* uniqueelement(int len, int *arr, int* newarr, int* mask, int* count, int lowerlimit){
    mask[arr[0]-lowerlimit]=1;
    newarr[*count]=arr[0];
    for (int i=1; i<len; i++){
        if (mask[arr[i]-lowerlimit]==0){
            (*count)+=1;
            newarr[(*count)]=arr[i];
            mask[arr[i]-lowerlimit]=1;

        }
        
    }
    return newarr;
}
int *randomaiser(int lowerlimit, int upperlimit, int len, int* arr,  int* flag){
    srand(time(NULL));
    if ((upperlimit -lowerlimit+1)<0){
        *flag=1;
    }
    for (int i=0; i<len; i++){
        arr[i]=rand()%(upperlimit -lowerlimit+1)+lowerlimit;
    }
    return arr;

}
int main(){
    int lowerlimit, upperlimit, flag=0, len;
    char k;
    printf("enter the size of the array ");
    scanf("%d", &len);
    printf("enter the lower border ");
    scanf("%d", &lowerlimit);
    printf("enter the upper bound ");
    scanf("%d", &upperlimit);
    printf("everve ");
    fflush(stdin);
    scanf("%c", &k);
    if (len<=0){
        printf("incorrect array size");
        return -1;
    }
    int *arr;
    arr=(int*)malloc(sizeof(int)*len);
    if (arr==NULL){
        printf("memory problem");
        return -1;
    }
    int *mask;
    mask=(int*)malloc(sizeof(int)*(upperlimit-lowerlimit+1));
    for (int i=0; i<upperlimit-lowerlimit+1; i++){
        mask[i]=0;
    }
    arr=randomaiser(lowerlimit, upperlimit, len, arr, &flag);
    if (flag==1){
        printf("wrong range");
        return -1;
    }
    for (int i=0; i<len; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    if (k=='b'){
        struct borders f;
        f=maxmin(arr, len);
        printf("%d ", f.min);
        printf("%d", f.max);
        replace_max_on_min(arr+f.min, arr+f.max);
        printf("\n");
        for (int i=0; i<len; i++){
            printf("%d ", arr[i]);
        }
        return 0;

    }
    if (k=='a'){
        int *newarr;
        newarr=(int*)malloc(sizeof(int)*len);
        if (newarr==NULL){
            printf("problem with memory");
            return -1;
        }
        int count=0;
        newarr=uniqueelement(len, arr, newarr, mask, &count, lowerlimit);
        for (int i=0; i<count+1; i++){
            printf("%d ", newarr[i]);
        }
        free(newarr);

    }
}
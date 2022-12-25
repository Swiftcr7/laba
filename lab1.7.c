#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int* randarr(int len, int arr[]){
    srand(time(NULL));
    for (int i=0; i<len; i++){
        arr[i]=rand();
    }
    return arr;
}
struct element{
    int numb;
    int mean;
};
struct limit{
    struct element min;
    struct element max;
};
int* replace( int arr[], struct limit d){
    arr[d.min.numb]=d.max.mean;
    arr[d.max.numb]=d.min.mean;
    return arr;
}
struct limit maxmin(int len, int arr[]){
    struct limit a;
    struct element b, c;
    int max1=0;
    int min1=INT_MAX;
    for (int i=0; i<len; i++){
        if (arr[i]<min1){
            b.numb=i;
            b.mean=arr[i];
            min1=arr[i];
        }
        if (arr[i]>max1){
            c.numb=i;
            c.mean=arr[i];
            max1=arr[i];

        }
    }
    a.min=b;
    a.max=c;
    return a;
}
int main(){
    int len =10;
    int arr[len];
    int* arr1;
    arr1=randarr( len,  arr);
    for (int i=0; i<len; i++){
        printf("%d ", *(arr1+i));
    }
    printf("\n");
    struct limit el=maxmin(len, arr);
    printf("%d\n", el.min.mean);
    printf("%d\n", el.max.mean);
    arr1=replace(arr, el);
    for (int i=0; i<len; i++){
        printf("%d ", arr1[i]);
    }
    return 0;
}
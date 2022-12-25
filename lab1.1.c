#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int factorial(int n){
  if (n==0 || n==1){
    return 1;
  }
  if (n<(INT_MAX/factorial(n-1))){
    return n*factorial(n-1);
  }else{
    return -1;
  }
}
int* rowpow(int powlimit, int* res){
  res[0]=1;
  int count=0;
  for (int i=1; i<=powlimit; i++){
    for (int g=2; g<=10; g++){
      count+=1;
      res[count]=pow(g, i);
    }
  }
  return res;
}
int myatoi(char string[]){
  int size=strlen(string);
  int n=0;
  for(int i=0; i<size; i++){
    if (string[i]>='0'&& string[i]<='9'){
      n=10*n+(string[i]-'0');
    }else{
      return -1;
    }
  }
  return n;
}
int easer(int num){
  int s=num/2;
  for (int i=2; i<=s;i++){
    if (num%i==0){
      return -1;
    }

  }
  return 1;
}
int* krat(int numb, int* count, int* arr){
  int c=0;
  int *arr1=NULL;
  for (int i=1; i<=100; i++){
    if (numb%i==0){
      c=c+1;
      *count=c;
      arr1=(int*)realloc(arr, c*sizeof(int));
      if (arr1==NULL){
        
      }else{
        arr=arr1;
      }
      arr[c-1]=i;
    }
  }
  return arr;
}
int summer(int edge){
  if ((edge+1)/2<INT_MAX/edge){
    return ((edge+1)*edge)/2;
  }else{
    return -1;
  }
}
int main (int argc, char*argv[]){
  char intmax[10]= "2147483649";
  int count=0;
  int* flg;
  int *arr=NULL;
  if (argc!=3){
    printf("a non-correct number of parameters has been entered");
    return 0;
  }
  if (argv[2][0]!='-' && argv[2][0]!='/'){
    printf(" non - correct flag");
    return 0;
  }
  if (strlen(argv[1])>10){
    printf("the entered number is too large");
    return 0;
  }
  if(strlen(argv[1])==10 && strcmp(argv[1],intmax)<0){
    printf("the entered number is too large");
    return 0;
  }
  int numb=myatoi(argv[1]);
  if (numb<=0){
    printf("a non-positive integer is entered");
    return 0;
  }
  if (argv[2][1]=='h'){
    flg=krat(numb, &count, arr);
    int num=count;
    if (num ==0){
      printf("there are no such numbers");
      free(arr);
      return 0;
    }
    for (int i=0; i<num; i++){
      printf("%d ", *(flg+i));
    }
    free(arr);
    return 0;
  }
  if (argv[2][1]=='p'){
    if (easer(numb)>0){
      printf("the number is simple");
      return 0;
      }else{
        printf("composite number");
        return 0;
      }
  }
  if (argv[2][1]=='s'){
    for (int h=0; h<strlen(argv[1]); h++){
      
      printf("%c ", argv[1][h]);
    }
    return 0;
  }
  if (argv[2][1]=='e'){
    if (numb>10){
      printf("a number greater than 10");
      return 0;
    }
    int res[(9*myatoi(argv[1]))+1];
    int* res2=rowpow(numb, res);
    for (int i=0; i<(9*numb +1); i++){
      printf("%d ", res2[i]);
    }
    return 0;
  }
  if (argv[2][1]=='a'){
    if (summer(numb)<0){
      printf("the entered number is too large");
      return 0;
    }else{
      printf("%d", summer(numb));
      return 0;
    }
  }
  if (argv[2][1]=='f'){
    if (factorial(myatoi(argv[1]))>0){
      printf("%d", factorial(myatoi(argv[1])));
      return 0;
    }else{
      printf("the entered number is too large");
      return 0;
    }
 }
 printf("invalid flag entered");
 return 0;
}
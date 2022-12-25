#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int right_triangle(float a, float b, float c){
    float hypotenuse=fmax(a, fmax(b,c));
    if (pow(hypotenuse,2)==(pow(fmin(a,fmin(b,c)), 2) + pow(a+b+c-hypotenuse-fmin(a,fmin(b,c)),2))){
        return 1;
    }else{
        return 0;
    }
}
int krat(int numb1, int numb2){
    if (numb1%numb2==0){
        return 1;
    }else {
        return -1;
    }
}
int myatoi(char string[]){
  int size=strlen(string);
  int n=0;
  int flg=0;
  for(int i=0; i<size; i++){
    if (string[i]=='-' && i==0){
        flg=1;
        continue;
    }
    if (flg==0){
        if (string[i]>='0'&& string[i]<='9'){
            n=10*n+(string[i]-'0');
            }else{
                return 0;
            }
    }else{
        if (string[i]>='0'&& string[i]<='9'){
            n=10*n-(string[i]-'0');
        }else{
            return 0;
        }
    } 
  }
  return n;
}
int calculateEquality (float a, float b, float c, float * x1, float * x2){
    if (a==0.0f){
        *x1=-1*c/b;
        return 0;
    }
    float D = b*b - 4.0f*a*c;
    if (D > 0.0f){
        *x1 = (sqrt(D) -b) / (2.0f * a);
        *x2 = (-1*sqrt(D) -b) / (2.0f * a);
        return 1;
    }else if (D == 0.0f){
        *x1 = -b / (2.0f * a);
        return 0;                           
    }else {
        return -1; 
    }                        
}
int exam(char string[]){
    int size=strlen(string);
    for (int i=0; i<size; i++ ){
        if ((string[i]>='0'&& string[i]<='9') || string[i]=='-' || string[i]=='.'){
            continue;
        }else{
            return -1;
        }
    }
    return 1;
}
int main (int argc, char* argv[]){
    if (argc!=4 && argc!=5){
        printf("Invailed number of arguments");
        return 0;
    }
    if (argc==5 && argv[4][1]=='q'){
        if (argv[4][0]!='-' && argv[4][0]!='/'){
            printf("Wrong flag format");
            return 0;
        }
        if (exam(argv[1])>0 && exam(argv[2])>0 && exam(argv[3])>0){
            float a=atof(argv[1]);
            float b=atof(argv[2]);
            float c=atof(argv[3]);
            float x1=0.0; 
            float x2=0.0;
            if (calculateEquality(a, b, c, &x1, &x2)==1){
                printf("%f ", x1);
                printf("%f", x2);
                return 0;
            }else if(calculateEquality(a, b, c, &x1, &x2)==0){
                printf("%f", x1);
                return 0;
            }else{
                printf("No roots");
                return 0;
            }
        }else{
            printf("Entered non-decimal number");
            return 0;
        }
    }
    if (argc==4 && argv[3][1]=='m'){
        if (argv[3][0]!='-' && argv[3][0]!='/'){
            printf("Wrong flag format");
            return 0;
        }
        if (myatoi(argv[2])==0 || myatoi(argv[1])==0){
            printf("not an integer or 0 is entered");
            return 0;
        }
        

        int numb1=myatoi(argv[1]);
        int numb2=myatoi(argv[2]);
        if (krat(numb1, numb2)>0){
            printf("The number is a multiple");
            return 0;
        }else{
            printf("The number is a not multiple");
            return 0;
        }
    }
    if (argc==5 && argv[4][1]=='t'){
        if (argv[4][0]!='-' && argv[4][0]!='/'){
            printf("Wrong flag format");
            return 0;
        }
        if (exam(argv[1])>0 && exam(argv[2])>0 && exam(argv[3])>0){
            float a=atof(argv[1]);
            float b=atof(argv[2]);
            float c=atof(argv[3]);
            if (a==0 || b==0 || c==0){
                printf("0 is enterd");
                return 0;
            }

            if (right_triangle(a,b,c)==1){
                printf("This is a right triangle");
            }else{
                printf("This is a not right triangle");
            }

        }
    }
    printf("Invailed flag entered");
    return 0;
}
// Polynomial addition
#include <iostream>
using namespace std;

// sum = addend + adder
void addition(long long int addendCoef[], long long int addendExpon[], int addendSize,
               long long int adderCoef[], long long int adderExpon[], int adderSize,
               long long int sumCoef[], long long int sumExpon[], int &sumSize );

// outputs the specified polynomial
void output( long long int coefficient[], long long int exponent[], int size );

const int arraySize = 100;

int main(){
   int T;
   cin>>T;
   for(int t=0;t<T;t++){
      long long int addendCoef[arraySize]={};
      long long int addendExpon[arraySize]={};
      int addendSize;
      cin>>addendSize; // input addend

      for(int i=addendSize-1;i>=0;i--){
         cin>>addendCoef[i];
      }
      for(int i=addendSize-1;i>=0;i--){
         cin>>addendExpon[i];
      }

      long long int adderCoef[arraySize]={};
      long long int adderExpon[arraySize]={};
      int adderSize;
      cin>>adderSize; // input adder
      for(int i=adderSize-1;i>=0;i--){
         cin>>adderCoef[i];
      }
      for(int i=adderSize-1;i>=0;i--){
         cin>>adderExpon[i];
      }
      long long int sumCoef[2*arraySize]={};
      long long int sumExpon[2*arraySize]={};
      int sumSize=1;

      addition(addendCoef,addendExpon,addendSize,
                adderCoef,adderExpon,adderSize,
                sumCoef,sumExpon,sumSize);

      output(sumCoef,sumExpon,sumSize);
   }
}

// sum = addend + adder
void addition( long long int addendCoef[], long long int addendExpon[], int addendSize,
               long long int adderCoef[], long long int adderExpon[], int adderSize,
               long long int sumCoef[], long long int sumExpon[], int &sumSize )
{
    int addend_look=0,adder_look=0;
    while(addend_look<addendSize && adder_look<adderSize){
        if(addendExpon[addend_look]==adderExpon[adder_look]){
            sumExpon[sumSize-1]=addendExpon[adder_look];//adderExpon[j]
            sumCoef[sumSize-1]=addendCoef[addend_look++]+adderCoef[adder_look++];
            if(sumCoef[sumSize-1]!=0){sumSize++;}
        }else if(addendExpon[addend_look]>adderExpon[adder_look]){
            sumExpon[sumSize-1]=adderExpon[adder_look];
            sumCoef[sumSize-1]=adderCoef[adder_look++];
            sumSize++;
        }else if(addendExpon[addend_look]<adderExpon[adder_look]){
            sumExpon[sumSize-1]=addendExpon[addend_look];
            sumCoef[sumSize-1]=addendCoef[addend_look++];
            sumSize++;
        }
    }
    while(addend_look<addendSize){
        sumExpon[sumSize-1]=addendExpon[addend_look];
        sumCoef[sumSize-1]=addendCoef[addend_look++];
        sumSize++;
    }
    while(adder_look<adderSize){
        sumExpon[sumSize-1]=adderExpon[adder_look];
        sumCoef[sumSize-1]=adderCoef[adder_look++];
        sumSize++;
    }
    while(sumSize>0 && sumCoef[sumSize-1]==0){
        sumSize--;
    }
}

// outputs the specified polynomial
void output( long long int coefficient[], long long int exponent[], int size){
   cout<<size<<endl;
   cout<<coefficient[size-1];
   for(int i=size-2;i>=0;i--){
      cout<<" "<<coefficient[i];
   }
   cout<<endl;

   cout<<exponent[size-1];
   for(int i=size-2;i>=0;i--){
      cout<<" "<<exponent[i];
   }
   cout<<endl;
}

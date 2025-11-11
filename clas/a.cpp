#include <iostream>
#include <cstring>
using namespace::std;

class HugeInt
{
public:
   int size;
   int *digit;

   // sum = addend + adder
   void addition( HugeInt adder, HugeInt &sum );
};

int main()
{
   char strA[ 251 ], strB[ 251 ];
   int T;
   cin >> T;
   for( int t = 0; t < T; ++t )
   {
      cin >> strA >> strB;

      HugeInt addend;
      addend.size = strlen( strA );
      addend.digit = new int[ addend.size ];
      for( int i = 0; i < addend.size; ++i )
         addend.digit[ i ] = strA[ addend.size - 1 - i ] - '0';

      HugeInt adder;
      adder.size = strlen( strB );
      adder.digit = new int[ adder.size ];
      for( int i = 0; i < adder.size; ++i )
         adder.digit[ i ] = strB[ adder.size - 1 - i ] - '0';

      HugeInt sum;
      addend.addition( adder, sum );

      for( int i = sum.size - 1; i >= 0; i-- )
         cout << sum.digit[ i ];
      cout << endl;

      delete[] addend.digit;
      delete[] adder.digit;
      delete[] sum.digit;
   }
}

// sum = addend + adder
void HugeInt::addition( HugeInt adder, HugeInt &sum )
{
  int maxSize=(size>adder.size) ? size : adder.size;
   sum.size=maxSize+1;
   sum.digit=new int[sum.size];
   
   for(int i=0;i<sum.size;++i){
      sum.digit[ i ] = 0;
   }
   int carry=0;
   for(int i=0;i<maxSize;++i){
      int digitSum=carry;
      if(i<size){
         digitSum += digit[ i ];
      }
      if( i < adder.size ){
         digitSum+=adder.digit[i];
      }
      sum.digit[i]=digitSum%10;
      carry=digitSum/10;
   }
   
   if(carry>0){
      sum.digit[maxSize]=carry;
   	
   }else{
      sum.size=maxSize;
   }
}
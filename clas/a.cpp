#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;

#include <vector>
using std::vector;

// quotient = dividend / divisor; remainder = dividend % divisor
// provided that dividend != 0, divisor != 0 and dividend >= divisor
void division( vector< int > dividend, vector< int > divisor,
               vector< int > &quotient, vector< int > &remainder );

// hugeInt /= 10, or equivalently, shifts right by one position
void divideBy10( vector< int > &hugeInt );

// minuend -= subtrahend
// provided that minuend != 0, subtrahend != 0 and minuend >= subtrahend
void subtraction( vector< int > &minuend, vector< int > subtrahend );

// returns true if and only if hugeInt1 < hugeInt2
// provided that hugeInt1 != 0 and hugeInt2 != 0
bool less( vector< int > hugeInt1, vector< int > hugeInt2 );

// return true if and only if hugeInt1 == hugeInt2
// provided that hugeInt1 != 0 and hugeInt2 != 0
bool equal( vector< int > hugeInt1, vector< int > hugeInt2 );

// returns true if and only if the specified huge integer is zero
bool isZero( vector< int > hugeInt );

const int arraySize = 250;

int main()
{
   char strA[ 251 ], strB[ 251 ];

   int T;
   cin >> T;
   for( int t = 0; t < T; ++t )
   {
      cin >> strA >> strB;

      int dividendSize = strlen( strA );
      vector< int > dividend( dividendSize );
      for( int i = 0; i < dividendSize; ++i )
         dividend[ i ] = strA[ dividendSize - 1 - i ] - '0';

      int divisorSize = strlen( strB );
      vector< int > divisor( divisorSize );
      for( int i = 0; i < divisorSize; ++i )
         divisor[ i ] = strB[ divisorSize - 1 - i ] - '0';

      vector< int > quotient;
      vector< int > remainder;
      division( dividend, divisor, quotient, remainder );

      for( int i = quotient.size() - 1; i >= 0; i-- )
         cout << quotient[ i ];
      cout << endl;

      for( int i = remainder.size() - 1; i >= 0; i-- )
         cout << remainder[ i ];
      cout << endl;
   }
}

// quotient = dividend / divisor; remainder = dividend % divisor
// provided that dividend != 0, divisor != 0 and dividend >= divisor
void division( vector< int > dividend, vector< int > divisor,
               vector< int > &quotient, vector< int > &remainder )
{
    while(dividend.size()>1 && dividend.back()==0){
        dividend.pop_back();
    }
    while(divisor.size()>1 && divisor.back()==0){
        divisor.pop_back();
    }
    quotient.clear();
    remainder.clear();
    remainder.push_back(0);

    vector<int>msQuotient;

    for(int i=dividend.size()-1;i>=0;--i){
        if(!isZero(remainder)){
            remainder.insert(remainder.begin(),0);
        }

        int carry=dividend[i];
        int index=0;
        while(carry>0){
            if(index>=remainder.size()){
                remainder.push_back(0);
            }

            int sum=remainder[index]+carry;
            remainder[index]=sum%10;
            carry=sum/10;
            ++index;
        }

        int count = 0;
        while(!less(remainder,divisor)){
            subtraction(remainder,divisor);
            ++count;
        }

        msQuotient.push_back(count);
    }

    int firstNonZero=0;
    while(firstNonZero<msQuotient.size() && msQuotient[firstNonZero]==0){
        ++firstNonZero;
    }
    if(firstNonZero==msQuotient.size()){
      quotient.push_back(0);
    }else{
        for(int i=msQuotient.size()-1;i>=firstNonZero;--i){
            quotient.push_back(msQuotient[i]);
        }
    }
    while(remainder.size()>1 && remainder.back()==0){
        remainder.pop_back();
    }
}

// hugeInt /= 10, or equivalently, shifts right by one position
void divideBy10( vector< int > &hugeInt )
{
   int size = hugeInt.size();
   if( size == 1 )
      hugeInt[ 0 ] = 0;
   else
   {
      for( int i = 1; i < size; i++ )
         hugeInt[ i - 1 ] = hugeInt[ i ];
      hugeInt.pop_back();
   }
}

// minuend -= subtrahend
// provided that minuend != 0, subtrahend != 0 and minuend >= subtrahend
void subtraction( vector< int > &minuend, vector< int > subtrahend )
{
    int subSize=subtrahend.size(),
        borrow=0;

    for(int i=0;i<minuend.size();++i){
        int subDigit=(i<subSize)?subtrahend[ i ]:0;
        int diff=minuend[i]-subDigit-borrow;

        if(diff<0){
            diff+=10;
            borrow=1;
        }else{
            borrow=0;
        }
        minuend[i]=diff;
    }
    while(minuend.size()>1 && minuend.back()==0){
        minuend.pop_back();
    }
}

// returns true if and only if hugeInt1 < hugeInt2
// provided that hugeInt1 != 0 and hugeInt2 != 0
bool less( vector< int > hugeInt1, vector< int > hugeInt2 )
{
    while(hugeInt1.size()>1 && hugeInt1.back()==0){
        hugeInt1.pop_back();
    }
    while(hugeInt2.size()>1 && hugeInt2.back()== 0){
        hugeInt2.pop_back();
    }
    if(hugeInt1.size()!=hugeInt2.size()){
        return hugeInt1.size()<hugeInt2.size();
    }
    for(int i=hugeInt1.size()-1;i>=0;--i){
        if(hugeInt1[i]!=hugeInt2[i]){
            return hugeInt1[i]<hugeInt2[i];
        }
    }
   return false;
}

// return true if and only if hugeInt1 == hugeInt2
// provided that hugeInt1 != 0 and hugeInt2 != 0
bool equal( vector< int > hugeInt1, vector< int > hugeInt2 )
{
   int size1 = hugeInt1.size();
   int size2 = hugeInt2.size();
   if( size1 != size2 )
      return false;

   for( int i = size1 - 1; i >= 0; i-- )
      if( hugeInt1[ i ] != hugeInt2[ i ] )
         return false;

   return true;
}

// returns true if and only if the specified huge integer is zero
bool isZero( vector< int > hugeInt )
{
   return hugeInt.size() == 1 && hugeInt[ 0 ] == 0;
}
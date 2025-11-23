#include <iostream>
#include <cstring>
#include <vector>
using namespace::std;

// product = multiplicand * multiplier
vector< int > multiplication( vector< int > multiplicand, vector< int > multiplier );

int main()
{
   char strA[ 251 ], strB[ 251 ];

   int T;
   cin >> T;
   for( int t = 0; t < T; ++t )
   {
      cin >> strA >> strB;

      int multiplicandSize = strlen( strA );
      vector< int > multiplicand( multiplicandSize );
      for( int i = 0; i < multiplicandSize; ++i )
         multiplicand[ i ] = strA[ multiplicandSize - 1 - i ] - '0';

      int multiplierSize = strlen( strB );
      vector< int > multiplier( multiplierSize );
      for( int i = 0; i < multiplierSize; ++i )
         multiplier[ i ] = strB[ multiplierSize - 1 - i ] - '0';

      vector< int > product = multiplication( multiplicand, multiplier );

      for( int i = product.size() - 1; i >= 0; i-- )
         cout << product[ i ];
      cout << endl;
   }
}

// product = multiplicand * multiplier
vector< int > multiplication( vector< int > multiplicand, vector< int > multiplier )
{
   if( ( multiplicand.size() == 1 && multiplicand[ 0 ] == 0 ) ||
       ( multiplier.size() == 1 && multiplier[ 0 ] == 0 ) )
   {
      vector< int > product( 1 );
      product[ 0 ] = 0;
      return product;
   }
    int maxsize=multiplicand.size()+multiplier.size()+1;
    vector<int>product(maxsize,0);
    for(int i=0;i<multiplicand.size();++i){
        for(int j=0;j<multiplier.size();++j){
            product[i+j]+=multiplicand[i]*multiplier[j];
        }
    }
    int carry=0;
    for(int i=0;i<maxsize;++i){
        product[i]+=carry;
        carry=product[i]/10;
        product[i]%=10;
    }
    while(product.size()>1 && product[product.size()-1]==0){
        product.pop_back();
    }
    return product;
}

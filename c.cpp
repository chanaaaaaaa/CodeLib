// Polynomial multiplication
#include <iostream>
using namespace std;

// product = multiplicand * multiplier
void multiplication( long long int *multiplicandCoef, long long int *multiplicandExpon, int multiplicandSize,
                     long long int *multiplierCoef, long long int *multiplierExpon, int multiplierSize,
                     long long int *&productCoef, long long int *&productExpon, int &productSize );

// addend += adder
void addition( long long int *&addendCoef, long long int *&addendExpon, int &addendSize,
               long long int *adderCoef, long long int *adderExpon, int adderSize );

// returns true if and only if the specified polynomial is the zero polynomial
bool isZero( long long int *coefficient, int size );

// outputs the specified polynomial
void output( long long int *coefficient, long long int *exponent, int size );

int main()
{
   int T;
   cin >> T;
   for( int t = 0; t < T; t++ )
   {
      int multiplicandSize;
      cin >> multiplicandSize; // input multiplicand
      long long int *multiplicandCoef = new long long int[ multiplicandSize ]();
      long long int *multiplicandExpon = new long long int[ multiplicandSize ]();
      for( int i = multiplicandSize - 1; i >= 0; i-- )
         cin >> multiplicandCoef[ i ];
      for( int i = multiplicandSize - 1; i >= 0; i-- )
         cin >> multiplicandExpon[ i ];

      int multiplierSize;
      cin >> multiplierSize; // input multiplier
      long long int *multiplierCoef = new long long int[ multiplierSize ]();
      long long int *multiplierExpon = new long long int[ multiplierSize ]();
      for( int i = multiplierSize - 1; i >= 0; i-- )
         cin >> multiplierCoef[ i ];
      for( int i = multiplierSize - 1; i >= 0; i-- )
         cin >> multiplierExpon[ i ];

      int productSize;
      long long int *productCoef;
      long long int *productExpon;
      // product = multiplicand * multiplier
      multiplication( multiplicandCoef, multiplicandExpon, multiplicandSize,
                      multiplierCoef, multiplierExpon, multiplierSize,
                      productCoef, productExpon, productSize );

      output( productCoef, productExpon, productSize );

      delete[] multiplicandCoef;
      delete[] multiplicandExpon;
      delete[] multiplierCoef;
      delete[] multiplierExpon;
      delete[] productCoef;
      delete[] productExpon;
   }
}

// product = multiplicand * multiplier
void multiplication( long long int *multiplicandCoef, long long int *multiplicandExpon, int multiplicandSize,
                     long long int *multiplierCoef, long long int *multiplierExpon, int multiplierSize,
                     long long int *&productCoef, long long int *&productExpon, int &productSize )
{
  productCoef =  new long long int[ multiplicandSize+multiplierSize ]();
  productExpon = new long long int[ multiplicandSize+multiplierSize ]();

  productSize=1;
	productCoef[0]=0;
	productExpon[0]=0;
	for(int i=0;i<multiplicandSize;i++){

		long long int adderCoef[multiplicandSize+multiplierSize];
		long long int adderExpon[multiplicandSize+multiplierSize];
		int adderSize=0;
        //cal
		for(int j=0;j<multiplierSize;j++){
			adderCoef[adderSize]=multiplicandCoef[i]*multiplierCoef[j];
			adderExpon[adderSize++]=multiplicandExpon[i]+multiplierExpon[j];
		}
        //check no 0
		addition(productCoef,productExpon,productSize,
             adderCoef,adderExpon,adderSize);
	}
}

// addend += adder
void addition( long long int *&addendCoef, long long int *&addendExpon, int &addendSize,
               long long int *adderCoef, long long int *adderExpon, int adderSize )
{
  if(isZero(addendCoef,addendSize)){
		addendSize=adderSize;
		for(int i=0;i<adderSize;i++){
			addendCoef[i]=adderCoef[i];
			addendExpon[i]=adderExpon[i];
		}
		return;
	}
	if(isZero(adderCoef,adderSize)){return;}

	long long int resultCapacity=(addendSize+adderSize)*(addendSize+adderSize+1);
	long long int resultCoef[resultCapacity];
	long long int resultExpon[resultCapacity];

    //3 pin to copy ans to result
	int i=0,j=0,k=0;
	while(i<addendSize && j<adderSize){
		if(addendExpon[i]<adderExpon[j]){
			resultCoef[k]=addendCoef[i];
			resultExpon[k++]=addendExpon[i++];
		}else if(addendExpon[i]>adderExpon[j]){
			resultCoef[k]=adderCoef[j];
			resultExpon[k++]=adderExpon[j++];
		}else{
			if(addendCoef[i]+adderCoef[j]!=0){
				resultCoef[k]=addendCoef[i]+adderCoef[j];
				resultExpon[k]=addendExpon[i];
			}
			i++;j++;k++;
		}
	}
    //if i lost
	while(i<addendSize){
		resultCoef[k]=addendCoef[i];
		resultExpon[k++]=addendExpon[i++];
	}
    //if j lost
	while(j<adderSize){
		resultCoef[k]=adderCoef[j];
		resultExpon[k++]=adderExpon[j++];
	}
    //if ans 0
	if(k==0){
		resultCoef[0]=0;
		resultExpon[0]=0;
		k=1;
	}
    //copy ans
	for(int idx=0;idx<k;idx++){
		addendCoef[idx]=resultCoef[idx];
		addendExpon[idx]=resultExpon[idx];
	}
  addendSize=k;
}

// returns true if and only if the specified polynomial is the zero polynomial
bool isZero( long long int *coefficient, int size )
{
   return ( size == 1 && coefficient[ 0 ] == 0 );
}

// outputs the specified polynomial
void output( long long int *coefficient, long long int *exponent, int size )
{
   cout << size << endl;
   cout << coefficient[ size - 1 ];
   for( int i = size - 2; i >= 0; i-- )
      cout << " " << coefficient[ i ];
   cout << endl;

   cout << exponent[ size - 1 ];
   for( int i = size - 2; i >= 0; i-- )
      cout << " " << exponent[ i ];
   cout << endl;
}

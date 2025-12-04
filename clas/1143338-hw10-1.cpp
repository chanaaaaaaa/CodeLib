#include <iostream>
#include <cstring>
#include <fstream>
#include <cctype>
using namespace::std;

// reads in a C++ program from a cpp file, and put it to the array program
void load( char( *program )[ 100 ], int &numLines );

// deletes the comment beginning with "//" from sourceLine if any
void delComment( char sourceLine[] );

// deletes all string constants from sourceLine
void delStrConsts( char sourceLine[] );

// deletes all character constants from sourceLine
void delCharConsts( char sourceLine[] );

// extracts all identifiers from sourceLine, and put them into the array identifiers
void extractIdentifiers( char sourceLine[], char identifiers[][ 32 ], int &numIdentifiers );

// stores all non-keyword strings in the array identifiers into a text file
void store( char ( *identifiers )[ 32 ], int numIdentifiers );

// returns true if and only if str is a C++ keyword
bool keyword( char str[] );

// returns true if and only if identifiers[ pos ] belongs to identifiers[ 0 .. pos-1 ]
bool duplicate( char ( *identifiers )[ 32 ], int pos );

const char keywords[][ 20 ] = { "auto", "break", "case", "char", "const",
                                "continue", "default", "define","do", "double",
                                "else", "enum", "extern", "float", "for",
                                "goto", "if", "int", "long", "register",
                                "return", "short", "signed", "sizeof",
                                "static", "struct", "switch", "typedef",
                                "union", "unsigned", "void", "volatile",
                                "while", "bool", "catch", "class",
                                "const_cast", "delete", "dynamic_cast",
                                "explicit", "false", "friend", "inline",
                                "mutable", "namespace", "new", "operator",
                                "private", "protected", "public",
                                "reinterpret_cast", "static_cast", "template",
                                "this", "throw", "true", "try", "typeid",
                                "typename", "using", "virtual", "include" };

int main()
{
   char ( *program )[ 100 ] = new char[ 500 ][ 100 ];
   int numLines = 0;

   // reads in a C++ program from a cpp file, and put it to the array program
   load( program, numLines );

   char ( *identifiers )[ 32 ] = new char[ 500 ][ 32 ];
   int numIdentifiers = 0;

   for( int i = 0; i < numLines; i++ )
   {
      delComment( program[ i ] ); // deletes the comment beginning with "//" from program[ i ]
      delStrConsts( program[ i ] ); // deletes all string constants from program[ i ]
      delCharConsts( program[ i ] ); // deletes all character constants from program[ i ]

      if( strcmp( program[ i ], "" ) != 0 )
         extractIdentifiers( program[ i ], identifiers, numIdentifiers );
         // extracts all identifiers from program[ i ], and put them into the array identifiers
   }

   // stores all non-keyword strings in the array identifiers into a text file
   store( identifiers, numIdentifiers );

   delete[] program;
   delete[] identifiers;
}

void load( char( *program )[ 100 ], int &numLines )
{
   char filename[100];
   cin >> filename;
   ifstream inFile(filename);

   if(!inFile){
      cout<<"File could not open\n";
      return;
   }
   numLines=0;
   while(inFile.getline(program[numLines],120)){
      numLines++;
   }
   inFile.close();
}

void delComment( char sourceLine[] )
{
   size_t length = strlen( sourceLine );
   if( length > 1 )
      for( size_t i = 0; i < length - 1; i++ )
         if( sourceLine[ i ] == '/' && sourceLine[ i + 1 ] == '/' )
         {
            sourceLine[ i ] = '\0';
            return;
         }
}

void delStrConsts( char sourceLine[] )
{
   char temp[200];
   int i=0,j=0;
   while(sourceLine[i]!='\0'){
      if(sourceLine[i]=='"'){
         i++;
         while(sourceLine[i]!='\0' && sourceLine[i]!='"'){
            if(sourceLine[i]=='\\'){
               ++i;
            }
            ++i;
         }
         if(sourceLine[i]=='"'){
            ++i;
         }
      }else{
         temp[j]=sourceLine[i];
         ++i;++j;
      }
   }
   temp[j]='\0';
   strncpy(sourceLine, temp, 99);
   sourceLine[99] = '\0';
}

void delCharConsts( char sourceLine[] )
{
   char temp[200];
   int i=0,j=0;
   while(sourceLine[i]!='\0'){
      if(sourceLine[i]=='\''){
         ++i;
         while(sourceLine[i]!='\0' && sourceLine[i]!='\''){
            if(sourceLine[i]=='\\'){
               ++i;
            }
            ++i;
         }
         if(sourceLine[i]=='\''){
            ++i;
         }
      }else{
         temp[j]=sourceLine[i];
         ++i;++j;
      }
   }
   temp[j]='\0';
   strncpy(sourceLine, temp, 99);
   sourceLine[99] = '\0';
}

void extractIdentifiers( char sourceLine[], char identifiers[][ 32 ], int &numIdentifiers )
{
   int i=0;
   while(sourceLine[i]!='\0'){
      if(isalpha(sourceLine[i]) || sourceLine[i]=='_'){//isalpha('?') if is a~z||A~Z
         char temp[32];
         int j=0;
         while(isalnum(sourceLine[i]) || sourceLine[i]=='_'){//isalnum('?') if is a~z||A~Z||0~9
            temp[j]=sourceLine[i];
            ++j;
            ++i;
         }
         temp[j]='\0';
         if(!keyword(temp)){//if have
            strncpy(identifiers[numIdentifiers], temp, 31);
            identifiers[numIdentifiers][31] = '\0';
            if(!duplicate(identifiers,numIdentifiers)){//if no same thing ++numIdentifiers
               ++numIdentifiers;
            }
         }
      }else{
         ++i;
      }
   }
}

void store( char ( *identifiers )[ 32 ], int numIdentifiers )
{
   ofstream outFile("identifiers.txt");
   if(!outFile){
      return;
   }
   for(int i=0;i<numIdentifiers;++i){
      outFile<<identifiers[i]<<endl;
   }
   outFile.close();
}

bool keyword( char str[] )
{
   size_t numKeywords = sizeof( keywords ) / 20;
   for( size_t i = 0; i < numKeywords; i++ )
      if( strcmp( keywords[ i ], str ) == 0 )
         return true;

   return false;
}

bool duplicate( char ( *identifiers )[ 32 ], int pos )
{
   for( int i = 0; i < pos; i++ )
      if( strcmp( identifiers[ i ], identifiers[ pos ] ) == 0 )
         return true;

   return false;
}

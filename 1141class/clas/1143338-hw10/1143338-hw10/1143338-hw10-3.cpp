#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
using namespace::std;

// reads in a C++ program from a cpp file, and put it to the vector program
void load( vector< char * > &program );

// deletes the comment beginning with "//" from sourceLine if any
void delComment( char *sourceLine );

// deletes all string constants from sourceLine
void delStrConsts( char *sourceLine );

// deletes all character constants from sourceLine
void delCharConsts( char *sourceLine );

// extracts all identifiers from sourceLine, and
// put them into the vector identifiers
void extractIdentifiers( char *sourceLine, vector< char * > &identifiers );

// stores all non-keyword strings in the vector identifiers into a text file
void store( vector< char * > &identifiers );

// returns true if and only if str is a C++ keyword
bool keyword( char str[] );

// returns true iff identifiers[ pos ] belongs to identifiers[ 0 .. pos-1 ]
bool duplicate( vector< char * > &identifiers, int pos );

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
   vector< char * > program;

   // reads in a C++ program from a cpp file, and put it to the vector program
   load( program );

   vector< char * > identifiers;
   for( size_t i = 0; i < program.size(); i++ )
   {
      delComment( program[ i ] ); // deletes the comment beginning with "//" from program[ i ]
      delStrConsts( program[ i ] ); // deletes all string constants from program[ i ]
      delCharConsts( program[ i ] ); // deletes all character constants from program[ i ]

      if( strcmp( program[ i ], "" ) != 0 )
         extractIdentifiers( program[ i ], identifiers );
         // extracts all identifiers from program[ i ], and put them into the vector identifiers
   }

   // stores all non-keyword strings in the vector identifiers into a text file
   store( identifiers );

   for( size_t i = 0; i < identifiers.size(); i++ )
      delete[] identifiers[ i ];

   for( size_t i = 0; i < program.size(); i++ )
      delete[] program[ i ];
}

void load( vector< char * > &program )
{
   string filename;
   cin>>filename;

   ifstream inFile(filename.c_str());
   if(!inFile){
      cout<<"File could not open\n";
      return;
   }
   string line;
   while(getline(inFile, line)){
      char *str = new char[line.length() + 1];
      strncpy(str, line.c_str(), line.length());
      str[line.length()] = '\0';
      program.push_back(str);
   }
   inFile.close();
}

void delComment( char *sourceLine )
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

void delStrConsts( char *sourceLine )
{
   string temp;
   size_t length = strlen(sourceLine);
   int i=0;
   while(i < length){
      if(sourceLine[i]=='"'){
         i++;
         while(i < length && sourceLine[i]!='"'){
            if(sourceLine[i]=='\\'){
               ++i;
            }
            ++i;
         }
         if(i < length && sourceLine[i]=='"'){
            ++i;
         }
      }else{
         temp += sourceLine[i];
         ++i;
      }
   }
   strncpy(sourceLine, temp.c_str(), temp.length());
   sourceLine[temp.length()] = '\0';
}

void delCharConsts( char *sourceLine )
{
   string temp;
   size_t length = strlen(sourceLine);
   int i=0;
   while(i < length){
      if(sourceLine[i]=='\''){
         ++i;
         while(i < length && sourceLine[i]!='\''){
            if(sourceLine[i]=='\\'){
               ++i;
            }
            ++i;
         }
         if(i < length && sourceLine[i]=='\''){
            ++i;
         }
      }else{
         temp += sourceLine[i];
         ++i;
      }
   }
   strncpy(sourceLine, temp.c_str(), temp.length());
   sourceLine[temp.length()] = '\0';
}

void extractIdentifiers( char *sourceLine, vector< char * > &identifiers )
{
   size_t length = strlen(sourceLine);
   int i=0;
   while(i < length){
      if(isalpha(sourceLine[i]) || sourceLine[i]=='_'){//isalpha('?') if is a~z||A~Z
         string temp;
         while(i < length && (isalnum(sourceLine[i]) || sourceLine[i]=='_')){//isalnum('?') if is a~z||A~Z||0~9
            temp += sourceLine[i];
            ++i;
         }
         char *tempStr = new char[temp.length() + 1];
         strncpy(tempStr, temp.c_str(), temp.length());
         tempStr[temp.length()] = '\0';
         if(!keyword(tempStr)){//if have
            int numIdentifiers = identifiers.size();
            identifiers.push_back(tempStr);
            if(duplicate(identifiers, numIdentifiers)){//if same thing, remove it
               delete[] identifiers[numIdentifiers];
               identifiers.pop_back();
            }
         }else{
            delete[] tempStr;
         }
      }else{
         ++i;
      }
   }
}

void store( vector< char * > &identifiers )
{
   ofstream outFile("identifiers.txt");
   if(!outFile){
      return;
   }
   for(size_t i=0;i<identifiers.size();++i){
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

bool duplicate( vector< char * > &identifiers, int pos )
{
   for( int i = 0; i < pos; i++ )
      if( strcmp( identifiers[ i ], identifiers[ pos ] ) == 0 )
         return true;

   return false;
}

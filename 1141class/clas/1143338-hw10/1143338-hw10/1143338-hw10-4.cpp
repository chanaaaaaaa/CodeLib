#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace::std;

 // reads in a C++ program from a cpp file, and put it to the vector program
void load( vector< string > &program );

// deletes the comment beginning with "//" from sourceLine if any
void delComment( string &sourceLine );

// deletes all string constants from sourceLine
void delStrConsts( string &sourceLine );

// deletes all character constants from sourceLine
void delCharConsts( string &sourceLine );

// extracts all identifiers from sourceLine, and
// put them into the vector identifiers
void extractIdentifiers( string &sourceLine, vector< string > &identifiers );

// stores all non-keyword strings in the vector identifiers into a text file
void store( vector< string > &identifiers );

// return true if and only if "str" is a C++ keyword
bool keyword( string str );

// returns true iff identifiers[ pos ] belongs to identifiers[ 0 .. pos-1 ]
bool duplicate( vector< string > &identifiers, int pos );

const string keywords[] = { "auto", "break", "case", "char", "const",
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
   vector< string > program;

   // reads in a C++ program from a cpp file, and put it to the vector program
   load( program );

   vector< string > identifiers;
   string null;

   for( size_t i = 0; i < program.size(); i++ )
   {
      delComment( program[ i ] ); // deletes the comment beginning with "//" from program[ i ]
      delStrConsts( program[ i ] ); // deletes all string constants from program[ i ]
      delCharConsts( program[ i ] ); // deletes all character constants from program[ i ]

      if( program[ i ] != null )
         extractIdentifiers( program[ i ], identifiers );
         // extracts all identifiers from program[ i ], and put them into the vector identifiers
   }

   // stores all non-keyword strings in the vector identifiers into a text file
   store( identifiers );
}

void load( vector< string > &program )
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
      program.push_back(line);
   }
   inFile.close();
}

void delComment( string &sourceLine )
{
   size_t length = sourceLine.size();
   if( length > 1 )
      for( size_t i = 0; i < length - 1; i++ )
         if( sourceLine[ i ] == '/' && sourceLine[ i + 1 ] == '/' )
         {
            sourceLine.erase( i, length );
            break;
         }
}

void delStrConsts( string &sourceLine )
{
   string temp;
   size_t length = sourceLine.length();
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
   sourceLine = temp;
}

void delCharConsts( string &sourceLine )
{
   string temp;
   size_t length = sourceLine.length();
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
   sourceLine = temp;
}

void extractIdentifiers( string &sourceLine, vector< string > &identifiers )
{
   size_t length = sourceLine.length();
   int i=0;
   while(i < length){
      if(isalpha(sourceLine[i]) || sourceLine[i]=='_'){//isalpha('?') if is a~z||A~Z
         string temp;
         while(i < length && (isalnum(sourceLine[i]) || sourceLine[i]=='_')){//isalnum('?') if is a~z||A~Z||0~9
            temp += sourceLine[i];
            ++i;
         }
         if(!keyword(temp)){//if have
            int numIdentifiers = identifiers.size();
            identifiers.push_back(temp);
            if(duplicate(identifiers, numIdentifiers)){//if same thing, remove it
               identifiers.pop_back();
            }
         }
      }else{
         ++i;
      }
   }
}

void store( vector< string > &identifiers )
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

bool keyword( string str )
{
   const int numKeywords = 62;
   for( int i = 0; i < numKeywords; i++ )
      if( keywords[ i ] == str )
         return true;

   return false;
}

bool duplicate( vector< string > &identifiers, int pos )
{
   for( int i = 0; i < pos; i++ )
      if( identifiers[ i ] == identifiers[ pos ] )
         return true;

   return false;
}
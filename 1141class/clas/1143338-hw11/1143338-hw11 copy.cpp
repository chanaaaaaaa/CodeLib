// This program reads a binary file,
// updates grades previously written to the file,
// adds new grades in the file,
// and deletes data previously stored in the file.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

struct StudentData
{
   char studentId[ 8 ];
   char lastName[ 12 ];
   char firstName[ 12 ];
   int grade;
};

enum class Choices{ PRINT = 1, UPDATE, NEW, DELETE, END };

// enable user to input menu choice
Choices enterChoice();

// create text file for printing
void createTextFile( fstream &readFromFile );

// update grade in record
void updateRecord( fstream &updateFile );

// add a new grade in record
void newRecord( fstream &insertInFile );

// delete an existing record
void deleteRecord( fstream &deleteFromFile );

// obtain student ID from user
void getID( const char * const prompt, char studentId[] );

int main()
{
   // open file for reading and writing
   fstream inOutGrade( "grades.dat", ios::in | ios::out | ios::binary );

   // exit program if fstream cannot open file
   if( !inOutGrade )
   {
      cerr << "File could not be opened." << endl;
      system( "pause" );
      exit( 1 );
   }

   Choices choice; // store user choice

   // enable user to specify action
   while( ( choice = enterChoice() ) != Choices::END )
   {
      switch( choice )
      {
      case Choices::PRINT:
         createTextFile( inOutGrade ); // create text file from binary file
         break;
      case Choices::UPDATE:
         updateRecord( inOutGrade ); // update grade
         break;
      case Choices::NEW:
         newRecord( inOutGrade ); // add a new grade
         break;
      case Choices::DELETE:
         deleteRecord( inOutGrade ); // delete existing record
         break;
      default:
         cerr << "Incorrect choice" << endl;
         break;
      }




      cout << endl;
   }

   inOutGrade.close();

   system( "pause" );
}

// enable user to input menu choice
Choices enterChoice()
{
   // display available options
   cout << "Enter your choice" << endl
      << "1 - store a text file of all students' information" << endl
      << "    called \"grades.txt\" for printing" << endl
      << "2 - update a student's grade" << endl
      << "3 - add a student's grade" << endl
      << "4 - delete a student's information" << endl
      << "5 - end program\n? ";

   int menuChoice;
   cin >> menuChoice;
   return static_cast< Choices >( menuChoice );
}

// create text file for printing
void createTextFile( fstream &readFromFile )
{
   ofstream outPrintFile("grades.txt", ios::out);

   // exit program if ofstream cannot create file
   if( !outPrintFile )
   {
      cerr << "File could not be created." << endl;
      return;
   }

   outPrintFile << left << setw( 8 ) << "ID" << setw( 12 )
      << "Last Name" << setw( 12 ) << "First Name" << setw( 10 )
      << "Grade" << endl;

   // also output header to console
   cout << left << setw( 8 ) << "ID" << setw( 12 )
      << "Last Name" << setw( 12 ) << "First Name" << setw( 10 )
      << "Grade" << endl;

   // set file-position pointer to beginning of readFromFile
   readFromFile.seekg( 0 );

   // read first record from file
   StudentData student;
   readFromFile.read( reinterpret_cast< char * >( &student ),
      sizeof( StudentData ) );

   // copy all records from random-access file into text file
   while( readFromFile && !readFromFile.eof() )
   {
      // write single record to text file and console
      if( student.studentId[ 0 ] != '\0' ) // skip empty records
      {
         outPrintFile << left << setw( 8 ) << student.studentId
            << setw( 12 ) << student.lastName
            << setw( 12 ) << student.firstName
            << setw( 10 ) << student.grade << endl;

         // also output to console
         cout << left << setw( 8 ) << student.studentId
            << setw( 12 ) << student.lastName
            << setw( 12 ) << student.firstName
            << setw( 10 ) << student.grade << endl;
      }

      // read next record from file
      readFromFile.read( reinterpret_cast< char * >( &student ),
         sizeof( StudentData ) );
   }

   outPrintFile.close();
   cout << "\nText file created successfully." << endl;
}

// update grade in record
void updateRecord( fstream &updateFile )
{
   char studentId[8];
   getID("\nEnter student ID to update",studentId);

   //重置檔案狀態與指標
   updateFile.clear(); 
   updateFile.seekg(0,ios::beg);

   StudentData student;
   streampos currentPos;
   bool found=false;

   //搜尋
   while (true){
      currentPos=updateFile.tellg();//讀取前的位置
      updateFile.read(reinterpret_cast<char*>(&student),sizeof(StudentData));

      if(updateFile.eof() || !updateFile){break;}

      //比對 ID
      if(strcmp(student.studentId,studentId)==0 && student.studentId[0]!='\0'){
         found=true;
            
         //修改：加入成績檢查邏輯
         if (student.grade==-1){
            //如果成績是 -1，不更新，錯誤
            cout << endl << "Student ID " << studentId << " has no grade." << endl;
         }else{
            //不為 -1，更新
                
            cout << endl << left << setw( 8 ) << student.studentId
               << setw( 12 ) << student.lastName
               << setw( 12 ) << student.firstName
               << setw( 10 ) << student.grade << endl;
                     
            cout << "\nEnter new grade: ";
            int newGrade;
            cin >> newGrade;
            //更新成績
            student.grade=newGrade;

            //指標回到該筆開頭
            updateFile.clear();//保險
            updateFile.seekp(currentPos);

            //寫入 覆蓋一筆
            updateFile.write(reinterpret_cast<const char*>(&student),sizeof(StudentData));
            updateFile.flush();

            cout << endl << left << setw( 8 ) << student.studentId
               << setw( 12 ) << student.lastName
               << setw( 12 ) << student.firstName
               << setw( 10 ) << student.grade << endl;
                 
         }
         //結束
         break;
      }
   }

   if(!found){
      cout << endl << "Student ID " << studentId << " is empty." << endl;
   }
}

// add a new grade in record
void newRecord( fstream &insertInFile )
{
   char studentId[8];
   getID("\nEnter student ID to add",studentId);

   //初始化讀取
   insertInFile.clear();
   insertInFile.seekg(0,ios::beg);

   StudentData student;
   streampos currentPos;
   streampos emptySlotPos=-1;// 紀錄刪除空位
   bool idFound = false;

   //掃描
   while(true){
      currentPos=insertInFile.tellg();
      insertInFile.read(reinterpret_cast<char*>(&student),sizeof(StudentData));

      if(insertInFile.eof() || !insertInFile){break;}

      //檢查存在
      if(strcmp(student.studentId,studentId)==0 && student.studentId[0]!='\0'){
         idFound=true;
         break;//找到就停下
      }

      //紀錄是否有空位ID\:0
      if(emptySlotPos==-1 && student.studentId[0]=='\0'){
         emptySlotPos=currentPos;
      }
   }

   //根據搜尋結果處理

   //情況 A: 學生存在 (ID Found) 
   if(idFound){
      //成績為 -1 時，才允許變更
      if(student.grade==-1){
            cout << endl << "Enter grade: ";
            int newGrade;
            cin >> newGrade;

            //更新資料
            student.grade=newGrade;

            //寫回檔案 Update
            insertInFile.clear(); //確保正常
            insertInFile.seekp(currentPos);
            insertInFile.write(reinterpret_cast<const char*>(&student),sizeof(StudentData));
            insertInFile.flush();

            cout << endl << left << setw( 8 ) << student.studentId
                     << setw( 12 ) << student.lastName
                     << setw( 12 ) << student.firstName
                     << setw( 10 ) << student.grade << endl;    
      }else{
         // 如果成績不是 -1，則禁止新增，提示改用 Update
         cout << "Student ID #" << studentId << " already has a grade (" << student.grade << ")." << endl;
         cout << "Please use option 2 (Update) to change an existing grade." << endl;
      }
      return;
   }
   //B: 學生不存在
   //執行標準的新增學生流程
    
   //初始化資料
   StudentData newStudent;
   strncpy(newStudent.studentId,studentId,8);//複製 ID

   cout << endl << "Student ID " << studentId << " is empty." << endl;
}

// delete an existing record
void deleteRecord(fstream &deleteFromFile)
{
   char studentId[8];
   getID("\nEnter student ID to delete",studentId);

   deleteFromFile.clear();

   deleteFromFile.seekg(0,ios::beg);

   StudentData student;
   streampos currentPosition;

   while(true){
      currentPosition=deleteFromFile.tellg();

      deleteFromFile.read(reinterpret_cast<char*>(&student),sizeof(StudentData));

      if(deleteFromFile.eof() || !deleteFromFile){
         break;
      }

      if(strcmp(student.studentId,studentId)==0){
         StudentData emptyStudent;
         emptyStudent.studentId[0]='\0';
         emptyStudent.lastName[0]='\0';
         emptyStudent.firstName[0]='\0';
         emptyStudent.grade=0;

         deleteFromFile.seekp(currentPosition);

         deleteFromFile.write(reinterpret_cast<const char*>(&emptyStudent),sizeof(StudentData));

         deleteFromFile.flush();

         cout << endl << "Student ID " << studentId << " deleted." << endl;
         return;
      }
   }
   cout << endl << "Student ID " << studentId << " is empty." << endl;
}

// obtain student ID from user
void getID( const char * const prompt, char studentId[] )
{
   do
   {
      cout << prompt << " ( 1141401 - 1141450 ): ";
      cin >> studentId;
   } while( strcmp( studentId, "1141401" ) < 0 || strcmp( studentId, "1141450" ) > 0 );
}

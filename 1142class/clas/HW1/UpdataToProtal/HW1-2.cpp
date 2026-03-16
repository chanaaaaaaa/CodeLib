#include<iostream>

using namespace std;

class Course
{
private:
    string name;
    int unit,score;
public:
    Course(string _n,int _u,int _s):name(_n),unit(_u),score(_s){}
    Course():name(""),unit(0),score(-1){}

    string getName(){
        return name;
    }
    int getUnit(){
        return unit;
    }
    int getScore(){
        return score;
    }
};

class Student
{
private:
    string name;
    Course *courses;
public:
    Student(string _n):name(_n){courses=new Course[100];}
    ~Student(){delete[] courses;}

    void addCourse(string _n,int _u,int _s){
        for(int i=0;i<100;i++){
            if(courses[i].getScore()==-1){
                courses[i]=Course(_n,_u,_s);
                return;
            }
        }
    }
    void print(){
        cout<<"Student: "<<name<<'\n';
        double sumGP=0,sumCredit=0;
        for(int i=0;i<100;i++){
            if(courses[i].getScore()==-1){break;}
            int s=courses[i].getScore(),u=courses[i].getUnit(),gp;
            char g;

            if     (s>=90){g='A';gp=4;}
            else if(s>=80){g='B';gp=3;}
            else if(s>=70){g='C';gp=2;}
            else if(s>=60){g='D';gp=1;}
            else          {g='E';gp=0;}

            cout<<"Course: "<<courses[i].getName()<<" Credit: "<<u<<" Score: "<<s<<" Grade: "<<g<<endl;
            sumGP+=gp*u; sumCredit+=u;
        }
        cout<<"GPA: "<<(sumCredit>0?sumGP/sumCredit:0.0)<<'\n';
        cout<<"-------------------"<<'\n';
    }
};

int main(){
    Student student1("Henry");
    student1.addCourse("History", 3, 86);
    student1.addCourse("C++", 5, 70);
    student1.print();
    Student student2("Juan");
    student2.addCourse("Chem", 5, 60);
    student2.addCourse("Calc", 3, 55);
    student2.addCourse("Eng", 3, 90);
    student2.addCourse("PE", 1, 78);
    student2.print();
    return 0;
}
#include<iostream>
using namespace std;

// Analogy - A Teacher is person and employee along with Human
// Human
// Person , Employee 
// Teacher

// multi level and hierarchical

class Human{
        public:
        void speak(){
                cout << "Human Speaking" << endl;
        }
};

class Person: virtual public Human{
        public:
        void speak(){
                cout << "Person Speaking" << endl;
        }
};
class Employee:virtual public Human{
        public:
        void speak(){
                cout << "Employee Speaking" << endl;
        }
};
class Teacher: public Employee,public Person{
        public:
        void speak(){
                cout << "Teacher Speaking" << endl;
        }
};




int main(){

        Teacher* t;

        t->speak();

        delete t;



        return 0;
}
#include<iostream>
using namespace std;



class Test {
    int t;
    public:

    Test(){
        t=0;
    }

    Test(int a, int b=0, int c=0){
        t=a+b+c;
    }

    Test operator ()(int a, int b,int c){
        Test* temp= new Test(a,b,c);
        return *temp;
    }


    int curval(){
        return t;
    }

};

class Sample{
    int s;
    public:

    Sample(int val=0){
        s=val;
    }

    Sample operator = (Test &obj){
        this->s= obj.curval();
    }

    void display(){
        cout<<s<<endl;
    }

};

int main(){
    Sample s1, s2(10);
    Test t1= 15;
    s1=t1;
    Test t2(20,25),t3;
    t3=t2(15,30,45);
    cout<<t3.curval()<<endl;
}
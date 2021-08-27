#include<iostream>
using namespace std;

class upper{
protected:
    int data;

public:
    upper(int x){
        data=x;   
    }

    void print1(){
        cout<<data<<endl;
    }
};

class lower: public upper{
private:
    int data1;
public:
    lower(){
        data1=data;
    }
    
    void print2(){
        cout<<data1<<endl;
    }
};

int main(){
    upper made(50);
    nextmade.print2();

    return 0;
}


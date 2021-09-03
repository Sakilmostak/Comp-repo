#include<iostream>

using namespace std;

class trying{
private:
    static int count;
public:
    trying(){
        count+=2;
    }

    void print(){
        cout<<count<<endl;
    }
};

int trying::count= 8;

int main(){
    trying obj;
    trying obj1;
    trying obj2;
    obj2.print();
    obj.print();
}
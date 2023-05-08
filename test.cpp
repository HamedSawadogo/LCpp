#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    /**
     *  float *numbers=new float;
    numbers={13,19,100,3838}
    for (int i = 0; i <4; i++)
    {
        std::cout<<numbers[i]<<endl;
    }
    delete [] numbers;
     * 
    */
   union nombre{
    int a;
    int b;
   };

   nombre a;
   a.a=100;
   int B=a.a;
   cout<<B<<endl;
   
    
    /* code */
    return 0;
}

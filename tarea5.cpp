#include <cstdlib>
#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char *argv[])
{
    if(strcmp(argv[1], "-v")==0)
    {
        cout <<"Hola mundo"<<endl;                   
    }
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

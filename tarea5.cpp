#include <cstdlib>
#include <iostream>
#include <string.h>
#include <time.h>
#define SIZE 256

using namespace std;

int main(int argc, char *argv[])
{
    if(strcmp(argv[1], "-s")==0)
    { 
         /*
         select asignatura, avg(nota), STDDEV(nota) 
         from asignaturas_cursadas
         inner join cursos on cursos.curso_id = asignaturas_cursadas.curso_id
         group by asignatura
         */
    }
    
    if(strcmp(argv[1], "-v")==0)
    {
        char buffer[SIZE];
       time_t curtime;
       struct tm *loctime;
     
       /* Get the current time. */
       curtime = time (NULL);
     
       /* Convert it to local time representation. */
       loctime = localtime (&curtime);
       cout <<"Hora del sistema: "<<endl<<endl;
       /* Print out the date and time in the standard format. */
       fputs (asctime (loctime), stdout);
       cout<<endl;
       cout<<"Version del software: "<<endl<<"Beta 1.5"<<endl<<endl;
       cout <<"Integrantes: "<<endl;       
       cout <<"Loreta Astudillo Ollig"<<endl; 
       cout <<"Mario Ibarra Tapia"<<endl;
       cout <<"Abraham Munoz Saez"<<endl;           
    }
    
   
    
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

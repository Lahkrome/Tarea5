#include <cstdlib>
#include <iostream>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <libpq-fe.h>

using namespace std;

int main(int argc, char *argv[])
{
	PGconn *cnn = NULL;
	PGresult *result = NULL;
	PGresult *prom = NULL;
	char *host = "sebastian.cl";
	char *port = "5432";
	char *dataBase = "iswdb";
	char *user = "isw";
	char *passwd = "isw";

	 int i;
     cnn = PQsetdbLogin(host,port,NULL,NULL,dataBase,user,passwd);
	
    if(strcmp(argv[1], "-s")==0)
    { 
		
		if (PQstatus(cnn) != CONNECTION_BAD)
			{
				cout << "Conectado a PostgreSQL!" << endl;
				result = PQexec(cnn, "SELECT * FROM cursos");

					if (result != NULL)
					{
						result =PQexec(cnn,"select asignatura, avg(nota), STDDEV(nota) from asignaturas_cursadas inner join cursos on cursos.curso_id = asignaturas_cursadas.curso_id group by asignatura");
						int tuplas = PQntuples(result);
						int campos = PQnfields(result);
						cout <<"Formato: "<<endl;
						cout <<"Ramo | Promedio |  Desviacion Estandar"<<endl;
						for (i=0; i<tuplas; i++) 
						{
							for (int j=0; j<campos; j++) 
							{
								//cout <<"Ramo : ";
								//cout <<"Promedio : ";
								//cout <<"Desviacion Estandar : ";
								cout << PQgetvalue(result,i,j) << " | ";
							}
						cout << endl;
						}

					// liberar la memoria
					PQclear(result);
					}
			}

		else 
		{
			cout << "Error de conexion" << endl;
			return 0;
        }

    PQfinish(cnn);
         
         
         
    }
    
    if(strcmp(argv[1], "-v")==0)
    {
		time_t rawtime;

        time (&rawtime);
	    cout <<"Fecha del sistema: "<<endl<<endl;
       printf ("La hora y fecha actual del sistema es: %s", ctime (&rawtime));
       cout<<endl;
       cout<<"Version del software: "<<endl<<"Beta 1.5"<<endl<<endl;
       cout <<"Integrantes: "<<endl;       
       cout <<"Loreta Astudillo Ollig"<<endl; 
       cout <<"Mario Ibarra Tapia"<<endl;
       cout <<"Abraham Munoz Saez"<<endl;           
    }
    
    return EXIT_SUCCESS;
    	   /*
    	   Consulta que pertenece a la opcion -a
    	   
    	   SELECT avg(nota), estudiante_id
           FROM asignaturas_cursadas 
           INNER JOIN cursos ON cursos.curso_id=asignaturas_cursadas.curso_id 
           where not asignatura='CÁLCULO VECTORIAL'
           Group by estudiante_id 
         
         SELECT avg(nota), estudiante_id
FROM asignaturas_cursadas 
INNER JOIN cursos ON cursos.curso_id=asignaturas_cursadas.curso_id 
where asignatura='CÁLCULO VECTORIAL'
Group by estudiante_id
           */



}

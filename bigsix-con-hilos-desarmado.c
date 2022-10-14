#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_THREADS 2
#define CANTIDAD_INICIAL_HAMBURGUESAS 20

int cantidad_restante_hamburguesas = CANTIDAD_INICIAL_HAMBURGUESAS; 

int turno = 0;


void *comer_hamburguesa_comensal0()
	{ 
	while(1 == 1)
		{
		while(turno == 0)
			{
    		if(cantidad_restante_hamburguesas > 0)
	    		{
				printf("Hola! soy el comensal 0, me voy a comer una hamburguesa! ya que todavía queda/n %d \n", cantidad_restante_hamburguesas);
		
				cantidad_restante_hamburguesas--;

				turno = 1;
				}
    		else
	    		{	
			    printf("Soy el comensal 0 - Se terminaron las hamburguesas \n");

				turno = 1;

			    pthread_exit(NULL);
		    	}
		    }
	    }
	}


void *comer_hamburguesa_comensal1()
	{ 
	while(1 == 1)
		{
		while(turno == 1)
			{
            if (cantidad_restante_hamburguesas > 0)
			    {
				printf("Hola! soy el comensal 1, me voy a comer una hamburguesa! ya que todavía queda/n %d \n", cantidad_restante_hamburguesas);
		
				cantidad_restante_hamburguesas--;

				turno = 0;
                }
			else
			    {
			    printf("Soy el comensal 1 - Se terminaron las hamburguesas \n");

                turno = 0;

			    pthread_exit(NULL);
			    }
                
            }
		}
	}



int main(void)
	{ 
	pthread_t threads[NUMBER_OF_THREADS];
	int status, ret;

    void *retval;


	printf("Hola! soy el hilo principal. Estoy creando el comensal 0 \n");

	status = pthread_create(&threads[0], NULL, comer_hamburguesa_comensal0, NULL);

	if (status != 0)
		{ 
		printf("Algo salió mal, al crear el hilo recibó el código de error %d \n", status);
			
		exit(-1);
		}
	
    
	printf("Hola! soy el hilo principal. Estoy creando el comensal 1 \n");

	status = pthread_create(&threads[1], NULL, comer_hamburguesa_comensal1, NULL);

	if (status != 0)
		{
		printf("Algo salió mal, al crear el hilo recibó el código de error %d \n", status);
			
		exit(-1);
		}
	


    ret = pthread_join(threads[0], &retval);

    ret = pthread_join(threads[1], &retval);


    pthread_exit(NULL);
	}
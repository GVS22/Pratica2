#include "pilhaA.h"
#include "pilhaBC.h"
#include "lista.h"
#include "fila.h"





int main(){

    int U=1;

    do{
        

        printf("\t______________________________\n");
        printf("|-----------menu-------------|\n");
        printf("|      Digite 1->1.a         |\n");
        printf("|      Digite 2->1.b         |\n");
        printf("|      Digite 3->2.a         |\n");
        printf("|      Digite 4->2.b         |\n");
        printf("|      Digite 5->2.c         |\n");
        printf("|      Digite 6->3.a         |\n");
        printf("|      Digite 7->3.b         |\n");
        printf("|      Digite 0->Sair        |\n");
        printf("______________________________\n");


       
		//switch(U){
        //case '1':
        printf("\nEscolha uma opcao\n");
         scanf("%d", &U);
		

    if (U==1)
    {
        
        Resposta1A();

            U == 1; 

             //return    break;
        //case '2':
    }else if(U==2){
        Resposta1B();

             U == 1; 
            
              //return  break;
        //case '3':

       }else if(U==3){

        

            char exp[50];
            printf("\t______________________________\n");
            printf("\tDigite um expressao: ");
            scanf("%s49[^\n]", exp);
            printf("\nExpressao: %s\nRetorno: %d\n", exp, identifica_formacao(exp));
            printf("\t______________________________\n");

             U == 1; 
            
           // return    break;

        //case '4':

        }else if(U==4){
        
            printf("\t______________________________\n");
            printf("\tPensei em uma logica de inverter a pilha e depois passar para a outro\n para copiar, so que eu nao consegui implementar. ");
        
    
             U == 1; 
            
          //  return    break;
        //case '5':
        }else if(U==5){
    
			Resposta2c();
    
             U == 1; 
            
            //return    break;
        
        //case '6':
        }else if(U==6){

            Resposta3A();

             U == 1; 
            
          //   return   break;       

        //case '7':

        }else if(U==6){

             U == 1; 
            
           //return     break;
       //case '0':
        }else if(U==0)

             U == 0; 
            printf("\tPrograma Finalizado \n");
              //return  break;

        //default:
            }while (U != 0);
            
            
            

    } 

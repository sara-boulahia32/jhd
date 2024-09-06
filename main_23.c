/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char entree[100];
    int compteur=0;
    int i;
    
    scanf("%s", entree);
    for(i=0; i<100; i++){
        if(entree[i]!=0){
            compteur++;
        }
    }
    printf("%d", compteur);
    return 0;
}

    
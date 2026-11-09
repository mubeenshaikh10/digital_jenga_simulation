#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define layers 18
#define blocks 3
void initall(int tower[][blocks]);
void showtower(int tower[][blocks]);

int main(){
    int tower[layers][blocks];
    initall(tower);
    showtower(tower);
    
}
void initall(int tower[][blocks]){
    for(int i = 0 ; i < layers ; i++){ 
        for(int j = 0 ; j < blocks ; j++){
            tower[i][j] = 1;
        }
    }
}
void showtower(int tower[][blocks]){
    printf("====DIGITAL JENGA SIMULATION====\n");
    for(int i = layers - 1 ; i >=0 ; i-- ){
        printf("Layer %2d ", i);
        for (int j = 0 ; j < blocks ; j++){
            if(tower[i][j] == 1 ){
                printf("[#] ");
            }
            else{
                printf("[] ");
            }
        }
        printf("\n");
    }
}
    
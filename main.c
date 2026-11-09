#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define layers 18
#define blocks 3
void initall(int tower[][blocks]);
void showtower(int tower[][blocks]);
void removeblock(int tower[][blocks] , int layer , int pos);

int main(){
    int tower[layers][blocks];
    initall(tower);
    showtower(tower);
    int pos , layer; 
    printf("Enter the Layer (0-16): "); 
    scanf("%d", &layer); 
    printf("Enter position (1=left 2=middle 3=right): ");
    scanf("%d" , &pos);
    pos = pos - 1 ; 
    removeblock(tower , layer , pos);
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
                printf("[ ] ");
            }
        }
        printf("\n");
    }
}
void removeblock(int tower[][blocks] , int layer , int pos){
    tower[layer][pos] = 0;
}

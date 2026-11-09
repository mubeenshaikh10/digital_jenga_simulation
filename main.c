#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define layers 18
#define blocks 3
void initall(int tower[][blocks]);
void showtower(int tower[][blocks]);
void removeblock(int tower[][blocks] , int layer , int pos);
void getmove(int tower[][blocks], int *layer, int *pos);

int main(){
    int tower[layers][blocks];
    initall(tower);
    showtower(tower);
    int pos , layer; 
    getmove(tower , &layer , &pos);
    removeblock(tower, layer, pos);
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
void getmove(int tower[][blocks], int *layer, int *pos){
    int l, p;
    while(1){
        printf("Enter the layer (0-16) and Position (1-3): ");
        if (scanf("%d %d", &l, &p) != 2)
        {
            printf("Numbers only. Try again.\n");
            while (getchar() != '\n');
            continue;
        }
        if (l < 0 || l > layers - 2)
        {
            printf("Layer must be 0 to 16.\n");
            continue;
        }
        if(p < 1 || p > blocks){
            printf("Position must be 1 to 3.\n");
            continue;
        }
        if (tower[l][p-1] == 0)
        {
            printf("That block is already removed.\n");
            continue;
        }
        *layer = l;
        *pos = p - 1;
        break;
       
    }
}


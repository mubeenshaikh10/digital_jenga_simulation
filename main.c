#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define layers 18
#define blocks 3
void initall(int tower[][blocks]);
void showtower(int tower[][blocks]);
void removeblock(int tower[][blocks] , int layer , int pos);
void getmove(int tower[][blocks], int *layer, int *pos);
int checkemptylayer(int tower[][blocks], int layer);
int checkcenter(int tower[][blocks], int layer);
int checklayer0(int tower[][blocks]);
int checkchain(int tower[][blocks]);
int checkstability(int tower[][blocks] , int layer);
int  calcRisk(int removed);
void saveScore(int turns, int removed, int loser);
void showScores(void);
void playgame(void);

int main(){
    int choice;
    srand(time(NULL));
   
    
    if(choice == 1){
        playgame();
    }
    else if(choice == 2){
        printf("\n===== HIGH SCORES =====\n");
        showScores();
    }
    else if(choice == 3){
        printf("Goodbye!\n");
        break;
    }
    else{
        printf("Choose 1 to 3.\n");
    }
     
    
    return 0;
}
void playgame(void){
    int tower[layers][blocks];
    int layer , pos; 
    int player = 1; 
    int gameover = 0;
    int turns = 0; 
    int removed = 0;
    int fell;
}
void initall(int tower[][blocks]){
    for(int i = 0 ; i < layers ; i++){ 
        for(int j = 0 ; j < blocks ; j++){
            tower[i][j] = 1;
        }
    }
}
void showtower(int tower[][blocks]){
    printf("\n====DIGITAL JENGA SIMULATION====\n");
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
int checkemptylayer(int tower[][blocks], int layer){
    if (tower[layer][0] == 0 && tower[layer][1] == 0 && tower[layer][2] == 0){
        printf("Layer is EMPTY!\n");
        return 1;
    }
    else{
        return 0;
    }
}
int checkcenter(int tower[][blocks], int layer){
    if(tower[layer][0]==0 && tower[layer][1]==1 && tower[layer][2]==0){
        printf("Only the center block is left! Tower is unbalanced.\n");
        return 1;
    }
    else{
        return 0;
    }
}
int checklayer0(int tower[][blocks]){
    int count = 0 , j; 
    for (j = 0 ; j < blocks ; j++){
        count = count + tower[0][j];
    }
    if(count<2){
        printf("The Base can no Longer hold the Tower!\n");
        return 1;
    }
    return 0;
}
int checkchain(int tower[][blocks]){
    for (int j = 0 ; j < blocks ; j++){
        int gone = 1;
        for (int i = 0; i<layers-1 ; i++){
            if( tower[i][j] == 1 ){
                gone = 0;
            }
        }
        if(gone == 1){
            printf("A whole column of blocks is gone! Tower has lost its support.\n");
            return 1;
        }
    }
    return 0;
}
int checkstability(int tower[][blocks] , int layer){
    if (checkemptylayer(tower, layer) == 1) return 0;
    if (checkcenter(tower, layer) == 1)     return 0;
    if (checklayer0(tower) == 1)              return 0;
    if (checkchain(tower) == 1)             return 0;
    return 1;
}
int calcRisk(int removed)
{
    return 1 + removed;
}

void saveScore(int turns, int removed, int loser)
{
    FILE *fp = fopen("records.txt", "a");
    if (fp == NULL)
    {
        printf("Error: could not open records.txt\n");
        return;
    }
    fprintf(fp, "Loser: Player %d | Turns: %d | Blocks removed: %d\n",
            loser, turns, removed);
    fclose(fp);
}
void showScores(void)
{
    FILE *fp = fopen("records.txt", "r");
    char line[256];
    if (fp == NULL)
    {
        printf("No records yet.\n");
        return;
    }
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        printf("%s", line);
    }
    fclose(fp);
}



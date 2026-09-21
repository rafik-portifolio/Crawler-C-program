#include "gradient.h"

void printf_view(float view[VIEW_SIZE][VIEW_SIZE]){
    int i,j;
    for (i=0;i<VIEW_SIZE;i++){
        for (j=0;j<VIEW_SIZE;j++){
            printf("%0.2f ", view[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}


int is_chunk_empty(float view[VIEW_SIZE][VIEW_SIZE]){
//assume it is empty, find something then flip the switch
//0 means not empty, 1 means empty
    int bool = 1;
    int i,j;
    for (i=0;i<VIEW_SIZE;i++){
        for (j=0;j<VIEW_SIZE;j++){
            if(view[i][j] > -1){
                bool = 0;
            }
        }
    }   
    return bool;
}
int contains_float(float target, float list[], int list_size){
    int bool = 0;
    for(int i=0; i<list_size; i++){
        if(list[i] == target){
            bool = 1;
        } 
    }
    return bool;
}



path_point find_max(float view[VIEW_SIZE][VIEW_SIZE]){
    int x,y,max_x,max_y;
    path_point res;
    float max = -1;
    if(!is_chunk_empty(view)){
    for (x=0;x<VIEW_SIZE;x++){
        for (y=0;y<VIEW_SIZE;y++){
            if(view[x][y] > max){
            max = view[x][y];
            max_x = x;
            max_y = y;
            }
        }
    }
    }
    else{
        printf("error: no max\n");
    }
    res.y = max_y;
    res.x = max_x;
    return res;
    
}

path_point find_highest_point(){
    // your solution here
    path_point p;
    float view[VIEW_SIZE][VIEW_SIZE];
    int x = VIEW_RADIUS;
    int y = VIEW_RADIUS;
    int way;
    float prev;
    float highest_non_peak = -1;
    int peak = 0;
    generate_view(view,x,y);
    int counter = 0;
    
    
    while(peak == 0){
    path_point possible = find_max(view);
    
    if(prev == view[possible.x][possible.y] && view[possible.x][possible.y] > highest_non_peak){
        peak = declare_peak(y,x);
        if(peak == 0){//plateu
            highest_non_peak == view[possible.y][possible.x];
            
            possible.x = VIEW_SIZE;
            possible.y = VIEW_SIZE;
        }
        else{ 
            p.x =y;
            p.y = x;
            return p;
        }
    }
    
    x += possible.x - VIEW_RADIUS;
    y += possible.y - VIEW_RADIUS;
    prev = view[possible.x][possible.y];
    generate_view(view,x,y);
    }
}

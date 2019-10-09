# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main(int argc, char* argv[]){

    int num[51][51];
    int height = 0, width = 0;
    char str[500];
    int n = 0;
    int i = 0, j = 0;

    while(!feof(stdin)){
        scanf("%s", str);
        if(strcmp(str, " ") == 0)
            continue;
        else if(getchar() == '\n'){
            num[height][n++] = atoi(str);
            height++;
            width = n;
            n = 0;
        }else{
            num[height][n++] = atoi(str);
        }
    }

    for(i = 0; i < height; i++){
        for(j = 0; j < width; j++){
            if(i == 0 && j == width-1)  continue;
            printf("%d ", num[i][j]);
        }
        printf("\n");
    }

    FILE* file = fopen("formula", "w");

    for(i = 0; i < height; i++){
        for(j = 0; j < width;j++){
            if(i == 0 && j == width-1)
                continue;
            fprintf(file, "(declare-const a%d%d Int)\n", i, j);
        }
    }

    for(i = 1; i < height; i++){
        for(j = 0; j < width-1; j++){
            fprintf(file, "(assert (and (<= a%d%d 1) (>= a%d%d 0)))\n", i, j, i, j);
        }
    }

    int row = 0;
    int k, l;
    fprintf(file, "(assert (and ");
    for(k = 0; k < width-1; k++){
        fprintf(file, "(= (+ ");
        for(l = 1; l < height; l++){
            fprintf(file, "(* %d a%d%d) ", num[l][k], l, k);
        }
        fprintf(file, ") %d) ", num[0][row++]);
    }
    fprintf(file, "))\n");

    int un = -1;
    int column = 1;
    fprintf(file, "(assert (and ");
    for(i = 1; i < height; i++){
        fprintf(file, "(= (+ ");
        for(j = 0; j < width-1; j++){
            fprintf(file, "(* (* (- a%d%d 1) %d) %d) ",  i, j, un, num[i][j]);
        }
        fprintf(file, ") %d) ", num[column++][width-1]);
    }

    fprintf(file, "))\n");

    fprintf(file, "(check-sat)\n(get-model)\n");

    fclose(file);


    char b[128];
    char s[128];
    char t[128];
    char buf[128];
    int p, q;

    int board[height-1][width-1];

    FILE* z3 = popen("z3 formula", "r");
    fscanf(z3, "%s", buf);
    if(strcmp(buf, "sat") != 0){
        printf("No Solution.\n");
        pclose(z3);
        return -1;
    }

    fscanf(z3, "%s", b);

    for(k = 0; k < (height-1)*(width-1); k++){
        fscanf(z3, "%s %s %s %s %s", b, s, b, b, t);
        p = s[1] - '0';
        q = s[2] - '0';

        if(strcmp(t, "0)") == 0){
            board[p-1][q] = 0;
        }else if(strcmp(t, "1)") == 0){
            board[p-1][q] = 1;
        }
    }

    printf("\n");
    for(i = 0; i < height-1; i++){
        for(j = 0; j < width-1; j++){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }



    return 0;
}
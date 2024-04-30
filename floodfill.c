#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void flood(char** map,int x, int y, char target_col, char replacement)
{
    if(map[x][y] == '1' || map[x][y] == replacement)
        return ;
    if(map[x][y] == target_col || map[x][y] == 'E')
        map[x][y] = replacement;
    flood(map,x,y+1,target_col,replacement);
    flood(map,x,y-1,target_col,replacement);
    flood(map,x+1,y,target_col,replacement);
    flood(map,x-1,y,target_col,replacement);
    return ;
}

int main()
{
    int y = 0;
    char **map;

    map = (char **)malloc(sizeof(char *) * 6);
    if(!map)
        return 1;
    while(y < 5)
    {
      map[y] = (char *)malloc(sizeof(char) * 7);
      y++;
    }
    
    strcpy(map[0], "111111");
    strcpy(map[1], "1000E1");
    strcpy(map[2], "100001");
    strcpy(map[3], "1P0001");
    strcpy(map[4], "111111");
    map[5] = NULL;

    flood(map,3,1,'0','2');
//     for(int i = 0;i < 5;i++)
//   {
//     for(int j = 0; j < 6;j++)
//       printf("%c",map[i][j]);
//     printf("\n");
//   }

}
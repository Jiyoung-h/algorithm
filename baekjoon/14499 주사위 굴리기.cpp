#include <cstdio>
#include <vector>
 
using namespace std;
 
int n, m, x, y, k;
 
int map[20][20];
 
const int dir[5][2] = {{0,0},{0,1},{0,-1},{-1,0},{1,0}};
 
void Rotate(vector<int>& cube, int r)
{
    switch (r)
    {
    case 1:
    {
        int a = cube[0], b = cube[2], c = cube[3], d = cube[5];
        cube[0] = c, cube[2] = a, cube[3] = d, cube[5] = b;
        break;
    }
    case 2:
    {
        int a = cube[0], b = cube[2], c = cube[3], d = cube[5];
        cube[0] = b, cube[2] = d, cube[3] = a, cube[5] = c;
        break;
    }
    case 3:
    {
        int a = cube[0], b = cube[1], c = cube[4], d = cube[5];
        cube[0] = c, cube[1] = a, cube[4] = d, cube[5] = b;
        break;
    }
    case 4:
    {
        int a = cube[0], b = cube[1], c = cube[4], d = cube[5];
        cube[0] = b, cube[1] = d, cube[4] = a, cube[5] = c;
        break;
    }
    }
}
 
int main()
{
    scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);    int i, j;
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < m; ++j)
        {
            scanf("%d", &map[i][j]);
        }
    }
 
    vector<int> cube = {0,0,0,0,0,0};
 
    for (i = 0; i < k; ++i)
    {
        int r;
        scanf("%d", &r);
        x += dir[r][0];
        y += dir[r][1];
        if (x < 0 || y < 0 || x >= n || y >= m)
        {
            x -= dir[r][0];
            y -= dir[r][1];
            continue;
        }
        Rotate(cube, r);
        if (map[x][y] == 0)
        {
            map[x][y] = cube[5];
        }
        else
        {
            cube[5] = map[x][y];
            map[x][y] = 0;
        }
        printf("%d\n", cube[0]);
    }
 
    return 0;
}

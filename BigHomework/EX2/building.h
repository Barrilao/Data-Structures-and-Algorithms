#include<iostream>
#include "node.h"
#include "mystack.h"
#define R 4
#define C 5

using namespace std;

class Building{
    private:
        int rows=R, columns=C;
        int path[R][C];
        int coordx, coordy;
    public:
        Stack<node> mapping(int mapp[R][C])
        {
            Stack<node> position;
            int i = 0, j = 0;
            node point(i, j);
            position.push(point);

            while (!position.isEmpty()) {
                point = position.peek();
                int direc = point.dir;
                i = point.x, j = point.y;
                point.dir++;
                position.pop();
                position.push(point);
                if (i == coordx and j == coordy) {
                    return position;
                }
                if (direc == 0) {
                    if (i - 1 >= 0 && mapp[i - 1][j] != 1 && path[i - 1][j] == 0) {
                        node temp(i - 1, j);
                        path[i - 1][j] = 1;
                        position.push(temp);
                    }
                }
                else if (direc == 1) {
                    if (j - 1 >= 0 && mapp[i][j - 1] != 1 && path[i][j - 1] == 0) {
                        node temp(i, j - 1);
                        path[i][j - 1] = 1;
                        position.push(temp);
                    }
                }
                else if (direc == 2) {
                    if (i + 1 < rows && mapp[i + 1][j] != 1 && path[i + 1][j]==0) {
                        node temp(i + 1, j);
                        path[i + 1][j] = 1;
                        position.push(temp);
                    }
                }
                else if (direc == 3) {
                    if (j + 1 < columns && mapp[i][j + 1] != 1 && path[i][j + 1]==0) {
                        node temp(i, j + 1);
                        path[i][j + 1] = 1;
                        position.push(temp);
                    }
                }
                else {
                    path[point.x][point.y] = 0;
                    position.pop();
                }
            }
            Stack<node> false_return;
            return false_return;
        }

        Building (int cx, int cy, int p[R][C]){
            coordx = cx;
            coordy = cy;
            for(int i = 0 ; i < R ; i++){
                for(int j = 0;j < C; j++){
                    path[i][j] = p[i][j];
                }
            }

        }


};

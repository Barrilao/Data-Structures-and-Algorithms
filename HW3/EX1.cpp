#include <iostream>
#define NMAX 5

using namespace std;

class Point{
    private:
        int coordX, coordY;

    public:

        Point(){}
        Point(int x, int y)
        {
            this->coordX=x;
            this->coordY=y;
        }
        ~Point(){}
        void reset(){
            coordX = coordY = 0;
        }

        void moveX(int x){
            if(coordX + x > NMAX){
                coordX = 0;
                return;
            }
            coordX += x;
        }

        void moveY(int y){
            if(coordY + y > NMAX){
                coordY = 0;
                return;
            }
            coordY += y;
        }

        void moveXY(int x, int y){
            if(coordX + x > NMAX || coordY + y > NMAX){
                reset();
                return;
            }
            moveX(x);
            moveY(y);
        }

        void print(){
            cout << coordX << " ";
            cout << coordY << endl;
        }

        //getters
        int getX()
        {
            return coordX;
        }
        int getY()
        {
            return coordY;
        }

        //setters
        void setX(int x)
        {
            this->coordX=x;
        }
        void setY(int y)
        {
            this->coordY=y;
        }

};

int main()
{
    Point p1;
    p1.setX(0);
    p1.setY(0);

    p1.moveX(2);
    p1.moveY(2);
    p1.print();
    p1.moveX(4);
    p1.print();
    p1.moveY(3);
    p1.print();

    return 0;
}

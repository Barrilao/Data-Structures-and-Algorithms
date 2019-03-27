#include <iostream>
#include <cmath>
#define NMAX 20

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

        int getX()
        {
            return coordX;
        }
        int getY()
        {
            return coordY;
        }

        void setX(int x)
        {
            this->coordX=x;
        }
        void setY(int y)
        {
            this->coordY=y;
        }
        
        double distance(){
        	return sqrt(pow(coordX,2)+pow(coordY,2));
		}
        

};

void insertionSort(Point points[], int n) {
	int i, j;
	Point key;
	for (i = 1; i < n; i++) {
		key = points[i];
		j = i - 1;
		while (j >= 0 && points[j].distance() > key.distance()) {
			points[j + 1] = points[j];
			j = j - 1;
		}
		points[j + 1] = key;
	}
}

int main() {
	Point p1(1, 2);
	Point p2(2, 2);
	Point p3(3, 3);
	Point p4(3, 2);
	Point p5(1, 1);
	Point points[5] = { p1, p2, p3, p4, p5 };
	for (int i = 0; i < 5; i++)
		cout << points[i].getX() << ", " << points[i].getY() << "; ";
	cout << "\n";
	insertionSort(points, 5);
	for (int i = 0; i < 5; i++)
		cout << points[i].getX() << ", " << points[i].getY() << "; ";

	return 0;
}

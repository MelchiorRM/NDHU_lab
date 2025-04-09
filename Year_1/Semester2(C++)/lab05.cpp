#include <iostream>
using namespace std;

int main() {
    int startX, startY, destX, destY;
    cin >> startX >> startY >> destX >> destY;
    
    Frog frog(startX, startY);
    
    while (frog.getCurrentPositionX() != destX) {
        if (frog.getCurrentPositionX() < destX)
            frog.moveRight();
        else
            frog.moveLeft();
    }
    
    while (frog.getCurrentPositionY() != destY) {
        if (frog.getCurrentPositionY() < destY)
            frog.moveUp();
        else
            frog.moveDown();
    }
    
    return 0;
}
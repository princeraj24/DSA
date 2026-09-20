class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // Method - 1
        // int closest_X;
        // int closest_Y;

        // if(x1 > xCenter){
        //     closest_X = x1;
        // }

        // else if(x2 < xCenter){
        //     closest_X = x2;
        // }

        // else{
        //     closest_X = xCenter;
        // }

        // if(y1 > yCenter){
        //     closest_Y = y1;
        // }

        // else if(y2 < yCenter){
        //     closest_Y = y2;
        // }

        // else{
        //     closest_Y = yCenter;
        // }


        // Method - 2
        // use clamp(value, lo, hi) inbuilt c++ function
        // lo : if(lo > value)
        // hi : if(hi > value)
        // else value

        int closest_X = clamp(xCenter, x1, x2);
        int closest_Y = clamp(yCenter, y1, y2);


        int dx = xCenter - closest_X; // here we don't consider negative value as we are calculating square of distance
        int dy = yCenter - closest_Y;

        return dx * dx + dy * dy <= radius * radius;
    }
};
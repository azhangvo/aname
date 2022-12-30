#include "Canvas.h"
#include <opencv2/opencv.hpp>

int main() {
    Canvas canvas(400, 400);

    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 200; j++) {
            canvas.drawPixel(i, j, 255, 255, 255);
        }
    }

    canvas.show();

    cv::waitKey(0);

    return 0;
}

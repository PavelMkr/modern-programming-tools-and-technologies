#include "image.h"
#include "fractal.h"

#define WIDTH 300
#define HEIGHT 300

void empty_fractal(image_p picture)
{
    for (pixel_coord y = 0; y < HEIGHT; y++) {
        for (pixel_coord x = 0; x < WIDTH; x++) {
            pixel_coord X = x, Y = y;
            bool isFilled = true;
            while (X > 0 || Y > 0) {
                if (X % 3 == 1 && Y % 3 == 1) {
                    isFilled = false;
                    break;
                }
                X /= 3;
                Y /= 3;
            }
            pixel_data color = isFilled ? 0 : 255;
            set_pixel(picture, x, y, color);
        }

    }
}
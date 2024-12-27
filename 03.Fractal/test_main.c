#include <stdio.h>
#include "utest/utest.h" // Подключение utest.h
#include "image.h"
#include "fractal.h"

struct ImageTestFixture {
    image_p i;
};

UTEST_F_SETUP(ImageTestFixture) {
    utest_fixture->i = create_image(300, 300);
    ASSERT_NE((void *) utest_fixture->i, NULL);
}

UTEST_F_TEARDOWN(ImageTestFixture) {
    free_image(utest_fixture->i);
}

UTEST_F(ImageTestFixture, Set_Get_Pixel1){
    set_pixel(utest_fixture->i, 10, 10, 10);
    ASSERT_EQ(10, get_pixel(utest_fixture->i, 10, 10));
}

UTEST_F(ImageTestFixture, ClearImage2){
    clear_image(utest_fixture->i);
    ASSERT_EQ(0, get_pixel(utest_fixture->i, 10, 10));
}

UTEST_F(ImageTestFixture, EmptyFractal) {
    clear_image(utest_fixture->i);
    empty_fractal(utest_fixture->i);

    ASSERT_EQ(0, get_pixel(utest_fixture->i, 0, 0));
    ASSERT_EQ(255, get_pixel(utest_fixture->i, 1, 1));
}

UTEST_F(ImageTestFixture, FillRandom) {
    fill_random(utest_fixture->i);

    pixel_data p1 = get_pixel(utest_fixture->i, 10, 10);
    pixel_data p2 = get_pixel(utest_fixture->i, 20, 20);
    ASSERT_NE(p1, p2);
}

UTEST(CreateImage, DifferentSizeImage) {
    image_p img = create_image(100, 900);
    ASSERT_NE((void *)img, NULL);

    set_pixel(img, 99, 899, 100);
    ASSERT_EQ(100, get_pixel(img, 99, 899));

    free_image(img);
}

UTEST_MAIN();
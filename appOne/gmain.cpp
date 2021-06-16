#include"libOne.h"
int createTriangle() {
    struct SHAPE_VERTEX vertices[3];
    vertices[0].x = 0;
    vertices[0].y = -1;
    vertices[1].x = 1;
    vertices[1].y = 1;
    vertices[2].x = -1;
    vertices[2].y = 1;
    return createShape(vertices, 3);
}
int createPolygon() {
    const int NUM = 60;
    struct SHAPE_VERTEX vertices[NUM];
    float deg = 360.0f / NUM;
    angleMode(DEGREES);
    for (int i = 0; i < NUM; i++) {
        vertices[i].x = sin(deg * i);
        vertices[i].y = -cos(deg * i);
    }
    return createShape(vertices, NUM);
}
int createStar() {
    const int NUM = 10;
    struct SHAPE_VERTEX vertices[NUM];
    float deg = 360.0f / NUM;
    angleMode(DEGREES);
    for (int i = 0; i < NUM; i++) {
        float radius = 0.5 + 0.5f * (i % 2);
        vertices[i].x = sin(deg * i) * radius;
        vertices[i].y = cos(deg * i) * radius;
    }
    return createShape(vertices, NUM);
}
int createHeart() {
    const int NUM = 600;
    struct SHAPE_VERTEX vertices[NUM];
    float deg = 360.0f / NUM;
    angleMode(DEGREES);
    for (int i = 0; i < NUM; i++) {
        float t = deg * i;
        vertices[i].x =
           pow(sin(t), 3);
        vertices[i].y = -(
            13 * cos(t) -
            5 * cos(t * 2) -
            2 * cos(t * 3) -
            1 * cos(t * 4)) / 16;
    }
    return createShape(vertices, NUM);
}


void gmain() {
    window(1000, 1000);
    int idx = createHeart();
    angleMode(DEGREES);
    float deg = 0;
    while (notQuit) {
        //deg += 0.5;
        clear(31, 30, 51);
        fill(217, 48, 92);
        shape(idx, 500, 500, deg, 200);

    }
}

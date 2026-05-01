#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pos;
    int speed;
} Car;

int compare(const void *a, const void *b) {
    Car *c1 = (Car *)a;
    Car *c2 = (Car *)b;
    return c2->pos - c1->pos;
}

int main() {
    int n, target;
    scanf("%d %d", &n, &target);

    Car cars[1000];

    for (int i = 0; i < n; i++)
        scanf("%d", &cars[i].pos);

    for (int i = 0; i < n; i++)
        scanf("%d", &cars[i].speed);

    qsort(cars, n, sizeof(Car), compare);

    int fleets = 0;
    double lastTime = 0;

    for (int i = 0; i < n; i++) {
        double time = (double)(target - cars[i].pos) / cars[i].speed;

        if (time > lastTime) {
            fleets++;
            lastTime = time;
        }
    }

    printf("%d\n", fleets);

    return 0;
}
#include <stdio.h>

#define WIDTH  5
#define HEIGHT 5
#define IMAGE_SIZE (WIDTH*HEIGHT)


void print_image(int *img);
void edit_image(int *y_img, int x, int value);

int main ()
{
    int x, y, value;
    int image[IMAGE_SIZE] = { 0, 1, 1, 1, 0,
			      1, 1, 1, 0, 0,
			      1, 1, 0, 0, 1,
			      1, 0, 0, 1, 1,
			      0, 0, 1, 1, 1 };

    print_image(image);
    printf("Input x(0-%d or -1), y(0-%d), and value(0 or 1): ", WIDTH-1, HEIGHT-1);
    fflush(stdout);
    scanf("%d %d %d", &x, &y, &value);

    if (x < -1 || x >= WIDTH  || y < 0 || y >= HEIGHT || (value != 0 && value != 1)) {
	printf("Invalid input.\n");
	return -1;
    }

    edit_image(&image[y * WIDTH], x, value);

    print_image(image);  /* This blank is the same as above-cited (1) */

    return(0);
}

void print_image(int *img)
{
    int i, j;

    printf("\n");
    for (i = 0; i < HEIGHT; i++) {
	for (j = 0; j < WIDTH; j++) {
	    printf("%d ", img[i * WIDTH + j]);
	}
	printf("\n");
    }
    printf("\n");
}

void edit_image(int *y_img, int x, int value)
{
    int i;

    if (x < 0) {
	for (i = 0; i < WIDTH; i++) {
	    y_img[i] = value;
	}
    }
    else {
	    y_img[x] = value;
    }
}
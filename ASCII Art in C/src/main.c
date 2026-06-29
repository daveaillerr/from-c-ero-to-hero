#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "../include/stb_image.h"
#include "../include/stb_image_resize2.h"

void print_banner() {
    printf("\n");
    printf("  +-----------------------------------------+\n");
    printf("  |                                         |\n");
    printf("  |           ASCII ART CONVERTER           |\n");
    printf("  |                                         |\n");
    printf("  +-----------------------------------------+\n");
    printf("\n");
}

int get_term_cols() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        return csbi.srWindow.Right - csbi.srWindow.Left + 1;
    }
    return 80; // fallback
}

int get_term_rows() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    }
    return 24; // fallback
}

int main() {

    // Define image metadata
    int width, height, channel;
    char image_name[256];

    // ASCII characters ordered from darkest to brightest
    char value[] = ".-~+=:;oaAOD0%&$B8MW#@";

    print_banner();

    print_again:

    printf("  Image file: ");
    fgets(image_name, sizeof(image_name), stdin);

    // Remove trailing newline
    size_t length = strlen(image_name);
    if (length > 0 && image_name[length - 1] == '\n') {
        image_name[length - 1] = '\0';
    }

    // Load image as grayscale
    unsigned char *input_image = stbi_load(image_name, &width, &height, &channel, 1);

    if (input_image == NULL) {
        printf("\n  Could not open \"%s\". Check the filename and try again.\n\n", image_name);
    } else {
        // Scale output to fit the terminal window
        int term_cols = get_term_cols();
        int term_rows = get_term_rows();

        // Each char takes 1 column (no space between), so output_w = term_cols
        int output_w = term_cols;
        // Preserve aspect ratio; terminal chars are ~2x taller than wide, so multiply by 0.45
        int output_h = (int)(output_w * ((double)height / width) * 0.45);
        // Leave room for banner and prompts
        if (output_h > term_rows - 6) output_h = term_rows - 6;

        unsigned char *output_image = malloc(output_w * output_h);

        stbir_resize_uint8_srgb(input_image, width, height, 0,
                                 output_image, output_w, output_h, 0,
                                 STBIR_1CHANNEL);

        printf("\n");
        for (int j = 0; j < output_h; j++) {
            for (int i = 0; i < output_w; i++) {
                int pixel_index = i + j * output_w;
                int b = output_image[pixel_index];
                int ascii_index = (b * 21) / 256;
                printf("%c", value[ascii_index]);
            }
            printf("\n");
        }
        printf("\n");

        free(output_image);
    }

    stbi_image_free(input_image);

    char choice;
    do {
        printf("  Print another image? (y/n): ");
        scanf(" %c", &choice);
        while (getchar() != '\n');

        if (choice == 'y' || choice == 'Y') {
            printf("\n");
            goto print_again;
        } else if (choice == 'n' || choice == 'N') {
            printf("\n  Goodbye!\n\n");
            exit(0);
        } else {
            printf("Invalid input.\n");
        }
    } while (choice != 'n' && choice != 'N');

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "./include/stb_image.h"
#include "./include/stb_image_resize2.h"

int main(){

    // Define size of image using stb_image.h
    int canvass_width = 20, canvass_height = 50;
    int width, height, channel;
    char image_name[256];

    // Define ASCII characters (darkest to brightest)
    char value[] = { ' ', '.', ':', '-', '=', '+', '*', 'o', 'O', '0', '#', '@', 'M', 'W', '&', '$', '%'};
    
    print_again:

    printf("Enter your image name and extention: ");
    fgets(image_name, sizeof(image_name), stdin);

    // Remove unesessary newline
    size_t length = strlen(image_name);
    if (length > 0 && image_name[length - 1] == '\n'){
        image_name[length - 1] = '\0';
    }

    // Loads and make a grayscale of an image
    unsigned char *input_image = stbi_load(image_name, &width, &height, &channel, 1);

    if (input_image == NULL){ 
        printf("File Corrupted\n");
    }

    else {
            int output_w = width / 35;
            int output_h = height / 45 ;
            unsigned char *output_image = malloc(output_w * output_h);
            
            // Image resize
            stbir_resize_uint8_srgb(input_image,  width,  height,  0, output_image, output_w, output_h, 0, STBIR_1CHANNEL);

            printf("\n");

            for (int j = 0; j < output_h; j++) {
                for (int i = 0; i < output_w; i++) {
                    int pixel_index = i + j * output_w;
                    int b = output_image[pixel_index];
                    // Map grayscale value (0-255) to ASCII index (0-14)
                    int ascii_index = (b * 17) / 255;
                    printf("%c ", value[ascii_index]);
                }
                printf("\n");
            }
            free(output_image);
        }
            stbi_image_free(input_image);

        char choice;
        
        do {
            printf("Print another image? (y/n): ");
            scanf("%c", &choice);
            while (getchar() != '\n');

            if  (choice == 'y' || choice == 'Y'){
                goto print_again;
            }
            else if (choice == 'n' || choice == 'N'){
                exit(1);
            }
            else {
                printf("Invalid!\n");
            }
        } while(choice != 'n' || choice != 'N');

    return 0;
}


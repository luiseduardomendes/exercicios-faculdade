#include <stdio.h>
#include <string.h>
#define MAX_SIZE 0x20000

void read_txt(char *filename);
unsigned char* sum_ascii_codes(const unsigned char *str, int size, unsigned char *output);

int main() {
    char file[128];
    scanf("%s", file);
    read_txt(file);
    return 0;
}

void read_txt(char *filename){
    unsigned char str[MAX_SIZE], ch, cl;
    unsigned char out[MAX_SIZE / 4];
    FILE *file, *file_out;
    char filename_out[128], ext[5], newExt[5]= ".res";
    int i = 0, j = 0, name_size;

    file = fopen(filename, "rb");

    strcpy(filename_out, filename);
    while (filename_out[j] != 0)
        j++;
    name_size = j;
    for (j = name_size - 4; j <= name_size; j ++)
        ext[j-name_size+4] = filename_out[j];
    if (!strcmp(ext, ".txt"))
        for (j = name_size - 4; j <= name_size; j ++)
            filename_out[j] = newExt[j-name_size+4];
    else
        for (j = name_size; j <= name_size+5; j ++)
            filename_out[j] = newExt[j-name_size];
    printf("File output: %s\n", filename_out);
    file_out = fopen(filename_out, "w");

    while(!feof(file)){
        ch = (unsigned char)fgetc(file);
        if (ch <= 0x7e){
            str[i] = ch;
            i ++;
            if (ch < 0x10)
                fputc('0', file_out);
            fprintf(file_out, "%x", ch);
            if (i % 4 == 0)
                fputc('\n', file_out);
        }
    }
    fclose(file);

    sum_ascii_codes(str, i, out);

    printf("Bytes: %d\n", i);
    printf("soma: ");
    for (j = 0; j < 4; j ++)
        printf("%x ", out[j]);
    printf("\n");


    for (j = 0; j < 4; j ++){
        ch = out[j];
        cl = ch >> 4;
        ch = ch - (cl << 4);
        fprintf(file_out, "0%x", cl);
        i++;
        if (i % 4 == 0)
            fputc('\n', file_out);
        fprintf(file_out, "0%x", ch);
        i++;
        if (i % 4 == 0)
            fputc('\n', file_out);


    }
    fclose(file_out);
}

unsigned char* sum_ascii_codes(const unsigned char *str, int size, unsigned char *output){
    int i;
    unsigned char ch, c2;

    for (i = 0; i < size; i ++){
        ch = str[i];
        output[i % 4] += ch;
    }

    return output;
}
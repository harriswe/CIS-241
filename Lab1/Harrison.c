#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char** argv)
{
    char ch;
    FILE *in, *out;
    in = fopen ("input.txt","r" );
    out = fopen ("output.txt", "w" );

    if (argc > 1 ) {
        printf( "This program does not allow more than one command-line argument!" );
        exit(1);
    }
    if ( in == NULL || out == NULL  )
    {
        printf( "file could not be opened!\n" );
        exit(1);
    }

    while ( ! feof(in) )   {

        fscanf ( in, "%c", &ch );
            if ( isupper(ch)) {
                ch = tolower(ch);
                fprintf ( out, "%c", ch );
            } else if ( ! isupper(ch)) {
                ch = toupper(ch);
                fprintf ( out, "%c", ch );
            } else if ( ! isalpha(ch)) {
                fprintf ( out, "%c", ch );
            }

    }



    fclose(in);
    fclose(out);
    return 0;
}

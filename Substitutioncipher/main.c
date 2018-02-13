#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<ctype.h>

char encrypt(int array[], int size);
void decrypt(int array[], int size);
void sortArray(int array[], int keysize);
void printArray(int array[]);
void selectKey(int key[], int cipher[]);


int main(int argc, char* argv[]) {

    int alphasize = 26;
    int temp, keysize;
    int cipher[alphasize];
    FILE *fin, *fout;

    keysize = strlen(argv[2]); //calculates our key size.

    int key[keysize];

    for(int i = 0; i < keysize; i++){ //fills key with input
        key[i] = argv[2][i];
    }

    for (int i = 0; i < alphasize; i++) {      //adds alphabet array.
        cipher[i] = 'z' - i; //reverse alphabet for cipher.

    }

    for (int i = 0; i < alphasize; i++) { //This selects our key from the alphabet.
       for(int j = 0; j < keysize; j++){
           if(cipher[i] == key[j]){
               temp = cipher[j];
               cipher[j] = key[j];
               cipher[i] = temp;
           }
       }

    }

    fin = fopen(argv[1], "r");
    fout = fopen(argv[3], "w");
    if (fin ==  NULL || fout == NULL)
    {
        printf("File could not be opened!\n");
        exit(1);
    }
    //selectKey();
    sortArray(cipher, keysize);

    if(argv[4] == 'e'){
        //encrypt()
    }

    return 0;
}
void printArray(int array[]){
    for(int i = 0; i < 26; i++){
        printf("%c", array[i]);
    }
    printf("\n");
}

void sortArray(int array[], int keysize) { //bubble sort the remaining alphabet.
    int temp;

    for(int i = keysize; i < 26 - 1; i++) {
        for(int j = keysize; j < 26 - 2; j++) {
            if(array[j+1] > array[j]) {
                // used for testing printf("Items compared: %i, J and %i J+1 \n", array[j], array[j+1]);
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }

    }

}

char encrypt(int array[], int size){
    while ( fscanf(fin, "%c", &ch) != EOF )
    {
        fprintf(fout, "%c", encrypt_decrypt(ch, key));
    }
}
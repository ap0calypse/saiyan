#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>

/******************************************************************************
    project:    saiyan
    purpose:    symmetric cipher tool, encrypts/decrypts text files

    usage:      ./saiyan /PATH/TO/INPUTFILE [ /PATH/TO/OUTPUTFILE ]
    
    author:     Manuel Fill (ap0calypse@agitatio.org)
    license:    public domain
*******************************************************************************/


#define BLOCKLENGTH 128

void usage();

int main(int argc, char *argv[]) {
    
    if (argc < 2) {
        usage();
        exit(1);
    }
    else if (argc == 2) {

    char *key;
    key = getpass("Please enter password: (won't be echoed) "); // getpass comes from unistd.h

    char cleartext[BLOCKLENGTH] = "aaaaaaaaaaaaaaaaaaaaaa";
    char ciphertext[BLOCKLENGTH];
    int i;
    for(i = 0; i < strlen(cleartext); i++) {
        ciphertext[i] = cleartext[i] ^ key[i];
    }
    printf("the cipherded text is %s\n", ciphertext);
    
    for(i = 0; i < strlen(cleartext); i++) {
        ciphertext[i] = ciphertext[i] ^ key[i];
    }
    
    printf("the de-cipherded text is %s\n", ciphertext);

    return(0);
}

void usage() {
    printf("\nUsage information:\n\n " \
           "\tsaiyan INPUTFILE [OUTPUTFILE]\n\n" \
            "\t\tWhere INPUTFILE is the path to a plain or ciphered text file,\n" \
            "\t\tand OUTPUTFILE is optional. If you don't specify OUTPUTFILE, output\n" \
            "\t\twill be sent to STDOUT.\n\n");
}

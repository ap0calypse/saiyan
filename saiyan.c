#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

/******************************************************************************
    project:    saiyan
    purpose:    symmetric cipher tool, encrypts/decrypts text files

    usage:      ./saiyan /PATH/TO/INPUTFILE /PATH/TO/OUTPUTFILE
    
    author:     Manuel Fill (ap0calypse@agitatio.org)
    license:    public domain
*******************************************************************************/


#define BLOCKLENGTH 128

void usage();
char *crypt_block(char *, char *);
void process_file(char *, char *);
char *get_password();

int main(int argc, char *argv[]) {
    
    // not enough args
    if (argc < 3) {
        usage();
        exit(1);
    }
    // INPUTFILE given
    else if (argc == 3) {
        process_file(argv[1], argv[2]);
    }
    else {
        usage();
        exit(2);
    }
    return(0);
}

void usage() {
    printf("\nUsage information:\n\n " \
           "\tsaiyan INPUTFILE [OUTPUTFILE]\n\n" \
            "\t\tWhere INPUTFILE is the path to a plain or ciphered text file,\n" \
            "\t\tand OUTPUTFILE is optional. If you don't specify OUTPUTFILE, output\n" \
            "\t\twill be sent to STDOUT.\n\n");
}

char *get_password() {
    char *key;
    key = getpass("Please enter password: (won't be echoed) "); // getpass comes from unistd.h
    return(key);
}

char *crypt_block(char *key, char *block) {

    
}

void process_file(char *infile, char *outfile) {
    char cleartext[BLOCKLENGTH];
    char ciphertext[BLOCKLENGTH];
    char *key;
    key = get_password();
    FILE *infd, *outfd;
    infd = fopen(infile, "r");
    outfd = fopen(outfile, "w");
    int i, character;
    while ((character = fgetc(infd)) != EOF) {
        printf("%s", character);
    }
    fclose(infd);
    fclose(outfd);
}

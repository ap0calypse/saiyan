#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/******************************************************************************
    project:    saiyan
    purpose:    symmetric cipher tool, encrypts/decrypts text files

    usage:      ./saiyan /PATH/TO/INPUTFILE /PATH/TO/OUTPUTFILE
    
    author:     Manuel Fill (ap0calypse@agitatio.org)
    license:    public domain
*******************************************************************************/

void usage();
void process_file(char *, char *);

int main(int argc, char *argv[]) {
    (argc == 3) ? process_file(argv[1], argv[2]) : usage(); exit(1);
    return(0);
}

void usage() {
    printf("\nUsage information:\n\n " \
           "\tsaiyan INPUTFILE OUTPUTFILE\n\n" \
            "\t\tWhere INPUTFILE is the path to a plain or ciphered text file,\n" \
            "\t\tand OUTPUTFILE is where the resulting de-/encrypted file will go.\n\n");
}

void process_file(char *infile, char *outfile) {
    char *key;
    key = getpass("Please enter password: (won't be echoed) "); // getpass comes from unistd.h

    FILE *infd, *outfd;
    infd = fopen(infile, "r");
    outfd = fopen(outfile, "w");
    int i = 0, character;
    
    while ((character = fgetc(infd)) != EOF) {
        fputc(character ^ key[i++], outfd);
        key[i] == '\0' ? i = 0 : i ;
    }
    fclose(infd);
    fclose(outfd);
}

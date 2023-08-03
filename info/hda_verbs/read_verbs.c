#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>
#include <dirent.h>

/* Script for outputting the corb frames as more sane verbs and parameters. 
   I just run this script in VSCode directly. 
   */
void main() {
    unsigned char buffer[0xfff];
    unsigned int pins[32];

    FILE *ptr;
    unsigned int val1, val, addr, nid, verb, parm, mask, p_val;
    unsigned int i;

    ptr = fopen("./all-corb-frames","rb");

    fread(buffer, sizeof(buffer), 1, ptr);

    for(int i = 0; i<sizeof(buffer); i+=4) {

        val = (buffer[i]) | (buffer[i+1] << 8) | (buffer[i+2] << 16) | (buffer[i+3] << 24);


        addr = (val & 0xF0000000) >> 28;
        nid = (val &  0x0FF00000) >> 20;
        verb = (val & 0x000FFF00) >> 8;
        if (((verb & 0x0F00) >> 8) >= 7) {
            parm = (val & 0x000000FF);
            printf("{ 0x%02x, 0x%03x, 0x%02x },", nid, verb, parm);
            //printf("i: %04x, %08x, addr: %01x, nid: %02x, verb: %03x, parm: %02x", i, val, addr, nid, verb, parm);
        }
        else {
            verb = (verb & 0xF00);
            parm = (val & 0xFFFF);
            printf("{ 0x%02x, 0x%03x, 0x%02x },", nid, verb, parm);
            //printf("i: %04x, %08x, addr: %01x, nid: %02x, verb: %03x, parm: %04x", i, val, addr, nid, verb, parm);
        }

        printf("\n");
        if ((verb - 0x71c) < 4) {
            mask = 0xff << (verb - 0x71c) * 8;
            p_val = pins[nid];
            p_val = ((p_val & mask) ^ p_val) | (parm << ((verb- 0x71c) * 8));
            pins[nid] = p_val;
        }


        
    } 

    printf("\n\rFinal Pin Configurations\n\r");
    for (i=0;i<32;i++) {
        printf("pin %02x: %08x\n\r", i, pins[i]);
    }
    //printf("%lu\n\r", sizeof(unsigned int));
}
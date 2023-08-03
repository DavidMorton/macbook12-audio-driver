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

char *verb_names[38] = {"AC_VERB_SET_STREAM_FORMAT","AC_VERB_SET_AMP_GAIN_MUTE","AC_VERB_SET_PROC_COEF","AC_VERB_SET_COEF_INDEX","AC_VERB_SET_CONNECT_SEL","AC_VERB_SET_PROC_STATE","AC_VERB_SET_SDI_SELECT","AC_VERB_SET_POWER_STATE","AC_VERB_SET_CHANNEL_STREAMID","AC_VERB_SET_PIN_WIDGET_CONTROL","AC_VERB_SET_UNSOLICITED_ENABLE","AC_VERB_SET_PIN_SENSE","AC_VERB_SET_BEEP_CONTROL","AC_VERB_SET_EAPD_BTLENABLE","AC_VERB_SET_DIGI_CONVERT_1","AC_VERB_SET_DIGI_CONVERT_2","AC_VERB_SET_DIGI_CONVERT_3","AC_VERB_SET_VOLUME_KNOB_CONTROL","AC_VERB_SET_GPIO_DATA","AC_VERB_SET_GPIO_MASK","AC_VERB_SET_GPIO_DIRECTION","AC_VERB_SET_GPIO_WAKE_MASK","AC_VERB_SET_GPIO_UNSOLICITED_RSP_MASK","AC_VERB_SET_GPIO_STICKY_MASK","AC_VERB_SET_CONFIG_DEFAULT_BYTES_0","AC_VERB_SET_CONFIG_DEFAULT_BYTES_1","AC_VERB_SET_CONFIG_DEFAULT_BYTES_2","AC_VERB_SET_CONFIG_DEFAULT_BYTES_3","AC_VERB_SET_EAPD","AC_VERB_SET_CODEC_RESET","AC_VERB_SET_STRIPE_CONTROL","AC_VERB_SET_CVT_CHAN_COUNT","AC_VERB_SET_HDMI_DIP_INDEX","AC_VERB_SET_HDMI_DIP_DATA","AC_VERB_SET_HDMI_DIP_XMIT","AC_VERB_SET_HDMI_CP_CTRL","AC_VERB_SET_HDMI_CHAN_SLOT","AC_VERB_SET_DEVICE_SEL"};
unsigned int verb_values[38] = { 0x200,0x300,0x400,0x500,0x701,0x703,0x704,0x705,0x706,0x707,0x708,0x709,0x70a,0x70c,0x70d,0x70e,0x73e,0x70f,0x715,0x716,0x717,0x718,0x719,0x71a,0x71c,0x71d,0x71e,0x71f,0x788,0x7ff,0x724,0x72d,0x730,0x731,0x732,0x733,0x734,0x735 };

char* verb_name(unsigned int verb_value) {
    int i;
    char* result;
    for (i = 0; i < sizeof(verb_values) / sizeof(verb_values[0]); i++) {
        if (verb_value == verb_values[i])
            return verb_names[i];
    }
    
    result = malloc(sizeof(char) * 5);
    sprintf(result, "0x%03x", verb_value);
    return result;
}

void main() {
    unsigned char buffer[0xfff];
    unsigned int pins[40];

    FILE *ptr;
    unsigned int val1, val, addr, nid, verb, parm, mask, p_val;
    unsigned int i;
    unsigned char* v_name;

    ptr = fopen("./all-corb-frames","rb");

    fread(buffer, sizeof(buffer), 1, ptr);

    for(int i = 0; i<sizeof(buffer); i+=4) {

        val = (buffer[i]) | (buffer[i+1] << 8) | (buffer[i+2] << 16) | (buffer[i+3] << 24);


        addr = (val & 0xF0000000) >> 28;
        nid = (val &  0x0FF00000) >> 20;
        verb = (val & 0x000FFF00) >> 8;
        if (((verb & 0x0F00) >> 8) >= 7) {
            parm = (val & 0x000000FF);
            //printf("{ 0x%02x, 0x%03x, 0x%02x },", nid, verb, parm);
            //printf("i: %04x, %08x, addr: %01x, nid: %02x, verb: %03x, parm: %02x", i, val, addr, nid, verb, parm);
        }
        else {
            verb = (verb & 0xF00);
            parm = (val & 0xFFFF);
            
            //printf("i: %04x, %08x, addr: %01x, nid: %02x, verb: %03x, parm: %04x", i, val, addr, nid, verb, parm);
        }

        v_name = verb_name(verb);
        // Eliminate the gets from this system. We're going to try just with the sets.
        if (((verb & 0xF00) >> 8) < 0xa)
            printf("{ 0x%02x, %s, 0x%02x }, // 0x%08x\n", nid, v_name, parm, val);

        if ((verb - 0x71c) < 4) {
            mask = 0xff << (verb - 0x71c) * 8;
            p_val = pins[nid];
            p_val = ((p_val & mask) ^ p_val) | (parm << ((verb- 0x71c) * 8));
            pins[nid] = p_val;
        }


        
    } 

    printf("\n\rFinal Pin Configurations\n");
    for (i=0;i<32;i++) {
        printf("{ 0x%02x, 0x%08x },\n", i, pins[i]);
    }
    //printf("%lu\n\r", sizeof(unsigned int));
}
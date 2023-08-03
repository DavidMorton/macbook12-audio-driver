#include <stdio.h>

/* Simple test script to test a particular verb and ensure I'm interpreting the raw 
   binary data correctly. 
   */
void main() {
    // 0ef8, 771f5701 (00007fff), addr: 77, nid: 1f, verb: 701, parm: 05
    unsigned int addr, nid, verb, parm, val;
    addr = 0x7;
    nid = 0x1f;
    verb = 0x701;
    parm = 0x05;

    val = addr << 28; // address of the CORB buffer
    val |= nid << 20; // NID
    val |= verb << 8; // verb
    val |= parm; // verb parameter
    printf("%08x\n\r", val);
}
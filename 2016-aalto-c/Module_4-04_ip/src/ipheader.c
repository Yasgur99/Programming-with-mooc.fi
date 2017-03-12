#include <stdio.h>
#include <arpa/inet.h>
#include "ipheader.h"

/* Parses the given buffer into an IP header structure.
 * 
 * Parameters:
 * ip: pointer to the IP header structure that will be filled based
 *      on the data in the buffer
 * buffer: buffer of 20 bytes that contain the IP header. */
void parseIp(struct ipHeader *ip, const void *buffer) {
    unsigned char* bytes = buffer;

    ip->version = bytes[0] >> 4;
    ip->ihl = (bytes[0] & 0x0f) * 4;
    ip->dscp = (bytes[1] & 0xfc) >> 2;
    ip->ecn = (bytes[1] & 0x03);
    ip->length = ((bytes[2] & 0x00ff) << 8) + (bytes[3] & 0xff);
    ip->identification = ((bytes[4] & 0x00ff) << 8) + (bytes[5] & 0xff);
    ip->flags = bytes[6] >> 5;
    ip->fragment_offset = ((bytes[6] & 0x1f) << 8) + (bytes[7] & 0xff);
    ip->time_to_live = bytes[8];
    ip->protocol = bytes[9];
    ip->header_checksum = (bytes[10] << 8)+ (bytes[11] & 0xff);

    int currentByte = 12;
    for (int i = 0; i < 4; i++)
        ip->source_ip[i] = bytes[currentByte++];

    for (int i = 0; i < 4; i++)
        ip->destination_ip[i] = bytes[currentByte++];

}

/* Builds a 20-byte byte stream based on the given IP header structure
 * 
 * Parameters:
 * buffer: pointer to the 20-byte buffer to which the header is constructed
 * ip: IP header structure that will be packed to the buffer */
void sendIp(void *buffer, const struct ipHeader *ip) {
    unsigned char* bytes = buffer;

    bytes[0] = ((ip->version & 0xff)<< 4) + ((ip->ihl/4) & 0xff);
    bytes[1] = ((ip ->dscp <<2)& 0xfc) + (ip->ecn & 0x03);
    bytes[2] = ip->length >> 8;
    bytes[3] = ip->length & 0xffff;
    bytes[4] = ip->identification >> 8;
    bytes[5] = ip->identification & 0xffff;
    bytes[6] = (ip->flags << 5) + (ip->fragment_offset >>8); 
    bytes[7] = ip->fragment_offset & 0xffff;
    bytes[8] = ip->time_to_live;
    bytes[9] = ip ->protocol;
    bytes[10] = ip->header_checksum >> 8;
    bytes[11] = ip->header_checksum & 0xff;

    bytes[12] = ip->source_ip[0];
    bytes[13] = ip->source_ip[1];
    bytes[14] = ip->source_ip[2];
    bytes[15] = ip->source_ip[3];
    bytes[16] = ip->destination_ip[0];
    bytes[17] = ip->destination_ip[1];
    bytes[18] = ip->destination_ip[2];
    bytes[19] = ip->destination_ip[3];
}

/* Prints the given IP header structure */
void printIp(const struct ipHeader *ip) {
    /* Note: ntohs below is for converting numbers from network byte order
     to host byte order. You can ignore them for now
     To be discussed further in Network Programming course... */
    printf("version: %d   ihl: %d   dscp: %d   ecn: %d\n",
            ip->version, ip->ihl, ip->dscp, ip->ecn);
    printf("length: %d   id: %d   flags: %d   offset: %d\n",
            ntohs(ip->length), ntohs(ip->identification), ip->flags, ip->fragment_offset);
    printf("time to live: %d   protocol: %d   checksum: 0x%04x\n",
            ip->time_to_live, ip->protocol, ntohs(ip->header_checksum));
    printf("source ip: %d.%d.%d.%d\n", ip->source_ip[0], ip->source_ip[1],
            ip->source_ip[2], ip->source_ip[3]);
    printf("destination ip: %d.%d.%d.%d\n", ip->destination_ip[0],
            ip->destination_ip[1],
            ip->destination_ip[2], ip->destination_ip[3]);
}

/* Shows hexdump of given data buffer */
void hexdump(const void *buffer, unsigned int length) {
    const unsigned char *cbuf = buffer;
    unsigned int i;
    for (i = 0; i < length;) {
        printf("%02x ", cbuf[i]);
        i++;
        if (!(i % 8))
            printf("\n");
    }
}

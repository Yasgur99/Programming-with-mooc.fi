#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base64.h"

/* The set of base64-encoded characters. You may use this table if you want.
 * (The last character is not part of the actual base64 set, but used for
 * padding). 
 */
const char *encoding = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

/* Open file named <src_file> for reading, and convert it to Base64 format,
 * which is written to file named <dst_file>.
 * 
 * Returns: number of bytes in <src_file>, or -1 if there was an error,
 * for example if opening of <src_file> did not succeed.
 */


int to_base64(const char *dst_file, const char *src_file) {
    /*Open files*/
    FILE* src = fopen(src_file, "r");
    if (!src) return -1;

    FILE* dest = fopen(dst_file, "w");
    if (!dest) {
        fclose(src);
        return -1;
    }

    //Read file to buffer
    int nBytesRead = 0;
    int nBytesLine = 0;
    while (!feof(src)) {
        unsigned char sBuffer[3];
        size_t read = fread(sBuffer, sizeof (char), 3, src);
        nBytesRead += read;

        if (nBytesLine > 0 && nBytesLine % 64 == 0) {
            nBytesLine = 0;
            fputc('\n', dest);
        }

        unsigned char dbuffer[4];
        if (read == 1) {
            dbuffer[0] = encoding[(sBuffer[0] & 0xff) >> 2];
            dbuffer[1] = encoding[(sBuffer[0] & 0x03) << 4];
            dbuffer[2] = '=';
            dbuffer[3] = '=';
        } else if (read == 2) {
            dbuffer[0] = encoding[(sBuffer[0] & 0xff) >> 2];
            dbuffer[1] = encoding[((sBuffer[0] & 0x03) << 4) + ((sBuffer[1] & 0xf0) >> 4)];
            dbuffer[2] = encoding[(sBuffer[1] & 0x0f) << 2];
            dbuffer[3] = '=';
        } else if (read == 3) {
            dbuffer[0] = encoding[(sBuffer[0] & 0xff) >> 2];
            dbuffer[1] = encoding[((sBuffer[0] & 0x03) << 4) + ((sBuffer[1] & 0xf0) >> 4)];
            dbuffer[2] = encoding[((sBuffer[1] & 0x0f) << 2) + ((sBuffer[2] & 0xc0) >> 6)];
            dbuffer[3] = encoding[sBuffer[2] & 0x3f];
        }
        nBytesLine += 4;

        //write to destination file
        if (read > 0)
            fwrite(dbuffer, sizeof (char), 4, dest);
    }
    fclose(src);
    fclose(dest);
    return nBytesRead;
}

/* Open Base64-encoded file named <src_file> for reading, and convert it
 * to regular binary format, which is written to file named <dst_file>.
 * 
 * Returns: number of bytes in <src_file>, or -1 if there was an error,
 * for example if opening of <src_file> did not succeed.
 */

unsigned int decode(char *buf) {
    unsigned int i = 0;
    unsigned int len = strlen(buf);
    for (i = 0; i < len; i++) {
        char *p = strchr(encoding, buf[i]);
        if (p) {
            buf[i] = p - encoding;
        } else {
            // non-base64 character terminates the line right away.
            return i;
        }
    }
    return i;
}

int from_base64(const char *dst_file, const char *src_file) {
    FILE *sf = fopen(src_file, "r");
    if (!sf) {
        return -1;
    }
    FILE *df = fopen(dst_file, "w");
    if (!df) {
        fclose(sf);
        return -1;
    }

    char srcbuf[68];
    int scount = 0;

    while (fgets(srcbuf, sizeof (srcbuf), sf)) {
        scount += strlen(srcbuf);
        unsigned int len = decode(srcbuf);
        char *sb = srcbuf;
        while (len >= 4) {
            unsigned char dbuf[3] = {0};
            size_t dlen = 1;
            dbuf[0] = sb[0] << 2 | sb[1] >> 4;
            if (sb[2] != 64) {
                dbuf[1] = sb[1] << 4 | sb[2] >> 2;
                dlen++;
            }
            if (sb[3] != 64) {
                dbuf[2] = sb[2] << 6 | sb[3];
                dlen++;
            }
            if (fwrite(dbuf, 1, dlen, df) < dlen) {
                // unexpected error
                fclose(sf);
                fclose(df);
                return -1;
            }
            len -= 4;
            sb += 4;
        }
    }
    fclose(sf);
    fclose(df);
    return scount;
}
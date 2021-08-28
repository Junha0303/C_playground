#include <stdio.h>
int main(int argc, char const *argv[])
{
    char buffer[100];
    fgets(buffer, sizeof(buffer), stdin);

    char *inx = buffer;
    while(*inx)
    {
        unsigned char temp = 0x00;
        for(int i = 0; i < 8; i++)
        {
            if(*inx == '0'){
                inx++;
            }
            else if(*inx == '1'){
                temp |= (0x01 << (7 - i));
                inx++;
            }
            else break;
        }
        fprintf(stdout, "%c", temp);
    }
    return 0;
}

#include <stdio.h>

struct inode_disk {
	u_int32_t start;                /* First data sector. */
	u_int32_t length;                       /* File size in bytes. */
	u_int32_t is_directory;				/* Is directory or file */
	u_int32_t magic;                     /* Magic number. */
	u_int32_t unused[124];               /* Not used. */
};

int main(int argc, char const *argv[])
{
    static char zeros[512];
    printf("%d\n", *(zeros + 123));
}
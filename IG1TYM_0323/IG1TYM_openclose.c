#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FAJL "IG1TYM.txt"

int main()
{
    int file = open(FAJL, O_RDWR);
    if(file == -1)
    {
        printf("Nem sikerult megnyitni a(z) \"%s\" fajlt!\n", FAJL);
        return 1;
    } else printf(" A(z) \"%s\" fajl sikeresen megnyilt!\n", FAJL);

    char szoveg[] = "Bettes Benjamin, Programtervezo Informatikus, IG1TYM";
    int irt = write(file, szoveg, sizeof(szoveg));
    printf("A fajlba irtuk a(z) \"%s\" szoveget. Osszesen \"%i\" byte.\n", szoveg, irt);

    lseek(file, 0, SEEK_SET);
    printf("A mutato a fajl elejen!\n");

    char tartalom[64];
    int beolvasott = read(file, tartalom, sizeof(tartalom));

    tartalom[beolvasott] = '\0';
    printf("Beolvasott tartalom: \"%s\". Osszesen: \"%i\" byte.\n", tartalom, beolvasott);

    close(file);
    return 0;
}

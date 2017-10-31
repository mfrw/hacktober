// LANGUAGE: C
// AUTHOR: Ewerton Queiroz
// GITHUB: http://github.com/EwertonQueiroz/

#include <stdio.h>

int qtd_disk = 0;
int moviment = 0;

int main () {
	// Tower of Hanoi
    while (qtd_disk == 0) {
        printf ("Enter the disks quantity:\n");
        scanf ("%d", &qtd_disk);
    }

	transfer (qtd_disk, 'A', 'C', 'B');

	return 0;
}

void transfer (int size, char source, char destiny, char aux) {
    if (size == 1) {
        moviment++;
        printf("%d - Move disk from %c to %c\n", moviment, source, destiny);
    }

    else {
        transfer (size - 1, source, aux, destiny);
        moviment++;
        printf("%d - Move disk from %c to %c\n", moviment, source, destiny);
        transfer (size - 1, aux, destiny, source);
    }
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LINE_LEN 1024

int main() {
    FILE *fin = fopen("emoji-test.txt", "r");
    if (!fin) {
        perror("Could not open emoji-test.txt for reading");
        return 1;
    }

    FILE *fout = fopen("emojis.txt", "w");
    if (!fout) {
        perror("Could not open emojis.txt for writing");
        fclose(fin);
        return 1;
    }

    char line[LINE_LEN];
    int count = 0;

    while (fgets(line, sizeof(line), fin)) {
        if (line[0] == '#' || !strstr(line, ";")) continue;

        char *hash = strchr(line, '#');
        if (!hash) continue;

        char emoji[32];
        char *p = hash + 1;
        while (*p && isspace((unsigned char)*p)) p++;

        int i = 0;
        while (*p && !isspace((unsigned char)*p) && i < (int)sizeof(emoji) - 1) {
            emoji[i++] = *p++;
        }
        emoji[i] = '\0';

        while (*p && isspace((unsigned char)*p)) p++;

        if (*p == 'E') {
            while (*p && !isspace((unsigned char)*p)) p++;
            while (*p && isspace((unsigned char)*p)) p++;
        }

        char *name = p;
        name[strcspn(name, "\r\n")] = 0;

        if (strlen(name) > 0 && strlen(emoji) > 0) {
            fprintf(fout, "%s  %s\n", emoji, name);
            count++;
        }
    }

    fclose(fin);
    fclose(fout);

    printf("Successfully processed %d emojis into emojis.txt\n", count);
    return 0;
}

#include <stdio.h>
#include <stdbool.h>

char findClass(char str[]) {
    int ip = 0;
    sscanf(str, "%d", &ip);

    if (ip >= 1 && ip <= 126) return 'A';
    else if (ip >= 127 && ip <= 191) return 'B';
    else if (ip >= 192 && ip <= 223) return 'C';
    else if (ip >= 224 && ip <= 239) return 'D';
    else if (ip >= 240 && ip <= 255) return 'E';
    else {
        printf("Invalid IP address\n");
        return '\0';
    }
}

void separate(char str[], char ipClass) {
    int i = 0, j = 0;
    char network[16] = {'\0'}, host[16] = {'\0'};
    int dotCount = 0;

    while (str[j] != '\0') {
        if(ipClass == 'A') {
            if(dotCount < 1) {
                if(str[j] == '.') {
                    dotCount++;
                    network[i] = '\0';
                    i = 0;
                } else {
                    network[i++] = str[j];
                }
            } else {
                host[i++] = str[j];
            }
        } else if(ipClass == 'B') {
            if(dotCount < 2) {
                if(str[j] == '.') {
                    dotCount++;
                    network[i] = '\0';
                    i = 0;
                } else {
                    network[i++] = str[j];
                }
            } else {
                host[i++] = str[j];
            }
        } else if(ipClass == 'C') {
            if(dotCount < 3) {
                if(str[j] == '.') {
                    dotCount++;
                    network[i] = '\0';
                    i = 0;
                } else {
                    network[i++] = str[j];
                }
            } else {
                host[i++] = str[j];
            }
        } else {
            printf("In this class, IP address is not divided into Network and Host ID\n");
            return;
        }
        j++;
    }

    host[i] ='\0';

    printf("Network ID is %s\n", network);
    printf("Host ID is %s\n", host);
}

int main() {
    char str[16];
    scanf("%s", str);

    int oct1, oct2, oct3, oct4;
    if (sscanf(str, "%d.%d.%d.%d", &oct1, &oct2, &oct3, &oct4) != 4) {
        printf("Invalid IP Address format\n");
        return 0;
    }

    if (oct1 < 0 || oct1 > 255 ||
        oct2 < 0 || oct2 > 255 ||
        oct3 < 0 || oct3 > 255 ||
        oct4 < 0 || oct4 > 255) {
        printf("Invalid address\n");
        return 0;
    }

    char ipClass = findClass(str);
    if(ipClass != '\0') {
        printf("Given IP address belongs to class %c\n", ipClass);
        separate(str, ipClass);
    }
    return 0;
}
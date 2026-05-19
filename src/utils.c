#include <string.h>
#include "../include/utils.h"

void removerEnter(char str[]) {
    str[strcspn(str, "\n")] = '\0';
}
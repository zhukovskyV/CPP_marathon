#include "inventory.h"

int count_args(char *command, char **comm, char **arg) {
    char *char_in_str = strtok(command, " ");
    char *buff = *comm;
    char *buffarg = *arg;
    int count = 0;
    if(char_in_str != NULL) {
        strcpy(buff, char_in_str);
        while (char_in_str != NULL) {
            char_in_str = strtok(NULL, " ");
            if((std::string(buff) == "insert" || std::string(buff) == "remove") && count == 0) {
                if(char_in_str == NULL) {
                    count = -1;
                    break;
                }
                strcpy(buffarg, char_in_str);
            }
            count++;
        }
    }
    return count;
}

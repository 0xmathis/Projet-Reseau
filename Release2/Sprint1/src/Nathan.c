#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/api.h"
#include "../include/constantes.h"
#include "../include/Mathis.h"
#include <../include/Nathan.h>
#include "../include/request.h"
#include "../include/utils.h"

int check_accept_encoding(Node *root, int clientId) {

    _Token *codings = searchTree(root, "codings");
    int length;
    char *start = getElementValue(codings, &length);
    char *value = (char *) malloc(sizeof(char) * length+1);
    sprintf(value, "%.*s", length, start);

    if (codings != NULL) {

        if strstr(value, "q-0") {
                sendErrorCode(root, clientId, 406, "ALED");
                return 1;
            }

        while (codings->next != NULL) {

            start = *start = getElementValue(codings, &length);
            value = (char *) malloc(sizeof(char) * length+1);
            sprintf(value, "%.*s", length, start);
            
            if strstr(value, "q-0") {
                sendErrorCode(root, clientId, 406, "q-0 n'est pas accepté dans les content-coding");
                return 1;
            }
        }
    }

    return 0;
}

int check_accept_language(Node *root, int clientId) {

    _Token *accept_language = searchTree(root, "accept-language");
    int length;
    char *start = getElementValue(accept_language, &length);
    char *value = (char *) malloc(sizeof(char) * length+1);
    sprintf(value, "%.*s", length, start);

    while (codings->next != NULL) {
        
        if (strcmp(value, "fr") == 0 || strcmp(value,'fr-FR') == 0) {
            return 0;
        }
    }

    sendErrorCode(root, clientId, 406, "Le français n'est pas dans la liste des langages acceptés");
    return 1;

}
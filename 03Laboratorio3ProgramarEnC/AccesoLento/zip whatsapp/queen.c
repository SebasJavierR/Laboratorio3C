#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./libs/key.h"
#include "./libs/memory.h"
#include "./libs/messages.c"
#include "./libs/random.h"
#include "./state.h"

// IMPRIME LA FNIALIZACION DE UNA HORMIGA
void endAntCollect(Message message) {
    int antNumber = atoi(message.content);
    printf("La homirga %d termino la colecta\n", antNumber);
}

// IMPRIME LA FNIALIZACION DE TODAS LAS HORMIGAS Y TERMINA.
void endCollect() {
    printf("Termino la colecta \n");
    exit(0);
}

// CHEQUEA EL ESTADO DE LAS HORMIGAS.
void *stateCheck(void *parametro) {
    State *state = (State *)parametro;

    while (1) {
        Message message;
        recieveMessage(state[0].messageQueueID, SUBJECT_QUEEN, &message);

        switch (message.eventID) {
            case EVENT_END_ANT:
                endAntCollect(message);
                break;
            case EVENT_END_ALL:
                endCollect();
                break;
            default:
                printf("Soy la reina y recibi un mensaje extranio\n");
                break;
        }
    }

    pthread_exit((void *)"Termino la colecta");
}

// IMPRIME LOS INSUMOS A ELEGIR PARA COLECTAR
void printInsumeOptions() {
    int i;
    for (i = 0; i < INSUMES_LENGTH; i++) {
        printf("%d - Mandar a colectar %s\n", i, INSUMES[i]);
    }
}

// NOTIFICA A LAS HORMIGAS DE COLECTAR
void notifyInsumeCollection(int option, int messageQueueID, State *state) {
    int i;
    for (i = 0; i < state[0].antsLength; i++) {
        Message message;

        char content[TEXT_LENGTH] = "";
        sprintf(content, "%d", option);

        message.recieverID = SUBJECT_ANT + i;
        message.senderID = SUBJECT_QUEEN;
        message.eventID = EVENT_START_ANT;
        strcpy(message.content, content);

        sendMessage(messageQueueID, message);
    }
}

// OBTIENE EL INSUMO A COLECTAR Y NOTIFICA
void executeInsumeCollection(int option, int messageQueueID, State *state) {
    if (option < 0 || option > INSUMES_LENGTH - 1) {
        printf("El insumo no esta en la lista\n");
    } else {
        notifyInsumeCollection(option, messageQueueID, state);
    }
}

int main(int argc, char *argv[]) {
    int stateMemoryID;
    State *state = (State *)createSharedMemory(
        sizeof(State), &stateMemoryID,
        createKey(MEMORY_STATE_FILE, MEMORY_STATE_INT));

    if (state[0].initialized != 1) {
        printf("Primero inicialize a las hormigas!\n");
        freeSharedMemory(stateMemoryID, state);
        return 0;
    }

    key_t key = createKey(MESSAGE_QUEUE_FILE, MESSAGE_QUEUE_INT);
    int messageQueueID = createMessageQueue(key);

    pthread_t threadID;
    pthread_attr_t atributos;

    pthread_attr_init(&atributos);
    pthread_attr_setdetachstate(&atributos, PTHREAD_CREATE_JOINABLE);

    state[0].messageQueueID = messageQueueID;

    if (pthread_create(&threadID, &atributos, stateCheck, state) != 0) {
        perror("No puedo crear thread\n");
        exit(-1);
    }

    int option;

    while (1) {
        printInsumeOptions();
        scanf("%d", &option);
        executeInsumeCollection(option, messageQueueID, state);
    }
};

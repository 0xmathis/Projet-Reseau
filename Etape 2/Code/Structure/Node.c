#include "Node.h"
#include <stdio.h>
#include <string.h>

// Constructeurs

Node *newChild(Node * Parent){
    Parent.
}

Node *newBrother(Node *){

}


// Setters

void setLabel(Node *this, char *label) {
    strcpy(this->__label, label);
}

void setStart(Node *this, char *start) {
    this->__start = start;
}

void setLength(Node *this, int length) {
    this->__length = length;
}

void setChild(Node *this, Node *child) {
    this->__child = child;
}

void setBrother(Node *this, Node *brother) {
    this->__brother = brother;
}

// Getters

char *getLabel(Node *this) {
    return this->__label;
}

char *getStart(Node *this) {
    return this->__start;
}

int getLength(Node *this) {
    return this->__length;
}

Node *getChild(Node *this) {
    return this->__child;
}

Node *getBrother(Node *this) {
    return this->__brother;
}

// Autre

void printChildren(Node *this, int depth) {
    for (int i = 0; i < depth; i++) { printf("\t"); }
    printf("%s: ", this->__label);
    for (int i = 0; i < getLength(this); i++) { printf("%c", *(getStart(this) + i)); }
    printf("\n");

    if (getChild(this) != NULL) {
        printChildren(getChild(this), depth + 1);
    }

    if (getBrother(this) != NULL) {
        printChildren(getBrother(this), depth);
    }
}
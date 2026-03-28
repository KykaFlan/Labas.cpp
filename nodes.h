#pragma once

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class DNode {
public:
    int data;
    DNode* next;
    DNode* prev;

    DNode(int val) : data(val), next(nullptr), prev(nullptr) {}
};
#include "TList.h"
#include <cstdlib>
#include <iostream>

// Êîíñòðóêòîð
TList::TList() : First(nullptr), Last(nullptr), Current(nullptr) {}

// Êîíñòðóêòîð êîïèðîâàíèÿ
TList::TList(const TList& other) : First(nullptr), Last(nullptr), Current(nullptr) {
    if (other.First) {
        DNode* cur = other.First;
        while (cur) {
            append(cur->data);
            cur = cur->next;
        }
    }
    std::cout << "Êîíñòðóêòîð êîïèðîâàíèÿ TList ñîçäàë êîïèþ\n";
}

// Äåñòðóêòîð
TList::~TList() {
    std::cout << "Íà÷èíàåì î÷èñòêó ñïèñêà\n";
    DNode* cur = First;
    int count = 0;

    while (cur) {
        DNode* temp = cur;
        cur = cur->next;
        std::cout << "Óäàëÿåì óçåë ñ àäðåñîì " << temp << ", çíà÷åíèå " << temp->data << std::endl;
        delete temp;
        count++;
    }

    First = Last = Current = nullptr;
    std::cout << "Ñïèñîê î÷èùåí. Óäàëåíî " << count << " ýëåìåíòîâ\n";
}

// Äîáàâëåíèå â êîíåö
void TList::append(int val) {
    DNode* newNode = new DNode(val);

    if (isEmpty()) {
        First = Last = newNode;
    }
    else {
        Last->next = newNode;
        newNode->prev = Last;
        Last = newNode;
    }
}

// Ïðîâåðêà íà ïóñòîòó
bool TList::isEmpty() const {
    return First == nullptr;
}

// Âûâîä
void TList::print() const {
    if (isEmpty()) {
        std::cout << "Ñïèñîê ïóñò\n";
        return;
    }

    DNode* cur = First;
    while (cur) {
        std::cout << cur->data << " ";
        cur = cur->next;
    }
    std::cout << std::endl;
}

// Ïîèñê
void TList::find(int val) const {
    if (isEmpty()) {
        std::cout << "Ñïèñîê ïóñò. Ïîèñê íåâîçìîæåí.\n";
        return;
    }

    DNode* cur = First;
    int position = 1;

    while (cur) {
        if (cur->data == val) {
            std::cout << "Ýëåìåíò " << val << " íàéäåí â ñïèñêå!\n";
            std::cout << "Ïîçèöèÿ: " << position << "\n";
            std::cout << "Àäðåñ: " << cur << "\n";
            std::cout << "Çíà÷åíèå: " << cur->data << "\n";
            return;
        }
        cur = cur->next;
        position++;
    }

    std::cout << "Ýëåìåíò " << val << " íå íàéäåí â ñïèñêå\n";
}

// Ñäåëàòü òåêóùèì ïåðâûé
void TList::ToFirst() {
    Current = First;
}

// Ïåðåéòè ê ñëåäóþùåìó
void TList::ToNext() {
    if (Current && Current->next) {
        Current = Current->next;
    }
}

// Óñòàíîâèòü çíà÷åíèå òåêóùåìó
void TList::SetData(int val) {
    if (Current) {
        Current->data = val;
    }
}

// Ïðîâåðêà ïîñëåäíèé ëè òåêóùèé  
bool TList::IsLast() const {
    return Current == Last;
}


// Ñëó÷àéíîå çàïîëíåíèå
void TList::fillRandom(int count) {
    for (int i = 0; i < count; ++i) {
        append(rand() % 100);
    }
}

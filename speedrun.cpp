// judul : mesin gerbong kereta pointer single linked list
#include <iostream>
using namespace std;

// kamus
class Node 
{
    private :
        char data;
        Node* next;

    public :
        Node(char value)
        {
            data = value;
            next = nullptr;
        }

        char getData()
        {
            return data;
        }

        Node* getnext()
        {
            return next;
        }

        void setData(char value)
        {
            data = value;
        }

        void setNext(Node* nextAddr)
        {
            next = nextAddr;
        }
};

typedef Node* nodePntr;
class singleLinkedList
{
    protected:
        nodePntr head;
        nodePntr tail;
    public :
    singleLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void printList()
    {
        if(head == nullptr)
        {
            cout << "Tidak ada isi linked list" << endl;
        }
        else
        {
            cout << endl;
            cout << "Isi Linked List \n";
            cout << "'data[currentAddr] -> [nextaddr]'  \n \n";

            nodePntr current = head;
            while(current != nullptr)
            {
                cout << current->getData() << "["<< current << "] " << "-> " << "["<< current->getnext() << "]";
                cout << endl;
                current = current->getnext();
            }
        }
    }

    int totalNode()
    {
        int totalNode = 0;
        nodePntr current = head;

        while(current != nullptr)
        {
            totalNode++;
            current = current->getnext();
        }

        return totalNode;
    }

    void insertHead(char value)
    {
        nodePntr newNode = new Node(value);
        if(head == nullptr)
        {
            head = tail = newNode;
        }
        else 
        {
            newNode->setNext(head);
            head = newNode;
        }
    }

    void insertAfter(char tujuanNode, char value)
    {
        nodePntr current = head;
        while(current != nullptr)
        {
            if(current->getData() == tujuanNode)
            {
                nodePntr newNode = new Node(value);
                newNode->setNext(current->getnext());
                current->setNext(newNode);
                cout << "sukses dibuat \n \n";
                return;
            }
            current = current->getnext();
        }
        if(current == nullptr)
        {
            cout << "Tujuan Data Node tidak ada, tolong masukkan yang benar. \n";
        }
    }

    void insertLast(char value)
    {
        nodePntr current = head;
        if(head == nullptr)
        {
            head = tail = new Node(value);
        }
        else
        {
            nodePntr newNode = new Node(value);
            newNode->setNext(tail->getnext());
            tail->setNext(newNode);
            tail = newNode;
        }
    }

};

// procedure
void menuTampilan();
void ketentuanInsert(int totalNode);
void menuInserFirst(int totalNode, char value);
void menuInsertAfter(int totalNode, char value);
void menuInsertLast(int totalNode, char value);
void menuPrintList();

singleLinkedList sLL;
bool mainMachine;
int totalNode, pilihan;
char value;
char tujuanNode;

// deskripsi
int main()
{
    cout << "Mesin Single Linked List \n";
    cout << "======================== \n";
    mainMachine = true;
    while(mainMachine == true)
    {
        totalNode = sLL.totalNode();
        menuTampilan();
        cin >> pilihan;
        switch (pilihan)
        {
            case 1: // insert Head
                menuInserFirst(totalNode, value);
                break;

            case 2: // insert after
                menuInsertAfter(totalNode, value);
                break;
            
            case 3: // insert last
                menuInsertLast(totalNode, value);
                break;

            case 7: // printlist
                menuPrintList();
                break;

            case 0:
                cout << "Keluar Program \n";
                mainMachine = false;
            default:
                break;
        }
    }

    mainMachine == false;
    return 0;
}

// function

void menuTampilan()
{
    cout << "Menu Single Linked List" << endl;
    cout << "--------------------------" << endl;
    cout << "1. Insert Head"    << endl;
    cout << "2. Insert After"   << endl;
    cout << "3. Insert Last"    << endl;
    cout << "4. Delete Head"    << endl;
    cout << "5. Delete After"   << endl;
    cout << "6. Delete Last"    << endl;
    cout << "7. Print List"     << endl;
    cout << "0. Exit"           << endl << endl;
    cout << "Pilih (contoh 1): ";
}

void ketentuanInsert(int totalNode)
{
    if(totalNode >= 4)
    {
        cout << "kakehan woi \n";
        cout << endl;
    }
}

void ketentuanDelete(int totalNode)
{
    if(totalNode == 0)
    {
        cout << "gaono seng iso dihapus le";
    }
    cout << endl;
}

void menuInserFirst(int totalNode, char value)
{
    ketentuanInsert(totalNode);
    cout << "Masukkan Data (character) : ";
    cin >> value;
    sLL.insertHead(value);
}

void menuInsertAfter(int totalNode, char value)
{
    ketentuanInsert(totalNode);
    if(totalNode > 0)
    {
        sLL.printList();
        cout << endl;
        cout << "Mau menambahkan setelah Node dengan data apa? \n";
        cout << "input : ";
        cin >> tujuanNode;
        cout << "Masukkan data yang akan ditambahkan : ";
        cin >> value;
        sLL.insertAfter(tujuanNode, value);
        cout << endl;
    }
    else
    {
        cout << "belum ada data apa apa, silahkan insert First/last terlebih dahulu \n \n";
    }
}

void menuInsertLast(int totalNode, char value)
{
    ketentuanInsert(totalNode);
    cout << "Masukkan Data (character) : ";
    cin >> value;
    sLL.insertLast(value);
}

void menuPrintList()
{
    sLL.printList();
    cout << endl;
}
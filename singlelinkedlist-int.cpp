// judul : mesin gerbong kereta pointer single linked list
// Farros A11.2024.15694
// 24-04-2025 || Paper Plane Project
// Repo : https://github.com/Elnathz/singlelinkedlist-homemade.git
#include <iostream>
using namespace std;

// kamus
class Node 
{
    private :
        int data;
        Node* next;

    public :
        Node(int value)
        {
            data = value;
            next = nullptr;
        }

        int getData()
        {
            return data;
        }

        Node* getnext()
        {
            return next;
        }

        void setData(int value)
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
            cout << "Isi Linked List \n";
            cout << "'data[currentAddr] -> [nextaddr]'  \n \n";
            cout << "Head : " << head->getData() << "[" << head << "]" << endl;
            cout << "Tail : " << tail->getData() << "[" << tail << "]" << endl << endl;

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
        int total = 0;
        nodePntr current = head;

        while(current != nullptr)
        {
            total++;
            current = current->getnext();
        }

        return total;
    }

    void insertHead(int value)
    {
        nodePntr newNode = new Node(value);
        if(head == nullptr)
        {
            head = tail = newNode;
            cout << "Data berhasil ditambahkan! \n \n";
        }
        else 
        {
            newNode->setNext(head);
            head = newNode;
            cout << "Data berhasil ditambahkan! \n \n";
        }
    }

    void insertAfter(int tujuanNode, int value)
    {
        nodePntr current = head;
        while(current != nullptr)
        {
            if(current->getData() == tujuanNode)
            {
                nodePntr newNode = new Node(value);
                if(current->getnext() == nullptr)
                {
                    tail = newNode;
                }
                newNode->setNext(current->getnext());
                current->setNext(newNode);
                cout << "Data berhasil ditambahkan! \n \n";
                return;
            }
            current = current->getnext();
        }
        if(current == nullptr)
        {
            cout << "Tujuan data node tidak ada, tolong masukkan yang benar!" << endl << endl;
        }
    }

    void insertLast(int value)
    {
        nodePntr current = head;
        nodePntr newNode = new Node(value);

        if(head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->setNext(newNode);
            tail = newNode;
        }
        cout << "Node berhasil ditambahkan!" << endl;
    }

    void deleteHead()
    {
        nodePntr pembuangan = head;
        if(head == tail)
        {
            head = tail = nullptr;
        }
        else
        {
            head = head->getnext();
        }
        delete pembuangan;
        cout << "Node berhasil dihapus!" << endl << endl;
    }

    void deleteAfter(int tujuanNode)
    {
        nodePntr current = head;
        while(current != nullptr)
        {
            if(current->getData() == tujuanNode)
            {
                nodePntr pembuangan = current->getnext();
                current->setNext(pembuangan->getnext());
                if(pembuangan == nullptr)
                {
                    cout << "Tidak ada node setelah \"" << tujuanNode << "\", penghapusan Node gagal!" << endl << endl;
                    return;
                }
                else if(pembuangan == tail)
                {
                    tail = current;
                }
                delete pembuangan;
                cout << "Node setelah \"" << tujuanNode << "\" berhasil dihapus!" << endl;
                cout << "Isi Node Setelah dihapus: " << endl;
                return;
            }
            current = current->getnext();
            if(current == nullptr)
            {
                cout << "Node dengan data \"" << tujuanNode << "\" tidak ditemukan!" << endl << endl;
                return;
            }
        }
    }

    void DeleteLast()
    {
        if(head == tail)
        {
            delete head;
            head = tail = nullptr;
            cout << "Node berhasil dihapus!" << endl;
        }
        else
        {
            nodePntr current = head;
            while(current->getnext() != tail)
            {
                current = current->getnext();
            }
            delete tail;
            tail = current;
            current->setNext(nullptr);
            cout << "Node terakhir berhasil dihapus!" << endl;
        }
    }
};

// function
int ketentuanGeneral(int totalNode, int pilihan);

// procedure
void menuTampilan();
void menuInsertFirst(int value);
void menuInsertAfter(int value, int tujuanNode);
void menuInsertLast(int value);
void menuDeleteHead();
void menuDeleteAfter(int tujuanNode);
void menuDeleteLast();
void menuPrintList();

// variable
singleLinkedList sLL;

bool mainMachine;
int totalNode, pilihan;
int value;
int tujuanNode;

// deskripsi
int main()
{
    cout << "Mesin Single Linked List \n";
    mainMachine = true;
    while(mainMachine == true)
    {
        totalNode = sLL.totalNode();
        menuTampilan();
        pilihan = ketentuanGeneral(totalNode, pilihan);
        switch (pilihan)
        {
            case 1: // insert Head
                menuInsertFirst(value);
                break;
    
            case 2: // insert after
                menuInsertAfter(value, tujuanNode);
                break;
                
            case 3: // insert tail
                menuInsertLast(value);
                break;

            case 4: // delete head
                menuDeleteHead();
                break;
                
            case 5: // delete after
                menuDeleteAfter(tujuanNode);
                break;
            
            case 6: // delete last
                menuDeleteLast();
                break;
                
            case 7: // printlist
                menuPrintList();
                break;

            case 0:
                cout << "Terima Kasih Telah Mencoba! \n";
                mainMachine = false;
                break;

            default:
                break;
        }
    }

    mainMachine == false;
    return 0;
}

// function
void menuPrintList()
{
    sLL.printList();
    cout << endl;
}

void menuTampilan()
{
    cout << "==========================" << endl;
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
    cin >> pilihan;
    cout << "========================== \n";
}

int ketentuanGeneral(int totalNode, int pilihan)
{
    if(totalNode >= 4 && pilihan < 4 && pilihan > 0)
    {
        cout << "Max untuk panjang node adalah 4!             " << endl;
        cout << "Silahkan pilih menu Delete, Print, atau Exit." << endl << endl;
        return -1;
    }
    else if(totalNode <= 0 && pilihan > 3 && pilihan < 7)
    {
        cout << "Tidak ada node yang bisa dihapus!" << endl;
        cout << "Silahkan pilih menu Insert, Print, atau Exit." << endl << endl;
        return -1;
    }
    else if(totalNode == 0 && pilihan == 2)
    {
        cout << "Tolong isi dulu untuk node awalnya menggunakan Insert Head/Insert Last!" << endl << endl;
        return -1;
    }
    else if(pilihan < 0 || pilihan > 7)
    {
        cout << "Tidak ada pilihan menu " << pilihan << "!" << endl;
        cout << "Tolong pilih menu antara 0-7 !" << endl << endl;
        return -1;
    }
    else 
    {
        return pilihan;
    }
}

void menuInsertFirst(int value)
{
    cout << "Masukkan Data (Angka) : ";
    cin >> value;
    sLL.insertHead(value);
}

void menuInsertAfter(int value, int tujuanNode)
{
    sLL.printList();
    cout << endl;
    cout << "Mau menambahkan setelah Node dengan data apa? \n";
    cout << "input : ";
    cin >> tujuanNode;
    cout << "Masukkan data yang akan ditambahkan : ";
    cin >> value;
    sLL.insertAfter(tujuanNode, value);
}

void menuInsertLast(int value)
{
    cout << "Masukkan Data (Angka) : ";
    cin >> value;
    sLL.insertLast(value);
    cout << endl;
}

void menuDeleteHead()
{
    sLL.deleteHead();
    cout << "Setelah dihapus : \n";
    menuPrintList();
}

void menuDeleteAfter(int tujuanNode)
{
    sLL.printList();
    cout << endl;
    cout << "Mau menghapus setelah Node dengan data apa? \n";
    cout << "input : ";
    cin >> tujuanNode;
    sLL.deleteAfter(tujuanNode);
    
    sLL.printList();
}

void menuDeleteLast()
{
    sLL.DeleteLast();
    sLL.printList();
}

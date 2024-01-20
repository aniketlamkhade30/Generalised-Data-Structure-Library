// SinglyLL
// SinglyCL
// DoublyLL
// DoublyCL

#include <iostream>
using namespace std;
#pragma pack(1)

template <class T>

struct nodeS
{
    T data;
    struct nodeS *next;
};

template <class T>
struct nodeD
{
    T data;
    struct nodeD *next;
    struct nodeD *prev;
};

template <class T>

struct nodeSQ
{
    T data;
    struct nodeSQ *next;
};

template <class T>
class SinglyLL
{
public:
    struct nodeS<T> *Head; // Characteristics
    int iCount;

    SinglyLL(); // Behaviours

    void InsertFirst(T no);
    void InsertLast(T no);
    void InsertAtPosition(T no, int ipos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPosition(int ipos);

    void Display();
};

template <class T>
SinglyLL<T>::SinglyLL()
{
    Head = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL<T>::InsertFirst(T no)
{
    // Step 1 Allocate the memory for Node
    struct nodeS<T> *newn = new struct nodeS<T>;

    // Step 2 Initialise Node
    newn->data = no;
    newn->next = NULL;

    // Step 3 Check if LL is empty or not
    if (Head == NULL) // if(iCount == 0)
    {
        Head = newn;
        iCount++;
    }
    else // If LL contains atleast one node
    {
        newn->next = Head;
        Head = newn;
        iCount++;
    }
}

template <class T>
void SinglyLL<T>::InsertLast(T no)
{
    // Step 1 Allocate the memory for Node
    struct nodeS<T> *newn = new struct nodeS<T>;

    // Step 2 Initialise Node
    newn->data = no;
    newn->next = NULL;

    // Step 3 Check if LL is empty or not
    if (Head == NULL) // if(iCount == 0)
    {
        Head = newn;
        iCount++;
    }
    else // If LL contains atleast one node
    {
        struct nodeS<T> *temp = Head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        iCount++;
    }
}

template <class T>

void SinglyLL<T>::InsertAtPosition(T no, int ipos)
{
    if ((ipos < 1) || (ipos > iCount + 1))
    {
        cout << "Invalid Position\n";
        return;
    }
    else if (ipos == 1)
    {
        InsertFirst(no);
    }
    else if (ipos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        struct nodeS<T> *newn = new struct nodeS<T>;

        newn->data = no;
        newn->next = NULL;

        struct nodeS<T> *temp = Head;
        for (int iCnt = 1; iCnt < (ipos - 1); iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}
template <class T>

void SinglyLL<T>::DeleteFirst()
{
    if (Head == NULL) // if(Count ==0)
    {
        return;
    }
    else if (Head->next == NULL) // else if (iCount == 1)
    {
        delete Head;
        Head = NULL;
        iCount--;
    }
    else
    {
        struct nodeS<T> *temp = Head;
        Head = Head->next;
        delete temp;
        iCount--;
    }
}
template <class T>
void SinglyLL<T>::DeleteLast()
{
    if (Head == NULL) // if(Count ==0)
    {
        return;
    }
    else if (Head->next == NULL) // else if (iCount == 1)
    {
        delete Head;
        Head = NULL;
        iCount--;
    }
    else
    {
        struct nodeS<T> *temp = Head;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;

        iCount--;
    }
}
template <class T>
void SinglyLL<T>::DeleteAtPosition(int ipos)
{
    if ((ipos < 1) || (ipos > iCount))
    {
        cout << "Invalid Position\n";
        return;
    }
    else if (ipos == 1)
    {
        DeleteFirst();
    }
    else if (ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        struct nodeS<T> *temp1 = Head;

        for (int iCnt = 1; iCnt < (ipos - 1); iCnt++)
        {
            temp1 = temp1->next;
        }

        struct nodeS<T> *temp2 = temp1->next;

        temp1->next = temp2->next;

        delete temp2;

        iCount--;
    }
}
template <class T>
void SinglyLL<T>::Display()
{
    cout << "Elements of linked list are :\n";
    struct nodeS<T> *temp = Head;

    while (temp != NULL)
    {
        cout << "| " << temp->data << " |->";
        temp = temp->next;
    }
    cout << "NULL\n";
}

///////////////////////////////////////////////////////////////////////////////////
template <class T>

class DoublyLL
{
public:
    struct nodeD<T> *Head;
    int iCount;

    DoublyLL();

    void InsertFirst(T no);
    void InsertLast(T no);
    void InsertAtPosition(T no, int ipos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPosition(int ipos);

    void Display();
};

template <class T>
DoublyLL<T>::DoublyLL()
{
    iCount = 0;
    Head = NULL;
}
template <class T>
void DoublyLL<T>::InsertFirst(T no)
{
    struct nodeD<T> *newn = new struct nodeD<T>; // Allocate the memory

    newn->data = no; // Initialise Node
    newn->next = NULL;
    newn->prev = NULL;

    if (Head == NULL)
    {
        Head = newn;
        iCount++;
    }
    else
    {
        newn->next = Head;
        (Head)->prev = newn;

        Head = newn;
        iCount++;
    }
}
template <class T>
void DoublyLL<T>::InsertLast(T no)
{
    struct nodeD<T> *newn = new struct nodeD<T>; // Allocate the memory
    struct nodeD<T> *temp = Head;

    newn->data = no; // Initialise Node
    newn->next = NULL;
    newn->prev = NULL;

    if (Head == NULL)
    {
        Head = newn;
        iCount++;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        temp->prev = temp;
        iCount++;
    }
}

template <class T>
void DoublyLL<T>::InsertAtPosition(T no, int ipos)
{
    struct nodeD<T> *newn = new struct nodeD<T>;
    struct nodeD<T> *temp = Head;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if ((ipos < 1) || (ipos > iCount + 1))
    {
        cout << "Invalid Position\n";
    }
    else if (ipos == 1)
    {
        InsertFirst(no);
    }
    else if (ipos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        for (int i = 1; i < ipos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        newn->prev = temp;
        temp->next->prev = newn;
        temp->next = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>::DeleteAtPosition(int ipos)
{
    struct nodeD<T> *temp1 = Head;
    struct nodeD<T> *temp2 = NULL;

    if ((ipos < 1) || (ipos > iCount + 1))
    {
        cout << "Invalid Position\n";
    }
    else if (ipos == 1)
    {
        DeleteFirst();
    }
    else if (ipos == iCount + 1)
    {
        DeleteLast();
    }
    else
    {
        for (int i = 1; i < ipos - 1; i++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        temp2->next->prev = temp1;
        delete temp2;
    }
    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    if (Head == NULL)
    {
        return;
    }
    else if (Head->next == NULL)
    {
        Head = NULL;
        delete Head;
        iCount--;
    }
    else
    {
        struct nodeD<T> *temp = Head;
        Head = Head->next;
        Head->prev = NULL;
        delete temp;
        iCount--;
    }
}
template <class T>
void DoublyLL<T>::DeleteLast()
{
    if (Head == NULL)
    {
        return;
    }
    else if (Head->next == NULL)
    {
        Head = NULL;
        delete Head;
        iCount--;
    }
    else
    {
        struct nodeD<T> *temp = Head;
        struct nodeD<T> *temp1;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        temp1 = temp->next;
        temp->next = NULL;
        delete temp1;

        iCount--;
    }
}
template <class T>
void DoublyLL<T>::Display()
{
    cout << "\nElements of Linked list are\n";
    struct nodeD<T> *temp = Head;

    cout << "NULL<=> ";

    while (temp != NULL)
    {
        cout << "| " << temp->data << " |<=>";
        temp = temp->next;
    }
    cout << "NULL \n";
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>

class SinglyCL
{
public:
    struct nodeS<T> *Head;
    struct nodeS<T> *Tail;

    SinglyCL();

    void InsertFirst(T no);
    void InsertLast(T no);
    void InsertAtPos(T no, int ipos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int ipos);

    void Display();
    int Count();
};

template <class T>
SinglyCL<T>::SinglyCL()
{
    Head = NULL;
    Tail = NULL;
}

template <class T>
void SinglyCL<T>::InsertFirst(T no)
{
    struct nodeS<T> *newn = new struct nodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if ((Head == NULL) && (Tail == NULL)) // if Empty Linked List
    {
        Head = Tail = newn;
        (Tail)->next = Head;
    }
    else // Linked List Contains atleast one node
    {
        newn->next = Head;
        Head = newn;
        (Tail)->next = Head;
    }
}

template <class T>
void SinglyCL<T>::InsertLast(T no)
{
    struct nodeS<T> *newn = new struct nodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if ((Head == NULL) && (Tail == NULL)) // if Empty Linked List
    {
        Head = Tail = newn;
        (Tail)->next = Head;
    }
    else // Linked List Contains atleast one node
    {
        (Tail)->next = newn;
        Tail = newn;
        (Tail)->next = Head;
    }
}

template <class T>

void SinglyCL<T>::InsertAtPos(T no, int ipos)
{
    struct nodeS<T> *newn = NULL;
    struct nodeS<T> *temp = Head;
    int iNodeCnt = 0, iCnt = 0;
    iNodeCnt = Count();

    if ((ipos < 1) || (ipos > iNodeCnt + 1))
    {
        cout << "Invalid Position";
        return;
    }
    if (ipos == 1)
    {
        InsertFirst(no);
    }
    else if (ipos == iNodeCnt + 1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct nodeS<T>;

        newn->data = no;
        newn->next = NULL;

        for (iCnt = 1; iCnt < (ipos - 1); iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

template <class T>

void SinglyCL<T>::DeleteFirst()
{
    struct nodeS<T> *temp = Head;
    if (Head == NULL && Tail == NULL) // IF LL is Empty
    {
        return;
    }
    else if (Head == Tail) // LL contains single node
    {
        delete (Head);
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Head = (Head)->next;
        delete (temp);
        (Tail)->next = Head;
    }
}

template <class T>
void SinglyCL<T>::DeleteLast()
{
    struct nodeS<T> *temp = Head;
    if (Head == NULL && Tail == NULL) // IF LL is Empty
    {
        return;
    }
    else if (Head == Tail) // LL contains single node
    {
        delete (Head);
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        while (temp->next != Tail)
        {
            temp = temp->next;
        }
        delete (temp->next); // free(*Last)
        Tail = temp;
        (Tail)->next = Head;
    }
}

template <class T>

void SinglyCL<T>::DeleteAtPos(int ipos)
{
    struct nodeS<T> *temp2 = NULL;
    struct nodeS<T> *temp1 = Head;
    int iNodeCnt = 0, iCnt = 0;
    iNodeCnt = Count();

    if ((ipos < 1) || (ipos > iNodeCnt))
    {
        cout << "Invalid Position";
        return;
    }
    if (ipos == 1)
    {
        DeleteFirst();
    }
    else if (ipos == iNodeCnt + 1)
    {
        DeleteLast();
    }
    else
    {

        for (iCnt = 1; iCnt < (ipos - 1); iCnt++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete (temp2);
    }
}

template <class T>

void SinglyCL<T>::Display()
{
    struct nodeS<T> *temp = Head;
    cout << "Elemets of Linked List are :\n";
    do
    {
        cout << "| " << temp->data << " |->";
        temp = temp->next;
    } while (temp != Tail->next);
    printf("\n");
}

template <class T>

int SinglyCL<T>::Count()
{
    struct nodeS<T> *temp = Head;
    int iCnt = 0;
    do
    {
        iCnt++;
        temp = temp->next;
    } while (temp != Tail->next);
    return iCnt;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>

class DoublyCL
{
public:
    struct nodeD<T> *First;
    struct nodeD<T> *Last;
    DoublyCL();
    void InsertFirst(T no);
    void InsertLast(T no);
    void InsertAtPos(T no, int ipos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int ipos);

    void Display();
    int Count();
};

template <class T>

DoublyCL<T>::DoublyCL() // Default Constructor
{
    First = NULL;
    Last = NULL;
}

template <class T>
void DoublyCL<T>::InsertFirst(T no)
{
    struct nodeD<T> *newn = new struct nodeD<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if ((First == NULL) && (Last == NULL)) // LL is Empty
    {
        First = newn;
        Last = newn;
    }
    else // LL contains 1 node
    {
        newn->next = First;
        (First)->prev = newn;
        First = newn;
    }
    (First)->prev = Last;
    (Last)->next = First;
}

template <class T>

void DoublyCL<T>::InsertLast(T no)
{
    struct nodeD<T> *newn = new struct nodeD<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if ((First == NULL) && (Last == NULL)) // LL is Empty
    {
        First = newn;
        Last = newn;
    }
    else // LL contains 1 node
    {
        (Last)->next = newn;
        newn->prev = Last;
        Last = newn;
    }
    (First)->prev = Last;
    (Last)->next = First;
}

template <class T>
void DoublyCL<T>::Display()
{
    struct nodeD<T> *temp = First;
    struct nodeD<T> *temp1 = Last;
    if ((temp == NULL) && temp1 == NULL)
    {
        cout << "Linked List is Empty\n";
        return;
    }
    cout << "\nElements of Linked List are :\n";
    do
    {
        cout << " | " << temp->data << " | <=> ";
        temp = temp->next;

    } while (temp != temp1->next);
}

template <class T>
int DoublyCL<T>::Count()
{
    struct nodeD<T> *temp = First;
    struct nodeD<T> *temp1 = Last;
    int iCnt = 0;
    if ((temp == NULL) && temp1 == NULL)
    {
        return iCnt;
    }
    do
    {
        iCnt++;
        temp = temp->next;
    } while (temp != temp1->next);

    return iCnt;
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if ((First == NULL) && (Last == NULL)) // Empty LL
    {
        return;
    }
    else if (First == Last) // Single Node
    {
        delete (First);
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = (First)->next;
        delete ((Last)->next); // delete(First)->prev;
        (First)->prev = Last;
        (Last)->next = First;
    }
}

template <class T>
void DoublyCL<T>::DeleteLast()
{
    if ((First == NULL) && (Last == NULL)) // Empty LL
    {
        return;
    }
    else if (First == Last) // Single Node
    {
        delete (First);
        First = NULL;
        Last = NULL;
    }
    else // multiple node
    {
        Last = (Last)->prev;
        delete ((First)->prev); // delete(Last -> next);
        (First)->prev = Last;
        (Last)->next = First;
    }
}

template <class T>
void DoublyCL<T>::InsertAtPos(T no, int ipos)
{
    int iNodeCnt = Count();
    struct nodeD<T> *newn = new struct nodeD<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    struct node *temp = NULL;

    if ((ipos < 1) || (ipos > iNodeCnt + 1))
    {
        cout << "Invalid Position\n";
    }
    else if (ipos == 1)
    {
        InsertFirst(no);
    }
    else if (ipos == (iNodeCnt + 1))
    {
        InsertLast(no);
    }
    else
    {
        temp = First;
        int iCnt = 0;
        for (iCnt = 1; iCnt < (ipos - 1); iCnt++)
            ;
        {
            temp = temp->next;
        }
    }
    newn->next = temp->next;
    temp->next->prev = newn;

    temp->next = newn;
    newn->prev = temp;
}

template <class T>

void DoublyCL<T>::DeleteAtPos(int ipos)
{
    int iNodeCnt = Count();

    struct nodeD<T> *temp = NULL;

    if ((ipos < 1) || (ipos > iNodeCnt + 1))
    {
        cout << "Invalid Position\n";
    }
    else if (ipos == 1)
    {
        DeleteFirst();
    }
    else if (ipos == iNodeCnt + 1)
    {
        DeleteLast();
    }
    else
    {
        temp = First;
        for (int iCnt = 1; iCnt < (ipos - 1); iCnt++)
            ;
        {
            temp = temp->next;
        }
    }
    temp->next = temp->next->next;
    delete (temp->next->prev);
    temp->next->prev = temp;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class Stack
{
public:
    struct nodeSQ<T> *First;
    int iCount;

    Stack();

    bool IsStackEmpty();
    void Push(T no); // Insert
    T Pop();         // Delete
    void Display();
};

template <class T>
Stack<T>::Stack()
{
    First = NULL;
    iCount = 0;
}
template <class T>
bool Stack<T>::IsStackEmpty()
{
    if (iCount == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
void Stack<T>::Push(T no) // InsertFirst
{
    struct nodeSQ<T> *newn = new nodeSQ<T>;
    newn->data = no;
    newn->next = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;

    cout << no << " gets pushed in the stack successfully\n";
}
template <class T>

T Stack<T>::Pop()
{
    if (First == NULL)
    {
        cout << "unable to pop the element as stack is Empty..\n";
        return -1;
    }
    else
    {
        T value = First->data;
        struct nodeSQ<T> *temp = First;

        First = First->next;
        delete temp;

        iCount--;

        return value;
    }
}
template <class T>

void Stack<T>::Display()
{
    if (First == NULL)
    {
        cout << "stack is empty..";
    }
    else
    {
        cout << "elements of stack are :\n";

        struct nodeSQ<T> *temp = First;
        while (temp != NULL)
        {
            cout << "\t" << temp->data << "\n";
            temp = temp->next;
        }
        cout << "\tNULL\n";
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class Queue
{
public:
    struct nodeSQ<T> *First;
    int iCount;

    Queue();

    bool IsQueueEmpty();
    void EnQueue(T no); // Insert
    T DeQueue();        // Delete
    void Display();
};
template <class T>
Queue<T>::Queue()
{
    First = NULL;
    iCount = 0;
}
template <class T>
bool Queue<T>::IsQueueEmpty()
{
    if (iCount == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
template <class T>
void Queue<T>::EnQueue(T no) // InsertFirst
{
    struct nodeSQ<T> *newn = new nodeSQ<T>;
    newn->data = no;
    newn->next = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        struct nodeSQ<T> *temp = First;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;

    cout << no << " gets EnQueued in the Queue successfully\n";
}
template <class T>
T Queue<T>::DeQueue()
{
    if (First == NULL)
    {
        cout << "unable to DeQueue the element as Queue is Empty..\n";
        return (T)-1;
    }
    else
    {
        int value = First->data;
        struct nodeSQ<T> *temp = First;

        First = First->next;
        delete temp;

        iCount--;

        return (T)value;
    }
}
template <class T>
void Queue<T>::Display()
{
    if (First == NULL)
    {
        cout << "Queue is empty..";
    }
    else
    {
        cout << "elements of Queue are :\n\n";

        struct nodeSQ<T> *temp = First;

        while (temp != NULL)
        {
            cout << "\t |" << temp->data << "| \n";
            temp = temp->next;
        }
        cout << "\t| NULL |\n";
    }
}
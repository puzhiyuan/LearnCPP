#include <iostream>

struct LinkList
{
    int data;
    struct LinkList* next;
};



int main(int argc, char const *argv[])
{
    LinkList *temp = nullptr, *head = nullptr, *tail = nullptr;
    temp = new LinkList({20, nullptr});
    head = temp;
    tail = temp;

    for (size_t i = 0; i < 5; i++)
    {
        temp = new LinkList({21+(int)i, nullptr});
        tail->next = temp;
        tail = tail->next;
    }
    temp = head;
    int i = 0;
    while (temp->next)
    {
        std::cout << "Node " << i << ": " << temp << "\t" << temp->data << std::endl;
        temp = temp->next;
        i++;
    }
    return 0;
}

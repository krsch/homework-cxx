#include <memory>

struct ListElement {
    int value;
    std::shared_ptr<ListElement> next;
    std::weak_ptr<ListElement> prev;
    ListElement(int v) : value(v) {}
};

struct DoubleQueue {
    std::shared_ptr<ListElement> first;
    std::shared_ptr<ListElement> last;

    DoubleQueue() {};

    bool isEmpty() const;

    int popFirst();

    int popLast();

    void pushFirst(int value);

    void pushLast(int value);

    void clear();
};
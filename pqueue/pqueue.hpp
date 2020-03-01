#include <vector>
#include <string>
#include <list>

struct pqueue {
    // Можете изменить следующую строку
    using handle = std::list<size_t>::iterator;

    handle insert(int priority, std::string const& name);
    void erase(handle it);
    void update_priority(handle it, int new_priority);
    std::string extract_min();
    std::string const& get(handle it) const;
    int get_priority(handle it) const;
    size_t size() const;

    // Можете изменить последующие строки
    struct heap_element {
        int priority;
        handle iter;
        std::string payload;
    };
    std::vector<heap_element> heap; // Куча, в которой хранятся строки и итераторы
    std::list<size_t> heap_positions; // Список положений строк в куче. Необходимо для быстрого удаления элементов
};


#include "TextDocument.h" 

#include <atomic>   
#include <iostream> 
#include <stdexcept> 

// Метод генерации уникального идентификатора документа
std::string TextDocument::generateId() {
    static std::atomic<unsigned long long> nextId{ 0 };
    return "doc_" + std::to_string(++nextId);
}

// КОНСТРУКТОР ПО УМОЛЧАНИЮ
TextDocument::TextDocument()
    : id_(generateId()), 
    size_(0),           
    content_(""),       
    previousSizes_(new std::size_t[10]{}),

    historyCount_(0) {
    std::cout << "default constructor\n";
}

// ИНИЦИАЛИЗИРУЮЩИЙ КОНСТРУКТОР
TextDocument::TextDocument(const std::string& content)

    : id_(generateId()),       
    size_(content.size()),
    content_(content),   
    previousSizes_(new std::size_t[10]{}),

    historyCount_(0) {    

    std::cout << "initialization constructor\n";
}

// КОНСТРУКТОР КОПИРОВАНИЯ
TextDocument::TextDocument(const TextDocument& other)

    : id_(generateId()),         
    size_(other.size_),        
    content_(other.content_),
    previousSizes_(new std::size_t[10]{}),
    historyCount_(other.historyCount_) {

    for (std::size_t i = 0; i < 10; ++i) {

        previousSizes_[i] = other.previousSizes_[i];
    }

    std::cout << "copy constructor\n";
}

// ОПЕРАТОР ПРИСВАИВАНИЯ
TextDocument& TextDocument::operator=(const TextDocument& other) {

    std::cout << "assignment operator\n";

    // this - указатель на текущий объект
    // &other - адрес исходного объекта
    // Проверяем, что объект не присваивается самому себе
    if (this != &other) {
        content_ = other.content_;
        size_ = other.size_;
        historyCount_ = other.historyCount_;
        for (std::size_t i = 0; i < 10; ++i) {
            previousSizes_[i] = other.previousSizes_[i];
        }
    }

    return *this;
}

// ДЕСТРУКТОР
TextDocument::~TextDocument() {
    delete[] previousSizes_;
}

// СОХРАНЕНИЕ ПРЕДЫДУЩЕГО РАЗМЕРА
// Метод вызывается перед изменением содержимого
void TextDocument::rememberSize() {
    if (historyCount_ < 10) {
        previousSizes_[historyCount_++] = size_;

    }
    else {
        for (std::size_t i = 1; i < 10; ++i) {
            previousSizes_[i - 1] = previousSizes_[i];
        }
        previousSizes_[9] = size_;
    }
}

// ГЕТТЕР ID
const std::string& TextDocument::getId() const {
    return id_;
}

// ГЕТТЕР ТЕКУЩЕГО РАЗМЕРА
std::size_t TextDocument::getSize() const {
    return size_;
}

// ГЕТТЕР СОДЕРЖИМОГО
const std::string& TextDocument::getContent() const {
    return content_;
}

// ГЕТТЕР КОЛИЧЕСТВА ЗАПИСЕЙ ИСТОРИИ
std::size_t TextDocument::getHistoryCount() const {
    return historyCount_;
}

// ПОЛУЧЕНИЕ ПРЕДЫДУЩЕГО РАЗМЕРА ПО ИНДЕКСУ
std::size_t TextDocument::getPreviousSize(std::size_t index) const {
    // Проверяем, что индекс находится в заполненной
    // части массива истории
    if (index >= historyCount_) {

        // Если индекса нет, выбрасываем исключение
        // out_of_range означает выход за границы диапазона
        throw std::out_of_range("history index is out of range");
    }
    return previousSizes_[index];
}

// СЕТТЕР СОДЕРЖИМОГО
// Изменяет текст, сохраняя историю размеров
void TextDocument::setContent(const std::string& content) {
    std::string updated(content);
    rememberSize();
    content_.swap(updated);
    size_ = content_.size();
}

// ВЫВОД ИНФОРМАЦИИ О ДОКУМЕНТЕ
void TextDocument::print() const {
    std::cout << "ID: " << id_
        << "\nSize: " << size_
        << "\nContent: " << content_
        << "\nPrevious sizes:";

    // Проходим только по заполненным элементам истории
    for (std::size_t i = 0; i < historyCount_; ++i) {
        std::cout << ' ' << previousSizes_[i];
    }

    std::cout << "\n\n";
}

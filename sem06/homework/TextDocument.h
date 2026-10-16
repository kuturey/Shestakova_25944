#ifndef TEXT_DOCUMENT_H 
#define TEXT_DOCUMENT_H 

#include <cstddef> 
#include <string>  

class TextDocument {

private:
    // Уникальный ID документа
    const std::string id_;
    // Текущий размер содержимого документа
    std::size_t size_;
    std::string content_;
    // Указатель на динамический массив из 10 предыдущих размеров
    std::size_t* previousSizes_;
    // Количество заполненных элементов истории (от 0 до 10)
    std::size_t historyCount_;

    // метод для генерации уникального ID
    static std::string generateId();

    // Сохраняет текущий размер в историю перед изменением текста
    void rememberSize();

public:
    TextDocument();

    // Создает документ с переданным содержимым
    // explicit запрещает неявное преобразование строки в документ
    explicit TextDocument(const std::string& content);

    // Создает НОВЫЙ объект на основе существующего
    // other исходный документ, данные которого копируются
    TextDocument(const TextDocument& other);

    // Копирует данные в УЖЕ СУЩЕСТВУЮЩИЙ объект
    // TextDocument& возвращает ссылку на текущий объект
    TextDocument& operator=(const TextDocument& other);

    // Деструктор
    // Освобождает память динамического массива через delete[]
    ~TextDocument();

    // ГЕТТЕРЫ методы для получения значений закрытых полей

    // Возвращает ID документа по константной ссылке
    // const после () метод не изменяет объект
    const std::string& getId() const;

    std::size_t getSize() const;
    const std::string& getContent() const;
    std::size_t getHistoryCount() const;

    // Возвращает предыдущий размер по индексу
    // index номер элемента истории, начиная с 0
    std::size_t getPreviousSize(std::size_t index) const;

    // СЕТТЕР метод изменения содержимого
    // Сохраняет старый размер в историю
    // Обновляет текст и пересчитывает текущий размер
    void setContent(const std::string& content);

    // Выводит ID, размер, содержимое и историю в консоль
    // const метод не изменяет состояние документа
    void print() const;

};

#endif

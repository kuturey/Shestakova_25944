
#include "TextDocument.h"
#include <gtest/gtest.h>
#include <string>
#include <type_traits>
#include <stdexcept>

// Проверка конструктора по умолчанию
TEST(TextDocumentTest, DefaultConstructor) {
    TextDocument doc;

    EXPECT_FALSE(doc.getId().empty());
    EXPECT_EQ(doc.getSize(), 0u);
    EXPECT_TRUE(doc.getContent().empty());
    EXPECT_EQ(doc.getHistoryCount(), 0u);
}

// Проверка инициализирующего конструктора
TEST(TextDocumentTest, InitializationConstructor) {
    TextDocument doc("abc");

    EXPECT_EQ(doc.getSize(), 3u);
    EXPECT_EQ(doc.getContent(), "abc");
}

// Проверка уникальности и неизменяемости ID
TEST(TextDocumentTest, UniqueUnchangeableId) {
    TextDocument a;
    TextDocument b("text");
    TextDocument c(a);

    EXPECT_NE(a.getId(), b.getId());
    EXPECT_NE(a.getId(), c.getId());
    EXPECT_NE(b.getId(), c.getId());

    // Проверяем, что ID нельзя изменить через геттер
    EXPECT_FALSE((std::is_assignable<
        decltype(a.getId()),
        std::string
    >::value));
}

// Проверка сеттера и сохранения инварианта
TEST(TextDocumentTest, SetterAndInvariant) {
    TextDocument doc("abcd");
    doc.setContent("");

    EXPECT_EQ(doc.getSize(), 0u);
    EXPECT_EQ(doc.getContent(), "");
    EXPECT_EQ(doc.getHistoryCount(), 1u);
    EXPECT_EQ(doc.getPreviousSize(0), 4u);
}

// Проверка хранения последних 10 размеров
TEST(TextDocumentTest, LastTenPreviousSizes) {
    TextDocument doc;

    for (int i = 1; i <= 12; ++i) {
        doc.setContent(
            std::string(static_cast<std::size_t>(i), 'x')
        );
    }

    EXPECT_EQ(doc.getSize(), 12u);
    EXPECT_EQ(doc.getHistoryCount(), 10u);

    for (std::size_t i = 0; i < 10; ++i) {
        EXPECT_EQ(doc.getPreviousSize(i), i + 2);
    }

    // Проверка выхода за границы истории
    EXPECT_THROW(
        doc.getPreviousSize(10),
        std::out_of_range
    );
}

// Проверка конструктора копирования
TEST(TextDocumentTest, CopyConstructorMakesIndependentCopy) {
    TextDocument original("abc");
    original.setContent("abcd");

    TextDocument copy(original);

    EXPECT_NE(copy.getId(), original.getId());
    EXPECT_EQ(copy.getContent(), "abcd");
    EXPECT_EQ(copy.getPreviousSize(0), 3u);

    // Изменяем исходный документ
    original.setContent("changed");

    // Копия должна остаться неизменной
    EXPECT_EQ(copy.getContent(), "abcd");
    EXPECT_EQ(copy.getHistoryCount(), 1u);
}

// Проверка оператора присваивания
TEST(TextDocumentTest, AssignmentKeepsTargetIdAndCopiesValues) {
    TextDocument target("x");
    TextDocument source("abc");

    source.setContent("abcd");

    const std::string targetId = target.getId();

    TextDocument& returned = (target = source);

    // Оператор должен вернуть ссылку на целевой объект
    EXPECT_EQ(&returned, &target);

    // ID целевого объекта не должен измениться
    EXPECT_EQ(target.getId(), targetId);
    EXPECT_NE(target.getId(), source.getId());

    // Данные должны скопироваться
    EXPECT_EQ(target.getContent(), "abcd");
    EXPECT_EQ(target.getPreviousSize(0), 3u);

    // Изменение исходного объекта не влияет на target
    source.setContent("different");
    EXPECT_EQ(target.getContent(), "abcd");
}

// Проверка присваивания объекта самому себе
TEST(TextDocumentTest, SelfAssignment) {
    TextDocument doc("abc");
    const std::string id = doc.getId();

    doc = doc;

    EXPECT_EQ(doc.getId(), id);
    EXPECT_EQ(doc.getContent(), "abc");
}

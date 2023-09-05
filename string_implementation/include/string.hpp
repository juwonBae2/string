#pragma once

#include <iostream>

class String
{
public:
    String();
    String(const char *str);
    String(const char *str, size_t length);

    ~String();

    // 복사 생성자: 다른 String 객체를 인수로 받아 새로운 객체를 초기화
    String(const String &str);
    // 이동 생성자: rValue을 인수로 받아 새로운 객체를 초기화
    String(String &&str) noexcept;

    // 복사 대입 연산자: 다른 String 객체의 복사본을 대상 객체에 할당
    String &operator=(const String &str);
    // 이동 대입 연산자: rValue를 인수로 받아 대상 객체에 할당
    String &operator=(String &&str) noexcept;

    bool operator==(const String &str) const;
    bool operator!=(const String &str) const;
    bool operator<(const String &str) const;
    bool operator>(const String &str) const;

    String operator+(const String &str) const;
    String &operator+=(const String &str);

    char &front() const;
    char &back() const;

    String trim() const;
    String erase(size_t start, size_t count) const;
    // TODO: string의 오버로드 된 find 함수 추가 구현
    String find(const String &str) const;

    String substr(size_t start) const;
    String substr(size_t start, size_t count) const;
    bool empty() const;
    void pop_back();
    void push_back(const String &str);
    char &at(size_t index) const;

    // TODO: 추가 함수 구현
    String reserve();
    String resize();
    String cleer();
    String capacity();

    // TODO: friend 삭제
    friend std::ostream &
    operator<<(std::ostream &os, const String &str);

    size_t size() const;

    class Iterator;
    Iterator begin();
    Iterator end();

    // String::size_type 구현
    // String::Npos 구현
    class size_type;
    class Nops;

private:
    char *data_;
    size_t size_;

    void initializeFromString(const char *str);
    void initializeFromOther(const String &other);
};

// std::ostream &operator<<(std::ostream &os, const String &str)
// {
//     if (str.data_ != nullptr)
//     {
//         os << str.data_;
//     }
//     return os;
// }

// Member types

// TODO: 사이트처럼 파일 분리 (https://en.cppreference.com/w/cpp/string)
// TODO: String::iterator 구현
// ex) for( String::iterator sample; sample.begin() < sample.end(); ++sample)
// String::size_type 구현
// String::Npos 구현

class String::size_type
{
};

class String::Nops
{
};

class String::Iterator
{
public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = char;
    using pointer = char *;
    using reference = char &;
    using difference_type = std::ptrdiff_t;

    Iterator(pointer ptr);

    reference operator*() const;
    pointer operator->();
    Iterator &operator++();
    Iterator operator++(int);

    bool operator==(const Iterator &other) const;
    bool operator!=(const Iterator &other) const;

private:
    pointer ptr_;
};

// TODO: stoi, itos 구현
void stoi();
void itos();
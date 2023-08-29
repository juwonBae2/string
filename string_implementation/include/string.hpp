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

    char &front();
    char &back();

    String trim() const;
    String erase(size_t start, size_t count) const;
    String find(const String &str) const;

    friend std::ostream &operator<<(std::ostream &os, const String &str);

    size_t size() const;

    class Iterator;
    Iterator begin();
    Iterator end();

private:
    char *data_;

    void initializeFromString(const char *str);
    void initializeFromOther(const String &Other);
};

// TODO: iterator 구현
// ex) String::iterator sample; sample.begin(), sample.end()
class String::Iterator
{
public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = char;
    using pointer = char *;
    using reference = char &;
    using difference_type = std::ptrdiff_t;

    Iterator(pointer ptr) : ptr_(ptr) {}

    reference operator*() const { return *ptr_; }
    pointer operator->() { return ptr_; }

    Iterator &operator++()
    {
        ++ptr_;
        return *this;
    }

    Iterator operator++(int)
    {
        Iterator temp = *this;
        ++ptr_;
        return temp;
    }

    bool operator==(const Iterator &other) const
    {
        return ptr_ == other.ptr_;
    }

    bool operator!=(const Iterator &other) const
    {
        return ptr_ != other.ptr_;
    }

private:
    pointer ptr_;
};
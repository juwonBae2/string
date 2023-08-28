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

    // TODO: 추가 함수 구현
    String front() const;
    String back() const;
    String trim() const;
    String erase(size_t start, size_t count) const;
    String find(const String &str) const;
    // TODO: namespace iterator 구현
    // ex) String::iterator, String::begin, String::end

    friend std::ostream &operator<<(std::ostream &os, const String &str);

private:
    char *data_;

    size_t size() const;

    void initializeFromString(const char *str);
    void initializeFromOther(const String &Other);
};
#pragma once

#include <iostream>

class String
{
public:
    String();
    String(const char *str);
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
    // string의 시작과 끝의 문자열을 반환해주는 함수
    String front() const;
    String back() const;
    // 공백 제거 함수
    // ex) Hello world => Helloworld
    String trim(const String &str) const;
    // 특정 문자열 제거 할 수 있는 함수
    // https://nomad-learner.github.io/study/2021/02/23/anagram%EB%A7%8C%EB%93%A4%EA%B8%B02.html
    String erase() const;
    // 특정 문자열을 찾을수 있도록 하는 함수
    String find(const String &str) const;
    // TODO: namespace iterator 구현
    // ex) String::iterator, String::begin, String::end

    friend std::ostream &operator<<(std::ostream &os, const String &str);

private:
    char *data_;

    void initializeFromString(const char *str);
    void initializeFromOther(const String &Other);
};
#include "string_implementation.hpp"

String::String() : data(nullptr) {}

String::String(const char *str)
{
    initializeFromString(str);
}

String::~String()
{
    if (this->data != nullptr)
    {
        delete[] this->data;
    }
}

String::String(const String &other)
{
    initializeFromOther(other);
}

String::String(String &&other) noexcept
{
    this->data = other.data;
    other.data = nullptr;
}

String &String::operator=(const String &other)
{
    if (this != &other)
    {
        delete[] data;
        initializeFromOther(other);
    }
    return *this;
}

String &String::operator=(String &&other) noexcept
{
    if (this != &other)
    {
        delete[] data;
        data = other.data;
        other.data = nullptr;
    }
    return *this;
}

bool String::operator==(const String &other) const
{
    return (strcmp(this->data, other.data) == 0);
}

bool String::operator!=(const String &other) const
{
    return !(strcmp(this->data, other.data) == 0);
}

bool String::operator<(const String &other) const
{
    return (strcmp(this->data, other.data) < 0);
}

bool String::operator>(const String &other) const
{
    return (strcmp(this->data, other.data) > 0);
}

String String::operator+(const String &other) const
{
    size_t totalLen = strlen(this->data) + strlen(other.data);
    char *temp = new char[totalLen + 1];
    strcpy(temp, data);
    strcat(temp, other.data);
    String result(temp);
    delete[] temp;
    return result;
}

std::ostream &operator<<(std::ostream &os, const String &str)
{
    if (str.data != nullptr)
    {
        os << str.data;
    }
    return os;
}

void String::initializeFromString(const char *str)
{
    if (str != nullptr)
    {
        this->data = new char[strlen(str) + 1];
        strcpy(data, str);
    }
    else
    {
        this->data = nullptr;
    }
}

void String::initializeFromOther(const String &other)
{
    if (other.data != nullptr)
    {
        this->data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }
    else
    {
        this->data = nullptr;
    }
}

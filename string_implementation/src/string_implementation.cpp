#include "string_implementation.hpp"

String::String() : data(nullptr) {}

String::String(const char *str)
{
    if (str != nullptr)
    {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }
    else
    {
        data = nullptr;
    }
}

String::~String()
{
    delete[] data;
}

String::String(const String &other)
{
    if (other.data != nullptr)
    {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }
    else
    {
        data = nullptr;
    }
}

String::String(String &&other) noexcept
{
    data = other.data;
    other.data = nullptr;
}

String &String::operator=(const String &other)
{
    if (this != &other)
    {
        delete[] data;
        if (other.data != nullptr)
        {
            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
        }
        else
        {
            data = nullptr;
        }
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

bool String::operator<(const String &other) const
{
    return (strcmp(data, other.data) < 0);
}

bool String::operator>(const String &other) const
{
    return (strcmp(data, other.data) > 0);
}

String String::operator+(const String &other) const
{
    size_t totalLen = strlen(data) + strlen(other.data);
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

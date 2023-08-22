#include "string.hpp"

String::String() : data_(nullptr) {}

String::String(const char *str)
{
    initializeFromString(str);
}

String::~String()
{
    if (this->data_ != nullptr)
    {
        delete[] this->data_;
    }
}

String::String(const String &other)
{
    initializeFromOther(other);
}

String::String(String &&other) noexcept
{
    this->data_ = other.data_;
    other.data_ = nullptr;
}

String &String::operator=(const String &other)
{
    if (this != &other)
    {
        delete[] data_;
        initializeFromOther(other);
    }
    return *this;
}

String &String::operator=(String &&other) noexcept
{
    if (this != &other)
    {
        delete[] data_;
        data_ = other.data_;
        other.data_ = nullptr;
    }
    return *this;
}

bool String::operator==(const String &other) const
{
    return (strcmp(this->data_, other.data_) == 0);
}

bool String::operator!=(const String &other) const
{
    return !(strcmp(this->data_, other.data_) == 0);
}

bool String::operator<(const String &other) const
{
    return (strcmp(this->data_, other.data_) < 0);
}

bool String::operator>(const String &other) const
{
    return (strcmp(this->data_, other.data_) > 0);
}

String String::operator+(const String &other) const
{
    size_t totalLen = strlen(this->data_) + strlen(other.data_);
    char *temp = new char[totalLen + 1];
    strcpy(temp, data_);
    strcat(temp, other.data_);
    String result(temp);
    delete[] temp;
    return result;
}

String String::trim() const
{
    return 0;
}

std::ostream &operator<<(std::ostream &os, const String &str)
{
    if (str.data_ != nullptr)
    {
        os << str.data_;
    }
    return os;
}

void String::initializeFromString(const char *str)
{
    if (str != nullptr)
    {
        this->data_ = new char[strlen(str) + 1];
        strcpy(data_, str);
    }
    else
    {
        this->data_ = nullptr;
    }
}

void String::initializeFromOther(const String &other)
{
    if (other.data_ != nullptr)
    {
        this->data_ = new char[strlen(other.data_) + 1];
        strcpy(data_, other.data_);
    }
    else
    {
        this->data_ = nullptr;
    }
}

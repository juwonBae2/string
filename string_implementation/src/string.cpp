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

String::String(const String &str)
{
    initializeFromOther(str);
}

String::String(String &&str) noexcept
{
    this->data_ = str.data_;
    str.data_ = nullptr;
}

String &String::operator=(const String &str)
{
    if (this != &str)
    {
        delete[] data_;
        initializeFromOther(str);
    }
    return *this;
}

String &String::operator=(String &&str) noexcept
{
    if (this != &str)
    {
        delete[] data_;
        data_ = str.data_;
        str.data_ = nullptr;
    }
    return *this;
}

bool String::operator==(const String &str) const
{
    return (strcmp(this->data_, str.data_) == 0);
}

bool String::operator!=(const String &str) const
{
    return !(strcmp(this->data_, str.data_) == 0);
}

bool String::operator<(const String &str) const
{
    return (strcmp(this->data_, str.data_) < 0);
}

bool String::operator>(const String &str) const
{
    return (strcmp(this->data_, str.data_) > 0);
}

String String::operator+(const String &str) const
{
    size_t totalLen = strlen(this->data_) + strlen(str.data_);
    char *temp = new char[totalLen + 1];
    strcpy(temp, data_);
    strcat(temp, str.data_);
    String result(temp);
    delete[] temp;
    return result;
}

String String::front() const
{
    if (data_ != nullptr && data_[0] != '\0')
    {
        char frontChar[2] = {data_[0], '\0'};
        return frontChar;
    }
    return String();
}

String String::back() const
{
    if (data_ != nullptr && data_[0] != '\0')
    {
        size_t sizeLength = strlen(data_);
        char backChar[2] = {data_[sizeLength - 1], '\0'};
        return backChar;
    }
    return String();
}

String String::trim() const
{
    if (data_ == nullptr)
    {
        return String();
    }

    size_t length = strlen(data_);
    size_t newIndex = 0;
    char *trimmedData = new char[length + 1];

    for (size_t i = 0; i < length; ++i)
    {
        if (!isspace(data_[i]))
        {
            trimmedData[newIndex++] = data_[i];
        }
    }

    trimmedData[newIndex] = '\0';

    String trimmedString;
    if (newIndex > 0)
    {
        char *trimmedDataCopy = new char[newIndex + 1];
        strncpy(trimmedDataCopy, trimmedData, newIndex);
        trimmedDataCopy[newIndex] = '\0';
        trimmedString = String(trimmedDataCopy);
        delete[] trimmedDataCopy;

        delete[] trimmedData;
        return trimmedString;
    }
    else
    {
        delete[] trimmedData;
        return trimmedString;
    }
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

void String::initializeFromOther(const String &Other)
{
    if (Other.data_ != nullptr)
    {
        this->data_ = new char[strlen(Other.data_) + 1];
        strcpy(data_, Other.data_);
    }
    else
    {
        this->data_ = nullptr;
    }
}

#include <cstring>
#include <iostream>
// sample
class String
{

private:
    char *data;

public:
    String() : data(nullptr){};

    String(const char *str)
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

    ~String()
    {
        delete[] data;
    }

    String(const String &other)
    {
        if (other.data != nullptr)
        {
            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
        }
    }

    String(String &&other) noexcept
    {
        data = other.data;
        other.data = nullptr;
    }

    String &operator=(const String &other)
    {
        if (this != &other)
        {
            delete[] data;
        }
    }
};
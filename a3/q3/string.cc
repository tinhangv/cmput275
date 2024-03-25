#include <iostream>
#include <string.h>

class String{
    private:
        char* m_buffer;
        unsigned int m_size;

    public:
        String(const char* string){
            m_size = strlen(string);
            m_buffer = new char[m_size+1];
            memcpy(m_buffer, string, m_size);
            m_buffer[m_size]=0;
        }

        //copy constructor
        String(const String& other):m_size(other.m_size){
            m_buffer = new char[m_size+1];
            memcpy(m_buffer, other.m_buffer, m_size+1);
        }

        ~String(){
            delete[] m_buffer;
        }

        char& operator[](size_t index){
            return m_buffer[index];
        }

        friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

void PrintString(const String& string){
    std::cout << string << std::endl;
}

std::ostream& operator<<(std::ostream& stream, const String& string){
    stream << string.m_buffer;
    return stream;
}
int main(){
    String string = "nigger";
    String second = string;

    second[4] = 'a';
    second[5] = ' ';
    std::cout<<string<<std::endl;
    std::cout<<second<<std::endl;

    PrintString(string);
    PrintString(second);

    return 0;
}
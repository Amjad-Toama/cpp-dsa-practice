#include <iostream>
#include <stdexcept>

class ScopedBuffer {
public:
    explicit ScopedBuffer(size_t size);
    ~ScopedBuffer();                   

    ScopedBuffer(const ScopedBuffer&) = delete;
    ScopedBuffer& operator=(const ScopedBuffer&) = delete;

    size_t size() const;
    int& operator[](size_t i);
    const int& operator[](size_t i) const;

private:
    int* data_;
    size_t size_;
};

ScopedBuffer::ScopedBuffer(size_t size) : data_{new int[size]}, size_{size} {
    std::cout << "ScopedBuffer constructed\n";
}

ScopedBuffer::~ScopedBuffer() {
    delete[] data_;
    std::cout << "ScopedBuffer destroyed\n";
}

size_t ScopedBuffer::size() const {
    return size_;
}

int& ScopedBuffer::operator[](size_t i) {
    if (i >= size_){
        throw std::out_of_range("index out of range");
    }
    return data_[i];
}

const int& ScopedBuffer::operator[](size_t i) const {
    if (i >= size_){
        throw std::out_of_range("index out of range");
    }
    return data_[i];
}

int main() {
    ScopedBuffer buf{5};
    for (size_t i = 0; i < buf.size(); ++i)
        buf[i] = static_cast<int>(i * 10);

    for (size_t i = 0; i < buf.size(); ++i)
        std::cout << buf[i] << "\n";
}
#include <iostream>
#include <stdexcept>

class ScopedBuffer {
public:
    explicit ScopedBuffer(size_t size);  // allocate
    ~ScopedBuffer();                     // free

    // delete copy — why? write the reason as a comment
    ScopedBuffer(const ScopedBuffer&) = delete;
    ScopedBuffer& operator=(const ScopedBuffer&) = delete;

    size_t size() const;
    int& operator[](size_t i);
    const int& operator[](size_t i) const;

private:
    int* data_;
    size_t size_;
};

int main() {
    ScopedBuffer buf{5};
    for (size_t i = 0; i < buf.size(); ++i)
        buf[i] = static_cast<int>(i * 10);

    for (size_t i = 0; i < buf.size(); ++i)
        std::cout << buf[i] << "\n";
}
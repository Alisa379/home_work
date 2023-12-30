
#include <iostream>

template <class T> 
class table {
public:
    int rows, columns;
    T **array;
    table(int rows, int columns) : rows(rows), columns(columns) {
        array = new T* [rows];
        for (int i = 0; i < rows; ++i) {
            array[i] = new T [columns];
        }
    }
    table(T& f) : rows(f.rows), columns(f.columns) {
        array = new T * [rows];
        for (int i = 0; i < rows; ++i) {
            array[i] = new T[columns];
        }
    }
    T* operator[](int s) {
        return array[s];
    }
    T* operator[](int s) const {
        return array[s];
    }
    
    T& operator=(const T& other) {
        if (this != &other) {
            delete[] this->array;
            this.array = new T * [other.rows];
            this.rows = other.rows;
            this.columns = other.columns;
            for (int i = 0; i < this.rows; ++i) {
                this.array[i] = new T[this.columns];
            }
            for (int i = 0; i < this.rows; ++i) {
                for (int j = 0; j < this.columns; ++j) {
                    this.array[i][j] = other.array[i][j];
                }
            }
        }
        return this;
    }
    
};


int main()
{
    auto test = table<int>(2, 3);
    test[1][2];
    test[0][0] = 4;

    std::cout << test[0][0]; 
    auto test1 = table<std::string>(2, 3);
    test1[0][0] = "Hello";

    const table<int> tt(2, 3);
    tt[0][0] = 4;
    std::cout << tt[0][0] << std::endl;

   
    table<int> t1(2, 3);
    table<int> t2(2, 3);

    t1[0][0] = -1;
    t2 = t1;
    std::cout << t1[0][0] << std::endl;
    std::cout << t2[0][0] << std::endl;

    table<int> t3(2, 3);
    t3[0][0] = 10;
    table<int> t4(t3);
    std::cout << t3[0][0] << std::endl;
    std::cout << t4[0][0] << std::endl;
}


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
    T* operator[](int s) {
        return array[s];
    }
    T* operator[](int s) const {
        return array[s];
    }
    
    T& operator=(const T& other) {
        if (this != &other) {
            delete[] array;
            rows = other.rows;
            columns = other.columns;
            auto array = table<int>(rows, columns);
            for (int i = 0; i < rows; ++i) {
                array[i] = new T[columns];
            }
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < columns; ++j) {
                    array[i][j] = other.array[i][j];
                }
            }
        }
        return *this;
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
    std::cout << tt[0][0];

   
    table<int> t1(2, 3);
    table<int> t2(2, 3);

    t1 = t2;
   
}

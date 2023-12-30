
#include <iostream>
#include <vector>
#include <algorithm>


class functor {
public:
    int get_sum = []() {
        int sum = 0;
        for (auto i = this.begin(); i < this.end(); ++i) {
            if (i % 3 == 0) {
                sum += i;
            }
        }
        return sum;
    };
    int get_count = []() {
        int count = 0;
        for (auto i = this.begin(); i < this.end(); ++i) {
            if (i % 3 == 0) {
                count += 1;
            }
        }
        return count;
        };
};

int main()
{
    std::vector<int> vector = { 4, 1, 3, 6, 25, 54 };
    functor f;

    f = std::for_each(vector.begin(), vector.end(), f);

    std::cout << "[OUT] : get_sum() = " << f.get_sum() << std::endl;
    std::cout << "[OUT] : get_count() = " << f.get_count() << std::endl;
}
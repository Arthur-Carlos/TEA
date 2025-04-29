#include <iostream>
#include <vector>

class FenwickTree {
private:
    std::vector<int> tree;
    int size;

    int lsb(int index) {
        return index & -index;
    }

public:
    FenwickTree(int n) : size(n) {
        tree.resize(n + 1, 0);
    }

    void update(int index, int delta) {
        while (index <= size) {
            tree[index] += delta;
            index += lsb(index);
        }
    }

    int query(int index) {
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= lsb(index);
        }
        return sum;
    }

    int rangeQuery(int left, int right) {
        return query(right) - query(left - 1);
    }
};

int main() {
    int n, queries;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    FenwickTree fenwick(n);

    std::cout << "Enter the number of queries: ";
    std::cin >> queries;

    for (int i = 0; i < queries; ++i) {
        int type;
        std::cout << "Enter query type (1 for update, 2 for range query): ";
        std::cin >> type;

        if (type == 1) {
            int index, delta;
            std::cout << "Enter index and delta: ";
            std::cin >> index >> delta;
            fenwick.update(index, delta);
        } else if (type == 2) {
            int left, right;
            std::cout << "Enter range (left and right): ";
            std::cin >> left >> right;
            std::cout << "Range sum: " << fenwick.rangeQuery(left, right) << std::endl;
        } else {
            std::cout << "Invalid query type!" << std::endl;
        }
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <tuple>

template <class T>
class SearchableVector {
public:
    // TODO : use a constructor to initialize the vector element
    // vector does not throw error when accessing out of bound indexes, so check size before access
    std::vector<T> svec;
    /**
     * The first tuple elemnt is the distance from the 0th element, the second element is the index
     * If -1s are returned, meaning result not found. 
    */
    std::tuple<double, double> find_elem(T t) {
        if (this->svec.size() <= 0) {
            printf("Vector empty, initialize vectory before element search");
            return std::make_tuple(-1, -1);
        }
        auto result =  std::find(svec.begin(), svec.end(), t);
        double dist {0};
        if (result != svec.end()) {
            dist = std::distance(svec.begin(), result);
            printf("The requested element is found at position %d.\n", int(dist));
        } else {
            return std::make_tuple(-1, -1);
        }
        return std::make_tuple(dist+1, dist);
    };
};

int main(int, char**) {

    SearchableVector<int> svi;
    for(int i = 0; i < 1000; i++) {
        svi.svec.push_back(i);
    }
    int search_elem = 2000;
    auto result = svi.find_elem(search_elem);
    std::cout << "The distance is " << std::get<0>(result) << std::endl;
    std::cout << "The index is " << std::get<1>(result) << std::endl;
    std::cout << "The element accessed through indexing matches : " << std::boolalpha
              << (search_elem == svi.svec[(int)std::get<1>(result)]) << std::endl;
    std::cout << svi.svec[2000] << std::endl;

}

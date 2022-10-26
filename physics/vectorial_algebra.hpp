#include <vector>
using namespace std;

namespace Vec{
    enum {x, y, z};

    class Vec{
    private:
        vector<double> u;
        
    public:
        Vec operator+(Vec v){
            for (int i = 0; i < 3; i ++)
                u[i] = u[i] + v[i];
        }
        double operator[](int i){
            return u[i];
        }


    };
}
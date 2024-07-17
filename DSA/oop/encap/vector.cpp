#include <iostream>
#include <cstring>

using namespace std;

class Vector{
    private:
        int x;
        int y;
    public:
        Vector(int x, int y){
            this->x = x;
            this->y = y;
        }
        // Vector(int x, int y) : x(x), y(y) { }

        Vector add( Vector v) {
            int new_x = this->x + v.x;
            int new_y = this->y + v.y;
            return Vector(new_x, new_y);
        }
    friend ostream& operator<<(ostream& os, const Vector& v) {
        os << "(" << v.x << ", " << v.y << ")";
        return os;
    }
};

Vector vector_1(1, 2), vector_2(3, 4);

int main() {
    cout << vector_1.add(vector_2);
    return 0;
}
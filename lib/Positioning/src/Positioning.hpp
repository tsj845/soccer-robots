namespace Positioning {
    class vector2 {
        public:
        double x;
        double y;
        public:
        vector2(double x = 0, double y = 0) {
            this->x = x;
            this->y = y;
        }
        vector2 operator+(vector2 other) {return vector2(x+other.x,y+other.y);}
        // vector2 operator+(vector2 const& other) {return vector2(x+other.x,y+other.y);}
        // vector2 operator+(vector2* other) {return vector2(x+other->x,y+other->y);}
        vector2 operator-(vector2 other) {return vector2(x-other.x,y-other.y);}
        vector2 operator-(vector2 const& other) {return vector2(x-other.x,y-other.y);}
        vector2 operator-(vector2* other) {return vector2(x-other->x,y-other->y);}
        vector2 operator*(double scalar) {return vector2(x*scalar,y*scalar);}
        vector2 operator*(float scalar) {return vector2(x*scalar,y*scalar);}
        vector2 operator*(int scalar) {return vector2(x*scalar,y*scalar);}
        vector2 operator/(double scalar) {return vector2(x/scalar,y/scalar);}
        vector2 operator/(float scalar) {return vector2(x/scalar,y/scalar);}
        vector2 operator/(int scalar) {return vector2(x/scalar,y/scalar);}
        double magnitude() {return sqrt(x*x + y*y);}
        double dot(vector2 other) {return x*other.x + y*other.y;}
        double dot(vector2 const& other) {return x*other.x + y*other.y;}
        double dot(vector2* other) {return x*other->x + y*other->y;}
        vector2 normalize() {return vector2(x,y)/magnitude();}

    };
    vector2 D1 = vector2(0, 1);
    vector2 D2 = vector2(0.707106781186548, 0.707106781186548);
    vector2 D3 = vector2(1, 0);
    vector2 D4 = vector2(0.707106781186548, -0.707106781186548);
    vector2 D5 = vector2(0, -1);
    vector2 D6 = vector2(-0.707106781186548, -0.707106781186548);
    vector2 D7 = vector2(-1, 0);
    vector2 D8 = vector2(-0.707106781186548, 0.707106781186548);

    /**
     * @brief relative to ball
     */
    vector2 getPosition() { // MOCKUP
        vector2 r = D1*readBall(1)+D2*readBall(2)+D3*readBall(3)+D4*readBall(4)+D5*readBall(5)+D6*readBall(6)+D7*readBall(7)+D8*readBall(8);
        return r;
    }
}

using Positioning::vector2;
using Positioning::getPosition;
// PRECISO TESTAR TUDO

// 3D point
#define X first.first
#define Y first.second
#define Z second
typedef pair<pair<int, int>, int> point;
// SERÁ QUE TUPLE SERIA MELHOR DO QUE PAIR(PAIR())?

// dot product
int dot(point a, point b){return a.X * b.X + a.Y * b.Y + a.Z * b.Z;}

// |a|²
int norm(point a){return dot(a, a);}

// |a|
double length(point a){return sqrt(norm(a));}

// angle AOB in radians
double angle(point a, point b){
    return acos( dot(a,b) / (length(a) * length(b)) );
}

// angle ACB in radians
double angle2(point a, point b, point c){
    a = {a.X-c.X, a.Y-c.Y, a.Z-c.Z};
    b = {b.X-c.X, b.Y-c.Y, b.Z-c.Z};
    return angle(a, b);
}

// cross product (needs 3D points)
point cross(point a, point b){
    int cx = a.Y * b.Z - a.Z * b.Y;
    int cy = a.Z * b.X - a.X * b.Z;
    int cz = a.X * b.Y - a.Y * b.X;
    return {{cx, cy}, cz};
}

// area of the paralelogram defined by 'a' and 'b'
int area2(point a, point b){return length(cross(a,b));}

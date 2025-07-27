// PRECISO TESTAR TUDO
// ref: https://github.com/brunomaletta/Biblioteca/blob/master/Codigo/Primitivas/geometria.cpp

#define sz(x) (int)x.size()
#define sq(x) ((x)*(x))

using T = int;
using ld = double;

const ld EPS = 1e-9;
const ld pi = acos(-1);

// compare using EPS
bool eq(ld x, ld y){return abs(x-y) <= EPS;}

struct Pt{
    T x, y;
    Pt(T _x = 0, T _y = 0) : x(_x), y(_y) {}
    Pt&  operator += (const Pt p)       { x += p.x; y += p.y; return *this; }
    Pt&  operator -= (const Pt p)       { x -= p.x; y -= p.y; return *this; }
    Pt   operator +  (const Pt p) const { return Pt(x + p.x, y + p.y); }
    Pt   operator -  (const Pt p) const { return Pt(x - p.x, y - p.y); }
    Pt   operator *  (const T  a) const { return Pt(x * a  , y * a); }
    Pt   operator /  (const T  a) const { return Pt(x / a  , y / a); }
    T    operator *  (const Pt p) const { return x * p.x + y * p.y; }
    T    operator ^  (const Pt p) const { return x * p.y - y * p.x; }
    bool operator == (const Pt p) const { return eq(x, p.x) && eq(y, p.y); }
    bool operator != (const Pt p) const { return !(*this == p); }
    bool operator <  (const Pt p) const {
        if(!eq(x, p.x)) return x < p.x;
        if(!eq(y, p.y)) return y < p.y;
        return 0;
    }
    friend istream& operator >> (istream& in, Pt& p){ return in >> p.x >> p.y; }
    friend ostream& operator << (ostream& out, Pt& p){
        return out << '(' << p.x << ',' << p.y << ')';
    }
};

using Polygon = vector<Pt>;

struct Line{
    Pt a, b;
    Line(Pt _a = Pt(0,0), Pt _b = Pt(0,0)) : a(_a), b(_b) {}
    friend istream& operator >> (istream& in, Line& l){
        return in >> l.a >> l.b;
    }
};

ld norm(Pt v){ return sqrt(v * v); } // |v|

T dist2(Pt a, Pt b){ return (a - b) * (a - b); } // squared point distance

ld dist(Pt a, Pt b){ return sqrt(dist2(a, b)); } // point distance

ld angle(Pt v){ // angle with x axis in [0, 2pi)
    ld ang = atan2(v.y, v.x);
    if(ang < 0) ang += 2 * pi;
    return ang;
}

// angle AOB in radians
ld angle_between(Pt a, Pt b){ return acos( (a * b) / (norm(a) * norm(b)) ); }

// angle ACB in radians
ld angle2(Pt a, Pt b, Pt c){ return angle_between(a - c, b - c); }

// signed area of the paralelogram defined by 'a' and 'b'
int sarea2(Pt a, Pt b){ return a ^ b; }

// does the path a,b,c makes a counter-clockwise curve?
int ccw(Pt a, Pt b, Pt c){
    T det = (c - b) ^ (b - a);
    if(eq(det, 0)) return 0; // collinear
    if(det > 0) return 1;    // ccw
    return -1;               // cw
}

Pt rotate(Pt v, ld theta){ // rotate v by theta radians
    return Pt(  v.x * cos(theta) - v.y * sin(theta),
                v.x * sin(theta) + v.y * cos(theta));
}

Pt rotate90(Pt v) { return Pt(-v.y, v.x); } // rotate v by 90 degrees

// angle opposite to side 'a' in a triangle of sides a,b,c
ld angle_a(int a, int b, int c){
    return acos( ld(a*a - b*b - c*c) / ld(-2*b*c) );
}

// distance between point 'p' and line defined by 'a' and 'b'
ld dist_pl(Pt p, Pt a, Pt b){
    ld num =
    abs( (b.y - a.y)*p.x - (b.x - a.x)*p.y + b.x*a.y - b.y*a.x );
    ld den =
    sqrt( (b.y - a.y)*(b.y - a.y) + (b.x - a.x)*(b.x - a.x) );
    return num / den;
}

// Shoelace Formula to compute the area of a generic polygon
ld area_polygon(Polygon P){
    int n = sz(P);
    ld area = 0;
    for(int i = 0; i < n; ++i){
        Pt a = P[i], b = P[(i + 1) % n];
        area += (a ^ b);
    }
    return abs(area / 2);
}

// is point 'a' inside convex polygon 'P' (given in ccw order)? O(|P|)
bool is_inside(Pt a, Polygon P){
    int n = sz(P);
    for(int i = 0; i < n; ++i)
        if(ccw(P[i], P[(i + 1) % n], a) == -1)
            return false;
    return true;
}

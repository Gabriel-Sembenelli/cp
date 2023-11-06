// PRECISO TESTAR TUDO

#define sz(x) (int)x.size()

const double EPS = 1e-9;
const double pi = acos(-1);

// 2D point
#define X first
#define Y second
typedef pair<int, int> point;

// line "y = Ax + B", where A = (Anum / Aden), B = (Bnum, Bden)
#define Anum first.first
#define Aden first.second
#define Bnum second.first
#define Bden second.second
typedef pair<pair<int,int>, pair<int,int>> line;

// polygon
typedef vector<point> polygon;

// compare using EPS
bool equals(double x, double y){return abs(x-y) < EPS;}

// dot product
int dot(point a, point b){return a.X * b.X + a.Y * b.Y;}

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
    a = {a.X-c.X, a.Y-c.Y};
    b = {b.X-c.X, b.Y-c.Y};
    return angle(a, b);
}

// area of the paralelogram defined by 'a' and 'b'
int area2(point a, point b){return a.X * b.Y - a.Y * b.X;}

// line that passes through a and b             PRECISO TESTAR ISSO
line make_line(point a, point b){
    int anum = b.Y - a.Y;
    int aden = b.X - a.X;
    int bnum = a.X * b.Y - a.Y * b.X;
    int bden = b.X - a.X;
    return {{anum, aden}, {bnum, bden}};
}

// angle opposite to side 'a' in a triangle of sides a,b,c
double angle_a(int a, int b, int c){
    return acos( double(a*a - b*b - c*c) / double(-2*b*c) );
}

// distance between point 'p' and line defined by 'a' and 'b'
double dist_pl(point p, point a, point b){
    double num =
    abs( (b.Y - a.Y)*p.X - (b.X - a.X)*p.Y + b.X*a.Y - b.Y*a.X );
    double den =
    sqrt( (b.Y - a.Y)*(b.Y - a.Y) + (b.X - a.X)*(b.X - a.X) );
    return num / den;
}

// uses Gauss's Formula to compute area of generic polygon
double area_polygon(polygon P){
    int n = sz(P);
    double area = 0;
    for(int i=0; i<n; i++){
        point p1 = P[i], p2 = P[(i+1)%n];
        area += (p2.X + p1.X) * (p2.Y - p1.Y); // TA CERTO ISSO?
        //area += p1.X * p2.Y - p1.Y * p2.X; // NÃO SERIA ISSO?
    }
    area /= 2.0;
    return abs(area);
}

// does the path a,b,c makes a counter-clockwise curve?
int ccw(point a, point b, point c){
    int det = (b.X - a.X) * (c.Y - a.Y) - (b.Y - a.Y) * (c.X - a.X);
    if(det > 0) return 1;   // ccw
    if(det < 0) return -1;  // cw
    return 0;               // collinear
}

// is point 'a' inside of convex polygon 'P'? O(|P|)
bool is_inside(point a, polygon P){
    int n = sz(P);
    for(int i=0; i<n; i++)
        if(ccw(P[i], P[(i+1)%n], a) == -1)
            return false;
    return true;
}

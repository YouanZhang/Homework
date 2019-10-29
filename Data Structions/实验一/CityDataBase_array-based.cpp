#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
class Point {
private:
    DB x, y;
public:
    Point (DB _x, DB _y) : x(_x), y(_y) {}
    DB getX() {return x;}
    DB getY() {return y;}
    DB distanceWith(Point a) {return sqrt((x - a.x) * (x - a.x) + (y - a.y) * (y - a.y));}
    Point () {}
};
typedef string Name;
typedef pair <Name, Point> City;
class CityDataBase {
private:
    vector <City> city;
    string Ope[5] = {"", "Insert", "Delete", "Search", "Exit"};
    string Typ[3] = {"", "name", "coordinate"};
public:
    void printFirstLevelUi() {
        cout << "Choose your operation (index):" << endl;
        for (int i = 1; i <= 4; i++) cout << i << " : " << Ope[i] << endl;
    }

    void printSecondLevelUi(string ope) {
        cout << "Choose your " << ope << " type (index):" << endl;
        for (int i = 1; i <= 2; i++) cout << i << " : By " << Typ[i] << endl;
    }

    int pointSearchByName(string & tmpname) {
        for (int c = 0; c < city.size(); c++) 
            if (city[c].first == tmpname) return c;
        return -1; // error
    }

    int pointSearchByCoordinate(Point tmpcoodinate) {
        for (int c = 0; c < city.size(); c++) 
            if (city[c].second.getX() == tmpcoodinate.getX() && city[c].second.getY() == tmpcoodinate.getY()) return c;
        return -1; // error
    }

    void pointSearch() {
        printSecondLevelUi("search");
        int typ;
        cin >> typ;
        int index;
        if (typ == 1) {
            cout << "Enter city name: " << endl;
            string tmpname;
            cin >> tmpname;
            index = pointSearchByName(tmpname);
            if (index != -1) cout << "It it located ( " << city[index].second.getX() << " , " << city[index].second.getY() << " )." << endl;
            else cout << "SEARCH ERROR" << endl << "Please check your city name." << endl;
        }
        if (typ == 2) {
            cout << "Enter city coordinate: (e.g. 1 1):" << endl;
            DB tmpx, tmpy;
            index = pointSearchByCoordinate(Point(tmpx, tmpy));
            if (index != -1) cout << "It is " << city[index].first << endl;
            else cout << "SEARCH ERROR" << endl << "Please check your city coordinate." << endl;
        }
    }

    void rangeSearch() {
        cout << "Enter your coodinate (e.g. 1 1):" << endl;
        DB tmpx, tmpy;
        cin >> tmpx >> tmpy;
        Point center(tmpx, tmpy);
        cout << "Enter your search radius :" << endl;
        DB tmpr;
        cin >> tmpr;
        int cnt = 0;
        for (auto c : city)
            if (c.second.distanceWith(center) <= tmpr) {
                cnt++;
                cout << c.first << " ( " << c.second.getX() << " , " << c.second.getY() << " )" << endl;
            }
        cout << "Total :" << cnt << endl;
    }

    void search() {
        cout << "Choose your search mode :" << endl;
        cout << "1 : Point search" << endl;
        cout << "2 : Range search" << endl;
        int mode;
        cin >> mode;
        if (mode == 1) pointSearch();
        if (mode == 2) rangeSearch();
    }

    void insertByName() {
        cout << "Enter city name: " << endl;
        string tmpname;
        cin >> tmpname;
        cout << "Enter city coordinate (e.g. 1 1):" << endl;
        DB tmpx, tmpy;
        cin >> tmpx >> tmpy;
        if (pointSearchByName(tmpname) == -1 && pointSearchByCoordinate(Point(tmpx, tmpy)) == -1) city.push_back(City(tmpname, Point(tmpx, tmpy)));
        else cout << "INSERT ERROR" << endl << "Please check your city name and coordinate." << endl;
    }

    void insertByCoordinate() {
        cout << "Enter city coordinate (e.g. 1 1):" << endl;
        DB tmpx, tmpy;
        cin >> tmpx >> tmpy;
        cout << "Enter city name: " << endl;
        string tmpname;
        cin >> tmpname;
        if (pointSearchByName(tmpname) == -1 && pointSearchByCoordinate(Point(tmpx, tmpy)) == -1) city.push_back(City(tmpname, Point(tmpx, tmpy)));
        else cout << "INSERT ERROR" << endl << "Please check your city name and coordinate." << endl;
    }

    void insert() {
        printSecondLevelUi("insert");
        int typ;
        cin >> typ;
        if (typ == 1) insertByName();
        if (typ == 2) insertByCoordinate();
    }

    void deletByName() {
        cout << "Enter city name :" << endl;
        string tmpname;
        cin >> tmpname;
        int index = pointSearchByName(tmpname);
        if (index != -1) {
            swap(city[index], city[city.size() - 1]);
            city.pop_back();
        }
        else cout << "DELETE ERROR" << endl << "Please check your city name." << endl;
    }

    void deletByCoordinate() {
        cout << "Enter city coordinate :" << endl;
        DB tmpx, tmpy;
        int index = pointSearchByCoordinate(Point(tmpx, tmpy));
        if (index != -1) {
            swap(city[index], city[city.size() - 1]);
            city.pop_back();
        }
        else cout << "DELETE ERROR" << endl << "Please check your city coordinate." << endl;
    }

    void delet() {
        printSecondLevelUi("delete");
        int typ;
        cin >> typ;
        if (typ == 1) deletByName();
        if (typ == 2) deletByCoordinate();
    }
};
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(2); cout << fixed;
    CityDataBase c;
    for (; ;) {
        c.printFirstLevelUi();
        int ope;
        cin >> ope ;
        if (ope == 1) c.insert();
        if (ope == 2) c.delet();
        if (ope == 3) c.search();
        if (ope == 4) break;
    }
    return 0;
}